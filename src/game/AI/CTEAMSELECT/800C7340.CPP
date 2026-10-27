#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802184C0_C7F40[2] = {
    0x40C90FDC, 0x40C90FDC,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C2538[2] = {
    0x3D0EFA36, 0x3F800000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C24F8[2] = {
    0x00000000, 0x2129FFFF,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C2258[2] = {
    0x65616D00, 0x437F0000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802184C0_C7F40_us_rev1.c */
const unsigned int D_blob_32e5c09556bbd500697d[2] = {
    0x40C90FDC, 0x40C90FDC,
};
#endif
