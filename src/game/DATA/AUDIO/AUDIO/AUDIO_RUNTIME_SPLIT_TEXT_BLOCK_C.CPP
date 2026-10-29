

/* 802B63E4_7.CPP */
#if defined(VERSION_EU)
unsigned char g_AudioRuntimeSplitTextBlockCTrailingBytes[12] = { 0xA0, 0x67, 0x00, 0x31, 0xA0, 0x65, 0x00, 0x32, 0xA0, 0x66, 0x00, 0x33 };
#endif

/* 802BA5F0_2.CPP */
#if defined(VERSION_US)
unsigned char g_AudioRuntimeSplitTextBlockCTrailingBytesBlock1[8] = { 0x07, 0x00, 0x00, 0x08, 0x00, 0x06, 0x00, 0x00 };
#endif

/* 802BA5F0_26.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_audioRuntimeSplitTextEuX[1] = { 0xAE020010U };
#endif
