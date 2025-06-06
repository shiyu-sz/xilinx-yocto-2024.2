# Automatically generated.  Manual changes will be lost.

ES1_PATH = "${@d.getVarFlag('ES1_PATH', d.getVar('BOARD')) or ''}"
SYS_PATH = "${@d.getVarFlag('SYS_PATH', d.getVar('BOARD')) or ''}"
ELF_PATH = "${@d.getVarFlag('ELF_PATH', d.getVar('BOARD')) or ''}"
JSON_PATH = "${@d.getVarFlag('JSON_PATH', d.getVar('BOARD')) or ''}"
JPG_PATH = "${@d.getVarFlag('JPG_PATH', d.getVar('BOARD')) or ''}"
PNG_PATH = "${@d.getVarFlag('PNG_PATH', d.getVar('BOARD')) or ''}"
JS_PATH = "${@d.getVarFlag('JS_PATH', d.getVar('BOARD')) or ''}"
BOOT_BIN_PATH = "${@d.getVarFlag('BOOT_BIN_PATH', d.getVar('BOARD')) or ''}"
OSPI_PATH = "${@d.getVarFlag('OSPI_PATH', d.getVar('BOARD')) or ''}"

# VCK190
# vck190.jpg
JPG_PATH[vck190] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VCK190/vck190.jpg;name=vck190-jpg'
SRC_URI[vck190-jpg.sha256sum] = '6edd9e644435783d4f7c25ba337eb5ea34ad7aa4c151b920f3ae7290505a33e4'

# VCK190.json
JSON_PATH[vck190] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VCK190/VCK190.json;name=vck190-json'
SRC_URI[vck190-json.sha256sum] = 'e59c525ef4a976045320362da36626aa280a166210e30f11697a9c94d76ecf75'

# VCK190_home.png
PNG_PATH[vck190] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VCK190/VCK190_home.png;name=vck190-png'
SRC_URI[vck190-png.sha256sum] = 'b781ed74f3d2f64e3c8b430271c2e671371a16abf41d3b46ebb54948a530fe0f'

# vck190_strings.js
JS_PATH[vck190] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VCK190/vck190_strings.js;name=vck190-js'
SRC_URI[vck190-js.sha256sum] = '449b9510320cb7a045244662e921a112e643d132a8602f89cbb1e598074bc563'

# vck190_system_wrapper.pdi
SYS_PATH[vck190] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VCK190/vck190_system_wrapper.pdi;name=vck190-system'
SRC_URI[vck190-system.sha256sum] = '9685e5d6df4f31b1efaea0912be0420afe1f409797e5998367bb8dafdbfd7f89'

# vck190_versal_bit.elf
ELF_PATH[vck190] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VCK190/vck190_versal_bit.elf;name=vck190-elf'
SRC_URI[vck190-elf.sha256sum] = '40cc14435f3220117093211a6d5400d9e941a11b3cbdd50a016d8fa6c568db41'

# VEK280
# vek280.jpg
JPG_PATH[vek280] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VEK280/vek280.jpg;name=vek280-jpg'
SRC_URI[vek280-jpg.sha256sum] = '2ec075cf00e15d67dfa106c785f08f47ebea50897629e29d23e27a1ed9ff3848'

# VEK280.json
JSON_PATH[vek280] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VEK280/VEK280.json;name=vek280-json'
SRC_URI[vek280-json.sha256sum] = 'fcd98c1cb4e6ae188a6d754a57206382dee96bd341a4fdd862ed8819533d0e6e'

# vek280_es1_system_wrapper.pdi
ES1_PATH[vek280] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VEK280/vek280_es1_system_wrapper.pdi;name=vek280-es1-system'
SRC_URI[vek280-es1-system.sha256sum] = '1c2390bb0383c5af75a6f0afc6b710f153edbabed4e8aef16832929fbf9cbc22'

# VEK280_home.png
PNG_PATH[vek280] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VEK280/VEK280_home.png;name=vek280-png'
SRC_URI[vek280-png.sha256sum] = '9ce1208334fc5434d9bf0158aa2a525944439a1b69f4ea4796b278d4edcb7018'

