#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char s_displayBufferText[15] = "Display Buffer";
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800DB9CB[1] = {
    0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800E855B[1] = {
    0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800ED39B[1] = {
    0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800DCD1B[1] = {
    0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_804058B0_E193C_us_rev1.c */
const char g_displayBufferText[15] = "Display Buffer";
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800E0D4B[1] = {
    0x00,
};
#endif
