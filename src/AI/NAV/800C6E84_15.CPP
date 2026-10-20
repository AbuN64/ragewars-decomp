#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8021035C_C7C40);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1EB4);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2264);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_8021035C_C7C40_us_rev1[13] = {
    0x44C00000, 0x44666666, 0x44000000, 0x3F490FDC, 0x4016CBE5, 0x3F8CCCCD, 0x3F99999A, 0x3F4CCCCD,
    0x3F4CCCCD, 0x3F8CCCCD, 0x3F99999A, 0x3F800000, 0x3F000000,
};
#endif
