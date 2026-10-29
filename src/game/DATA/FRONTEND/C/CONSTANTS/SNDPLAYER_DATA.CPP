#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

/* ROM-grounded data: src/rw_pool_802B2CF0_CD3B0_us_rev1.c */
const unsigned int k_SndplayerEncodedWordsBlock1[2] = {
    0x41DFFFFF, 0xFFC00000,
};

#if defined(VERSION_US)
char s_SndplayerTOptiText[8] =
    "t\011m_Opti";
#endif

#if defined(VERSION_EU)
unsigned int k_SndplayerEncodedWordsBlock4[2] = {
    0x00230180, 0x00230180,
};
#endif

#if defined(VERSION_DE)
char s_SndplayerOSyntheText[8] =
    "o/synthe";
#endif
