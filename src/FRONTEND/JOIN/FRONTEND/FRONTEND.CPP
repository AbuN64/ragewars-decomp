

/* 8041F1A8.CPP */
/* 8041F1A8.CPP */
#if defined(VERSION_US_REV1)
unsigned char g_FrontendTrailingBytes[8] = { 0x00, 0x00, 0x00, 0x00, 0x54, 0x50, 0x00, 0x0A };
#endif

/* 80442BC8_10.CPP */
#if defined(VERSION_US)
unsigned char g_FrontendTrailingBytesBlock12[8] = { 0x00, 0x00, 0x00, 0x4C, 0x00, 0x00, 0x00, 0x00 };
#endif

/* 8041DF04_2.CPP */
#if defined(VERSION_EU_X)
unsigned char g_FrontendTrailingBytesBlock1[4] = { 0x54, 0x50, 0x00, 0x0A };
#endif
