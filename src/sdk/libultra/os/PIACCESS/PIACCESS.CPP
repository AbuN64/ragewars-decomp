

/* 802BE040_14.CPP */
#if defined(VERSION_DE)
unsigned char g_PiaccessTrailingBytes[8] = { 0x00, 0x80, 0x80, 0x21, 0xAF, 0xB1, 0x00, 0x14 };
#endif

/* 802BE040_22.CPP */
/* 802BE040_22.CPP */
#if defined(VERSION_EU)
unsigned char g_PiaccessTrailingBytesBlock1[8] = { 0xA6, 0x17, 0x00, 0x1C, 0x86, 0x02, 0x00, 0x1E };
#endif

/* 802C0390_19.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802BB6F8_eu_x[2] = { 0x3C010400U, 0x0361D824U };
#endif
