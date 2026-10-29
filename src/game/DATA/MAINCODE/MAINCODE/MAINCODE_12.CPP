

/* 802AD544_9.CPP */
#if defined(VERSION_EU)
unsigned char g_MaincodeTrailingBytesBlock10[8] = { 0x44, 0x05, 0xA8, 0x00, 0x44, 0x06, 0xA0, 0x00 };
#endif

/* DATA_8021111C.CPP */
#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded data: func_8021113C_eu_padding_11D1C */
#ifdef VERSION_US
unsigned int g_MaincodeEncodedWords[1] = {
    0x36305F46,
};
#endif
#ifdef VERSION_US_REV1
unsigned int g_MaincodeEncodedWords[1] = {
    0x8E03031C,
};
#endif
#endif
