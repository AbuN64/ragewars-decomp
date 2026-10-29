

/* 8023EEF0_10.CPP */
#if defined(VERSION_EU)
unsigned char g_UnicolTrailingBytesBlock2[4] = { 0x26, 0x31, 0x00, 0x04 };
#endif

/* 8023EEF0_12.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_8024070C_eu_x[1] = { 0xC4C20000U };
#endif

/* 80259280_6.CPP */
#if defined(VERSION_US)
unsigned char g_UnicolTrailingBytesBlock10[4] = { 0x96, 0x0D, 0x00, 0x08 };
#endif
