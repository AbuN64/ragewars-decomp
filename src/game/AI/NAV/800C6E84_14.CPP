#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8020FA10_C7C10[6] = {
    0x42C80000, 0x42C80000, 0x3F800000, 0x42A00000, 0x41200000, 0x41200000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C2218[2] = {
    0x3C5F0B72, 0x3FE52EDF,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C21D8[2] = {
    0x01014824, 0x40896000,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_8020FA10_C7C10_us_rev1[6] = {
    0x42C80000, 0x42C80000, 0x3F800000, 0x42A00000, 0x41200000, 0x41200000,
};
#endif
