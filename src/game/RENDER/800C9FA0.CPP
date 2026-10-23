#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_80285630_CABA0[3] = {
    0x41F00000, 0x00000000, 0x38000100,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C4DEC[1] = {
    0x43414D45,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C51AC[1] = {
    0x20202020,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C516C[1] = {
    0x00021043,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C4EBC[1] = {
    0x3F800000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80285630_CABA0_us_rev1.c */
const unsigned int D_blob_069ab1292059e03559c0[3] = {
    0x41F00000, 0x00000000, 0x38000100,
};
#endif
