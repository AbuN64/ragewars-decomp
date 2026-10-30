#include "include_asm.h"
#include "TYPES.H"

#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_ContpadEncodedWordsBlock3AlignmentPad[1] = {
    0x0000000B,
};
#endif
