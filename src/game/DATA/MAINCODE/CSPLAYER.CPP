#include "include_asm.h"

/* 802AFD5C_3.CPP */
#if defined(VERSION_EU)
unsigned char g_CsplayerTrailingBytesBlock1[4] = { 0x44, 0x07, 0xB8, 0x00 };
#endif

/* s_firePodReaText_Csplayer.CPP */
#if defined(VERSION_US)
char s_firePodReaText[12] =
    "FIRE_POD_REA";
#endif

#if defined(VERSION_US_REV1)
unsigned int g_csplayerLinkGapWords[3] = {
    0x0C09CA6D, 0x24070001, 0x02202021,
};
#endif
