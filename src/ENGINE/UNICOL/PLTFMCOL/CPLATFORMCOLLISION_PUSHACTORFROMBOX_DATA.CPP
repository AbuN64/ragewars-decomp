#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const float k_CplatformcollisionPushactorfromboxEncodedWords[3] = {
    0.4096f, 0.4096f, 0.4096f,
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
/* ROM-grounded data: src/k_CplatformcollisionPushactorfromboxEncodedWordsBlock3_CplatformcollisionPushactorfromboxData.c */
const unsigned int k_CplatformcollisionPushactorfromboxEncodedWordsBlock3[1] = {
    0x3ED1B717,
};

/* ROM-grounded data: src/k_CplatformcollisionPushactorfromboxEncodedWordsBlock2_CplatformcollisionPushactorfromboxData.c */
const unsigned int k_CplatformcollisionPushactorfromboxEncodedWordsBlock2[1] = {
    0x3ED1B717,
};

/* ROM-grounded data: src/k_CplatformcollisionPushactorfromboxEncodedWordsBlock1_CplatformcollisionPushactorfromboxData.c */
const unsigned int k_CplatformcollisionPushactorfromboxEncodedWordsBlock1[1] = {
    0x3ED1B717,
};
#endif
