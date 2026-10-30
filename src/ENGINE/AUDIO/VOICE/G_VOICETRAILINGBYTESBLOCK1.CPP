

/* 8025C544_3.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_VoiceTrailingBytesAlignmentPad[12] = { 0xAF, 0xB5, 0x00, 0x10, 0x02, 0x00, 0x28, 0x21, 0x02, 0x60, 0x30, 0x21 };
#endif

/* 8025C544_4.CPP */
#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_VoiceTrailingBytesBlock1AlignmentPad[12] = { 0x27, 0xBD, 0x00, 0x20, 0x27, 0xBD, 0xFF, 0xE0, 0xAF, 0xB0, 0x00, 0x10 };
#endif

/* 8025E5B0_4.CPP */
#if defined(VERSION_US_REV1)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_VoiceTrailingBytesBlock3AlignmentPad[8] = { 0x10, 0x40, 0x01, 0xE6, 0x00, 0x00, 0x28, 0x21 };
#endif

/* 802A6AC0_3.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_VoiceTrailingBytesBlock4AlignmentPad[4] = { 0x07, 0x43, 0x6F, 0x6E };
#endif
