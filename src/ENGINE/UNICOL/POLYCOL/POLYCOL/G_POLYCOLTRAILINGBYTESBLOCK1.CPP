

/* 802412C0_11.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_PolycolTrailingBytesBlock1AlignmentPad[8] = { 0xAF, 0xB0, 0x00, 0x10, 0x50, 0x40, 0x00, 0x48 };
#endif

/* 802412C0_2.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_GPolycoltrailingbytesblock1ObjectAlignmentPadEuX1[1] = { 0x4480A000U };
#endif

/* 802624A0_17.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_PolycolTrailingBytesBlock2AlignmentPad[8] = { 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16 };
#endif
