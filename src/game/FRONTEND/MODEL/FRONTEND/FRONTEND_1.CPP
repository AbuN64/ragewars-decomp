

/* 8042FBEC_11.CPP */
#if defined(VERSION_EU)
unsigned char D_auto_func_8043ABFC_eu_padding_1B0BFC[4] = { 0x30, 0x82, 0x00, 0xFF };
#endif

/* DATA_802B53D8.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
#if defined(VERSION_EU_X)
unsigned int func_802B05E8_eu_x[2] = { 0x080AC5F3U, 0xA0500008U };
#elif defined(VERSION_US_REV1)
unsigned int func_802B05E8_eu_x[2] = { 0x080AD96FU, 0xA0500008U };
#endif
#endif
