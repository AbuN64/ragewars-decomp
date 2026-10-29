#include "include_asm.h"

/* ROM-grounded data: src/rw_pool_802110C4_C7CF0_us_rev1.c */
const unsigned int g_Nav_ResetWheelProbeStateConstantWords[2] = {
    0x42C80000, 0x4399999A,
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
