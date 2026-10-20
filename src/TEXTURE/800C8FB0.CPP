#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80256880_C9BB0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3DF8);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C41B8);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4178);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3EC8);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80256880_C9BB0_us_rev1.c */
const unsigned int D_blob_eaa307fd6066ded3fb20[2] = {
    0x41F00000, 0x00000000,
};
#endif
