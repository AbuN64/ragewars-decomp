#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8020F984_C7C04);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1E48);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C21F8);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C21B8);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1F18);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8020F984_C7C04_us_rev1.c */
const unsigned int D_blob_052a3b9ed7fa871fc91d[1] = {
    0xBF800000,
};
#endif
