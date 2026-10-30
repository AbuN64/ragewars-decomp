

/* 8024E914_11.CPP */
#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_InstanceTrailingBytesAlignmentPad[12] = { 0xAF, 0xB0, 0x00, 0x60, 0x00, 0xC0, 0x80, 0x21, 0xAF, 0xB3, 0x00, 0x6C };
#endif

/* 8024E914_12.CPP */
/* 8024E914_12.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_InstanceTrailingBytesBlock1AlignmentPad[12] = { 0xAF, 0xA0, 0x00, 0x10, 0x8E, 0x28, 0x00, 0x1C, 0x8E, 0x29, 0x00, 0x20 };
#endif

/* 8024E914_2.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_actorHeaderSplitTextEuXAlignmentPad[3] = { 0x00E09821U, 0xA2200000U, 0x96430008U };
#endif

/* 8028469C_19.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_InstanceTrailingBytesBlock2AlignmentPad[4] = { 0x65, 0x04, 0x2E, 0x65 };
#endif
