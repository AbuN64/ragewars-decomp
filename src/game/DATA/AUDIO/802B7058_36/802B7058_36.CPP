

/* 802B7058_36.CPP */
#if defined(VERSION_EU)
unsigned char D_auto_func_802BD1AC_eu_padding_BDDAC[4] = { 0xB8, 0x68, 0x00, 0x07 };
#endif

/* 802BE040_28.CPP */
#if defined(VERSION_US)
unsigned char D_auto_func_802B9EF8_us_padding_BAAF8[8] = { 0x00, 0x00, 0x08, 0x00, 0x06, 0x00, 0x00, 0x00 };
#endif

/* 802BE040_59.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
#if defined(VERSION_EU_X)
unsigned int func_802B9A04_eu_x[3] = { 0x3C03800EU, 0x8C63FC54U, 0x8C62000CU };
#elif defined(VERSION_US_REV1)
unsigned int func_802B9A04_eu_x[3] = { 0x3C03800EU, 0x8C638444U, 0x8C62000CU };
#endif
#endif
