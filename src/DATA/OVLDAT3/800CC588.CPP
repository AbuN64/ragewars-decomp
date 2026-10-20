#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802AE824_CD188);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7264);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8904);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7F34);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7344);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802AE824_CD188_us_rev1.c */
const unsigned int D_blob_6e17b1ab7ebf49014ea8[3] = {
    0x41F00000, 0x00000000, 0x4F000000,
};
#endif
