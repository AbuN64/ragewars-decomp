#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802066A4_C77D0);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1DC4);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1AE4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802066A4_C77D0_us_rev1.c */
const unsigned int D_blob_06def481576a7536a499[1] = {
    0x3F800000,
};
#endif
