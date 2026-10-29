

/* 802BE040_53.CPP */
#if defined(VERSION_EU)
unsigned char g_ViblackTrailingBytesBlock4[4] = { 0xAC, 0x86, 0x00, 0x3C };
#endif

/* DATA_802B82C8.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
#if defined(VERSION_EU_X)
unsigned int g_viblackLinkGapWords[2] = { 0xE601001CU, 0x0C0AC188U };
#elif defined(VERSION_US_REV1)
unsigned int g_viblackLinkGapWords[2] = { 0xE601001CU, 0x0C0AD504U };
#endif
#endif
