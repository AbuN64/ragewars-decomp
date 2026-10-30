

/* 80275E44_5.CPP */
#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_RegionTrailingBytesBlock1AlignmentPad[8] = { 0x03, 0xE0, 0x00, 0x08, 0x27, 0xBD, 0x00, 0x60 };
#endif

/* 80277444_5.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_RegionTrailingBytesBlock5AlignmentPad[4] = { 0xC6, 0x0C, 0x00, 0x08 };
#endif

/* 80279208_6.CPP */
#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_GRegiontrailingbytesblock5ObjectAlignmentPadUsRev11[3] = { 0x8FB500ECU, 0x8FB400E8U, 0x8FB300E4U };
#endif
