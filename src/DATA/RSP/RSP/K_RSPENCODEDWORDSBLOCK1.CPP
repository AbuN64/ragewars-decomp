#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

/* ROM-grounded data: src/g_Menu_BlendLinearConstantWordsSource.c */
const float g_Menu_BlendLinearConstantWords[1] = {
    1.0f,
};

#if defined(VERSION_US)
const char s_RspOSS3equRText[8] =
    "OSS3equR";
#endif

#if defined(VERSION_EU_X)
RestLinkerAlignmentFill8 k_RspEncodedWordsBlock1 = {
    { 0, 67, 20, 172, 0, 67, 20, 72 },
};
#endif

#if defined(VERSION_DE)
RestLinkerAlignmentFill8 k_RspEncodedWords = {
    { 0, 64, 64, 224, 0, 64, 65, 32 },
};
#endif
