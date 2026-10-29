#include "include_asm.h"

/* 8042FBEC_19.CPP */
#if defined(VERSION_EU)
unsigned char g_MenuLinkGapBaf28TrailingBytesBlock1[8] = { 0x54, 0x40, 0x00, 0x06, 0x24, 0x86, 0xFF, 0xFD };
#endif

/* DATA_802B97F8.CPP */
#if defined(VERSION_US)
char func_802B4A08_eu_x_padding_BA3F8[8] =
    "sionType";
#endif

#if defined(VERSION_US_REV1)
unsigned char g_MenuLinkGapBaf28TrailingBytes[8] = { 0x03, 0xE0, 0x00, 0x08, 0x27, 0xBD, 0x00, 0x40 };
#endif
