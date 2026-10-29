#include "include_asm.h"

#if defined(VERSION_US)
char s_evadeText[8] =
    "R_EVADE_";
#endif

#if defined(VERSION_US_REV1)
unsigned char g_SEvadetextTrailingBytes[8] = { 0x24, 0x84, 0x03, 0x08, 0x8F, 0xA5, 0x00, 0x50 };
#endif
