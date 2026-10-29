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
/* ROM-grounded data: src/s_statModelText_GStatmodeltext.c */
const char s_statModelText[11] =
    "stat model";
#endif
