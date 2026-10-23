#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_80217594_C7EDC[2] = {
    0x43E10000, 0x44160000,
};
#endif

#if defined(VERSION_US)
char rodata_unresolved_800C2124[12] =
    "CBHole_tT\000\000\000";
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C24D4[3] = {
    0x00000000, 0x41F00000, 0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C2494[3] = {
    0x3C01FFFF, 0x342100FF, 0x01816024,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C21F4[3] = {
    0x3F000000, 0x4F000000, 0x3B4CCCCD,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80217594_C7EDC_us_rev1.c */
const unsigned int D_blob_667c528ce0704f8f6261[2] = {
    0x43E10000, 0x44160000,
};
#endif
