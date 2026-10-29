

/* 802C0390_5.CPP */
#if defined(VERSION_EU)
unsigned char g_AudioLinkGapWordsB7E6CTrailingBytes[4] = { 0x32, 0xC2, 0xFF, 0xFF };
#endif

/* AudioLinkGapWordsBlock1EuXUsRev1.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_audioLinkGapWordsBlock1[1] = { 0xA8870000U };
#endif
