

/* 802B7488_4.CPP */
#if defined(VERSION_EU)
unsigned char g_ContqueryTrailingBytesBlock1[8] = { 0x25, 0x02, 0x00, 0x01, 0xAC, 0xC5, 0x00, 0x1C };
#endif

/* 802BFD80_13.CPP */
#if defined(VERSION_EU_X)
unsigned char g_ContqueryTrailingBytesBlock2[12] = { 0x27, 0x5A, 0x4B, 0xD0, 0xFF, 0x41, 0x00, 0x20, 0x40, 0x1B, 0x60, 0x00 };
#endif

/* DATA_802B2368.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_802AD578_eu_x_padding_B2F68 */
unsigned int g_ContqueryEncodedWords[2] = {
    0x00A0A821, 0xAFB70134,
};
#endif

/* DATA_802BBB98.CPP */
#if defined(VERSION_US)
unsigned int k_ContqueryEncodedWords[2] = {
    0x05000000, 0x00000B6D,
};
#endif
