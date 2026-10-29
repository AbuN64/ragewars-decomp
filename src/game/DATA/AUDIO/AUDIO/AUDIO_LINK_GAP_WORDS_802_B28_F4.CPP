

/* 802BE040_35.CPP */
#if defined(VERSION_EU)
unsigned char g_AudioLinkGapWordsB28F4TrailingBytes[8] = { 0x86, 0x22, 0x00, 0x18, 0x86, 0x23, 0x00, 0x1A };
#endif

/* DATA_802B76E4.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_audioLinkGapWords[3] = { 0xAFB7002CU, 0x00C0B821U, 0xAFBF0030U };
#endif
