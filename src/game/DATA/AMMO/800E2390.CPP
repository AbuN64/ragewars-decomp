#include "include_asm.h"

#if !(defined(VERSION_US))
/* ROM-grounded data: src/rw_pool_8043EF1C_us_rev1_E2F90_us_rev1.c */
const unsigned int D_blob_97066ebe20ee8a676742[1] = {
    0x42F00000,
};
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9BA4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EE9E4);
#endif
