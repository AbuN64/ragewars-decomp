#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802850C8_CAB90);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5194);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4EA4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802850C8_CAB90_us_rev1.c */
const unsigned int D_blob_bfe29edccd21ea0ddff2[1] = {
    0x4B189680,
};
#endif
