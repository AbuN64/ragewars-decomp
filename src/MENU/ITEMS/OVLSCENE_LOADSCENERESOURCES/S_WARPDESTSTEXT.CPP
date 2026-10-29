#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char s_warpDestsText[11] =
    "warp dests\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/g_warpDests.c */
const unsigned char g_warpDests[11] = {
    0x77, 0x61, 0x72, 0x70, 0x20, 0x64, 0x65, 0x73, 0x74, 0x73, 0x00,
};
#endif
