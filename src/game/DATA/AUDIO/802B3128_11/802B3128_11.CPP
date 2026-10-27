

/* 802B3128_11.CPP */
#if defined(VERSION_EU)
unsigned char D_auto_func_802B3248_eu_padding_B3E48[8] = { 0x31, 0xEF, 0x00, 0x01, 0x01, 0x4A, 0x50, 0x21 };
#endif

/* 802B7058.CPP */
#if defined(VERSION_US)
unsigned char D_auto_func_802B7058_us_padding_B7C58[8] = { 0x6D, 0x5F, 0x6E, 0x43, 0x68, 0x61, 0x72, 0x50 };
#endif

/* 802B7058_52.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802BD1EC_eu_x[1] = { 0x8EB30004U };
#endif
