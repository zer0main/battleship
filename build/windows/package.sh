#!/bin/bash

set -xue

strip $DEPLOY_FILE
upx -9 $DEPLOY_FILE

cp ${PROJECT_SOURCE_DIR}/src/view/images/battleship.ico build-dir

awk 'sub("$", "\r")' ${PROJECT_SOURCE_DIR}/README.md > \
    build-dir/README.txt
awk 'sub("$", "\r")' ${PROJECT_SOURCE_DIR}/LICENSE > \
    build-dir/LICENSE.txt

awk 'sub("$", "\r")' ${PROJECT_SOURCE_DIR}/AUTHORS > \
    build-dir/AUTHORS.txt

if [ -f "build-dir/wizard.nsi" ]; then
    build-dir/nsis_wizard.sh
fi

set +xue
