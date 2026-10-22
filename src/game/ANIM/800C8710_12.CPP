#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802433DC_C9464);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C36AC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3A6C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3A2C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C377C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802433DC_C9464_us_rev1.c */
const unsigned int D_blob_a1f4d95838a1e04b9138[2] = {
    0x3F333333, 0x3F333333,
};
#endif
