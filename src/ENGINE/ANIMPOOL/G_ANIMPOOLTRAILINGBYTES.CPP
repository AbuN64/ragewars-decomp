

/* 802624A0_18.CPP */
#if defined(VERSION_EU)
unsigned char g_AnimpoolTrailingBytesBlock1[8] = { 0x24, 0x84, 0x80, 0x80, 0xAF, 0xBF, 0x00, 0x10 };
#endif

/* 802624A0_20.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
unsigned char g_AnimpoolTrailingBytes[8] = { 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x20, 0x21 };
#endif

/* 802631C8.CPP */

/* g_AnimpoolEncodedWords_Animpool1.CPP */
#if defined(VERSION_US)
/* ROM-grounded data for us; supplied-list member has no us-rev1 placement. */
unsigned int g_AnimpoolEncodedWords[3] = {
    0x00040000, 0x00175346, 0x585F4144,
};
#endif
