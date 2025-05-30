PROVIDES:arm = " open-amp open-amp-xlnx "
RPROVIDES:${PN} += "open-amp"
RPROVIDES:${PN}-demos += "open-amp-demos"

inherit ccmake cmake python3-dir deploy

LOPS_DIR="${RECIPE_SYSROOT_NATIVE}/${PYTHON_SITEPACKAGES_DIR}/lopper/lops/"
SYSTEM_DTFILE_DEPENDS ??= ""
OPENAMP_DEPENDS ?= "${SYSTEM_DTFILE_DEPENDS}"
OPENAMP_DTFILE ?= "${SYSTEM_DTFILE}"

DEPENDS += "${OPENAMP_DEPENDS}"

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

OECMAKE_SOURCEPATH = "${S}/"

DEPENDS += "libmetal python3-pyyaml-native lopper-native python3-dtc-native"

DEPENDS_BAREMETAL ??= ""
DEPENDS_BAREMETAL:armv7r = "xiltimer libxil xilstandalone xiltimer xilinx-lops-native"
DEPENDS_BAREMETAL:armv8r = "xiltimer libxil xilstandalone xiltimer xilinx-lops-native"

DEPENDS += "${DEPENDS_BAREMETAL}"

DEPENDS_FREERTOS ??= ""
DEPENDS_FREERTOS:xilinx-freertos = "freertos10-xilinx"

DEPENDS += "${DEPENDS_FREERTOS}"

OPENAMP_WITH_PROXY ?= "OFF"

FILESEXTRAPATHS:prepend := "${THISDIR}/overlays:"
OPENAMP_OVERLAY_DEFAULT = "unknown"
OPENAMP_OVERLAY_DEFAULT:zynqmp ??= "openamp-overlay-zynqmp.yaml"
OPENAMP_OVERLAY_DEFAULT:versal ??= "openamp-overlay-versal.yaml"
OPENAMP_OVERLAY_DEFAULT:versal-net ??= "openamp-overlay-versal-net.yaml"
OPENAMP_OVERLAY ?= "${OPENAMP_OVERLAY_DEFAULT}"
SRC_URI:append = "  file://${OPENAMP_OVERLAY} "

OECMAKE_C_LINK_FLAGS:append:arm = " --sysroot=${STAGING_DIR_HOST}"
CFLAGS:append = " -DSDT -D_AMD_GENERATED_ -DVIRTIO_USE_DCACHE ${DEBUG_PREFIX_MAP} "
CFLAGS:append:armv7r = " -O3  -DXLNX_PLATFORM  -specs=${PKG_CONFIG_SYSROOT_DIR}/usr/include/Xilinx.spec "
CFLAGS:append:armv8r = " -O3  -DXLNX_PLATFORM  -specs=${PKG_CONFIG_SYSROOT_DIR}/usr/include/Xilinx.spec "
CFLAGS:append:xilinx-freertos = " -DUSE_FREERTOS "

OPENAMP_CMAKE_SOC = "unknown"
OPENAMP_CMAKE_SOC:zynqmp = "ZYNQMP"
OPENAMP_CMAKE_SOC:versal = "VERSAL"
OPENAMP_CMAKE_SOC:versal-net = "VERSAL_NET"

OPENAMP_CMAKE_SYSTEM_NAME = "unknown"
OPENAMP_CMAKE_SYSTEM_NAME:xilinx-standalone = "Generic"
OPENAMP_CMAKE_SYSTEM_NAME:xilinx-freertos = "FreeRTOS"

LINKER_METADATA_FILE="OpenAMP_Lopper_Linker_Cfg.cmake"

TOOLCHAIN_FILE_MACHINE:armv7r = "zynqmp_r5"
TOOLCHAIN_FILE_MACHINE:armv8r = "zynqmp_r5"
TOOLCHAIN_FILE_MACHINE:linux = "${OPENAMP_MACHINE}"

