

/* 802B661C.CPP */
#if defined(VERSION_EU)
unsigned int g_VisetmodeTrailingBytes[1] = {
    0x080AC591,
};
#endif

/* 802BA5F0_6.CPP */
#if defined(VERSION_US)
unsigned char s_ctorText[4] = { 0x63, 0x74, 0x6F, 0x72 };
#endif

/* 802BE040_11.CPP */
#if defined(VERSION_EU_X)
unsigned char g_VisetmodeTrailingBytesBlock1[12] = { 0x14, 0x40, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0A, 0xEA, 0x48 };
#endif

/* 802BE040_64.CPP */
#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802BED98_us_rev1[2] = { 0x2484185CU, 0x00801821U };
#endif
