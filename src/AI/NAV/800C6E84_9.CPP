#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8020EA10_C7B40);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1D8C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C213C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C20FC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1E5C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8020EA10_C7B40_us_rev1.c */
const unsigned int D_blob_e2105c22ed856e4916b8[3] = {
    0x3F19999A, 0x3E4CCCCD, 0x3F800000,
};
#endif
