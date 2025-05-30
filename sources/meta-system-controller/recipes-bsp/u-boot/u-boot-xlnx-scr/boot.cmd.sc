# This is a boot script for U-Boot
# Generate boot.scr:
# mkimage -c none -A arm -T script -d boot.cmd.default boot.scr
#
################
fitimage_name=@@FIT_IMAGE@@
kernel_name=@@KERNEL_IMAGE@@
ramdisk_name=@@RAMDISK_IMAGE1@@
rootfs_name=@@RAMDISK_IMAGE@@
@@PRE_BOOTENV@@

#Set DT selection
if test "${board_name}-${board_rev}" = "VEK280-B01" || test "${board_name}-${board_rev}" = "VEK280-B02" || test "${board_name}-${board_rev}" = "VEK280-B03"; then
        dtb_name=devicetree/system-sc-revc-zynqmp
else
        dtb_name=system
fi

setenv bootargs 'earlycon console=ttyPS0,115200 root=/dev/ram0 rw init_fatal_sh=1 @@KERNEL_COMMAND_APPEND@@';
for boot_target in ${boot_targets};
do
	echo "Trying to load boot images from ${boot_target}"
	if test "${boot_target}" = "jtag" ; then
		@@KERNEL_BOOTCMD@@ @@KERNEL_LOAD_ADDRESS@@ @@RAMDISK_IMAGE_ADDRESS@@ @@DEVICETREE_ADDRESS@@
	fi
	if test "${boot_target}" = "mmc0" || test "${boot_target}" = "mmc1" || test "${boot_target}" = "usb0" || test "${boot_target}" = "usb1"; then
		if test -e ${devtype} ${devnum}:${distro_bootpart} /@@UENV_TEXTFILE@@; then
			fatload ${devtype} ${devnum}:${distro_bootpart} @@UENV_MMC_LOAD_ADDRESS@@ @@UENV_TEXTFILE@@;
			echo "Importing environment(@@UENV_TEXTFILE@@) from ${boot_target}..."
			env import -t @@UENV_MMC_LOAD_ADDRESS@@ $filesize
			if test -n $uenvcmd; then
				echo "Running uenvcmd ...";
				run uenvcmd;
			fi
		fi
		if test -e ${devtype} ${devnum}:${distro_bootpart} /${fitimage_name}; then
			fatload ${devtype} ${devnum}:${distro_bootpart} @@FIT_IMAGE_LOAD_ADDRESS@@ ${fitimage_name};
			bootm @@FIT_IMAGE_LOAD_ADDRESS@@;
                fi
		if test -e ${devtype} ${devnum}:${distro_bootpart} /${kernel_name}; then
			fatload ${devtype} ${devnum}:${distro_bootpart} @@KERNEL_LOAD_ADDRESS@@ ${kernel_name};
		fi
		if test -e ${devtype} ${devnum}:${distro_bootpart} /${dtb_name}.dtb; then
			fatload ${devtype} ${devnum}:${distro_bootpart} @@DEVICETREE_ADDRESS@@ ${dtb_name}.dtb;
		fi
		if test -e ${devtype} ${devnum}:${distro_bootpart} /${ramdisk_name} && test "${skip_tinyramdisk}" != "yes"; then
			fatload ${devtype} ${devnum}:${distro_bootpart} @@RAMDISK_IMAGE_ADDRESS@@ ${ramdisk_name};
			@@KERNEL_BOOTCMD@@ @@KERNEL_LOAD_ADDRESS@@ @@RAMDISK_IMAGE_ADDRESS@@ @@DEVICETREE_ADDRESS@@
		fi
		if test -e ${devtype} ${devnum}:${distro_bootpart} /${rootfs_name} && test "${skip_ramdisk}" != "yes"; then
			fatload ${devtype} ${devnum}:${distro_bootpart} @@RAMDISK_IMAGE_ADDRESS@@ ${rootfs_name};
			@@KERNEL_BOOTCMD@@ @@KERNEL_LOAD_ADDRESS@@ @@RAMDISK_IMAGE_ADDRESS@@ @@DEVICETREE_ADDRESS@@
		fi
		@@KERNEL_BOOTCMD@@ @@KERNEL_LOAD_ADDRESS@@ - @@DEVICETREE_ADDRESS@@
	fi
done
