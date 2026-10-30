

/* 80275E44_10.CPP */
#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_RegionTrailingBytesBlock4AlignmentPad[12] = { 0x18, 0x40, 0x00, 0x25, 0x02, 0x00, 0xA0, 0x21, 0x24, 0x05, 0x15, 0x08 };
#endif

/* 80275E44_9.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_RegionTrailingBytesBlock3AlignmentPad[12] = { 0xC4, 0x22, 0x4B, 0x08, 0x46, 0x02, 0x00, 0x01, 0x46, 0x00, 0x08, 0x3C };
#endif

/* 80277444_7.CPP */
#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_GRegiontrailingbytesblock3ObjectAlignmentPadUsRev11[1] = { 0x45000009U };
#endif
