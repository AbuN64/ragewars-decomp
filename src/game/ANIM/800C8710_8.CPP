#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8023EF00_C93D0);
#endif

#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C3618);
#endif

#if defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C39D8);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3998);
#endif

#if defined(VERSION_DE)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C36E8);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8023EF00_C93D0_us_rev1.c */
const unsigned int D_blob_682bbc0322c5a074ded0[2] = {
    0xBF800000, 0x3F800000,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C87D8);
#endif
