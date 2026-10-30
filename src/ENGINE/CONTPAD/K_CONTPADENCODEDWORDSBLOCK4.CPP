#include "include_asm.h"
#include "TYPES.H"

#if defined(VERSION_DE) || defined(VERSION_EU)
#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_ContpadEncodedWordsBlock4AlignmentPad[1] = {
    0xC2FE0000,
};
#endif
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_ContpadEncodedWordsBlock4AlignmentPad[1] = {
    0x00542821,
};
#endif
#endif
