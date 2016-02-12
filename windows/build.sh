#!/bin/bash

set -xue

MXE_DIR=/usr/lib/mxe

if [ "$FILENAME_SUFFIX" = "windows32" ]; then
    MXE_TARGET=i686-w64-mingw32.static
fi

if [ "$FILENAME_SUFFIX" = "windows64" ]; then
    MXE_TARGET=x86-64-w64-mingw32.static
fi

$MXE_DIR/usr/bin/MXE_TARGET-cmake . -Bbuild-dir
cmake --build build-dir --config Release
source build-dir/rename_exe.sh

set +xue
