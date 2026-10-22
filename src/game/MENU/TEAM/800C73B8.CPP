#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802191B8_C7FB8);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C21FC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C25AC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C256C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C22CC);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802191B8_C7FB8_us_rev1.c */
const unsigned int D_blob_e0ab93a21c02d31fb494[1] = {
    0x40000000,
};
#endif
