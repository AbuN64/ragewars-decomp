

/* 802B7058_14.CPP */
#if defined(VERSION_EU)
unsigned char g_AiTrailingBytes[12] = { 0x3C, 0x03, 0x80, 0x0E, 0x24, 0x63, 0x46, 0xF0, 0xAF, 0xBF, 0x00, 0x10 };
#endif

/* 802BE040_18.CPP */
#if defined(VERSION_US)
unsigned char g_AiTrailingBytesBlock1[8] = { 0x00, 0x00, 0x10, 0x43, 0x50, 0x6C, 0x61, 0x79 };
#endif

/* 802BE040_5.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802B41EC_eu_x[1] = { 0x3C020308U };
#endif
