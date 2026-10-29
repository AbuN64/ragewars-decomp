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
/* ROM-grounded data: src/rw_pool_8023E8D4_C93C0_us_rev1.c */
const unsigned int k_CcollisionTestsegmentdiskEncodedWordsBlock1[1] = {
    0x4123D70A,
};

/* ROM-grounded data: src/rw_pool_8023EA44_C93C4_us_rev1.c */
const unsigned int k_CcollisionTestsegmentdiskEncodedWordsBlock2[1] = {
    0x4123D70A,
};

/* ROM-grounded data: src/rw_pool_8023ED64_C93C8_us_rev1.c */
const unsigned int k_CcollisionTestsegmentdiskEncodedWordsBlock3[1] = {
    0x4123D70A,
};
#endif
