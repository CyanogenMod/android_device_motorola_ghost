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
# This file sets variables that control the way modules are built
# thorughout the system. It should not be used to conditionally
# disable makefiles (the proper mechanism to control what gets
# included in a build is to use PRODUCT_PACKAGES in a product
# definition file).
#

# inherit from the proprietary version
-include vendor/motorola/moto_msm8960dt/BoardConfigVendor.mk

BOARD_VENDOR := motorola-qcom

# Platform
TARGET_BOARD_PLATFORM_GPU := qcom-adreno320
TARGET_BOARD_PLATFORM := msm8960
TARGET_BOOTLOADER_BOARD_NAME := MSM8960
TARGET_CPU_VARIANT := krait

-include device/motorola/qcom-common/BoardConfigCommon.mk

LOCAL_PATH := device/motorola/moto_msm8960dt

# Vendor Init
TARGET_UNIFIED_DEVICE := true
TARGET_INIT_VENDOR_LIB := libinit_msm
TARGET_LIBINIT_DEFINES_FILE := device/motorola/moto_msm8960dt/init/init_moto_msm8960dt.c

TARGET_SPECIFIC_HEADER_PATH += $(LOCAL_PATH)/include

TARGET_QCOM_MEDIA_VARIANT := caf
TARGET_USES_WCNSS_CTRL := true

# Inline kernel building
TARGET_KERNEL_SOURCE := kernel/motorola/msm8960dt-common
TARGET_KERNEL_CONFIG := msm8960dt_mmi_defconfig
TARGET_KERNEL_SELINUX_CONFIG := msm8960_mmi_selinux_defconfig
BOARD_KERNEL_CMDLINE := console=ttyHSL0,115200,n8 androidboot.hardware=qcom user_debug=31 msm_rtb.filter=0x3F ehci-hcd.park=3 maxcpus=2 vmalloc=400M androidboot.write_protect=0 zcache
BOARD_KERNEL_BASE := 0x80200000
BOARD_KERNEL_PAGESIZE := 2048
BOARD_MKBOOTIMG_ARGS := --ramdisk_offset 0x02200000 --dt $(LOCAL_PATH)/dt.img
BOARD_USERDATAIMAGE_PARTITION_SIZE := 12884901888

WLAN_MODULES:
	mkdir -p $(KERNEL_MODULES_OUT)/prima
	mv $(KERNEL_MODULES_OUT)/wlan.ko $(KERNEL_MODULES_OUT)/prima/prima_wlan.ko
	ln -sf /system/lib/modules/prima/prima_wlan.ko $(TARGET_OUT)/lib/modules/wlan.ko

TARGET_KERNEL_MODULES += WLAN_MODULES

# QCOM BSP
TARGET_USES_QCOM_BSP := true
COMMON_GLOBAL_CFLAGS += -DQCOM_BSP

# Audio
BOARD_USES_LEGACY_ALSA_AUDIO := true

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(LOCAL_PATH)/bluetooth

# GPS
BOARD_HAVE_NEW_QC_GPS := true

# Graphics
TARGET_QCOM_DISPLAY_VARIANT := caf
BOARD_EGL_CFG := $(LOCAL_PATH)/config/egl.cfg

# Custom relese tools for unified devices
TARGET_RELEASETOOLS_EXTENSIONS := device/motorola/moto_msm8960dt

# Assert
TARGET_OTA_ASSERT_DEVICE := xt1030,obakem_verizon,xt1053,ghost_retail,xt1055,ghost_usc,xt1056,ghost_sprint,xt1058,ghost_att,ghost_rcica,ghost,xt1060,ghost_verizon,xt1080,obake_verizon,xt1080m,obake

# Recovery
TARGET_RECOVERY_PIXEL_FORMAT := "RGBA_8888"
TARGET_RECOVERY_FSTAB := $(LOCAL_PATH)/rootdir/etc/fstab.qcom
TARGET_USERIMAGES_USE_EXT4 := true
TARGET_USERIMAGES_USE_F2FS := true
BOARD_RECOVERY_SWIPE := true

# TWRP
DEVICE_RESOLUTION := 720x1280
TW_BRIGHTNESS_PATH := /sys/class/backlight/lcd-backlight/brightness
TW_MAX_BRIGHTNESS := 126
