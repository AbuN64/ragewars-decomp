#include "include_asm.h"

/* 802BE040_19.CPP */
#if defined(VERSION_EU)
unsigned char g_GamecoreTrailingBytesBlock2[12] = { 0x27, 0xA5, 0x00, 0x18, 0x27, 0xA6, 0x00, 0x1A, 0x8F, 0xA8, 0x00, 0x54 };
#endif

/* 802C0390_18.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Linker alignment fill between osRecvMesg and osResetGlobalIntMask (8 bytes, ends 16-aligned): the first word is a stale
   leftover of an earlier build, the second (k_GamecoreZeroWords) is zero fill. */
unsigned int g_osRecvMesgAlignPad[1] = { 0x445BF800U };
#endif


/* k_GamecoreZeroWords_Gamecore3.CPP */
