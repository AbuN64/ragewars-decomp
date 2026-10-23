#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
const unsigned char D_8042C018_E2720[3] = {
    0x25, 0x64, 0x00,
};
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800DC7A3[1] = {
    0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800DDAF3[1] = {
    0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_8042C018_E2720_us_rev1.c */
const unsigned char D_blob_bd72dd2fe4d637499ad0[3] = {
    0x25, 0x64, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800E1B23[1] = {
    0x00,
};
#endif
