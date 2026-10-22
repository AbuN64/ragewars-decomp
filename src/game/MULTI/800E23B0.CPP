#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8043F120_E2FB0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DD036);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9BC6);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EEA06);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE386);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8043F120_E2FB0_us_rev1.c */
const unsigned short D_blob_05794516b6039adb8c7a[3] = {
    0x2533, 0x2E32, 0x6600,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E23B6);
#endif
