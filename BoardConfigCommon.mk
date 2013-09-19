#
# Copyright (C) 2013 The CyanogenMod Project
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

-include device/motorola/qcom-common/BoardConfigCommon.mk

LOCAL_PATH := device/motorola/msm8960dt-common

BOARD_VENDOR := motorola-msm8960

# Platform
TARGET_BOARD_PLATFORM_GPU := qcom-adreno320
#TARGET_QCOM_MEDIA_VARIANT := caf

# Inline kernel building
TARGET_KERNEL_SOURCE := kernel/motorola/msm8960dt-common
TARGET_KERNEL_CONFIG := msm8960_mmi_defconfig
TARGET_KERNEL_SELINUX_CONFIG := msm8960_mmi_selinux_defconfig
BOARD_KERNEL_CMDLINE := console=ttyHSL0,115200,n8 androidboot.hardware=qcom user_debug=31 msm_rtb.filter=0x3F ehci-hcd.park=3 maxcpus=2 vmalloc=400M androidboot.write_protect=0
BOARD_KERNEL_BASE := 0x80200000
BOARD_KERNEL_PAGESIZE := 2048
BOARD_MKBOOTIMG_ARGS := --ramdisk_offset 0x01600000

DTB:
	make -C $(TARGET_KERNEL_SOURCE) ARCH=arm CROSS_COMPILE="arm-eabi-" O=$(KERNEL_OUT) dtbs
	cat $(KERNEL_OUT)/arch/arm/boot/*.dtb > $(OUT)/msm8960dt.dtb

TARGET_KERNEL_MODULES += DTB

WLAN_MODULES:
	mkdir $(KERNEL_MODULES_OUT)/prima
	mv $(KERNEL_MODULES_OUT)/wlan.ko $(KERNEL_MODULES_OUT)/prima/prima_wlan.ko
	ln -sf /system/lib/modules/prima/prima_wlan.ko $(TARGET_OUT)/lib/modules/wlan.ko

TARGET_KERNEL_MODULES += WLAN_MODULES

# Special boot.img packaging w/ dtb appended to the end
BOARD_CUSTOM_BOOTIMG_MK := $(LOCAL_PATH)/boot.mk

# assert
TARGET_OTA_ASSERT_DEVICE := xt1030,obakem_verizon,xt1055,xt1056,xt1058,ghost_att,ghost_rcica,xt1060,ghost_verizon,ghost_retail,ghost,xt1080,obake_verizon,xt1080m,obake

# Recovery
TARGET_RECOVERY_FSTAB := $(LOCAL_PATH)/rootdir/etc/fstab.qcom
