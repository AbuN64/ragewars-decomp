#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char g_matricesText[9] =
    "Matrices\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80286AA8_CADF4_us_rev1.c */
const unsigned char s_matricesText[9] = {
    0x4D, 0x61, 0x74, 0x72, 0x69, 0x63, 0x65, 0x73, 0x00,
};
#endif
