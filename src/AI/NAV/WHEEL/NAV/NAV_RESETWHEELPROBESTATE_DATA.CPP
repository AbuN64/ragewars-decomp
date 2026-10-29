#include "include_asm.h"

/* ROM-grounded data: src/navResetWheelProbeStatePoolUsRev1.c */
const float g_Nav_ResetWheelProbeStateConstantWords[2] = {
    1e+02f, 307.2f,
};

#if defined(VERSION_EU_X)
unsigned int k_NavResetwheelprobestateEncodedWordsBlock2[2] = {
    0x00232790, 0x00232790,
};
#endif

#if defined(VERSION_EU)
unsigned int k_NavResetwheelprobestateEncodedWordsBlock1[2] = {
    0x00641023, 0xAEA20010,
};
#endif

#if defined(VERSION_DE)
unsigned int k_NavResetwheelprobestateEncodedWords[2] = {
    0x40490FDB, 0x3FC90FDB,
};
#endif
