#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802B2510_CD360);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8AD4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8104);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7514);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802B2510_CD360_us_rev1.c */
const unsigned int D_blob_0ac61d632b03a4a1fa7b[1] = {
    0x3F800000,
};
#endif
