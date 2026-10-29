

/* 802BE040_31.CPP */
#if defined(VERSION_DE)
unsigned char g_SptaskTrailingBytes[8] = { 0x8C, 0x42, 0x00, 0x00, 0x30, 0x42, 0x00, 0x1C };
#endif

/* 802BE040_43.CPP */
/* 802BE040_43.CPP */
#if defined(VERSION_EU)
unsigned char g_SptaskTrailingBytesBlock1[8] = { 0x24, 0x02, 0x7F, 0xFF, 0xA4, 0xA0, 0x00, 0x00 };
#endif

/* SptaskTrailingWordsUnit.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802B2924_eu_x[3] = { 0x00111600U, 0x04420001U, 0x00119823U };
#endif
