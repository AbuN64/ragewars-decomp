#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

/* 800CA040.CPP */
#if defined(VERSION_US_REV1)
const char g_cartridgeIndex[16] = "cartridge index";
#endif

/* 800CA270.CPP */
#if defined(VERSION_US)
const char g_levelNavVisionText[20] =
    "level nav vision\000\000\000\000";
#endif

/* 800CA780.CPP */
#if defined(VERSION_EU_X)
RestplayerEffectLightPatternWordsLayout269 g_playerEffectLightPatternWords = {
    { 1023, 64, -1, -32513, 511, 128, -1, -32513, 1023, 64, 4090, -1, 1023, 64, 0, 255 },
    { 1120, 1120, 1120, 1120, 1120, 1120, 1120, 1120, 1120, 1120, 1120, 1120, 1120, 1120, 1120, 1120, 1120, 1121, 1122, 1123 },
    { 3, 28, -32, 2, 0, 1, 120, 96, 0, 3, 120, 68, 2, 6, 0, 1, 120, 96, 0, 3, 120, -32, 2, 2, 96, 4, 314572, 2, 96, 6, 0, 3, 120, -46, 2, 2, 96, 4, 314572, 2, 96, 6, 0, 1, 190, 96, 0, 3, 190, -32, 2, 2, 96, 4, 314572, 2, 96, 6, 0, 3, 190, -46, 2, 2, 96, 4, 314572, 2, 96, 6, 0, 1, 260, 96, 0, 3, 260, -32, 2, 2, 96, 4, 314572, 2, 96, 6, 0, 3, 260, -46, 2, 2, 96, 4, 314572, 2, 96, 6, 0, 1, 16, 16, 0, 3, 16, 16, 2, 0, 1, 40, 16, 0, 3, -40, 16, 2, 2, 96, 3, 40, 16, 4, 6, 0, 1, -82, 16, 0, 3, -82, 16, 1, 2, 96, 0, 1, -82, 68, 0, 3, -82, 68, 1, 2, 96, 3, -82, 68, 1, 0, 1, -82, 68, 0, 3, -82, 68, 1, 2, 96, 3, -82, 68, 1, 0 },
    { 0.0f, 16.0f, 0.0f, 0.16f, 0.16f, 0.16f, 2.0f, 10.24f, 30.72f, 13.44f, 10.24f, 35.84f, 13.44f, 0.0f, 0.0f, 0.0f, 4.608f },
};
#endif

/* 800CAB6C.CPP */
#if defined(VERSION_EU)
float k_Ovltab2EncodedWords[6] = {
    -132.0f, 64.0f, 64.0f, 24.0f,
    -12.0f, -48.0f,
};
#endif

/* 8044ACCC_11.CPP */
#if defined(VERSION_US_REV1)
const char k_Ovltab2EncodedBytes[13] = "levels index";
#endif
