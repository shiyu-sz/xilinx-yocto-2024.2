# Override fancontrol configuration file, making this SC specific
SRC_URI:append = " file://0001-Restart-the-fancontrol-service-on-failure.patch"
SRC_URI:append = " file://0001-Update-fancontrol-for-systems-that-can-monitor-Versa.patch"
FILESEXTRAPATHS:append := "${THISDIR}/lmsensors:"

PACKAGE_ARCH = "${MACHINE_ARCH}"
SYSTEMD_AUTO_ENABLE = "enable"
