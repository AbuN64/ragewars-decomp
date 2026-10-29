

/* 802B7058_13.CPP */
#if defined(VERSION_EU)
unsigned char g_AisetfreqTrailingBytesBlock1[8] = { 0x90, 0x62, 0x00, 0x00, 0x24, 0x63, 0x00, 0x01 };
#endif

/* 802BE040_15.CPP */
#if defined(VERSION_US)
unsigned char g_AisetfreqTrailingBytesBlock2[12] = { 0x65, 0x46, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x54, 0x00, 0x00 };
#endif

/* 802BE040_45.CPP */
#if defined(VERSION_EU_X)
unsigned char g_AisetfreqTrailingBytesBlock3[8] = { 0xAC, 0x22, 0x3B, 0x00, 0x3C, 0x01, 0x80, 0x15 };
#endif

/* 802BE040_71.CPP */
#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802BF204_us_rev1[3] = { 0x2484CC50U, 0x3C05800DU, 0x24A5CC54U };
#endif
