

/* 80208000_17.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
unsigned char g_MaincodeTrailingBytes[12] = { 0x8F, 0xB1, 0x00, 0x14, 0x8F, 0xB0, 0x00, 0x10, 0x03, 0xE0, 0x00, 0x08 };
#endif

/* 80208000_19.CPP */

/* 8020EAE0_16.CPP */
#if defined(VERSION_EU)
unsigned char g_MaincodeTrailingBytesBlock1[4] = { 0xE7, 0xA0, 0x02, 0x2C };
#endif

/* 80231F5C_13.CPP */
#if defined(VERSION_US)
unsigned char g_MaincodeTrailingBytesBlock2[8] = { 0x61, 0x6E, 0x53, 0x74, 0x61, 0x74, 0x65, 0x64 };
#endif
