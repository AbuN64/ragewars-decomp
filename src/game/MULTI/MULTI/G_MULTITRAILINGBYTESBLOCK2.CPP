

/* 8042FBEC_17.CPP */
#if defined(VERSION_EU)
unsigned char g_MultiTrailingBytesBlock2[12] = { 0xAF, 0xAD, 0x00, 0x20, 0xAF, 0xAA, 0x00, 0x24, 0xAF, 0xAB, 0x00, 0x28 };
#endif

/* g_MultiLegacySplitWord.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802B061C_eu_x[1] = { 0x24160002U };
#endif
