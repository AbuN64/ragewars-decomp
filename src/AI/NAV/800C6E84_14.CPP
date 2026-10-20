#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8020FA10_C7C10);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2218);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C21D8);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_8020FA10_C7C10_us_rev1[6] = {
    0x42C80000, 0x42C80000, 0x3F800000, 0x42A00000, 0x41200000, 0x41200000,
};
#endif
