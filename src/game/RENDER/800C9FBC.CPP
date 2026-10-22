#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802859D0_CABBC);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4E04);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C51C4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5184);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4ED4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802859D0_CABBC_us_rev1.c */
const unsigned int D_blob_4faf23a8416908d6583f[2] = {
    0x3F800000, 0x3F800000,
};
#endif
