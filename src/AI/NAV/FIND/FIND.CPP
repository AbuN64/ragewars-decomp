#include "include_asm.h"

/* 80208000_25.CPP */
/* 80208000_25.CPP */
#if defined(VERSION_US)
char s_FindOshEdgeTCSText[12] =
    "oshEdge_t\013CS";
#endif

/* 80208000_27.CPP */
#if defined(VERSION_EU)
unsigned int k_FindEncodedWordsBlock1[3] = {
    0x00000000, 0x0007000D, 0x2401FFFF,
};
#endif

/* 80208000_26.CPP */
#if defined(VERSION_DE)
unsigned int k_FindEncodedWords[3] = {
    0x3F800000, 0x3F800000, 0x0C0AC91C,
};
#endif

/* 800C6E94.CPP */
#if defined(VERSION_US_REV1)
float g_FindEncodedWords[3] = {
    1.024f, -1.024f, 2.0f,
};
#endif
