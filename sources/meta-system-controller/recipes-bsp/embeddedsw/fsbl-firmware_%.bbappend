do_compile:append:eval-brd-sc-zynqmp() {
    printf "* ${PN}\nSRCREV: ${SRCREV}\nBRANCH: ${BRANCH}\n\n" > ${S}/${PN}.manifest
}

do_deploy:append:eval-brd-sc-zynqmp() {
    install -m 0644 ${S}/${PN}.manifest ${DEPLOYDIR}/${FSBL_BASE_NAME}.manifest
    ln -sf ${FSBL_BASE_NAME}.manifest ${DEPLOYDIR}/${FSBL_IMAGE_NAME}.manifest
}
