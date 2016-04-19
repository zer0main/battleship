#!/bin/bash

set -xue

cmake . -Bbuild-dir
cmake --build build-dir --config Release

set +xue
