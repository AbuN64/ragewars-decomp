#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80402BA0_E1860);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DB8EC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E847C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800ED2BC);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_constants_80402BA0_E1860_us_rev1.c */
const unsigned int D_blob_54f0a4ddb73e61d074da[3] = {
    0x41F00000, 0x00000000, 0x4F000000,
};
#endif
