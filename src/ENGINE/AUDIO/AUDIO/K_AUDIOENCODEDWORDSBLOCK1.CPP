#include "include_asm.h"

#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_AudioEncodedWordsBlock1AlignmentPad[1] = {
    0x447A0000,
};
#endif
