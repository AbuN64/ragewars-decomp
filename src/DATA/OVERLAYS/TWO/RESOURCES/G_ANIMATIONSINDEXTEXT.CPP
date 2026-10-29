#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char k_GAnimationsindextextEncodedBytes[33] =
    "\077\200\000\000>\000\000\000=\031\231\232\077\200\000\000animations index\000";
#endif

#if defined(VERSION_US_REV1)
const unsigned int k_GAnimationsindextextEncodedWords[4] = {
    0x3F800000, 0x3E000000, 0x3D19999A, 0x3F800000,
};

const char g_animationsIndexText[17] =
    "animations index";
#endif
