

/* 802AD544_5.CPP */
#if defined(VERSION_EU)
unsigned char g_MenuTrailingBytesBlock1[8] = { 0x27, 0xBD, 0xFF, 0xD8, 0xAF, 0xBF, 0x00, 0x24 };
#endif

/* g_MenuEncodedWords_Menu4.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_8020402C_us_rev1_padding_4C2C */
unsigned int g_MenuEncodedWords[1] = {
    0x30420400,
};
#endif
#if defined(VERSION_US)
unsigned int g_MenuTrailingBytes[1] = {
    0x00000800,
};
#endif

/* g_MenuTrailingBytesBlock2_Menu4.CPP */
#if defined(VERSION_EU_X)
unsigned char g_MenuTrailingBytesBlock2[8] = { 0x03, 0xE0, 0x00, 0x08, 0x27, 0xBD, 0x00, 0x40 };
#endif
