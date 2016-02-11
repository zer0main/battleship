#!/bin/bash

set -xue

cmake . -Bbuild-dir
cmake --build build-dir --config Release
build-dir/rename_exe.sh

set +xue
