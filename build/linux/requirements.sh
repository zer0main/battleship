#!/bin/bash

set -xue

sudo rm -rf /var/lib/apt/lists

sudo apt-get update

sudo apt-get --force-yes upgrade -y

sudo apt-get --yes install \
    g++ make cmake \
    libqt4-dev upx-ucl \

set +xue
