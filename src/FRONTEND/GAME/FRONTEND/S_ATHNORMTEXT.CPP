#include "include_asm.h"

#if defined(VERSION_US)
char s_athNormText[8] =
    "ATH_NORM";
#endif

#if defined(VERSION_US_REV1)
unsigned char g_SAthnormtextTrailingBytes[8] = { 0xAC, 0x43, 0x00, 0x00, 0x26, 0x52, 0x00, 0x01 };
#endif
