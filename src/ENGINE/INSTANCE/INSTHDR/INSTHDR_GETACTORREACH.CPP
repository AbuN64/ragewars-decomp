

/* 8024E914_5.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_InsthdrGetactorreachTrailingBytesAlignmentPad[12] = { 0x08, 0x09, 0x26, 0x6B, 0x00, 0x00, 0x00, 0x00, 0x46, 0x15, 0x00, 0x01 };
#endif

/* 8024E914_9.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_simpleObjectSplitTextEuXAlignmentPad[3] = { 0x248400E8U, 0x02001021U, 0x8FBF0018U };
#endif

/* 8028469C_8.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_InsthdrGetactorreachTrailingBytesBlock1AlignmentPad[4] = { 0x64, 0x00, 0x00, 0x00 };
#endif
