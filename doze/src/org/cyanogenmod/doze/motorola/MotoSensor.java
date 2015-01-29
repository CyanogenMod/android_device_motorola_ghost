/*
 * Copyright (c) 2015 The CyanogenMod Project
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

package org.cyanogenmod.doze.motorola;

import android.content.ActivityNotFoundException;
import android.content.Context;
import android.content.Intent;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.PowerManager;
import android.os.PowerManager.WakeLock;
import android.os.UserHandle;
import android.os.SystemClock;
import android.provider.MediaStore;

public abstract class MotoSensor {

    private static final String TAG = "MotoSensor";

    private static final String DOZE_INTENT = "com.android.systemui.doze.pulse";

    private static final int SENSOR_WAKELOCK_DURATION = 200;

    protected static final int SENSOR_TYPE_MMI_FLAT_UP = 34;
    protected static final int SENSOR_TYPE_MMI_FLAT_DOWN = 35;
    protected static final int SENSOR_TYPE_MMI_STOW = 36;
    protected static final int SENSOR_TYPE_MMI_CAMERA_ACTIVATION = 37;

    protected static final int BATCH_LATENCY_IN_MS = 100;

    protected Context mContext;
    protected PowerManager mPowerManager;
    protected SensorManager mSensorManager;
    protected Sensor mSensor;
    protected int mType;

    private WakeLock mSensorWakeLock;

    static {
        System.load("/system/lib/libjni_motoSensor.so");
    }

    protected static native void native_enableWakeSensor(int wakeSensor);
    protected static native void native_disableWakeSensor(int wakeSensor);

    public MotoSensor(Context context, int type) {
        mContext = context;
        mType = type;
        mPowerManager = (PowerManager) mContext.getSystemService(Context.POWER_SERVICE);
        mSensorManager = (SensorManager) mContext.getSystemService(Context.SENSOR_SERVICE);
        mSensor = mSensorManager.getDefaultSensor(mType);
        mSensorWakeLock = mPowerManager.newWakeLock(PowerManager.PARTIAL_WAKE_LOCK, "MotoSensorWakeLock");
    }

    public void enable() {
        mSensorManager.registerListener(mSensorEventListener, mSensor,
                SensorManager.SENSOR_DELAY_NORMAL, BATCH_LATENCY_IN_MS * 1000);
        native_enableWakeSensor(mType);
    }

    public void disable() {
        mSensorManager.unregisterListener(mSensorEventListener);
        native_disableWakeSensor(mType);
    }

    protected void launchDozePulse() {
        mContext.sendBroadcast(new Intent(DOZE_INTENT));
    }

    protected void launchCamera() {
        mSensorWakeLock.acquire(SENSOR_WAKELOCK_DURATION);
        mPowerManager.wakeUp(SystemClock.uptimeMillis());
        Intent intent = new Intent(MediaStore.INTENT_ACTION_STILL_IMAGE_CAMERA_SECURE);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK |
                Intent.FLAG_ACTIVITY_SINGLE_TOP | Intent.FLAG_ACTIVITY_CLEAR_TOP);
        try {
            mContext.startActivityAsUser(intent, null, new UserHandle(UserHandle.USER_CURRENT));
        } catch (ActivityNotFoundException e) {
            /* Ignore */
        }
    }

    protected abstract void onSensorEvent(SensorEvent event);

    private SensorEventListener mSensorEventListener = new SensorEventListener() {
        @Override
        public void onSensorChanged(SensorEvent event) {
            onSensorEvent(event);
        }

        @Override
        public void onAccuracyChanged(Sensor sensor, int accuracy) {
            /* Empty */
        }
    };
}
