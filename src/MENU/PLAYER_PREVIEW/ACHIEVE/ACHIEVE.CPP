#include "include_asm.h"

/* g_resultPreviewNumberFormatUs.CPP */
#if defined(VERSION_US)
const unsigned char g_resultPreviewNumberFormatUs[3] = {
    0x25, 0x64, 0x00,
};
#endif

/* 804379C8_4.CPP */
/* 804379C8_4.CPP */
#if defined(VERSION_US_REV1)
unsigned char g_AchieveTrailingBytes[4] = { 0x24, 0x05, 0x00, 0x04 };
#endif


/* 8042E080_19.CPP */

#if defined(VERSION_EU_X)
const unsigned char g_resultPreviewNumberFormatEuX[3] = {
    0x25, 0x64, 0x00,
};
#endif

/* 800E1F40.CPP */
#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* ROM-grounded data: src/k_AchieveEncodedWordsBlock1_Achieve.c */
const unsigned int k_AchieveEncodedWordsBlock1[1] = {
    0x3D888889,
};
#endif

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
const unsigned char k_AchieveEncodedBytes[3] = {
    0x25, 0x64, 0x00,
};
#endif

/* 8042E080_20.CPP */

#if defined(VERSION_EU)
const unsigned char g_resultPreviewNumberFormatEu[3] = {
    0x25, 0x64, 0x00,
};
#endif
