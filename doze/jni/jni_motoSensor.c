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

#define LOG_TAG "jni_motoSensor"

#include <errno.h>
#include <fcntl.h>
#include <jni.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <cutils/log.h>
#include <linux/msp430.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define UNUSED __attribute__((unused))

#define SENSOR_TYPE_MMI_FLAT_UP 34
#define SENSOR_TYPE_MMI_FLAT_DOWN 35
#define SENSOR_TYPE_MMI_STOW 36
#define SENSOR_TYPE_MMI_CAMERA_ACTIVATION 37

#define MSP_DEVICE "/dev/msp430"

static pthread_mutex_t ioctl_mutex = PTHREAD_MUTEX_INITIALIZER;

static uint16_t get_wake_sensors()
{
    int ret = 0;
    int fd;
    uint16_t wake_sensors;
    uint8_t buf[2];

    fd = open(MSP_DEVICE, O_RDWR);
    if (fd < 0) {
        ret = -errno;
        ALOGE("%s: Failed to open %s: %d\n", __func__, MSP_DEVICE, ret);
        return 0;
    }

    ret = ioctl(fd, MSP430_IOCTL_GET_WAKESENSORS, buf);
    if (ret < 0) {
        ret = -errno;
        ALOGE("%s: Failed to IOCTL_GET_WAKESENSORS: %d\n", __func__, ret);
        close(fd);
        return 0;
    }

    close(fd);

    wake_sensors = ((buf[1] << 8) | buf[0]);

    return wake_sensors;
}

static int set_wake_sensors(uint16_t wake_sensors)
{
    int ret = 0;
    int fd;
    uint8_t buf[2];

    fd = open(MSP_DEVICE, O_RDWR);
    if (fd < 0) {
        ret = -errno;
        ALOGE("%s: Failed to open %s: %d\n", __func__, MSP_DEVICE, ret);
        goto err_ret;
    }

    buf[0] = (wake_sensors & 0x00ff) >> 0;
    buf[1] = (wake_sensors & 0xff00) >> 8;

    ret = ioctl(fd, MSP430_IOCTL_SET_WAKESENSORS, buf);
    if (ret < 0) {
        ret = -errno;
        ALOGE("%s: Failed to IOCTL_SET_WAKESENSORS: %d\n", __func__, ret);
    }

    close(fd);
err_ret:
    return ret;
}

JNIEXPORT void JNICALL Java_org_cyanogenmod_doze_motorola_MotoSensor_native_1enableWakeSensor(
        UNUSED JNIEnv *env, UNUSED jclass thiz, jint wakeSensor)
{
    uint16_t wake_sensors = 0;

    pthread_mutex_lock(&ioctl_mutex);

    wake_sensors = get_wake_sensors();

    switch (wakeSensor) {
        case SENSOR_TYPE_MMI_FLAT_UP:
            wake_sensors |= M_FLATUP;
            break;
        case SENSOR_TYPE_MMI_FLAT_DOWN:
            wake_sensors |= M_FLATDOWN;
            break;
        case SENSOR_TYPE_MMI_STOW:
            wake_sensors |= M_STOWED;
            break;
        case SENSOR_TYPE_MMI_CAMERA_ACTIVATION:
            wake_sensors |= M_CAMERA_ACT;
            break;
    }

    set_wake_sensors(wake_sensors);

    pthread_mutex_unlock(&ioctl_mutex);
}

JNIEXPORT void JNICALL Java_org_cyanogenmod_doze_motorola_MotoSensor_native_1disableWakeSensor(
        UNUSED JNIEnv *env, UNUSED jclass thiz, jint wakeSensor)
{
    uint16_t wake_sensors = 0;

    pthread_mutex_lock(&ioctl_mutex);

    wake_sensors = get_wake_sensors();

    switch (wakeSensor) {
        case SENSOR_TYPE_MMI_FLAT_UP:
            wake_sensors &= (~M_FLATUP);
            break;
        case SENSOR_TYPE_MMI_FLAT_DOWN:
            wake_sensors &= (~M_FLATDOWN);
            break;
        case SENSOR_TYPE_MMI_STOW:
            wake_sensors &= (~M_STOWED);
            break;
        case SENSOR_TYPE_MMI_CAMERA_ACTIVATION:
            wake_sensors &= (~M_CAMERA_ACT);
            break;
    }

    set_wake_sensors(wake_sensors);

    pthread_mutex_unlock(&ioctl_mutex);
}
