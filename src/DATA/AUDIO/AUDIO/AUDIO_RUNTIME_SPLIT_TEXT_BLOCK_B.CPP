

/* 802B7058_37.CPP */
#if defined(VERSION_EU)
unsigned char g_AudioRuntimeSplitTextBlockBTrailingBytesBlock2[4] = { 0xB8, 0x6A, 0x00, 0x0F };
#endif

/* 802BE040_33.CPP */
#if defined(VERSION_US)
unsigned char g_AudioRuntimeSplitTextBlockBTrailingBytesBlock1[4] = { 0x6E, 0x64, 0x50, 0x6F };
#endif

/* 802BE040_6.CPP */
#if defined(VERSION_EU_X)
unsigned char g_AudioRuntimeSplitTextBlockBTrailingBytes[8] = { 0x24, 0x11, 0xFF, 0xFF, 0x3C, 0x05, 0x04, 0x00 };
#endif

/* 802BFD80_23.CPP */
#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_audioRuntimeSplitTextUsRev1[2] = { 0x3369FF00U, 0x11200014U };
#endif
