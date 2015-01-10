#
# Copyright (C) 2014 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

$(call inherit-product, device/motorola/msm8960dt-common/msm8960dt-common.mk)

$(call inherit-product, vendor/motorola/ghost/ghost-vendor.mk)

LOCAL_PATH := device/motorola/ghost

# Overlay
DEVICE_PACKAGE_OVERLAYS += $(LOCAL_PATH)/overlay

# Keylayout
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/keylayout/msp430sensorprocessor.kl:system/usr/keylayout/msp430sensorprocessor.kl

# Boot animation
TARGET_SCREEN_HEIGHT := 1280
TARGET_SCREEN_WIDTH := 720

# Lights
PRODUCT_PACKAGES += \
    lights.msm8960
