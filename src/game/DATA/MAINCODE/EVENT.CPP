

/* 802AFEEC_13.CPP */
#if defined(VERSION_EU)
unsigned char g_EventTrailingBytesBlock1[8] = { 0x24, 0x06, 0x00, 0x01, 0x3C, 0x07, 0x80, 0x0D };
#endif

/* g_EventEncodedWords_Event.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_8023D008_eu_x_padding_3DBB8 */
unsigned int g_EventEncodedWords[2] = {
    0x0C09C7E9, 0x02203021,
};
#endif
