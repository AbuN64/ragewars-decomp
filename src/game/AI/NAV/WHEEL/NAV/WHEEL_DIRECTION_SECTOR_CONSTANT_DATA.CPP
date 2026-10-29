#include "include_asm.h"

const unsigned int g_Wheel_GetDirectionSectorConstantWords[8] = {
    0x3EC90FDB, 0x40C90FDB, 0x40C90FDB, 0x40C5DCA8, 0x3DCCCCCD, 0x3E22F983, 0x41000000, 0x40E00000,
};

#if defined(VERSION_US)
char s_WheelDirectionSectorConstantReSetRText[8] =
    "reSetR\000\000";
#endif

#if defined(VERSION_EU_X)
unsigned int k_WheelDirectionSectorConstantEncodedWordsBlock1[2] = {
    0x00232790, 0x00232788,
};
#endif

#if defined(VERSION_DE)
unsigned int k_WheelDirectionSectorConstantEncodedWords[2] = {
    0x0C0AC91C, 0x02402821,
};
#endif
