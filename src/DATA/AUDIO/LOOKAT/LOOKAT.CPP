

/* 802B63E4_10.CPP */
#if defined(VERSION_EU)
unsigned char g_LookatTrailingBytes[8] = { 0x12, 0x20, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00 };
#endif

/* 802B7488_7.CPP */
#if defined(VERSION_US)
unsigned char g_LookatTrailingBytesBlock1[8] = { 0x57, 0x68, 0x65, 0x65, 0x6C, 0x49, 0x6E, 0x64 };
#endif

/* 802BA5F0_21.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802BA628_eu_x[2] = { 0x0007000DU, 0x2401FFFFU };
#endif
