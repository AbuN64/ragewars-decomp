#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const float k_CcollisionIntersectfrontplanefractionEncodedWords[3] = {
    1.0f, 1.0f, 1.0f,
};
#endif

#if defined(VERSION_US)
char s_CcollisionIntersectfrontplanefractionDwChText[8] =
    "\000\016m_dwCh";
#endif

#if defined(VERSION_EU_X)
unsigned int k_CcollisionIntersectfrontplanefractionEncodedWordsBlock3[2] = {
    0x47800000, 0x4F000000,
};
#endif

#if defined(VERSION_EU)
unsigned int k_CcollisionIntersectfrontplanefractionEncodedWordsBlock2[2] = {
    0x8E420028, 0x8E440044,
};
#endif

#if defined(VERSION_DE)
float k_CcollisionIntersectfrontplanefractionEncodedWordsBlock1[2] = {
    0.4096f, 0.4096f,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/ccollisionIntersectfrontplanefractionOneWordsVariant2UsRev1.c */
const unsigned int k_CcollisionIntersectfrontplanefractionOneWordsVariant2[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/ccollisionIntersectfrontplanefractionOneWordsUsRev1.c */
const unsigned int k_CcollisionIntersectfrontplanefractionOneWords[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/ccollisionIntersectfrontplanefractionOneWordsVariant1UsRev1.c */
const unsigned int k_CcollisionIntersectfrontplanefractionOneWordsVariant1[1] = {
    0x3F800000,
};
#endif
