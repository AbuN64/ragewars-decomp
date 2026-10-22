#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802745D0_D3228);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800CD2EC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800CE98C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800CDFBC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800CD3DC);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802745D0_D3228_us_rev1.c */
const unsigned int D_blob_4fa614eb4742521550ff[1] = {
    0x00000000,
};
#endif
