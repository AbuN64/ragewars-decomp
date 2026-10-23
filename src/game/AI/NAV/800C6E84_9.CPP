#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8020EA10_C7B40[3] = {
    0x3F19999A, 0x3E4CCCCD, 0x3F800000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C1D8C[1] = {
    0x4353776F,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C213C[1] = {
    0x0022EC68,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C20FC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C1E5C[1] = {
    0x0020ED00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8020EA10_C7B40_us_rev1.c */
const unsigned int D_blob_e2105c22ed856e4916b8[3] = {
    0x3F19999A, 0x3E4CCCCD, 0x3F800000,
};
#endif
