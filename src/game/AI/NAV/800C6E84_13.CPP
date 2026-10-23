#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8020F984_C7C04[1] = {
    0xBF800000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C1E48[2] = {
    0x08000000, 0x00001043,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C21F8[2] = {
    0x3FE52EDF, 0x3FE52EDF,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C21B8[2] = {
    0x00000000, 0x90420000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C1F18[2] = {
    0x3F800000, 0x42A00000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8020F984_C7C04_us_rev1.c */
const unsigned int D_blob_052a3b9ed7fa871fc91d[1] = {
    0xBF800000,
};
#endif
