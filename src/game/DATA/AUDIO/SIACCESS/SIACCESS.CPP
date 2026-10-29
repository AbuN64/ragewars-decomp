#include "include_asm.h"

/* 802BE040_29.CPP */
#if defined(VERSION_EU)
unsigned char g_SiaccessTrailingBytesBlock2[8] = { 0xAF, 0xBF, 0x00, 0x30, 0xAF, 0xB0, 0x00, 0x18 };
#endif

/* DATA_802B5458.CPP */
#if defined(VERSION_EU_X)
unsigned char g_SiaccessTrailingBytes[12] = { 0x8C, 0x44, 0x00, 0x0C, 0x8C, 0x82, 0x00, 0x08, 0x00, 0x40, 0xF8, 0x09 };
#endif

/* DATA_802B5494.CPP */
#if defined(VERSION_US)
char func_802B03C4_de_padding_B6094[12] =
    "m_nFramesRnd";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_802B03C4_de_padding_B6094 */
unsigned int g_SiaccessEncodedWords[3] = {
    0x00431021, 0xA050000A, 0x8E510064,
};
#endif
