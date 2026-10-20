#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802B6560_CD6A8);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7790);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_802B6560_CD6A8_us_rev1[6] = {
    0x3FE00000, 0x00000000, 0x00000000, 0x00000000, 0x3FE00000, 0x00000000,
};
#endif
