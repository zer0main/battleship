#!/bin/bash

set -xue

strip $DEPLOY_FILE
upx -9 $DEPLOY_FILE

set +xue
