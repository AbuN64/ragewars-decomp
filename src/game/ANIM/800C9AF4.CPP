#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80275F28_CA6F4);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4938);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4CF8);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4CB8);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4A08);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80275F28_CA6F4_us_rev1.c */
const unsigned int D_blob_dd17c7991d2f6b062f5a[1] = {
    0xBF800000,
};
#endif
