#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80264104_C9FF8);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C423C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C45FC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C45BC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C430C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80264104_C9FF8_us_rev1.c */
const unsigned int D_blob_f4126ef72f730e45faf9[1] = {
    0x3F800000,
};
#endif