# vek280_strings.js
JS_PATH[vek280] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VEK280/vek280_strings.js;name=vek280-js'
SRC_URI[vek280-js.sha256sum] = 'b39e3e1b5d6525dcdd544b72edbf2607d273bc181f364b80e4bad0e77d25bbe1'

# vek280_system_wrapper.pdi
SYS_PATH[vek280] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VEK280/vek280_system_wrapper.pdi;name=vek280-system'
SRC_URI[vek280-system.sha256sum] = 'cffa7c42221ac2618c3cff34e9f965484e6c10ad098fa52561cc2b4536114e4d'

# vek280_versal_bit.elf
ELF_PATH[vek280] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VEK280/vek280_versal_bit.elf;name=vek280-elf'
SRC_URI[vek280-elf.sha256sum] = '39943e7fea112dcb50a5655ff2319e36c549594e1686114bf0a6692fe438d5c4'

# VEK385
# edf-ospi-versal-2ve-2vm-vek385-sdt-seg-20250427145253.bin.gz
OSPI_PATH[vek385] = 'https://petalinux.xilinx.com/sswreleases/rel-v2025/system-controller/sc_app_bsp/2025.1/2025.1_202505222340/external/VEK385/edf-ospi-versal-2ve-2vm-vek385-sdt-seg.bin.gz;name=vek385-ospi;unpack=0'
SRC_URI[vek385-ospi.sha256sum] = '7ebe60b20be2bb7e5ce8a7b85be0428a15740d2c2f964599738fa4136734d55b'

# BOOT_vek385.bin
BOOT_BIN_PATH[vek385] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VEK385/BOOT_vek385.bin;name=vek385-boot-bin'
SRC_URI[vek385-boot-bin.sha256sum] = '1d10d0c602177aed4fc671780668e31e14801d9b32d790377e14f6027f41ad36'

# vek385.jpg
JPG_PATH[vek385] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VEK385/vek385.jpg;name=vek385-jpg'
SRC_URI[vek385-jpg.sha256sum] = 'c6753fc7859c7e783a3b920ec58f1be32b5e73a6554e5d9f8c48ecf7b81d678c'

# VEK385.json
JSON_PATH[vek385] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VEK385/VEK385.json;name=vek385-json'
SRC_URI[vek385-json.sha256sum] = 'e45e7b0b658845a7d239ba6f0c35266ed8544ff927004731f803349fbd946311'

# vek385_es1_system_wrapper.pdi
ES1_PATH[vek385] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VEK385/vek385_es1_system_wrapper.pdi;name=vek385-es1-system'
SRC_URI[vek385-es1-system.sha256sum] = 'f4481da499aeee1393e78ce9dd534d4363967aa5721e997361e4ca3aed9a150d'

# VEK385_home.png
PNG_PATH[vek385] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VEK385/VEK385_home.png;name=vek385-png'
SRC_URI[vek385-png.sha256sum] = 'aff86f39817f877873991a18e7aaf86780314648a3b0c9eb1c6128c0c9df0daf'

# vek385_strings.js
JS_PATH[vek385] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VEK385/vek385_strings.js;name=vek385-js'
SRC_URI[vek385-js.sha256sum] = 'e80924a52c3a5c59a0ec10b62ed95fc4fc1c2d46d1eb6d39068cd774f538eef3'

# vek385_versal_bit.elf
ELF_PATH[vek385] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VEK385/vek385_versal_bit.elf;name=vek385-elf'
SRC_URI[vek385-elf.sha256sum] = 'a23a2625c0bc297691b0b5dd1e92161a8f97ab5595dda73afbb2b71da159288c'

# VHK158
# vhk158.jpg
JPG_PATH[vhk158] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VHK158/vhk158.jpg;name=vhk158-jpg'
SRC_URI[vhk158-jpg.sha256sum] = '824d9ee61a31416b75d915dbb63a27af7b095e66565ca1cf3ea8945d3fbc3e58'

