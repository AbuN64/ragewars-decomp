#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802453D4_C94B0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3714);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3AD4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3A94);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_802453D4_C94B0_us_rev1[4] = {
    0x3F000000, 0x3F000000, 0x3F800000, 0x3EB33333,
};

/* ROM-grounded data: src/rw_pool_8024570C_C94C0_us_rev1.c */
const unsigned int D_blob_e8f2a431008ef3bd6bd7[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_802459A0_C94C4_us_rev1.c */
const unsigned int D_blob_de0755007133519d6e81[2] = {
    0x423E0000, 0x3F800000,
};

/* ROM-grounded data: src/rw_pool_80245AD8_C94CC_us_rev1.c */
const unsigned int D_blob_7e68b7368e1bafbf90a3[1] = {
    0x4123D70A,
};

/* ROM-grounded data: src/rw_pool_80245C38_C94D0_us_rev1.c */
const unsigned int D_blob_9ba48f4aa6132fffb82c[1] = {
    0x3D888889,
};
#endif
