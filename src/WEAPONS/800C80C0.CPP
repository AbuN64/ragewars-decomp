#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802323A4_C8CC0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2F04);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C32C4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3284);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2FD4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802323A4_C8CC0_us_rev1.c */
const unsigned int D_blob_d1eb619194e36cd3bb97[1] = {
    0x3F800000,
};
#endif
