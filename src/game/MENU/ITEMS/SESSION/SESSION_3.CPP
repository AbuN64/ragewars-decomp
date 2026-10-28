#include "include_asm.h"

#if !(defined(VERSION_US))
/* ROM-grounded data: src/rw_pool_8043EF1C_us_rev1_E2F90_us_rev1.c */
const unsigned int D_blob_97066ebe20ee8a676742[1] = {
    0x42F00000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E9BA4[3] = {
    0x00007530, 0x0041AEC0, 0x00000E03,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EE9E4[3] = {
    0x484A0800, 0x4A05174D, 0xE9171C7C,
};
#endif

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DCFEC[1] = {
    0x00000000,
};
#endif
#if defined(VERSION_US)
const unsigned int rodata_unresolved_800DCFEC[1] = {
    0x00000000,
};
#endif
#endif
