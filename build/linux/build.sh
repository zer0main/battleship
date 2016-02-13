#!/bin/bash

set -xue

cmake . -Bbuild-dir
cmake --build build-dir --config Release
source build-dir/rename_exe.sh

set +xue
