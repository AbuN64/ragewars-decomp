#include "include_asm.h"

/* ROM-grounded data: src/ALCSEQSECTOTICKS_ENCODED_WORDS_US_REV1.c */
const unsigned int k_AlcseqsectoticksEncodedWords[3] = {
    0x41F00000, 0x00000000, 0x4F000000,
};

#if defined(VERSION_US)
unsigned int k_AlcseqsectoticksEncodedWordsBlock1[3] = {
    0x40010000, 0x00000C43, 0x4672616D,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_AlcseqsectoticksEncodedWordsBlock3[3] = {
    0x002791AC, 0x002791EC, 0x002790F0,
};
#endif

#if defined(VERSION_EU)
unsigned int k_AlcseqsectoticksEncodedWordsBlock2[3] = {
    0x00229ED8, 0x00229EE0, 0x00229EE8,
};
#endif

#if defined(VERSION_DE)
char s_AlcseqsectoticksAudioCsplayText[12] =
    "audio/csplay";
#endif
