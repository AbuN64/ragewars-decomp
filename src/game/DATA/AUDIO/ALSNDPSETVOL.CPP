

/* 802B3128_9.CPP */
#if defined(VERSION_EU)
unsigned char g_AlsndpsetvolTrailingBytesBlock1[4] = { 0x20, 0x63, 0x00, 0x01 };
#endif

/* 802B7488_6.CPP */
#if defined(VERSION_US)
unsigned char g_AlsndpsetvolTrailingBytesBlock2[4] = { 0x6D, 0x5F, 0x53, 0x65 };
#endif

/* 802BA5F0_20.CPP */
#if defined(VERSION_EU_X)
unsigned char g_AlsndpsetvolTrailingBytesBlock4[12] = { 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0A, 0xF4, 0x78, 0x00, 0x00, 0x00, 0x00 };
#endif

/* 802BE040_58.CPP */
#if defined(VERSION_US_REV1)
unsigned char g_AlsndpsetvolTrailingBytesBlock3[12] = { 0x14, 0x40, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0A, 0xFD, 0xCC };
#endif
