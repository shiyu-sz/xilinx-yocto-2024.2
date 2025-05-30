#!/bin/bash
# Generate the system-controller-app.inc file
#
# Usage:
# cd sources/meta-system-controller
# ./scripts/sc-app-repo-generate-srcuri.sh \
#    https://xcoartifactory.xilinx.com/artifactory/system-controller/sc_app_bsp/2023.2/2023.2_02232200/external/ \
#    > recipes-utils/system-controller-app/system-controller-app.inc
#
# It is assumed the URL being pointed to will be a series of directories. The BOARD value
# will be the directory name, and the contents within the directory will be the board
# specific files.
#

if [ $# -lt 1 -o $# -gt 2 ]; then
    echo "Usage: $0 <url> [<local_dir>]" >&2
    exit 1
fi

url=$(echo $1 | sed -e 's,/$,,')

localdir=${2}

urlproto=$(echo $url | sed -e 's,://.*,://,')
urlpath=$(echo $url | sed -e 's,'${urlproto}',,')

if [ ${url} = ${urlproto} -o -z ${url} ]; then
    echo "URL $url is invalid" >&2
    exit 1
fi

if [ ${urlproto} = "file://" ]; then
    # file:// URL, usually only for testing
    cd ${urlpath}
elif [ -n "${localdir}" ]; then
    # Remote url, but using a local cache to generate
    cd ${localdir}
else
    # Remove url, recursive fetch and then generate
    tempdir=$(mktemp -d)
    cd ${tempdir}
    wget --recursive --no-parent $url/

    cd ${urlpath}
fi

echo "# Automatically generated.  Manual changes will be lost."
echo
echo "ES1_PATH = \"\${@d.getVarFlag('ES1_PATH', d.getVar('BOARD')) or ''}\""
echo "SYS_PATH = \"\${@d.getVarFlag('SYS_PATH', d.getVar('BOARD')) or ''}\""
echo "ELF_PATH = \"\${@d.getVarFlag('ELF_PATH', d.getVar('BOARD')) or ''}\""
echo "JSON_PATH = \"\${@d.getVarFlag('JSON_PATH', d.getVar('BOARD')) or ''}\""
echo "JPG_PATH = \"\${@d.getVarFlag('JPG_PATH', d.getVar('BOARD')) or ''}\""
echo "PNG_PATH = \"\${@d.getVarFlag('PNG_PATH', d.getVar('BOARD')) or ''}\""
echo "JS_PATH = \"\${@d.getVarFlag('JS_PATH', d.getVar('BOARD')) or ''}\""
echo "BOOT_BIN_PATH = \"\${@d.getVarFlag('BOOT_BIN_PATH', d.getVar('BOARD')) or ''}\""
echo "OSPI_PATH = \"\${@d.getVarFlag('OSPI_PATH', d.getVar('BOARD')) or ''}\""
echo

dirnames=$(curl --silent ${urlproto}${urlpath}/ | grep -o 'href=".*">' | sed 's/href="//;s/\/">//')
for dir in $dirnames; do 
	if [ "$dir" == ".." ]; then
		continue
	fi
	files=$(curl --silent "${urlproto}${urlpath}/$dir/" | grep -o 'href=".*">' | sed -e "s/href=\"//g" | sed -e 's/">//g')
	echo "# $dir"
	device=$(basename "$dir")
	device="${device,,}"
	for i in $files; do
		opts=''
		if [ "$i" == "../" ]; then
			continue
		fi
		if [[ "$i" == *"elf"* ]]; then
			name=$device-elf
			yp_name="ELF_PATH"
		elif [[ "$i" == *"pdi"* ]] && [[ "$i" == *"es1"* ]]; then
			name=$device-es1-system
			yp_name="ES1_PATH"
		elif [[ "$i" == *"pdi"* ]]; then
			name=$device-system
			yp_name="SYS_PATH"
		elif [[ "$i" == *"xsa"* ]]; then
			continue
		elif [[ "$i" == *"json"* ]]; then
			name=$device-json
			yp_name="JSON_PATH"
		elif [[ "$i" == *"strings"* ]]; then
			name=$device-js
			yp_name="JS_PATH"
		elif [[ "$i" == *"jpg"* ]]; then
			name=$device-jpg
			yp_name="JPG_PATH"
		elif [[ "$i" == *"png"* ]]; then
			name=$device-png
			yp_name="PNG_PATH"
		elif [[ "$i" == *"BOOT"* ]]; then
			name=$device-boot-bin
			yp_name="BOOT_BIN_PATH"
		elif [[ "$i" == *"bin.gz"* ]]; then
			name=$device-ospi
			yp_name="OSPI_PATH"
			opts=';unpack=0'
		fi
		echo "# $i"
		echo ${yp_name}["${device}"] = "'${urlproto}${urlpath}/${dir}/${i};name=${name}${opts}'"
		curl -o tempfile --silent "${urlproto}${urlpath}/$dir/$i"
		echo SRC_URI["${name}".sha256sum] = "'$(sha256sum tempfile | awk '{print $1}')'"
		echo
	done
done
rm tempfile
