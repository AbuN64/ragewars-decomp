#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const float k_CcollisionTestsegmentdiskEncodedWords[3] = {
    10.24f, 10.24f, 10.24f,
};
#endif

#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_CcollisionTestsegmentdiskEncodedWordsBlock4AlignmentPad[1] = {
    0x6C617965,
};
#endif

#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_CcollisionTestsegmentdiskEncodedWordsBlock5AlignmentPad[1] = {
    0x3A83126F,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/k_CcollisionTestsegmentdiskEncodedWordsBlock1_CcollisionTestsegmentdiskData.c */
const float k_CcollisionTestsegmentdiskEncodedWordsBlock1[1] = {
    10.24f,
};

/* ROM-grounded data: src/k_CcollisionTestsegmentdiskEncodedWordsBlock2_CcollisionTestsegmentdiskData.c */
const float k_CcollisionTestsegmentdiskEncodedWordsBlock2[1] = {
    10.24f,
};

/* ROM-grounded data: src/k_CcollisionTestsegmentdiskEncodedWordsBlock3_CcollisionTestsegmentdiskData.c */
const float k_CcollisionTestsegmentdiskEncodedWordsBlock3[1] = {
    10.24f,
};
#endif
