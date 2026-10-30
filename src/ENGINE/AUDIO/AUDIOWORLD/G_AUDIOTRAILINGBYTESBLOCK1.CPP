

/* 80259280.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_AudioTrailingBytesBlock1AlignmentPad[8] = { 0x8E, 0x03, 0x00, 0x00, 0xAE, 0xA3, 0x00, 0x00 };
#endif

/* 80259280_3.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_GAudiotrailingbytesblock1ObjectAlignmentPadEuX1[2] = { 0xE6000084U, 0x96440002U };
#endif

/* 8029FA7C.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_AudioTrailingBytesBlock3AlignmentPad[8] = { 0x00, 0x00, 0x68, 0x00, 0x00, 0x00, 0x08, 0x00 };
#endif
