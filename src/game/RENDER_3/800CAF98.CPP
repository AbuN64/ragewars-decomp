#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802A3DD4_CBB98);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5D3C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C60EC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C60AC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5E0C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802A3DD4_CBB98_us_rev1.c */
const unsigned int D_blob_ef73748110a4881bbf4f[1] = {
    0x40480000,
};
#endif
