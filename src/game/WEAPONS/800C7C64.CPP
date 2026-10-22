#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80226DD0_C8864);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2AAC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2E5C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2E1C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2B7C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80226DD0_C8864_us_rev1.c */
const unsigned int D_blob_32f649f10ae7c7e31f06[2] = {
    0x4223D70A, 0x3F000000,
};
#endif
