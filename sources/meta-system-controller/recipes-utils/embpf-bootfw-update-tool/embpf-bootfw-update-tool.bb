DESCRIPTION = "Versal and Kria OSPI /QSPI Programming Utility"
SUMMARY = "Scripts used to program Versal and Kria OSPI and QSPI Boot image"

LICENSE = "Proprietary & MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=15a2ee395e9805633766dce7d5d10a0f"

BRANCH = "main"
SRC_URI = " \
	git://github.com/Xilinx/embpf-bootfw-update-tool.git;branch=${BRANCH};protocol=https \
"

SRCREV = "8af618e0a2dfc4103bd1e65018bc359c2c60d4c0"

S="${WORKDIR}/git"

RDEPENDS:${PN} += " \
    bash \
    labtool-jtag-support \
	coreutils "

do_install() {
    install -d ${D}${datadir}/${PN}
    cp -r ${S}/* ${D}${datadir}/${PN}

}
