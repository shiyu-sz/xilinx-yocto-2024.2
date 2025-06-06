FILESEXTRAPATHS:append := ":${THISDIR}/u-boot-xlnx-scr"

BOOTMODE:k26-smk = ""
BOOTMODE:k24-smk = ""
BOOTMODE:k24i-sm = ""
BOOTMODE:k24c-sm = ""
BOOTMODE:k26-sm = ""
BOOTMODE:kria-zynqmp-generic = ""

BOOTFILE_EXT:k26-smk = "kria"
BOOTFILE_EXT:k24-smk = "kria"
BOOTFILE_EXT:k24c-sm = "kria.prod"
BOOTFILE_EXT:k24i-sm = "kria.prod"
BOOTFILE_EXT:k26-sm = "kria.prod"
BOOTFILE_EXT:kria-zynqmp-generic = "kria"

SRC_URI:append:k26-smk = " file://boot.cmd.kria"
SRC_URI:append:k24-smk = " file://boot.cmd.kria"
SRC_URI:append:k26-sm = " file://boot.cmd.kria.prod"
SRC_URI:append:k24i-sm = " file://boot.cmd.kria.prod"
SRC_URI:append:k24c-sm = " file://boot.cmd.kria.prod"
SRC_URI:append:kria-zynqmp-generic = " file://boot.cmd.kria"
