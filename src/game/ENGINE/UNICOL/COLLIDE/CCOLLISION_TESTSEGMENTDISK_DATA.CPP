#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int k_CcollisionTestsegmentdiskEncodedWords[3] = {
    0x4123D70A, 0x4123D70A, 0x4123D70A,
};
#endif

#if defined(VERSION_US)
unsigned int k_CcollisionTestsegmentdiskEncodedWordsBlock4[1] = {
    0x6C617965,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_CcollisionTestsegmentdiskEncodedWordsBlock5[1] = {
    0x3A83126F,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/k_CcollisionTestsegmentdiskEncodedWordsBlock1_CcollisionTestsegmentdiskData.c */
const unsigned int k_CcollisionTestsegmentdiskEncodedWordsBlock1[1] = {
    0x4123D70A,
};

/* ROM-grounded data: src/k_CcollisionTestsegmentdiskEncodedWordsBlock2_CcollisionTestsegmentdiskData.c */
const unsigned int k_CcollisionTestsegmentdiskEncodedWordsBlock2[1] = {
    0x4123D70A,
};

/* ROM-grounded data: src/k_CcollisionTestsegmentdiskEncodedWordsBlock3_CcollisionTestsegmentdiskData.c */
const unsigned int k_CcollisionTestsegmentdiskEncodedWordsBlock3[1] = {
    0x4123D70A,
};
#endif
