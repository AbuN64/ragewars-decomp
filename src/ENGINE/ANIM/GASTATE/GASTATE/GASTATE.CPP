

/* 802624A0_4.CPP */
/* 802624A0_4.CPP */
#if defined(VERSION_EU)
unsigned char g_GastateTrailingBytes[12] = { 0x0C, 0x0A, 0xC0, 0x80, 0x00, 0x05, 0x2C, 0x03, 0xE6, 0x34, 0x00, 0x2C };
#endif

/* 802624A0_5.CPP */
#if defined(VERSION_EU_X)
unsigned char g_GastateTrailingBytesBlock1[12] = { 0x08, 0x09, 0x8E, 0xB2, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x04, 0x80, 0x11 };
#endif

/* 80263760_4.CPP */
#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_80263754_us_rev1[3] = { 0x9022F308U, 0x10400003U, 0x24630001U };
#endif

/* g_GastateEncodedWords_Gastate.CPP */
#if defined(VERSION_US)
unsigned int g_GastateEncodedWords[3] = {
    0x0000076D, 0x5F6E5061, 0x74682800,
};
#endif

/* 802624A0_6.CPP */
#if defined(VERSION_DE)
unsigned char g_GastateTrailingBytesBlock2[12] = { 0xAF, 0xBE, 0x00, 0xB8, 0x00, 0x80, 0xF0, 0x21, 0xAF, 0xB4, 0x00, 0xA8 };
#endif
