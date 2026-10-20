#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8043F52C_E3058);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DD0DC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9C6C);
#endif

#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_unresolved_800EEAAC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE42C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8043F52C_E3058_us_rev1.c */
const unsigned int D_blob_b7ff8d583778774702c5[1] = {
    0x3F800000,
};
#endif
