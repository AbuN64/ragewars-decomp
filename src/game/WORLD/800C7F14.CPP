#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8022EA3C_C8B14);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3114);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C30D4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8022EA3C_C8B14_us_rev1.c */
const unsigned int D_blob_135fa7c8aae48ab6d5b0[3] = {
    0x44800000, 0x3A800000, 0x3F800000,
};
#endif
