#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char k_PolycolEncodedBytes[8] =
    "\077333\077333";
#endif

#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_PolycolEncodedWordsBlock1AlignmentPad[1] = {
    0x73520000,
};
#endif

#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_PolycolEncodedWordsBlock3AlignmentPad[1] = {
    0x4F000000,
};
#endif

#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_PolycolEncodedWordsBlock2AlignmentPad[1] = {
    0x50400027,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/k_PolycolEncodedWords_Polycol.c */
const float k_PolycolEncodedWords[2] = {
    0.7f, 0.7f,
};
#endif
