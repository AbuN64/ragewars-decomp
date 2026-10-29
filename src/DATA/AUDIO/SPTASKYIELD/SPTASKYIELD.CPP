

/* 802BE040_49.CPP */
#if defined(VERSION_EU)
unsigned char g_SptaskyieldTrailingBytesBlock1[4] = { 0x10, 0x80, 0x00, 0x09 };
#endif

/* SPTASKYIELD_RETAINED_INSTRUCTION_WORDS.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802B31D8_eu_x[2] = { 0x00471021U, 0xAC460000U };
#endif
