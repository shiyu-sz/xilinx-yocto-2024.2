SUMMARY = "System Controller App - VM-P-M1369-00 board specific files"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

require system-controller-app.inc

BOARD = "vm-p-m1369-00"
BOARD_upper = "VM-P-M1369-00"

SRC_URI = "\
	${JSON_PATH} \
"

RDEPENDS_${PN} = "packagegroup-syscontroller"

COMPATIBLE_MACHINE = "^$"
COMPATIBLE_MACHINE:system-controller = "${MACHINE}"

PACKAGE_ARCH = "${MACHINE_ARCH}"

FILES:${PN} += " \
	${datadir}/system-controller-app/ \
	"

do_install(){
	mkdir -p ${D}${datadir}/system-controller-app/board

	cp ${WORKDIR}/${BOARD_upper}.json ${D}${datadir}/system-controller-app/board/
}
