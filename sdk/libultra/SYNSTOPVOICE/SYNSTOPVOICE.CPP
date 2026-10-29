

/* 8025DE50_13.CPP */
/* 8025DE50_13.CPP */
#if defined(VERSION_US)
unsigned char g_SynstopvoiceTrailingBytes[4] = { 0x65, 0x6C, 0x73, 0x49 };
#endif

/* 8025DE50_15.CPP */
#if defined(VERSION_EU)
unsigned char g_SynstopvoiceTrailingBytesBlock1[8] = { 0x00, 0x50, 0x10, 0x21, 0xAF, 0xA2, 0x00, 0x2C };
#endif

/* 8025DE50_23.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802B3818_eu_x[2] = { 0x24070001U, 0x00002021U };
#endif

/* 8025DE50_17.CPP */
#if defined(VERSION_DE)
unsigned char g_SynstopvoiceTrailingBytesBlock2[4] = { 0xAF, 0xB6, 0x00, 0x30 };
#endif
