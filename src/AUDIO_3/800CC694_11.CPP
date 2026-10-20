#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802B2CF0_CD3B0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7488);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8B28);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8158);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7568);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802B2CF0_CD3B0_us_rev1.c */
const unsigned int D_blob_898e22e4f52e3e0e52d7[2] = {
    0x41DFFFFF, 0xFFC00000,
};
#endif
