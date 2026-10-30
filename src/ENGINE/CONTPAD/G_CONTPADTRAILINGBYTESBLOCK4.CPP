

/* 80263760_2.CPP */
#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_ContpadTrailingBytesBlock1AlignmentPad[12] = { 0x90, 0x22, 0x53, 0x08, 0x10, 0x40, 0x00, 0x03, 0x24, 0x63, 0x00, 0x01 };
#endif

/* 80265370_2.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_ContpadTrailingBytesBlock3AlignmentPad[8] = { 0x00, 0xC2, 0x10, 0x04, 0x24, 0x42, 0xFF, 0xFF };
#endif

/* 80275E44_11.CPP */
#if defined(VERSION_US_REV1)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_ContpadTrailingBytesBlock4AlignmentPad[12] = { 0x18, 0x40, 0x00, 0x25, 0x02, 0x00, 0xA0, 0x21, 0x24, 0x05, 0x15, 0x08 };
#endif

/* g_ContpadEncodedWordsBlock1_Contpad2.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_ContpadEncodedWordsBlock1AlignmentPad[3] = {
    0x00000A5C, 0x7C020262, 0x01349002,
};
#endif
