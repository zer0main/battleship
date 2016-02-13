#!/bin/bash

set -xue

cp @PROJECT_SOURCE_DIR@/src/view/images/battleship.ico build-dir

cp @PROJECT_SOURCE_DIR@/README.md > \
    build-dir/README.txt
cp @PROJECT_SOURCE_DIR@/LICENSE > \
    build-dir/LICENSE.txt

cp @PROJECT_SOURCE_DIR@/AUTHORS > \
    build-dir/AUTHORS.txt

strip $DEPLOY_FILE
upx -9 $DEPLOY_FILE

set +xue
