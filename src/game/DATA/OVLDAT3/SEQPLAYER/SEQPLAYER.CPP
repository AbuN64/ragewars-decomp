#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

#if !(defined(VERSION_US_REV1))
const unsigned int g_seqplayer_HandleSequenceMidiEventConstantWords[5] = {
    0x42FE0000, 0x4F000000, 0x3F800000, 0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_US)
unsigned int k_SeqplayerEncodedWordsBlock1[3] = {
    0x74656D54, 0x00008855, 0x02000800,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_SeqplayerEncodedWordsBlock2[3] = {
    0x002056F0, 0x0027924C, 0x00000000,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int k_SeqplayerEncodedWords[3] = {
    0x42FE0000, 0x4F000000, 0x3F800000,
};

/* ROM-grounded data: src/rw_pool_802B1990_CD31C_us_rev1.c */
const unsigned int g___initChanStateConstantWords[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_802B1A40_CD320_us_rev1.c */
const unsigned int g___resetPerfChanStateConstantWords[1] = {
    0x3F800000,
};
#endif
