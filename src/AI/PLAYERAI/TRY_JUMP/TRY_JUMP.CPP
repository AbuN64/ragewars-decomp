#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char g_flyModeOffText[13] =
    "Fly Mode Off\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/s_flyModeOffText_TryJump.c */
const unsigned char s_flyModeOffText[13] = {
    0x46, 0x6C, 0x79, 0x20, 0x4D, 0x6F, 0x64, 0x65, 0x20, 0x4F, 0x66, 0x66, 0x00,
};
#endif
