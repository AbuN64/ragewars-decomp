

/* 802B7488_10.CPP */
#if defined(VERSION_EU)
unsigned char g_ControllerTrailingBytesBlock1[4] = { 0x02, 0x00, 0x28, 0x21 };
#endif

/* 802BE040_73.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802BA46C_eu_x[1] = { 0xAFB10014U };
#endif

/* g_ControllerEncodedWords.CPP */
#if defined(VERSION_US)
unsigned int g_ControllerEncodedWords[3] = {
    0x005C0800, 0x00080004, 0x00000000,
};
#endif
