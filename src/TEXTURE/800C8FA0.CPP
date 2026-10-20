#include "include_asm.h"

#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80256880_C9BA0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3DEC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C416C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3EBC);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80256880_C9BA0_us_rev1.c */
const unsigned int D_blob_dde8808d8100365fa2c6[3] = {
    0x41F00000, 0x00000000, 0x3C888889,
};
#endif
