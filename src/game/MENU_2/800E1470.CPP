#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8041A280_E2070);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DC0F8);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E8C88);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EDAC8);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DD448);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8041A280_E2070_us_rev1.c */
const unsigned int D_blob_1466e2b8289b860d4bb9[2] = {
    0x3EAAAAAB, 0x3D4CCCCD,
};
#endif
