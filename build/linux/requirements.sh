#!/bin/bash

set -xue

sudo apt-get update

sudo apt-get --yes install \
    g++ make cmake \
    qtbase5-dev qttools5-dev qttools5-dev-tools \
    upx-ucl

set +xue
