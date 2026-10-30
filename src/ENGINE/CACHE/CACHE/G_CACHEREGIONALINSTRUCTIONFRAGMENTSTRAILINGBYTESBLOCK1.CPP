

/* 80254CE4_5.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_CacheRegionalInstructionFragmentsTrailingBytesAlignmentPad[8] = { 0x80, 0x85, 0x00, 0x0E, 0x14, 0xA2, 0x00, 0x10 };
#endif

/* 80254CE4_6.CPP */
#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_CacheRegionalInstructionFragmentsTrailingBytesBlock1AlignmentPad[8] = { 0x24, 0x05, 0x00, 0x18, 0x0C, 0x09, 0x57, 0x24 };
#endif

/* 80255C40_2.CPP */
#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_EngineCacheRetainedWords2AlignmentPad[1] = { 0x24062800U };
#endif

/* 802909E0.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_CacheRegionalInstructionFragmentsTrailingBytesBlock19AlignmentPad[8] = { 0x03, 0xE0, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00 };
#endif
