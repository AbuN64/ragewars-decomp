#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802625F0_C9F48);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C418C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C454C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C450C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C425C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802625F0_C9F48_us_rev1.c */
const unsigned int D_blob_c8f825d4ab0cc9948c9c[1] = {
    0x38C9116D,
};
#endif
