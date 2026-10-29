#include "sdk/libgultra.h"
#include "include_asm.h"

/* 800CD394_9.CPP */

/* 800CCD60.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int g_printfLengthModifierWordsLegacy[1] = {
    0x686C4C00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/g_printfLengthModifierCharactersUsRev1_LibcFormattocallbackData.c */
const unsigned char g_printfLengthModifierCharactersUsRev1[4] = {
    0x68, 0x6C, 0x4C, 0x00,
};
#endif
