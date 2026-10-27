#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8020AA0C_C7A24[2] = {
    0x3F800000, 0x3F060A93,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C1C6C[1] = {
    0x5F446973,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C201C[1] = {
    0xC2480000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C1FDC[1] = {
    0x3C04800E,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C1D3C[1] = {
    0xBF800000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8020AA0C_C7A24_us_rev1.c */
const unsigned int D_blob_3fa52e80a8180b523c67[2] = {
    0x3F800000, 0x3F060A93,
};
#endif
