#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

/* ROM-grounded data: src/g_Actionai_DrawFadedActorConstantWords_ActionDrawfadedactorData.c */
const float g_Actionai_DrawFadedActorConstantWords[2] = {
    8.5f, 255.0f,
};

#if defined(VERSION_US)
RestLinkerAlignmentFill4 k_ActionDrawfadedactorEncodedWords = {
    { 0, 8, 0, 32 },
};
#endif

#if defined(VERSION_EU_X)
RestLinkerAlignmentFill4 k_ActionDrawfadedactorEncodedWordsBlock3 = {
    { 60, 142, 250, 54 },
};
#endif

#if defined(VERSION_EU)
RestLinkerAlignmentFill4 k_ActionDrawfadedactorEncodedWordsBlock2 = {
    { 60, 2, 2, 0 },
};
#endif

#if defined(VERSION_DE)
RestLinkerAlignmentFill4 k_ActionDrawfadedactorEncodedWordsBlock1 = {
    { 0, 3, 16, 128 },
};
#endif
