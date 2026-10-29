#include "include_asm.h"

/* 802BFD80_14.CPP */
#if defined(VERSION_EU)
unsigned char g_CreatethreadTrailingBytesBlock1[8] = { 0x03, 0xE0, 0x00, 0x08, 0x27, 0xBD, 0x00, 0x18 };
#endif

/* k_createThreadFuncTextWord.CPP */
#if defined(VERSION_US)
unsigned int func_802B56DC_eu_x_padding_BB0CC[1] = {
    0x46756E63,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_802B56DC_eu_x_padding_BB0CC */
unsigned int g_CreatethreadEncodedWords[1] = {
    0x02002821,
};
#endif

/* g_CreatethreadTrailingBytesBlock2_Createthread.CPP */
#if defined(VERSION_EU_X)
unsigned char g_CreatethreadTrailingBytesBlock2[4] = { 0x0C, 0x0B, 0x01, 0x44 };
#endif
