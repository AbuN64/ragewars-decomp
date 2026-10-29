

/* 802BA5F0_13.CPP */
#if defined(VERSION_EU)
unsigned char g_SystemTrailingBytesBlock2[8] = { 0xC6, 0x40, 0x00, 0x18, 0x00, 0x43, 0x10, 0x25 };
#endif

/* 802BFD80_16.CPP */
#if defined(VERSION_EU_X)
unsigned char g_SystemTrailingBytesBlock3[8] = { 0x33, 0x69, 0xFF, 0x00, 0x11, 0x20, 0x00, 0x14 };
#endif

/* DATA_802B2A08.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_802AD8F4_de_padding_B3608 */
unsigned int k_SystemZeroWords[1] = {
    0x00000000,
};
#endif

/* DATA_802C1754.CPP */
#if defined(VERSION_US)
unsigned int g_SystemEncodedWords[3] = {
    0x656E755F, 0x74042E65, 0x6F735400,
};
#endif
