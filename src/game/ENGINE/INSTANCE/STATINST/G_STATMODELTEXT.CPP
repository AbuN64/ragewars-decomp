#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char g_statModelText[11] =
    "stat model\000";
#endif

#if defined(VERSION_US)
unsigned char k_GStatmodeltextEncodedBytes[1] = {
    0x65,
};
#endif

#if defined(VERSION_DE)
unsigned char k_GStatmodeltextEncodedBytesBlock1[1] = {
    0x21,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_802507AC_C9B84_us_rev1.c */
const unsigned char s_statModelText[11] = {
    0x73, 0x74, 0x61, 0x74, 0x20, 0x6D, 0x6F, 0x64, 0x65, 0x6C, 0x00,
};
#endif
