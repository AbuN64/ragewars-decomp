#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_80204808_C7764[2] = {
    0x41080000, 0x437F0000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C19AC[1] = {
    0x00080020,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C1D5C[1] = {
    0x3C8EFA36,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C1D1C[1] = {
    0x3C020200,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C1A7C[1] = {
    0x00031080,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80204808_C7764_us_rev1.c */
const unsigned int D_blob_bd7f8911fbfaa0635c67[2] = {
    0x41080000, 0x437F0000,
};
#endif
