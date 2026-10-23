#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_80418DA0_E2040[1] = {
    0x3F800000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EDA94[3] = {
    0x0800FF88, 0x011A011F, 0x011B011C,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DD414[3] = {
    0x3C23D70A, 0x3F99999A, 0x3D4CCCCD,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80418DA0_E2040_us_rev1.c */
const unsigned int D_blob_4dd9abd2df7b01df530e[1] = {
    0x3F800000,
};
#endif
