#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802110C4_C7CF0);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C22E8);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C22A8);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2008);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802110C4_C7CF0_us_rev1.c */
const unsigned int D_blob_baf2bb750ce0516204d1[2] = {
    0x42C80000, 0x4399999A,
};
#endif
