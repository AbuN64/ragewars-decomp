#include "include_asm.h"

#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
const unsigned int D_80256880_C9BA0[3] = {
    0x41F00000, 0x00000000, 0x3C888889,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C3DEC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C416C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C3EBC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80256880_C9BA0_us_rev1.c */
const unsigned int D_blob_dde8808d8100365fa2c6[3] = {
    0x41F00000, 0x00000000, 0x3C888889,
};
#endif
