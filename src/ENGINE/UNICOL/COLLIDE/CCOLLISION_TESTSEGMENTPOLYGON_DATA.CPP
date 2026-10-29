#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800D0648 */
const unsigned int k_CcollisionTestsegmentpolygonEncodedWords[1] = {
    0x3DCCCCCD,
};

#if defined(VERSION_US)
unsigned int k_CcollisionTestsegmentpolygonEncodedWordsBlock1[1] = {
    0x0000000F,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_CcollisionTestsegmentpolygonEncodedWordsBlock3[1] = {
    0x3FC78F78,
};
#endif

#if defined(VERSION_EU)
unsigned int k_CcollisionTestsegmentpolygonEncodedWordsBlock2[1] = {
    0x44415649,
};
#endif
