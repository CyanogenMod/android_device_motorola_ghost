LOCAL_PATH := device/motorola/msm8960dt-common
PRODUCT_COPY_FILES += \
	$(LOCAL_PATH)/keylayout/msp430sensorprocessor.kl:system/usr/keylayout/msp430sensorprocessor.kl \
	$(LOCAL_PATH)/keylayout/synaptics_dsx_i2c.kl:system/usr/keylayout/synaptics_dsx_i2c.kl \
	$(LOCAL_PATH)/keylayout/synaptics_rmi4_i2c.kl:system/usr/keylayout/synaptics_rmi4_i2c.kl
