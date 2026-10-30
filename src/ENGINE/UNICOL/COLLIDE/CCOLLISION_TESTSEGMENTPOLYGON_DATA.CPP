#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800D0648 */
const float k_CcollisionTestsegmentpolygonEncodedWords[1] = {
    0.1f,
};

#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_CcollisionTestsegmentpolygonEncodedWordsBlock1AlignmentPad[1] = {
    0x0000000F,
};
#endif

#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_CcollisionTestsegmentpolygonEncodedWordsBlock3AlignmentPad[1] = {
    0x3FC78F78,
};
#endif

#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_CcollisionTestsegmentpolygonEncodedWordsBlock2AlignmentPad[1] = {
    0x44415649,
};
#endif
