#!/bin/sh

set -e

export VENDOR=motorola
export DEVICE=ghost
./../../$VENDOR/msm8960dt-common/extract-files.sh $@
