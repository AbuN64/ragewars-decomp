

/* 802B3128_16.CPP */
#if defined(VERSION_EU)
unsigned char g_SynsetfxTrailingBytesBlock2[8] = { 0xA2, 0x50, 0x00, 0x08, 0xA2, 0x42, 0x00, 0x09 };
#endif

/* 802B7058_3.CPP */
#if defined(VERSION_US)
unsigned char g_SynsetfxTrailingBytesBlock3[4] = { 0x90, 0x00, 0x00, 0x00 };
#endif

/* 802B7488.CPP */
#if defined(VERSION_EU_X)
unsigned char g_SynsetfxTrailingBytesBlock5[4] = { 0x02, 0x00, 0x28, 0x21 };
#endif

/* 802B7488_12.CPP */
#if defined(VERSION_US_REV1)
unsigned char g_SynsetfxTrailingBytesBlock4[8] = { 0x24, 0x06, 0x00, 0x01, 0x12, 0x80, 0x00, 0x07 };
#endif
