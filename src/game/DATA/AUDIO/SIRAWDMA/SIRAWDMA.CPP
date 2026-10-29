

/* 802BE040_34.CPP */
#if defined(VERSION_EU)
unsigned char g_SirawdmaTrailingBytesBlock1[8] = { 0x00, 0x03, 0x1C, 0x00, 0x24, 0x42, 0x08, 0x00 };
#endif

/* DATA_802B7698.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_siRawDmaSplitTextEuX[2] = { 0x8FB00010U, 0x03E00008U };
#endif
