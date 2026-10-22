#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802AF2E0_CD270);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C734C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C89EC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C801C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C742C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802AF2E0_CD270_us_rev1.c */
const unsigned int D_blob_868e5463195d5f476023[3] = {
    0x42FE0000, 0x4F000000, 0x3F800000,
};
#endif
