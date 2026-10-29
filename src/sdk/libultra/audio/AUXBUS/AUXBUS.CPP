

/* 802BE040_2.CPP */
#if defined(VERSION_DE)
unsigned char g_AuxbusTrailingBytes[4] = { 0xAF, 0xB7, 0x00, 0x34 };
#endif

/* 802BE040_3.CPP */
/* 802BE040_3.CPP */
#if defined(VERSION_EU)
unsigned char g_AuxbusTrailingBytesBlock1[4] = { 0x8E, 0x42, 0x00, 0x2C };
#endif

/* AUXBUS.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802B27EC_eu_x[1] = { 0x8C820008U };
#endif
