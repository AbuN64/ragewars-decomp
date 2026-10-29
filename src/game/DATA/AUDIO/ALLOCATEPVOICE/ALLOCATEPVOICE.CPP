

/* 802B3128_15.CPP */
#if defined(VERSION_EU)
unsigned char g_AllocatepvoiceTrailingBytesBlock1[8] = { 0x10, 0x40, 0x00, 0x08, 0x02, 0x20, 0x20, 0x21 };
#endif

/* 802B7058_23.CPP */
#if defined(VERSION_US)
unsigned char g_AllocatepvoiceTrailingBytesBlock3[8] = { 0x00, 0x00, 0x00, 0x08, 0x00, 0x0D, 0x00, 0x00 };
#endif

/* 802B7058_53.CPP */
#if defined(VERSION_US_REV1)
unsigned char g_AllocatepvoiceTrailingBytesBlock4[4] = { 0x0C, 0x0B, 0x14, 0xC8 };
#endif

/* 802B7058_9.CPP */
#if defined(VERSION_EU_X)
unsigned char g_AllocatepvoiceTrailingBytesBlock2[8] = { 0x08, 0x0A, 0xE1, 0xDC, 0x24, 0x02, 0x00, 0x0B };
#endif
