#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
const unsigned char D_80433EA0_E2AE0[3] = {
    0x25, 0x64, 0x00,
};
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800DCB63[1] = {
    0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800DDEB3[1] = {
    0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_80433EA0_E2AE0_us_rev1.c */
const unsigned char g_noteInfoIntFormat[3] = {
    0x25, 0x64, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800E1EE3[1] = {
    0x00,
};
#endif
