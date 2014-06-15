#!/bin/bash

export VENDOR=motorola
export DEVICE=moto_msm8960dt
# Comment these out if there is no common device tree for this device
export COMMON_DEVICE=qcom-common
export BOARD_VENDOR=motorola-qcom
export TARGET_BOARD_PLATFORM=msm8960

../$COMMON_DEVICE/extract-files.sh $@
