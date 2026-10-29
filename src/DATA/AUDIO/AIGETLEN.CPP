

/* 802B7058_11.CPP */
#if defined(VERSION_EU)
unsigned char g_AigetlenTrailingBytesBlock2[12] = { 0xAC, 0x82, 0x00, 0x0C, 0x8C, 0x82, 0x00, 0x08, 0xAC, 0xA2, 0x00, 0x00 };
#endif

/* 802BE040.CPP */
#if defined(VERSION_US)
unsigned char g_AigetlenTrailingBytes[4] = { 0x11, 0x54, 0x55, 0x52 };
#endif

/* 802BE040_36.CPP */
#if defined(VERSION_EU_X)
unsigned char g_AigetlenTrailingBytesBlock3[8] = { 0x33, 0x69, 0xFF, 0x00, 0x11, 0x20, 0x00, 0x14 };
#endif

/* 802BE040_67.CPP */
#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_audioAiGetLengthSplitTextUsRev1[2] = { 0xAC22FD90U, 0x3C018015U };
#endif
