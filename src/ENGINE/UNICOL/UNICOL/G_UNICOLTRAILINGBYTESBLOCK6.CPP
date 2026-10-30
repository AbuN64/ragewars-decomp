

/* 802412C0_4.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_UnicolTrailingBytesBlock6AlignmentPad[4] = { 0xAF, 0xB1, 0x00, 0x24 };
#endif

/* 802412C0_9.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_GUnicoltrailingbytesblock6ObjectAlignmentPadEuX1[2] = { 0xAE00001CU, 0x8FA2021CU };
#endif

/* 80275E44_7.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_UnicolTrailingBytesBlock12AlignmentPad[12] = { 0x00, 0x00, 0x96, 0x0D, 0x00, 0x08, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00 };
#endif
