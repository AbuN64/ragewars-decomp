#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80204808_C7764);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C19AC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1D5C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1D1C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1A7C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80204808_C7764_us_rev1.c */
const unsigned int D_blob_bd7f8911fbfaa0635c67[2] = {
    0x41080000, 0x437F0000,
};
#endif
