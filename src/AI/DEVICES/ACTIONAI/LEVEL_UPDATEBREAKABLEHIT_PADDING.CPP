

/* 8020402C_2.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_80204808_de_padding_5468 */
unsigned int g_levelUpdatebreakablehitPaddingFloatConstantWords[2] = {
    0x00000000, 0x3C048014,
};
#endif

#if defined(VERSION_EU_X)
/* Alignment padding before the breakable hit callback. */
unsigned int Level_UpdateBreakableHit_padding_eu_x[1] = { 0x3C048015 };
#endif

/* 80207ABC_2.CPP */
#if defined(VERSION_US)
unsigned char g_LevelUpdatebreakablehitPaddingTrailingBytes[8] = { 0x00, 0x00, 0x08, 0x00, 0x04, 0x00, 0x00, 0x00 };
#endif

/* 80207ABC_5.CPP */
#if defined(VERSION_EU)
unsigned char g_LevelUpdatebreakablehitPaddingTrailingBytesBlock1[8] = { 0xC6, 0x74, 0x00, 0x64, 0x46, 0x01, 0x10, 0x32 };
#endif
