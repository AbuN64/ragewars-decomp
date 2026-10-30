

/* 8023EEF0_4.CPP */
#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_AnimTrailingBytesBlock1AlignmentPad[12] = { 0xAF, 0xB6, 0x01, 0xB8, 0x00, 0xC0, 0xB0, 0x21, 0xAF, 0xBE, 0x01, 0xC0 };
#endif

/* 8023EEF0_5.CPP */
/* 8023EEF0_5.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_AnimTrailingBytesAlignmentPad[12] = { 0x00, 0x00, 0x00, 0x00, 0x45, 0x02, 0x00, 0x01, 0xAF, 0xA0, 0x01, 0xA8 };
#endif

/* 8023EEF0_8.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_AnimObjectAlignmentPadEuX1[1] = { 0x00001021U };
#endif

/* 802624A0_11.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_AnimTrailingBytesBlock3AlignmentPad[4] = { 0x20, 0x50, 0x41, 0x52 };
#endif
