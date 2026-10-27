#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned char D_8044488C_E3380[5] = {
    0x25, 0x30, 0x32, 0x64, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8044488C_E3380_us_rev1.c */
const unsigned char g_fmtDec2Pad[5] = {
    0x25, 0x30, 0x32, 0x64, 0x00,
};
#endif
