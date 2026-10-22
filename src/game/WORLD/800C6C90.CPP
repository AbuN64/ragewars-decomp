#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80207BB8_C7890);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1E84);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1E44);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80207BB8_C7890_us_rev1.c */
const unsigned int D_blob_3799e9b95678ffcbaf99[1] = {
    0x3F800000,
};
#endif