# VHK158.json
JSON_PATH[vhk158] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VHK158/VHK158.json;name=vhk158-json'
SRC_URI[vhk158-json.sha256sum] = '115933acdb0824e6a931d749a275a19cff03eec59f4ed97392cfedeeacd7c256'

# vhk158_es1_system_wrapper.pdi
ES1_PATH[vhk158] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VHK158/vhk158_es1_system_wrapper.pdi;name=vhk158-es1-system'
SRC_URI[vhk158-es1-system.sha256sum] = 'bee9e6be013dd01c336a692133b7aa97c3d3e9e63070fcd37176a29aaac2ab73'

# VHK158_home.png
PNG_PATH[vhk158] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VHK158/VHK158_home.png;name=vhk158-png'
SRC_URI[vhk158-png.sha256sum] = 'a7ac77696a8c659741c9c078709a94de2b2f5bfc58812d17c852187de91d0713'

# vhk158_strings.js
JS_PATH[vhk158] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VHK158/vhk158_strings.js;name=vhk158-js'
SRC_URI[vhk158-js.sha256sum] = '5cfa5b1e2bf8cee112566a74c22cc833577f5ce9c1f1d6877a0a1df126fec2df'

# vhk158_system_wrapper.pdi
SYS_PATH[vhk158] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VHK158/vhk158_system_wrapper.pdi;name=vhk158-system'
SRC_URI[vhk158-system.sha256sum] = 'f0180ba75570c9d41289200cec3bc270a52d3220a217246c0258b37f65df3e36'

# vhk158_versal_bit.elf
ELF_PATH[vhk158] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VHK158/vhk158_versal_bit.elf;name=vhk158-elf'
SRC_URI[vhk158-elf.sha256sum] = 'cf7a2313e8e276ecdebb99d36bfccae1835799807c1332a62cc66c66f26a6431'

# VMK180
# vmk180.jpg
JPG_PATH[vmk180] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VMK180/vmk180.jpg;name=vmk180-jpg'
SRC_URI[vmk180-jpg.sha256sum] = '1da64085afe80d403f7586c54cea343fc2b5f3a64ed082e090588494877b8568'

# VMK180.json
JSON_PATH[vmk180] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VMK180/VMK180.json;name=vmk180-json'
SRC_URI[vmk180-json.sha256sum] = '2b897dc5a62c7c0fd2d119b292864d973a3696bcc75116e2c3bd097ab99e1c8b'

# VMK180_home.png
PNG_PATH[vmk180] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VMK180/VMK180_home.png;name=vmk180-png'
SRC_URI[vmk180-png.sha256sum] = 'b781ed74f3d2f64e3c8b430271c2e671371a16abf41d3b46ebb54948a530fe0f'

# vmk180_strings.js
JS_PATH[vmk180] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VMK180/vmk180_strings.js;name=vmk180-js'
SRC_URI[vmk180-js.sha256sum] = 'c70869322503a05993734ac4a65a6562d0f3bf3590eb875c48e8ff447fa0e906'

# vmk180_system_wrapper.pdi
SYS_PATH[vmk180] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VMK180/vmk180_system_wrapper.pdi;name=vmk180-system'
SRC_URI[vmk180-system.sha256sum] = '18ea2497911ffec3b9a269879233829421a8d566d9a67c94f5f05032d28a2160'

# vmk180_versal_bit.elf
ELF_PATH[vmk180] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VMK180/vmk180_versal_bit.elf;name=vmk180-elf'
SRC_URI[vmk180-elf.sha256sum] = 'b28ecb6c0c4e428504c413d592d5cba00ba1aebfc2a9f4fb6b1af48e8b0a7d70'

# VPK120
# vpk120.jpg
JPG_PATH[vpk120] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VPK120/vpk120.jpg;name=vpk120-jpg'
SRC_URI[vpk120-jpg.sha256sum] = '6c2fcfe2352bf3b7cb90de92bf6bbbcd95f06f158536307687a9e6d9813b321f'

