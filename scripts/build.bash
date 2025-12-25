#!/bin/bash
set -eou pipefail

BUILD_DIR="$(dirname $BASH_SOURCE)/../build"

cmake -B $BUILD_DIR
cmake --build $BUILD_DIR
