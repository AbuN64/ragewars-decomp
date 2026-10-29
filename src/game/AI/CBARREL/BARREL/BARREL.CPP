

/* 80217388_2.CPP */
#if defined(VERSION_DE)
unsigned char g_BarrelTrailingBytes[4] = { 0x00, 0x80, 0x40, 0x21 };
#endif

/* 80217388_3.CPP */
/* 80217388_3.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_BarrelWords1[1] = { 0xC6810008U };
#endif

/* 8022E938_3.CPP */
#if defined(VERSION_EU)
unsigned char g_BarrelTrailingBytesBlock1[8] = { 0x3C, 0x0B, 0x05, 0x00, 0x35, 0x6B, 0x02, 0x04 };
#endif

/* 802412C0_8.CPP */
#if defined(VERSION_US)
unsigned char g_BarrelTrailingBytesBlock2[8] = { 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D };
#endif
