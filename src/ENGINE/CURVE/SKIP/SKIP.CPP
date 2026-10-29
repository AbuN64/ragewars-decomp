

/* 80263760_12.CPP */
#if defined(VERSION_EU)
unsigned char g_SkipTrailingBytes[12] = { 0xAF, 0xA5, 0x00, 0x1C, 0xAF, 0xA6, 0x00, 0x20, 0xAF, 0xA7, 0x00, 0x24 };
#endif

/* 80263760_13.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_80265334_eu_x[3] = { 0x240200CAU, 0x1462002FU, 0x24020001U };
#endif

/* g_SkipEncodedWords_Skip.CPP */
#if defined(VERSION_US)
unsigned int g_SkipEncodedWords[3] = {
    0x00000E6D, 0x5F72704F, 0x626A6563,
};
#endif
