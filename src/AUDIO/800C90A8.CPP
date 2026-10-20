#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8025D350_C9CA8);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4274);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3FC4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8025D350_C9CA8_us_rev1.c */
const unsigned int D_blob_a274f83a44ed3e23c66c[3] = {
    0x41F00000, 0x00000000, 0x3C23D70A,
};
#endif
