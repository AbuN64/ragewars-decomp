#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8040170C_E3448);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DD4AC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800EA02C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EEE6C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE7FC);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_constants_8040170C_E3448_us_rev1.c */
const unsigned int D_blob_ff7189024c233f46147b[1] = {
    0x3E4CCCCD,
};
#endif
