

/* 8023EEF0_10.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_UnicolTrailingBytesBlock2AlignmentPad[4] = { 0x26, 0x31, 0x00, 0x04 };
#endif

/* 8023EEF0_12.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_GUnicoltrailingbytesblock2ObjectAlignmentPadEuX1[1] = { 0xC4C20000U };
#endif

/* 80259280_6.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_UnicolTrailingBytesBlock10AlignmentPad[4] = { 0x96, 0x0D, 0x00, 0x08 };
#endif
