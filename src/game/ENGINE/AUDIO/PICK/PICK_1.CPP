#include "include_asm.h"

/* 8025C544_8.CPP */
#if defined(VERSION_EU)
unsigned char g_PickTrailingBytes[8] = { 0x3C, 0x01, 0x80, 0x0C, 0xC4, 0x21, 0x41, 0x90 };
#endif

/* 8025DE50_4.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_8025DE1C_eu_x[1] = { 0x468010A0U };
#endif

/* 802ABDBC.CPP */
#if defined(VERSION_US)
unsigned int k_PickEncodedWords[1] = {
    0x72496E74,
};
#endif
