

/* 802ABDBC_3.CPP */
#if defined(VERSION_EU)
unsigned char g_PickupAndSequencePlayerSplitTextTrailingBytes[4] = { 0x10, 0x40, 0x00, 0x03 };
#endif

/* 802AD544_4.CPP */
#if defined(VERSION_EU_X)
unsigned char g_PickupAndSequencePlayerSplitTextTrailingBytesBlock1[12] = { 0xAE, 0x42, 0x00, 0x0C, 0xA2, 0x40, 0x00, 0x0A, 0x8F, 0xBF, 0x00, 0x24 };
#endif

/* 802AE254_2.CPP */
#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_pickupRuntimeSplitTextWordUsRev1[1] = { 0x00108200U };
#endif
