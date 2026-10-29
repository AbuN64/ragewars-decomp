

/* 802BA5F0_15.CPP */
#if defined(VERSION_EU)
unsigned char g_VisetmodeTrailingBytesBlock5[12] = { 0x00, 0x00, 0xB0, 0x21, 0xAF, 0xB1, 0x00, 0x10, 0x8C, 0x82, 0x00, 0x04 };
#endif

/* 802BFD80_20.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_visetmodeLinkGapWords[2] = { 0x8FBF0014U, 0x8FB00010U };
#endif
