

/* 802B7058_49.CPP */
#if defined(VERSION_EU)
unsigned char g_LongarithTrailingBytesBlock1[8] = { 0x34, 0x42, 0x05, 0x08, 0x8C, 0x52, 0x00, 0x00 };
#endif

/* 802BE040_70.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_longarithLinkGapWordsBlock1[1] = { 0xAFB10014U };
#endif

/* DATA_802B73D4.CPP */
#if defined(VERSION_US)
unsigned int g_longarithLinkGapWords[3] = {
    0x08003800, 0x00010000, 0x01000001,
};
#endif
