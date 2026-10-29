#include "include_asm.h"

/* ROM-grounded data: src/g_trackOpacityStepWords_TrackEvaluatetrackopacityData.c */
const unsigned int g_trackOpacityStepWords[1] = {
    0x3E4CCCCD,
};

#if defined(VERSION_US)
unsigned int k_TrackEvaluatetrackopacityEncodedWords[1] = {
    0x00006600,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_TrackEvaluatetrackopacityEncodedWordsBlock2[1] = {
    0x00000006,
};
#endif

#if defined(VERSION_EU)
unsigned int k_TrackEvaluatetrackopacityEncodedWordsBlock3[1] = {
    0xEAE20B09,
};
#endif

#if defined(VERSION_DE)
unsigned int k_TrackEvaluatetrackopacityEncodedWordsBlock1[1] = {
    0x007E7E7E,
};
#endif
