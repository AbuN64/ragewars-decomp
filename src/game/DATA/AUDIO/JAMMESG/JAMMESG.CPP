

/* 802C0390_8.CPP */
#if defined(VERSION_EU)
unsigned char g_JammesgTrailingBytesBlock1[12] = { 0x00, 0xA6, 0x28, 0x25, 0xAF, 0xBF, 0x00, 0x1C, 0xAF, 0xB1, 0x00, 0x14 };
#endif

/* g_jammesgSeparatedDataWord.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802B7F0C_eu_x[1] = { 0x8FB00038U };
#endif
