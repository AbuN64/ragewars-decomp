#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8020AA0C_C7A24);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1C6C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C201C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1FDC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1D3C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8020AA0C_C7A24_us_rev1.c */
const unsigned int D_blob_3fa52e80a8180b523c67[2] = {
    0x3F800000, 0x3F060A93,
};
#endif