# VPK120.json
JSON_PATH[vpk120] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VPK120/VPK120.json;name=vpk120-json'
SRC_URI[vpk120-json.sha256sum] = 'b1df74ab41db0a66fa330297f84ce6037598eba9de21060e9848b180c9923b79'

# vpk120_es1_system_wrapper.pdi
ES1_PATH[vpk120] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VPK120/vpk120_es1_system_wrapper.pdi;name=vpk120-es1-system'
SRC_URI[vpk120-es1-system.sha256sum] = '6972f7ad498df1512279879c2922c1612b75eea67b9ebf72165d3bb07bd1709e'

# VPK120_home.png
PNG_PATH[vpk120] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VPK120/VPK120_home.png;name=vpk120-png'
SRC_URI[vpk120-png.sha256sum] = '4764b6ad94b50de631808309c50935719d220300dbdbdeeb1a50d52d33687c93'

# vpk120_strings.js
JS_PATH[vpk120] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VPK120/vpk120_strings.js;name=vpk120-js'
SRC_URI[vpk120-js.sha256sum] = '694a7b77091e4351247a9a6c35d5589bf13b4a6c22dd477d626536d472cf5274'

# vpk120_system_wrapper.pdi
SYS_PATH[vpk120] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VPK120/vpk120_system_wrapper.pdi;name=vpk120-system'
SRC_URI[vpk120-system.sha256sum] = 'd2d8696a6f9099bf3016c8604cb22c9d7ca0cbf9388e54a7c7a13521f87d873b'

# vpk120_versal_bit.elf
ELF_PATH[vpk120] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VPK120/vpk120_versal_bit.elf;name=vpk120-elf'
SRC_URI[vpk120-elf.sha256sum] = '130bf88d1701003415e8bd0cc65eb3ece0b80e950c7cbc0f457b5af318d95f12'

# VPK180
# vpk180.jpg
JPG_PATH[vpk180] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VPK180/vpk180.jpg;name=vpk180-jpg'
SRC_URI[vpk180-jpg.sha256sum] = '58c8c3742750f40c44e7013632c617ab8a5552e9b7d11ed521ad6dd9b947a224'

# VPK180.json
JSON_PATH[vpk180] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VPK180/VPK180.json;name=vpk180-json'
SRC_URI[vpk180-json.sha256sum] = '0b34e326a9ed07fc636d624c69360eb7c2196f0b6cd85e112fb6212332441e3c'

# vpk180_es1_system_wrapper.pdi
ES1_PATH[vpk180] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VPK180/vpk180_es1_system_wrapper.pdi;name=vpk180-es1-system'
SRC_URI[vpk180-es1-system.sha256sum] = '4604bf8fb2e054f485f19225f5afc4919f73ae8f81d36ca4908fe95f2e7e7560'

# VPK180_home.png
PNG_PATH[vpk180] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VPK180/VPK180_home.png;name=vpk180-png'
SRC_URI[vpk180-png.sha256sum] = '9c94169377c50ebb5c68948e576ccb5e5e56cc24e3512c5d0053de2144a1cd5c'

# vpk180_strings.js
JS_PATH[vpk180] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VPK180/vpk180_strings.js;name=vpk180-js'
SRC_URI[vpk180-js.sha256sum] = '94dff92e09c14f6e6d98492d7f66a401a90796a139da3207a53adbe916534642'

# vpk180_system_wrapper.pdi
SYS_PATH[vpk180] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VPK180/vpk180_system_wrapper.pdi;name=vpk180-system'
SRC_URI[vpk180-system.sha256sum] = '2e49b04cf909bc9be7427bc2a1574e312421a5dd8b9034030780582dfd87d916'

# vpk180_versal_bit.elf
ELF_PATH[vpk180] = 'https://petalinux.xilinx.com/sswreleases/rel-v2024/system-controller/sc_app_bsp/2024.2/2024.2_202505021433/external/VPK180/vpk180_versal_bit.elf;name=vpk180-elf'
SRC_URI[vpk180-elf.sha256sum] = '40f403d1024055b860660ed9054e5d001a2989cb12c1f1f35dc15825c10d2587'

