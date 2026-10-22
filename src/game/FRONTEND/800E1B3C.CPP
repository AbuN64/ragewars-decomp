#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8042D28C_E273C);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DC7C4);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9354);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EE194);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DDB14);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8042D28C_E273C_us_rev1.c */
const unsigned int D_blob_e43399bdbd08619aff58[2] = {
    0x43160000, 0x437F0000,
};
#endif
