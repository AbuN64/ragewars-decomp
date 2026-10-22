#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8023CFE0_C9310);
#endif

#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C357C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C393C);
#endif

#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C38FC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C364C);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_8023CFE0_C9310_us_rev1[4] = {
    0x3D888889, 0x41700000, 0x3F800000, 0x3F000000,
};

/* ROM-grounded data: src/rw_pool_8023D158_C9320_us_rev1.c */
const unsigned int D_blob_be10cc59de99000dbca2[1] = {
    0x3F800000,
};

const unsigned int D_auto_src_rw_pool_8023D380_C9324_us_rev1[6] = {
    0x4123D70A, 0x41F5C28F, 0x3E51B717, 0x3F800000, 0x4083126F, 0x3F8637BE,
};
#endif
