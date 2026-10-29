#include "include_asm.h"

/* ROM-grounded data: src/g_Menu_BlendLinearConstantWordsSource.c */
const unsigned int g_Menu_BlendLinearConstantWords[1] = {
    0x3F800000,
};

#if defined(VERSION_US)
const char s_RspOSS3equRText[8] =
    "OSS3equR";
#endif

#if defined(VERSION_EU_X)
unsigned int k_RspEncodedWordsBlock1[2] = {
    0x004314AC, 0x00431448,
};
#endif

#if defined(VERSION_DE)
unsigned int k_RspEncodedWords[2] = {
    0x004040E0, 0x00404120,
};
#endif
