

/* 80268160_10.CPP */
/* 80268160_10.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_dynamicLightSplitTextEuXAlignmentPad[3] = { 0x8FA20028U, 0x8FA5002CU, 0x0202001AU };
#endif

/* 80268160_8.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_DynlightTrailingBytesAlignmentPad[12] = { 0x8F, 0xB4, 0x00, 0x20, 0x8F, 0xB3, 0x00, 0x1C, 0x8F, 0xB2, 0x00, 0x18 };
#endif

/* 80268160_11.CPP */
#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_DynlightTrailingBytesBlock1AlignmentPad[12] = { 0x8C, 0x42, 0xC3, 0x50, 0x10, 0x44, 0x01, 0x5A, 0x2C, 0x82, 0x00, 0x2A };
#endif
