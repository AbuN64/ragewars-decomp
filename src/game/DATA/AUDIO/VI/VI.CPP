

/* 802BFD80_10.CPP */
#if defined(VERSION_EU)
unsigned char g_ViTrailingBytesBlock1[4] = { 0x8C, 0x83, 0x00, 0x20 };
#endif

/* g_ViWords1_Vi.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_ViWords1[1] = { 0x24050007U };
#endif
