

/* 802B7058_35.CPP */
#if defined(VERSION_EU)
unsigned char g_AudioLinkGapWordsBfd74TrailingBytesBlock2[8] = { 0x88, 0xAA, 0x00, 0x0C, 0x98, 0xAA, 0x00, 0x0F };
#endif

/* 802BE040_27.CPP */
#if defined(VERSION_US)
unsigned char g_AudioLinkGapWordsBfd74TrailingBytes[8] = { 0x52, 0x00, 0x00, 0xD0, 0x06, 0x00, 0x00, 0x08 };
#endif

/* 802BE040_54.CPP */
#if defined(VERSION_EU_X)
unsigned char g_AudioLinkGapWordsBfd74TrailingBytesBlock1[4] = { 0x14, 0x61, 0x00, 0x04 };
#endif

/* 802BFD80_21.CPP */
#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_audioLinkGapWordsBlock3[3] = { 0x275A0E60U, 0xFF410020U, 0x401B6000U };
#endif
