#include "include_asm.h"

/* 800E2320.CPP */
#if defined(VERSION_US)
const char s_CmenuprofileFormatprofilequantitylabelEquEosRText[12] =
    "equ\004.eosR\000\000\000";
#endif
#if defined(VERSION_DE)
const unsigned int g_profileQuantityThreeColumnFormatWords[3] = {
    0x00000000, 0x25336400, 0x00000000,
};
#endif

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8043E2D8_E2F20_us_rev1.c */
const unsigned char g_profileQuantityTwoDigitFormat[5] = {
    0x25, 0x30, 0x32, 0x64, 0x00,
};
#endif

/* 800E9AF4.CPP */
