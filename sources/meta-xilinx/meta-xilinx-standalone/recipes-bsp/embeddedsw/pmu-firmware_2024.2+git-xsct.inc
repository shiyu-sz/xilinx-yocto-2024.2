FILESPATH .= ":${FILE_DIRNAME}/embeddedsw/${PV}:${FILE_DIRNAME}/embeddedsw"

SRC_URI += " \
            file://0001-sw_apps-zynqmp_pmufw-Correct-IOU-register-base-addre.patch \
           "
