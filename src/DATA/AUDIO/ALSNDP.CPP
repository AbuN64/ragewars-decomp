

/* 802B2D5C_13.CPP */
#if defined(VERSION_EU)
unsigned char g_AlsndpTrailingBytesBlock1[4] = { 0x31, 0xEF, 0x00, 0x01 };
#endif

/* 802B3128_4.CPP */
#if defined(VERSION_US)
unsigned char g_AlsndpTrailingBytesBlock2[8] = { 0x61, 0x6D, 0x65, 0x4F, 0x62, 0x6A, 0x65, 0x63 };
#endif

/* 802B63E4_5.CPP */
#if defined(VERSION_EU_X)
unsigned char g_AlsndpTrailingBytesBlock3[8] = { 0x30, 0xE2, 0x00, 0xFF, 0x2C, 0x42, 0x00, 0x11 };
#endif

/* 802B7058_15.CPP */
#if defined(VERSION_US_REV1)
unsigned char g_AlsndpTrailingBytesBlock4[8] = { 0x08, 0x0A, 0xF5, 0x58, 0x24, 0x02, 0x00, 0x0B };
#endif
