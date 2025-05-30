inherit cmake ccmake

S:xilinx-standalone = "${WORKDIR}/git"
B:xilinx-standalone = "${WORKDIR}/build"

OECMAKE_SOURCEPATH:xilinx-standalone = "${S}/"
PROVIDES:xilinx-standalone = "libmetal"

S:xilinx-freertos = "${WORKDIR}/git"
B:xilinx-freertos = "${WORKDIR}/build"

OECMAKE_SOURCEPATH:xilinx-freertos = "${S}/"
PROVIDES:xilinx-freertos = "libmetal"

DEPENDS:armv7r:append = " doxygen-native xilstandalone scugic xiltimer libxil nativesdk-xilinx-lops "
DEPENDS:append:xilinx-freertos = " freertos10-xilinx "

DEPENDS:remove:microblaze = " scugic xiltimer "
DEPENDS:remove:armv7r = " sysfsutils eudev "

COMPATIBLE_HOST:forcevariable = ".*"

LIBMETAL_CROSS_PREFIX:xilinx-standalone = "${TARGET_PREFIX}"
LIBMETAL_CROSS_PREFIX:xilinx-freertos = "${TARGET_PREFIX}"

LIBMETAL_MACHINE:armv7r = "zynqmp_r5"
LIBMETAL_MACHINE:xilinx-standalone:cortexa53 = "zynqmp_a53"
LIBMETAL_MACHINE:xilinx-standalone:cortexa72 = "zynqmp_a72"
LIBMETAL_MACHINE:xilinx-standalone:cortexa78 = "zynqmp_a78"
LIBMETAL_MACHINE:microblaze = "microblaze_generic"

LIBMETAL_GCC_INCLUDE:xilinx-standalone = "generic"
LIBMETAL_GCC_INCLUDE:xilinx-freertos = "freertos"

LIBMETAL_SYSTEM_NAME:xilinx-standalone = "Generic"
LIBMETAL_SYSTEM_NAME:xilinx-freertos = "FreeRTOS"

LIBMETAL_CMAKE_SYSTEM_PROCESSOR:xilinx-standalone = "${TRANSLATED_TARGET_ARCH}"
LIBMETAL_CMAKE_SYSTEM_PROCESSOR:xilinx-freertos = "${TRANSLATED_TARGET_ARCH}"

LIBMETAL_CMAKE_SYSTEM_PROCESSOR:xilinx-standalone:microblaze = "microblaze"

LIBMETAL_DEMO ?= "OFF"

EXTRA_OECMAKE:armv7r = "\
    -DWITH_EXAMPLES=${LIBMETAL_DEMO} \
    "

CFLAGS:append = " -DSDT -DXLNX_PLATFORM "

FILES:${PN}:xilinx-standalone:append = " ${libdir}/*.a ${bindir}/*elf "

cmake_do_generate_toolchain_file:append:armv7r() {
    cat >> ${WORKDIR}/toolchain.cmake <<EOF
    set (CMAKE_SYSTEM_PROCESSOR "${LIBMETAL_CMAKE_SYSTEM_PROCESSOR}" )
    set (CROSS_PREFIX           "${LIBMETAL_CROSS_PREFIX}" CACHE STRING "")
    set (MACHINE "${LIBMETAL_MACHINE}" )
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ")
    set (CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> qcs <TARGET> <LINK_FLAGS> <OBJECTS>")
    set (CMAKE_SYSTEM_NAME "${LIBMETAL_SYSTEM_NAME}")
    set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER CACHE STRING "")
    set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY NEVER CACHE STRING "")
    set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE NEVER CACHE STRING "")
    include (CMakeForceCompiler)
    CMAKE_FORCE_C_COMPILER("${OECMAKE_C_COMPILER}" GNU)
    set (CMAKE_LIBRARY_PATH "${PKG_CONFIG_SYSROOT_DIR}/usr/lib" CACHE STRING "")
    set (CMAKE_C_ARCHIVE_FINISH   true)
    set (CMAKE_INCLUDE_PATH "${PKG_CONFIG_SYSROOT_DIR}/usr/include/" CACHE STRING "")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${PKG_CONFIG_SYSROOT_DIR}/usr/include/   " CACHE STRING "")
    include (cross-${LIBMETAL_GCC_INCLUDE}-gcc)
    set (WITH_DOC OFF)
    set_property (GLOBAL PROPERTY HAS_SYSTEM_DT ON)
EOF
}
