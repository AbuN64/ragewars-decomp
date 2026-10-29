

/* 802C0390_13.CPP */
#if defined(VERSION_EU)
unsigned char g_SeteventmesgTrailingBytesBlock1[4] = { 0x45, 0x02, 0x00, 0x02 };
#endif

/* SeteventmesgLinkGapWords.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_seteventmesgLinkGapWords[1] = { 0x00001021U };
#endif
