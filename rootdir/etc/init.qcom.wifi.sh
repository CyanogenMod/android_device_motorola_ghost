#!/system/bin/sh
# Copyright (c) 2010-2013, The Linux Foundation. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above
#       copyright notice, this list of conditions and the following
#       disclaimer in the documentation and/or other materials provided
#       with the distribution.
#     * Neither the name of The Linux Foundation nor the names of its
#       contributors may be used to endorse or promote products derived
#       from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
# ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
# BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
# OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
# IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# This script will load and unload the wifi driver to put the wifi in
# in deep sleep mode so that there won't be voltage leakage.
# Loading/Unloading the driver only incase if the Wifi GUI is not going
# to Turn ON the Wifi. In the Script if the wlan driver status is
# ok(GUI loaded the driver) or loading(GUI is loading the driver) then
# the script won't do anything. Otherwise (GUI is not going to Turn On
# the Wifi) the script will load/unload the driver
# This script will get called after post bootup.

###### MOT added change - allow HW radio specific CAL select
phone_hw_type=`getprop ro.hw.radio`
### Phone MA map
# 1 = Americas (ATT + LATAM)
# 2 = VZW
# 3 = Europe and Korea (ROW)
# 4 = Sprint
# 5 = USC
# 6 = TMO

##### Setup HW Radio specific softlinks
validFileRetVal=-1
isValidFile(){
    inFile=$1
    if [ -f $inFile ]; then
        if [ -s $inFile ]; then
            validFileRetVal=1
        else
            validFileRetVal=0
        fi
    else
        validFileRetVal=0
    fi
}

if [ "$phone_hw_type" \> "0x6" ]
then
    echo "UNKNOWN HW Type  !! - Setting up WiFi Calibration to default version - getprop reported $phone_hw_type"
else
    hw_radio_cal_file="/system/etc/firmware/wlan/prima/cal_files/WCNSS_qcom_wlan_nv_calibration_$phone_hw_type.bin"
    default_cal_file="/system/etc/firmware/wlan/prima/cal_files/WCNSS_qcom_wlan_nv_calibration.bin"
    persist_cal_file="/persist/WCNSS_qcom_wlan_nv_calibration_persist.bin"
    hw_radio_reg_file="/system/etc/firmware/wlan/prima/cal_files/WCNSS_qcom_wlan_nv_regulatory_$phone_hw_type.bin"
    default_reg_file="/system/etc/firmware/wlan/prima/cal_files/WCNSS_qcom_wlan_nv_regulatory.bin"
    persist_reg_file="/persist/WCNSS_qcom_wlan_nv_regulatory_persist.bin"
    
    echo "Well known HW type!! - Setting up WiFi Calibration for getprop reported HW type $phone_hw_type"
    
    ### Setup CAL file softlinks
    isValidFile $hw_radio_cal_file
    if [ "$validFileRetVal" == 1 ]; then
        echo "Found valid HW RADIO specific CAL file $hw_radio_cal_file - update soft links "
        #cleanup link first
        rm $persist_cal_file
        ln -s $hw_radio_cal_file $persist_cal_file
    else
        echo "HW Radio Specific CAL file $hw_radio_cal_file NOT FOUND "
        isValidFile $default_cal_file
        if [ "$validFileRetVal" == 1 ]; then
            echo "Found valid DEFAULT CAL file $default_cal_file - update soft links"
            #cleanup link first
            rm $persist_cal_file
            ln -s $default_cal_file $persist_cal_file
        else
            echo "!!WARNING!! INVALID DEFAULT CAL file $default_cal_file - rely on persist or driver defaults!!!"
        fi
    fi
    
    ### Setup REG  file softlinks
    isValidFile $hw_radio_reg_file
    if [ "$validFileRetVal" == 1 ]; then
        echo "Found valid HW RADIO specific REG file $hw_radio_reg_file - update soft links "
        #cleanup link first
        rm $persist_reg_file
        ln -s $hw_radio_reg_file $persist_reg_file
    else
        echo "HW Radio Specific REG file $hw_radio_reg_file NOT FOUND "
        isValidFile $default_reg_file
        if [ "$validFileRetVal" == 1 ]; then
            echo "Found valid DEFAULT REG file $default_reg_file - update soft links"
            #cleanup link first
            rm $persist_reg_file
            ln -s $default_reg_file $persist_reg_file
        else
            echo "!!WARNING!! INVALID DEFAULT REG file $default_reg_file - rely on persist or driver defaults!!!"
        fi
    fi
fi
###### MOT - END CAL setup
