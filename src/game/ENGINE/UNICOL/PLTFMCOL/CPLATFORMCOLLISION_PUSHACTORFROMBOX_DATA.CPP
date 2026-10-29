#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int k_CplatformcollisionPushactorfromboxEncodedWords[3] = {
    0x3ED1B717, 0x3ED1B717, 0x3ED1B717,
};
#endif

#if defined(VERSION_US)
char s_CplatformcollisionPushactorfromboxDwCheaText[12] =
    "\000\000\000\025m_dwChea";
#endif

#if defined(VERSION_EU_X)
unsigned int k_CplatformcollisionPushactorfromboxEncodedWordsBlock5[3] = {
    0x4F000000, 0x47800000, 0x4F000000,
};
#endif

#if defined(VERSION_DE)
unsigned int k_CplatformcollisionPushactorfromboxEncodedWordsBlock4[3] = {
    0x3F333333, 0x3F333333, 0x2490FFFF,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80241BAC_C9448_us_rev1.c */
const unsigned int k_CplatformcollisionPushactorfromboxEncodedWordsBlock3[1] = {
    0x3ED1B717,
};

/* ROM-grounded data: src/rw_pool_80241F24_C944C_us_rev1.c */
const unsigned int k_CplatformcollisionPushactorfromboxEncodedWordsBlock2[1] = {
    0x3ED1B717,
};

/* ROM-grounded data: src/rw_pool_802426CC_C9450_us_rev1.c */
const unsigned int k_CplatformcollisionPushactorfromboxEncodedWordsBlock1[1] = {
    0x3ED1B717,
};
#endif
