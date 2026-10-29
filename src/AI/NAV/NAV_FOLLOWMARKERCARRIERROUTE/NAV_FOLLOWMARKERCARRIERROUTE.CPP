#include "include_asm.h"

/* 80212C90_2.CPP */
#if defined(VERSION_US)
char s_shotgunText[8] =
    "SHOTGUN_";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: s_shotgunText */
unsigned int g_NavFollowmarkercarrierrouteEncodedWords[2] = {
    0xAFAA0030, 0x0C0939B2,
};
#endif

/* 80212C90_20.CPP */
#if defined(VERSION_EU_X)
unsigned char g_NavFollowmarkercarrierrouteTrailingBytes[8] = { 0x02, 0x60, 0x20, 0x21, 0x10, 0x40, 0x00, 0x1D };
#endif

/* 80217388_17.CPP */
#if defined(VERSION_EU)
unsigned char g_NavFollowmarkercarrierrouteTrailingBytesBlock1[12] = { 0xAE, 0x40, 0x00, 0x24, 0x82, 0x22, 0x00, 0x34, 0x00, 0x53, 0x10, 0x26 };
#endif
