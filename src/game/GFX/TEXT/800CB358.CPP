#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802AA1AC_CBF58);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C610C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C64BC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C647C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C61DC);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_802AA1AC_CBF58_us_rev1[5] = {
    0x41F00000, 0x00000000, 0x3F800000, 0x3F800000, 0x3F800000,
};
#endif
