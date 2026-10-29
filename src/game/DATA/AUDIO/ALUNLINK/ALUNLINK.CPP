

/* 802B243C_8.CPP */
#if defined(VERSION_EU)
unsigned char g_AlunlinkTrailingBytesBlock1[4] = { 0x8F, 0xB3, 0x00, 0x0C };
#endif

/* 802B2D5C_7.CPP */
#if defined(VERSION_US)
unsigned char g_AlunlinkTrailingBytesBlock2[4] = { 0x08, 0x00, 0x18, 0x00 };
#endif

/* 802B3128_10.CPP */
#if defined(VERSION_EU_X)
unsigned char g_AlunlinkTrailingBytesBlock3[4] = { 0x3C, 0x02, 0x00, 0x2B };
#endif

/* 802B63E4_12.CPP */
#if defined(VERSION_US_REV1)
unsigned char g_AlunlinkTrailingBytesBlock4[8] = { 0x30, 0xE2, 0x00, 0xFF, 0x2C, 0x42, 0x00, 0x11 };
#endif
