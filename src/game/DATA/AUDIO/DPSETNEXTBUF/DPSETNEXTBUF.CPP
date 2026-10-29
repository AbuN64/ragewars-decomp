

/* 802B7488_11.CPP */
#if defined(VERSION_EU)
unsigned char g_DpsetnextbufTrailingBytes[4] = { 0xAE, 0x03, 0x00, 0x50 };
#endif

/* 802BE040_74.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802BA484_eu_x[3] = { 0x24130001U, 0x24120008U, 0x12930005U };
#endif

/* DPSETNEXTBUF_ENCODED_WORDS_US.CPP */
#if defined(VERSION_US)
unsigned int g_DpsetnextbufEncodedWords[3] = {
    0x6F72335F, 0x740F6D5F, 0x76477261,
};
#endif
