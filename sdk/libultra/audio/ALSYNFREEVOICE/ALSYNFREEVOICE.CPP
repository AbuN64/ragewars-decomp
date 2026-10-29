#include "include_asm.h"

/* 802B3128_12.CPP */
#if defined(VERSION_DE)
unsigned char g_AlsynfreevoiceTrailingBytes[4] = { 0xAF, 0xB1, 0x00, 0x14 };
#endif

/* 802B3128_18.CPP */
/* 802B3128_18.CPP */
#if defined(VERSION_EU)
unsigned char g_AlsynfreevoiceTrailingBytesBlock1[4] = { 0xAF, 0xB7, 0x01, 0x34 };
#endif

/* 802B7058_31.CPP */
#if defined(VERSION_US)
unsigned char g_AlsynfreevoiceTrailingBytesBlock3[4] = { 0x09, 0x6D, 0x5F, 0x72 };
#endif

/* 802B7488_5.CPP */
#if defined(VERSION_EU_X)
unsigned char g_AlsynfreevoiceTrailingBytesBlock2[8] = { 0x24, 0x06, 0x00, 0x01, 0x12, 0x80, 0x00, 0x07 };
#endif

/* 802BA5F0_27.CPP */
#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802BF954_us_rev1[3] = { 0x3C02A500U, 0x3C03A460U, 0x34630010U };
#endif
