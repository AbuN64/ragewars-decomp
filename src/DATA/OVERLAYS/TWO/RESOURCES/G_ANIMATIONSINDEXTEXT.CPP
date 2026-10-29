#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char k_GAnimationsindextextEncodedBytes[33] =
    "\077\200\000\000>\000\000\000=\031\231\232\077\200\000\000animations index\000";
#endif

#if defined(VERSION_US_REV1)
const unsigned int k_GAnimationsindextextEncodedWords[4] = {
    0x3F800000, 0x3E000000, 0x3D19999A, 0x3F800000,
};

const unsigned char g_animationsIndexText[17] = {
    0x61, 0x6E, 0x69, 0x6D, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x73, 0x20, 0x69, 0x6E, 0x64, 0x65, 0x78,
    0x00,
};
#endif
