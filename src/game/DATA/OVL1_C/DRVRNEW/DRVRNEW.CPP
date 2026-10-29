#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int g_DrvrnewWords1[2] = {
    0x3F100000, 0x00000000,
};

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_US)
const unsigned int k_DrvrnewEncodedWords[2] = {
    0x40D00000, 0x00000000,
};
#endif

#if defined(VERSION_US)
unsigned int k_DrvrnewEncodedWordsBlock1[2] = {
    0xC86D0200, 0x08000C00,
};
#endif

#if defined(VERSION_EU)
unsigned int k_DrvrnewEncodedWordsBlock2[2] = {
    0x3F800000, 0x3FE52EDF,
};
#endif

#if defined(VERSION_DE)
char k_DrvrnewEncodedBytes[8] =
    "o/env.c\000";
#endif