OPENAMP_MACHINE:xilinx-standalone = "${TOOLCHAIN_FILE_MACHINE}"
OPENAMP_MACHINE:xilinx-freertos = "${TOOLCHAIN_FILE_MACHINE}"

DEMO_LINK_FLAGS ?= ""
DEMO_LINK_FLAGS:append:armv7r = " -lxilstandalone -lscugic -lxiltimer"
DEMO_LINK_FLAGS:append:armv8r = " -lxilstandalone -lscugic -lxiltimer"
DEMO_LINK_FLAGS:append:xilinx-freertos = " -lfreertos "

# Generate Lopper linker config file before generating toolchain file
cmake_do_generate_toolchain_file:append:arm() {
    cat >> ${WORKDIR}/toolchain.cmake <<EOF
	include (CMakeForceCompiler)
	CMAKE_FORCE_C_COMPILER("${OECMAKE_C_COMPILER}" GNU)
	set (CMAKE_SYSTEM_PROCESSOR "${TRANSLATED_TARGET_ARCH}" )
	set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ")
	set (CMAKE_SYSTEM_NAME      "${OPENAMP_CMAKE_SYSTEM_NAME}")
	set (MACHINE                "${TOOLCHAIN_FILE_MACHINE}" )
	set (CMAKE_LIBRARY_PATH     "${PKG_CONFIG_SYSROOT_DIR}/usr/lib" CACHE STRING "")
	set (CMAKE_INCLUDE_PATH     "${CMAKE_INCLUDE_PATH} ${PKG_CONFIG_SYSROOT_DIR}/usr/include/" CACHE STRING "")
	set (CMAKE_FIND_ROOT_PATH   "${CMAKE_FIND_ROOT_PATH} ${STAGING_LIBDIR} ${CMAKE_INCLUDE_PATH} " CACHE STRING "")
	set (LIBMETAL_INCLUDE_DIR   " ${PKG_CONFIG_SYSROOT_DIR}/usr/include/" CACHE STRING "")
	set (LIBMETAL_LIB_DIR       " ${PKG_CONFIG_SYSROOT_DIR}/usr/lib" CACHE STRING "")
	set (XIL_INCLUDE_DIR        " ${PKG_CONFIG_SYSROOT_DIR}/usr/include/" CACHE STRING "")
	set (CMAKE_C_FLAGS          " ${CMAKE_C_FLAGS}  ${PKG_CONFIG_SYSROOT_DIR}/usr/include/" CACHE STRING "")
	set (WITH_PROXY             "${OPENAMP_WITH_PROXY}" CACHE STRING "")
	set_property (GLOBAL PROPERTY HAS_SYSTEM_DT ON)
	set_property(GLOBAL PROPERTY SOC "${OPENAMP_CMAKE_SOC}")
	set_property(GLOBAL PROPERTY LINKER_METADATA_FILE ${S}/${LINKER_METADATA_FILE})
	set (DEMO_LINK_FLAGS       "${DEMO_LINK_FLAGS}" CACHE STRING "")
EOF
}

do_generate_toolchain_file[postfuncs] += "openamp_toolchain_file_setup"
LOPPER_GEN_FILE_OUTPUT:linux = "zynqmp"
LOPPER_GEN_FILE_OUTPUT:armv7r = "zynqmp_r5"
LOPPER_GEN_FILE_OUTPUT:armv8r = "zynqmp_r5"

openamp_toolchain_file_setup() {
  cp ${WORKDIR}/amd_platform_info.h ${S}/apps/machine/${LOPPER_GEN_FILE_OUTPUT}
}

OPENAMP_LOPPER_INPUTS:armv7r = ""
OPENAMP_LOPPER_INPUTS:armv8r = ""

OPENAMP_LOPPER_INPUTS:linux:zynqmp = "            \
    -i ${LOPS_DIR}/lop-gen_domain_dts-invoke.dts  \
    -i ${LOPS_DIR}/lop-a53-imux.dts "

OPENAMP_LOPPER_INPUTS:linux:versal = "           \
    -i ${LOPS_DIR}/lop-gen_domain_dts-invoke.dts \
    -i ${LOPS_DIR}/lop-a72-imux.dts "

