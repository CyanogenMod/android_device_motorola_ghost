/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char radio[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char carrier[PROP_VALUE_MAX];
    char bootdevice[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.boot.radio", radio);
    property_get("ro.boot.carrier", carrier);
    property_get("ro.boot.device", bootdevice);
    if (ISMATCH(radio, "0x1")) {
        /* xt1058 */
        property_set("ro.product.device", "ghost_retail");
        property_set("ro.product.model", "Moto X");
        property_set("ro.build.description", "ghost_retail-user 4.4 13.11.1Q2.X-69-3 51 release-keys");
        property_set("ro.build.fingerprint", "motorola/ghost_retail/ghost:4.4/13.11.1Q2.X-69-3/51:user/release-keys");
        property_set("telephony.lteOnGsmDevice", "1");
    } else if ((ISMATCH(radio, "0x2")) && (ISMATCH(bootdevice, "ghost"))) {
        /* xt1060 */
        property_set("ro.product.device", "ghost_verizon");
        property_set("ro.product.model", "Moto X");
        property_set("ro.build.description", "ghost_verizon-user 4.4 13.11.1Q2.X-69-3 5 release-keys");
        property_set("ro.build.fingerprint", "motorola/ghost_verizon/ghost:4.4/13.11.1Q2.X-69-3/5:user/release-keys");
    } else if (ISMATCH(bootdevice, "obake-maxx")) {
        /* xt1080 */
        property_set("ro.product.device", "obake");
        property_set("ro.product.model", "DROID MAXX");
        property_set("ro.build.description", "obake_verizon-user 4.4 SU2-3 15 release-keys");
        property_set("ro.build.fingerprint", "motorola/obake_verizon/obake:4.4/SU2-3/15:user/release-keys");
        property_set(PROP_QEMU_NAVKEY, "1");
    } else if (ISMATCH(radio, "0x4")) {
        /* xt1056 */
        property_set("ro.product.device", "ghost_sprint");
        property_set("ro.product.model", "Moto X");
        property_set("ro.build.description", "ghost_sprint-user 4.4 13.11.3Q2.X-69-3-8 12 release-keys");
        property_set("ro.build.fingerprint", "motorola/ghost_sprint/ghost:4.4/13.11.3Q2.X-69-3-8/12:user/release-keys");
    } else if (ISMATCH(radio, "0x5")) {
        /* xt1055 */
        property_set("ro.product.device", "ghost_usc");
        property_set("ro.product.model", "Moto X");
        property_set("ro.build.description", "ghost_usc-user 4.4 13.11.3Q2.X-69-3-2 11 release-keys");
        property_set("ro.build.fingerprint", "motorola/ghost_usc/ghost:4.4/13.11.3Q2.X-69-3-2/11:user/release-keys");
    } else if (ISMATCH(radio, "0x6")) {
        /* xt1053 */
        property_set("ro.product.device", "ghost_retail");
        property_set("ro.product.model", "Moto X");
        property_set("ro.build.description", "ghost_retail-user 4.4 13.11.1Q2.X-69-3 51 release-keys");
        property_set("ro.build.fingerprint", "motorola/ghost_retail/ghost:4.4/13.11.1Q2.X-69-3/51:user/release-keys");
        property_set("telephony.lteOnGsmDevice", "1");
    }

    if (ISMATCH(carrier, "vzw")) {
        property_set("ro.mot.build.customerid ", "verizon");
        property_set("ro.config.svdo", "true");
        property_set("ro.cdma.home.operator.isnan", "1");
        property_set("ro.telephony.gsm-routes-us-smsc", "1");
        property_set("ro.cdma.otaspnumschema","SELC,1,80,99");
        property_set("ro.cdma.data_retry_config", "max_retries=infinite,0,0,10000,10000,100000,10000,10000,10000,10000,140000,540000,960000");
        property_set("ro.gsm.data_retry_config", "default_randomization=2000,max_retries=infinite,1000,1000,80000,125000,485000,905000");
        property_set("ro.gsm.2nd_data_retry_config", "max_retries=1,15000");
        property_set("persist.radio.vrte_logic", "2");
        property_set("persist.radio.0x9e_not_callname", "1");
        property_set("persist.ril.max.crit.qmi.fails", "4");
        property_set("ro.cdma.homesystem", "64,65,76,77,78,79,80,81,82,83");
        property_set("ro.mot.ignore_csim_appid", "true");
        property_set("persist.radio.eons.enabled", "1");
        property_set("ro.cdma.nbpcd", "1");
        property_set("persist.radio.skip_data_check", "1");
        property_set("ro.cdma.home.operator.alpha", "Verizon");
        property_set("ro.cdma.home.operator.numeric", "310004");
        property_set("telephony.rilV7NeedCDMALTEPhone", "true");
        property_set("ro.com.google.clientidbase.ms", "android-verizon");
        property_set("ro.com.google.clientidbase.am", "android-verizon");
        property_set("ro.com.google.clientidbase.yt", "android-verizon");
    } else if (ISMATCH(carrier, "usc")) {
        property_set("ro.cdma.nbpcd", "1");
        property_set("ro.cdma.data_retry_config", "max_retries=infinite,0,0,10000,10000,100000,10000,10000,10000,10000,140000,540000,960000");
        property_set("ro.cdma.international.eri", "2,74,124,125,126,157,158,159,193,194,195,196,197,198,228,229,230,231,232,233,234,235");
        property_set("ro.cdma.home.operator.isnan", "1");
        property_set("persist.data_netmgrd_mtu", "1472");
        property_set("persist.radio.0x9e_not_callname", "1");
        property_set("persist.radio.vrte_logic", "2");
        property_set("ro.cdma.subscription", "0");
        property_set("ro.config.svdo", "true");
        property_set("persist.radio.skip_data_check", "1");
        property_set("ro.mot.ignore_csim_appid", "true");
        property_set("telephony.rilV7NeedCDMALTEPhone", "true");
    } else if (ISMATCH(carrier, "sprint")) {
        property_set("ro.cdma.nbpcd", "0");
        property_set("ro.cdma.international.eri", "2,74,124,125,126,157,158,159,193,194,195,196,197,198,228,229,230,231,232,233,234,235");
        property_set("persist.radio.vrte_logic", "2");
        property_set("persist.radio.skip_data_check", "1");
        property_set("ro.cdma.homesystem", "64,65,76,77,78,79,80,81,82,83");
        property_set("persist.data_netmgrd_mtu", "1422");
        property_set("persist.radio.0x9e_not_callname", "1");
        property_set("ro.mot.ignore_csim_appid", "true");
        property_set("ro.config.svdo", "true");
        property_set("ro.config.svlte1x", "true");
        property_set("ro.telephony.gsm-routes-us-smsc", "1");
        property_set("ro.cdma.home.operator.isnan", "1");
        property_set("ro.cdma.otaspnumschema", "SELC,1,80,99");
        property_set("persist.ril.max.crit.qmi.fails", "4");
        property_set("telephony.rilV7NeedCDMALTEPhone", "true");
    }

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found device: %s radio id: %s carrier: %s Setting build properties for %s device\n", bootdevice, radio, carrier, devicename);
}
