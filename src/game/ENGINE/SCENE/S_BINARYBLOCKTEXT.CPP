#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char s_binaryBlockText[13] =
    "binary block\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/k_SBinaryblocktextEncodedBytesSource.c */
const unsigned char k_SBinaryblocktextEncodedBytes[13] = {
    0x62, 0x69, 0x6E, 0x61, 0x72, 0x79, 0x20, 0x62, 0x6C, 0x6F, 0x63, 0x6B, 0x00,
};
#endif
