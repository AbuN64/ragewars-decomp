#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
const unsigned char D_8042C018_E2724[5] = {
    0x25, 0x64, 0x25, 0x25, 0x00,
};
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800DC7A9[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800DDAF9[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8042C018_E2724_us_rev1.c */
const unsigned char D_blob_8afd4f4ba44d3a0f2d7f[5] = {
    0x25, 0x64, 0x25, 0x25, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800E1B29[3] = {
    0x00, 0x00, 0x00,
};
#endif
