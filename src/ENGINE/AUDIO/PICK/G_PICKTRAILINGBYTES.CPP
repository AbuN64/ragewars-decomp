#include "include_asm.h"

/* 8025C544_8.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_PickTrailingBytesAlignmentPad[8] = { 0x3C, 0x01, 0x80, 0x0C, 0xC4, 0x21, 0x41, 0x90 };
#endif

/* 8025DE50_4.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_GPicktrailingbytesObjectAlignmentPadEuX1[1] = { 0x468010A0U };
#endif

/* 802ABDBC.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_PickEncodedWordsAlignmentPad[1] = {
    0x72496E74,
};
#endif
