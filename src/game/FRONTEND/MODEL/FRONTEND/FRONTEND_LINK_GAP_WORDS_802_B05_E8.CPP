

/* 8042FBEC_11.CPP */
#if defined(VERSION_EU)
unsigned char g_FrontendLinkGapWordsB05E8TrailingBytes[4] = { 0x30, 0x82, 0x00, 0xFF };
#endif

/* DATA_802B53D8.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
#if defined(VERSION_EU_X)
unsigned int g_frontendLinkGapWordsBlock1[2] = { 0x080AC5F3U, 0xA0500008U };
#elif defined(VERSION_US_REV1)
unsigned int g_frontendLinkGapWordsBlock1[2] = { 0x080AD96FU, 0xA0500008U };
#endif
#endif
