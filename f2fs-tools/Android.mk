LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := mkfs/f2fs_format.c lib/libf2fs.c
LOCAL_MODULE := mkfs.f2fs_arm
LOCAL_MODULE_TAGS := optional
LOCAL_REQUIRED_MODULES := $(LOCAL_MODULE)
include $(BUILD_EXECUTABLE)

