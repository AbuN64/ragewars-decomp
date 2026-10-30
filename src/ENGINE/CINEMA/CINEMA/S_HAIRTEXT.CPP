

/* 80243A80_12.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_SHairtextObjectAlignmentPadEuX1[2] = { 0xAFA00010U, 0xAFA00014U };
#endif

/* 80243A80_15.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_SHairtextTrailingBytesAlignmentPad[8] = { 0x00, 0x80, 0x80, 0x21, 0x00, 0xA0, 0x18, 0x21 };
#endif

/* 80277444_3.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char s_hairTextAlignmentPad[4] = { 0x68, 0x61, 0x69, 0x72 };
#endif
