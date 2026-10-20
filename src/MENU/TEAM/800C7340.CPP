#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802184C0_C7F40);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2538);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C24F8);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2258);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802184C0_C7F40_us_rev1.c */
const unsigned int D_blob_32e5c09556bbd500697d[2] = {
    0x40C90FDC, 0x40C90FDC,
};
#endif
