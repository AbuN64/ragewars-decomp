#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_80207BB8_C7890[1] = {
    0x3F800000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C1E84[3] = {
    0x42000000, 0x3F000000, 0x42000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C1E44[3] = {
    0x2402FFFF, 0x14620016, 0x3C030002,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80207BB8_C7890_us_rev1.c */
const unsigned int D_blob_3799e9b95678ffcbaf99[1] = {
    0x3F800000,
};
#endif
