#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802138F0_C7DF0);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C240C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C23CC);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_802138F0_C7DF0_us_rev1[10] = {
    0x42C80000, 0x43000000, 0x41F00000, 0x00000000, 0x41F00000, 0x00000000, 0x3F000000, 0x3F800000,
    0x3FA00000, 0x437F0000,
};

/* ROM-grounded data: src/rw_pool_80213AAC_us_rev1_C7E18_us_rev1.c */
const unsigned int D_blob_24187ce5fa5537d6a654[1] = {
    0x3F800000,
};
#endif