# FIXME TODO loper is missing a78 linux domain lop file
OPENAMP_LOPPER_INPUTS:linux:versal-net = "       \
    -i ${LOPS_DIR}/lop-gen_domain_dts-invoke.dts \
    -i ${LOPS_DIR}/lop-a78-imux.dts "

# Here set Lopper targets as needed

OPENAMP_LOPPER_HOST ?= ""
OPENAMP_LOPPER_HOST:zynqmp = "a53_0"
OPENAMP_LOPPER_HOST:versal = "a72_0"
OPENAMP_LOPPER_HOST:versal-net = "a78_0"

OPENAMP_LOPPER_OUTPUT[psu_cortexa53_0] = "a53_0"
OPENAMP_LOPPER_OUTPUT[psu_cortexa53_1] = "a53_1"
OPENAMP_LOPPER_OUTPUT[psu_cortexr5_0] = "r5_0"
OPENAMP_LOPPER_OUTPUT[psu_cortexr5_1] = "r5_1"
OPENAMP_LOPPER_OUTPUT[psv_cortexr5_0] = "r5_0"
OPENAMP_LOPPER_OUTPUT[psv_cortexr5_1] = "r5_1"
OPENAMP_LOPPER_OUTPUT[psv_cortexa72_0] = "a72_0"
OPENAMP_LOPPER_OUTPUT[psv_cortexa72_1] = "a72_1"
OPENAMP_LOPPER_OUTPUT[psx_cortexa78_0] = "a78_0"
OPENAMP_LOPPER_OUTPUT[psx_cortexa78_1] = "a78_1"
OPENAMP_LOPPER_OUTPUT[psx_cortexr52_0] = "r52_0"
OPENAMP_LOPPER_OUTPUT[psx_cortexr52_1] = "r52_1"
OPENAMP_LOPPER_OUTPUT[psx_cortexr52_2] = "r52_2"
OPENAMP_LOPPER_OUTPUT[psx_cortexr52_3] = "r52_3"

OPENAMP_LOPPER_TARGET = "${@d.getVarFlag('OPENAMP_LOPPER_OUTPUT', d.getVar('ESW_MACHINE') or '') or ''}"

OPENAMP_LOPPER_REMOTE:armv7r = "${OPENAMP_LOPPER_TARGET}"
OPENAMP_LOPPER_REMOTE:armv8r = "${OPENAMP_LOPPER_TARGET}"
OPENAMP_LOPPER_REMOTE:linux:zynqmp ?= "r5_0"
OPENAMP_LOPPER_REMOTE:linux:versal ?= "r5_0"
OPENAMP_LOPPER_REMOTE:linux:versal-net ?= "r52_0"
OPENAMP_LOPPER_REMOTE ?= ""


OPENAMP_ROLE:armv7r = "remote"
OPENAMP_ROLE:armv8r = "remote"
OPENAMP_ROLE:linux = "host"

LOP_LINUX_HOST:zynqmp = "psu_cortexa53_0"
LOP_LINUX_HOST:versal = "psv_cortexa72_0"
LOP_LINUX_HOST:versal-net = "psx_cortexa78_0"

do_run_set_lopper_targets() {
	# Set OpenAMP Role, Host and Target in lop file
	sed -i -e 's/openamp_role=host/openamp_role=${OPENAMP_ROLE}/g' ${LOPS_DIR}/lop-openamp-invoke.dts
	sed -i -e 's/openamp_host=a53_0/openamp_host=${OPENAMP_LOPPER_HOST}/g' ${LOPS_DIR}/lop-openamp-invoke.dts
	sed -i -e 's/openamp_remote=r5_0/openamp_remote=${OPENAMP_LOPPER_REMOTE}/g' ${LOPS_DIR}/lop-openamp-invoke.dts

	# Set Linux Host
	sed -i -e 's/psv_cortexa72_0/${LOP_LINUX_HOST}/g' ${LOPS_DIR}/lop-gen_domain_dts-invoke.dts
}

