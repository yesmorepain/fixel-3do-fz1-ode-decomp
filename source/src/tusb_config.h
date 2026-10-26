#pragma once
#define CFG_TUSB_RHPORT0_MODE OPT_MODE_HOST
#define CFG_TUSB_OS OPT_OS_PICO
#define CFG_TUH_ENUMERATION_BUFSIZE 512   /* original: enum_get_9byte_config_desc_complete checks <= 512 */
#define CFG_TUH_HUB 0
#define CFG_TUH_MSC 1
#define CFG_TUH_DEVICE_MAX 1
#define CFG_TUH_ENDPOINT_MAX 8
