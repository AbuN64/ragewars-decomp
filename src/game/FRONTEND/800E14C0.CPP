#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8041CAD8_E20C0[2] = {
    0x46200000, 0x3C8EFA36,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DC148[2] = {
    0x00000000, 0x00124D55,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E8CD8[2] = {
    0x3C8EFA36, 0x3F800000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EDB18[2] = {
    0x013A013B, 0x08000063,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DD498[2] = {
    0x0041D3A0, 0x0041D258,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8041CAD8_E20C0_us_rev1.c */
const unsigned int D_blob_9ec24c11a49589b0ad4b[2] = {
    0x46200000, 0x3C8EFA36,
};
#endif