LOPPER_OPENAMP_OUT_DTB ?= "${WORKDIR}/openamp-lopper-output.dtb"
do_run_lopper() {
    export LOPPER_DTC_FLAGS="-b 0 -@"
    cd ${WORKDIR}

    lopper -f -v --enhanced  --permissive \
    -i ${OPENAMP_OVERLAY}		  \
    -i ${LOPS_DIR}/lop-load.dts           \
    -i ${LOPS_DIR}/lop-xlate-yaml.dts     \
    -i ${LOPS_DIR}/lop-openamp-invoke.dts \
    ${OPENAMP_LOPPER_INPUTS} ${OPENAMP_DTFILE} \
    ${LOPPER_OPENAMP_OUT_DTB} 2>&1 | tee do_run_lopper.log.txt

    cd -

    if [ ! -f ${WORKDIR}/amd_platform_info.h ]; then
        bberror "Unable to generate file amd_platform_info.h from OpenAMP Lopper run. See Below log:"

	out=$(cat ${WORKDIR}/do_run_lopper.log.txt)
	bberror "$out"
        exit 1
    fi
}

do_gen_linker() {
     cd ${S}/
     lopper -O ${S} ${LOPPER_OPENAMP_OUT_DTB} -- baremetallinker_xlnx ${ESW_MACHINE} ${S} openamp
     mv *Example.cmake ${LINKER_METADATA_FILE}
     cd -
}

do_run_lopper:append:armv7r() {
    do_gen_linker
}
do_run_lopper:append:armv8r() {
    do_gen_linker
}

PACKAGE_ARCH:linux = "${MACHINE_ARCH}"
COMPATIBLE_HOST:linux = ".*"
COMPATIBLE_HOST:arm = "[^-]*-[^-]*-eabi"

do_deploy() {
	# remove existing DTB if applicable
	if test -f ${DEPLOYDIR}${LOPPER_OPENAMP_OUT_DTB}; then
		rm ${DEPLOYDIR}${LOPPER_OPENAMP_OUT_DTB}
	fi
	install -Dm 0644 ${LOPPER_OPENAMP_OUT_DTB} ${DEPLOYDIR}
}

do_compile_rpu() {
       cmake_runcmake_build --target rpmsg-echo.out matrix_multiplyd.out rpc_demo.out
}

do_install_rpu() {
	install -d ${D}/${bindir}
	install -m 0755 ${B}/apps/examples/echo/rpmsg-echo.out ${D}/${bindir}
	install -m 0755 ${B}/apps/examples/matrix_multiply/matrix_multiplyd.out ${D}/${bindir}
	install -m 0755 ${B}/apps/examples/rpc_demo/rpc_demo.out ${D}/${bindir}
}

do_deploy_rpu() {
	install -d ${DEPLOYDIR}/
	install -Dm 0644 ${D}/${bindir}/*.out ${DEPLOYDIR}/
}

do_compile:armv7r() {
	do_compile_rpu
}
do_compile:armv8r() {
	do_compile_rpu
}

do_install:armv7r() {
	do_install_rpu
}
do_install:armv8r() {
	do_install_rpu
}

do_deploy:armv7r() {
	do_deploy_rpu
}
do_deploy:armv8r() {
	do_deploy_rpu
}

addtask do_deploy before do_build after do_install
addtask do_run_set_lopper_targets after do_prepare_recipe_sysroot
addtask do_run_set_lopper_targets after fetch before do_run_lopper
addtask do_run_lopper after do_run_set_lopper_targets do_patch before do_generate_toolchain_file
FILES:${PN}:append:armv7r = " ${libdir}/*.a ${bindir}/*.out  "
FILES:${PN}:append:armv8r = " ${libdir}/*.a ${bindir}/*.out  "

FILES:${PN}:append:linux = " ${DEPLOYDIR}${LOPPER_OPENAMP_OUT_DTB} "
