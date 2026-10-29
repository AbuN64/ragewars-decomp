

/* 802BE040_10.CPP */
#if defined(VERSION_EU)
unsigned char g_SystemTrailingBytes[12] = { 0x8F, 0xBF, 0x00, 0x20, 0x8F, 0xB1, 0x00, 0x1C, 0x8F, 0xB0, 0x00, 0x18 };
#endif

/* 802C0390_15.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802BB43C_eu_x[1] = { 0x3C0A800EU };
#endif
