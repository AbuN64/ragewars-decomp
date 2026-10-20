#include "include_asm.h"

#if !(defined(VERSION_DE) || defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8026E5E0_CA3A0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C45EC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C49AC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C496C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8026E5E0_CA3A0_us_rev1.c */
const unsigned int D_blob_66088a10f518a8d8ca1f[3] = {
    0x41700000, 0x40A00000, 0x43800000,
};
#endif
