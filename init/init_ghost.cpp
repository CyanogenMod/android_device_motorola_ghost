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

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

static void set_cmdline_properties()
{
    size_t i;
    int rc;
    char prop[PROP_VALUE_MAX];

    struct {
        const char *src_prop;
        const char *dest_prop;
        const char *def_val;
    } prop_map[] = {
        { "ro.boot.device", "ro.hw.device", "ghost", },
        { "ro.boot.hwrev", "ro.hw.hwrev", "0x8300", },
        { "ro.boot.radio", "ro.hw.radio", "0x1", },
    };

    for (i = 0; i < ARRAY_SIZE(prop_map); i++) {
        memset(prop, 0, PROP_VALUE_MAX);
        rc = property_get(prop_map[i].src_prop, prop);
        if (rc > 0) {
            property_set(prop_map[i].dest_prop, prop);
        } else {
            property_set(prop_map[i].dest_prop, prop_map[i].def_val);
        }
    }
}

static void gsm_properties()
{
    property_set("ro.telephony.default_network", "9");
    property_set("telephony.lteOnGsmDevice", "1");
}

static void cdma_properties(const char *default_sub, const char *op_numeric,
        const char *op_alpha)
{
    property_set("ro.telephony.default_cdma_sub", default_sub);
    property_set("ro.cdma.home.operator.numeric", op_numeric);
    property_set("ro.cdma.home.operator.alpha", op_alpha);

    property_set("persist.radio.0x9e_not_callname", "1");
    property_set("persist.ril.max.crit.qmi.fails", "4");

    property_set("ril.subscription.types", "NV,RUIM");
    property_set("ro.cdma.subscribe_on_ruim_ready", "true");
    property_set("ro.mot.ignore_csim_appid", "true");
    property_set("ro.ril.svdo", "true");
    property_set("ro.telephony.default_network", "10");
    property_set("telephony.lteOnCdmaDevice", "1");
    property_set("telephony.rilV7NeedCDMALTEPhone", "true");
}

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver,
        char *board_type)
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

    set_cmdline_properties();

    property_get("ro.boot.radio", radio);
    property_get("ro.boot.carrier", carrier);
    property_get("ro.boot.device", bootdevice);
    if (ISMATCH(radio, "0x1")) {
        /* xt1058 */
        property_set("ro.product.device", "ghost_retail");
        property_set("ro.product.model", "Moto X");
        property_set("ro.build.description", "ghost_retail-user 5.1 LPA23.12-15.5 4 release-keys");
        property_set("ro.build.fingerprint", "motorola/ghost_retail/ghost:5.1/LPA23.12-15.5/4:user/release-keys");
        property_set("ro.build.product", "ghost_retail");
        gsm_properties();
    } else if (ISMATCH(radio, "0x2")) {
        /* xt1060 */
        property_set("ro.product.device", "ghost_verizon");
        property_set("ro.product.model", "Moto X");
        property_set("ro.build.description", "ghost_verizon-user 5.1 LPA23.12-39.7 7 release-keys");
        property_set("ro.build.fingerprint", "motorola/ghost_verizon/ghost:5.1/LPA23.12-39.7/7:user/release-keys");
        property_set("ro.build.product", "ghost_verizon");

        property_set("ro.cdma.data_retry_config", "max_retries=infinite,0,0,10000,10000,100000,10000,10000,10000,10000,140000,540000,960000");
        property_set("ro.gsm.data_retry_config", "default_randomization=2000,max_retries=infinite,1000,1000,80000,125000,485000,905000");
        property_set("ro.gsm.2nd_data_retry_config", "max_retries=1,15000");
        property_set("ro.com.google.clientidbase.ms", "android-verizon");
        property_set("ro.com.google.clientidbase.am", "android-verizon");
        property_set("ro.com.google.clientidbase.yt", "android-verizon");
        cdma_properties("0", "311480", "Verizon");
    } else if (ISMATCH(radio, "0x3")) {
        /* xt1052 */
        property_set("ro.product.device", "ghost");
        property_set("ro.product.model", "Moto X");
        property_set("ro.build.description", "ghost_retde-user 5.1 LPA23.12-15.5 3 release-keys");
        property_set("ro.build.fingerprint", "motorola/ghost_retde/ghost:5.1/LPA23.12-15.5/3:user/release-keys");
        property_set("ro.build.product", "ghost");
        gsm_properties();
    } else if (ISMATCH(radio, "0x4")) {
        /* xt1056 */
        property_set("ro.product.device", "ghost_sprint");
        property_set("ro.product.model", "Moto X");
        property_set("ro.build.description", "ghost_sprint-user 5.1 LPA23.12-39.10 11 release-keys");
        property_set("ro.build.fingerprint", "motorola/ghost_sprint/ghost:5.1/LPA23.12-39.10/11:user/release-keys");
        property_set("ro.build.product", "ghost_sprint");
        cdma_properties("1", "310120", "Sprint");
    } else if (ISMATCH(radio, "0x5")) {
        /* xt1055 */
        property_set("ro.product.device", "ghost_usc");
        property_set("ro.product.model", "Moto X");
        property_set("ro.build.description", "ghost_usc-user 5.1 LPA23.12-21-1 1 release-keys");
        property_set("ro.build.fingerprint", "motorola/ghost_usc/ghost:5.1/LPA23.12-21-1/1:user/release-keys");
        property_set("ro.build.product", "ghost_usc");
        cdma_properties("0", "311580", "U.S.Cellular");
    } else if (ISMATCH(radio, "0x6")) {
        /* xt1053 */
        property_set("ro.product.device", "ghost_retail");
        property_set("ro.product.model", "Moto X");
        property_set("ro.build.description", "ghost_retail-user 5.1 LPA23.12-15.5 4 release-keys");
        property_set("ro.build.fingerprint", "motorola/ghost_retail/ghost:5.1/LPA23.12-15.5/4:user/release-keys");
        property_set("ro.build.product", "ghost_retail");
        gsm_properties();
    }

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    INFO("Found device: %s radio id: %s carrier: %s Setting build properties for %s device\n", bootdevice, radio, carrier, devicename);
}
