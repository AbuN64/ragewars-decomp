#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int k_CbarrelUpdatetrackeraimEncodedWords[4] = {
    0x424CCCCC, 0x424CCCCC, 0x40490FDB, 0x7F7FFFFF,
};
#endif

#if defined(VERSION_US_REV1)
const float k_CbarrelUpdatetrackeraimEncodedWordsBlock1[3] = {
    51.199997f, 51.199997f, 3.1415927f,
};

/* ROM-grounded data: src/k_CbarrelUpdatetrackeraimMaxFiniteFloatWords_CbarrelUpdatetrackeraimData.c */
const unsigned int k_CbarrelUpdatetrackeraimMaxFiniteFloatWords[1] = {
    0x7F7FFFFF,
};
#endif
