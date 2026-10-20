#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80285630_CABA0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4DEC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C51AC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C516C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4EBC);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80285630_CABA0_us_rev1.c */
const unsigned int D_blob_069ab1292059e03559c0[3] = {
    0x41F00000, 0x00000000, 0x38000100,
};
#endif
