/*
 * Copyright (C) 2015 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//#define LOG_NDEBUG 0

#define LOG_TAG "ActivityRecognition"
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include <cutils/log.h>
#include <hardware/activity_recognition.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MSP_AS_DEVICE "/dev/msp430_as"

static const char *g_ar_activity_list[] = {
    ACTIVITY_TYPE_STILL,
    ACTIVITY_TYPE_TILTING,
};

static const activity_recognition_callback_procs_t *ar_callback;

static void
ar_register_activity_callback(const struct activity_recognition_device *dev,
        const activity_recognition_callback_procs_t *callback)
{
    ALOGD(LOG_TAG, "%s: Registering callbacks\n", __func__);
    ar_callback = callback;
}

static int
ar_enable_activity_event(const struct activity_recognition_device *dev,
        uint32_t activity_handle, uint32_t event_type,
        int64_t max_batch_report_latency_ns)
{
    int ret = 0;

    return ret;
}

static int
ar_disable_activity_event(const struct activity_recognition_device *dev,
        uint32_t activity_handle, uint32_t event_type)
{
    int ret = 0;

    return ret;
}

static int
ar_flush(const struct activity_recognition_device *dev)
{
    int ret = 0;

    return ret;
}

static int
ar_close(struct hw_device_t *dev)
{
    if (dev) {
        free(dev);
    }

    return 0;
}

static int
ar_open(const hw_module_t *module, const char *name,
        hw_device_t **device)
{
    int ret = 0;

    if (strcmp(name, ACTIVITY_RECOGNITION_HARDWARE_INTERFACE) != 0) {
        ret = -EINVAL;
        goto err_open;
    }

    activity_recognition_device_t *dev = malloc(
            sizeof(activity_recognition_device_t));
    if (dev == NULL) {
        ret = errno;
        goto err_open;
    }

    memset(dev, 0, sizeof(activity_recognition_device_t));

    dev->common.tag = HARDWARE_DEVICE_TAG;
    dev->common.version = ACTIVITY_RECOGNITION_API_VERSION_0_1;
    dev->common.module = (struct hw_module_t *) module;
    dev->common.close = ar_close;

    dev->register_activity_callback = ar_register_activity_callback;
    dev->enable_activity_event = ar_enable_activity_event;
    dev->disable_activity_event = ar_disable_activity_event;
    dev->flush = ar_flush;

    *device = (struct hw_device_t *) dev;

err_open:
    return ret;
}

static int
ar_get_supported_activities_list(activity_recognition_module_t *module,
        char const* const* *activity_list)
{
    if (module == NULL) {
        activity_list = NULL;
        return 0;
    }

    *activity_list = g_ar_activity_list;
    return 2;
}

static struct hw_module_methods_t ar_module_methods = {
    .open = ar_open,
};

activity_recognition_module_t HAL_MODULE_INFO_SYM = {
    .common = {
        .tag = HARDWARE_MODULE_TAG,
        .hal_api_version = HARDWARE_HAL_API_VERSION,
        .id = ACTIVITY_RECOGNITION_HARDWARE_MODULE_ID,
        .name = "MOTO X Activity Recognition HAL",
        .author = "The CyanogenMod Project",
        .methods = &ar_module_methods,
        .dso = NULL,
        .reserved = {0},
    },
    .get_supported_activities_list = ar_get_supported_activities_list,
};
