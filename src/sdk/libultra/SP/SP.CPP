

/* 802BE040_32.CPP */
#if defined(VERSION_DE)
unsigned char g_SpTrailingBytes[8] = { 0x00, 0x80, 0x98, 0x21, 0xAF, 0xB2, 0x00, 0x18 };
#endif

/* 802BE040_44.CPP */
/* 802BE040_44.CPP */
#if defined(VERSION_EU)
unsigned char g_SpTrailingBytesBlock1[8] = { 0x45, 0x03, 0x00, 0x01, 0x46, 0x20, 0x0B, 0x86 };
#endif

/* DATA_802B7E48.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_802B2CF0_de_padding_B8A48 */
unsigned int k_SpZeroWords[1] = {
    0x00000000,
};
#endif

/* DATA_802B7E4C.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802B305C_eu_x[1] = { 0xAE440000U };
#endif
