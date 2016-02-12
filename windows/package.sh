#!/bin/bash

set -xue

strip $DEPLOY_FILE
upx -9 $DEPLOY_FILE
if [ -f "build-dir/wizard.nsi" ]; then
    build-dir/nsis_wizard.sh
fi

set +xue
