

/* 8023EEF0_15.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_UnicolTrailingBytesBlock4AlignmentPad[4] = { 0xC7, 0xB4, 0x00, 0x50 };
#endif

/* 8023EEF0_6.CPP */
#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_UnicolTrailingBytesAlignmentPad[12] = { 0x2C, 0x42, 0x00, 0x02, 0x10, 0x40, 0x00, 0x59, 0x00, 0x60, 0x90, 0x21 };
#endif

/* 80254CE4_4.CPP */
#if defined(VERSION_US_REV1)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_UnicolTrailingBytesBlock9AlignmentPad[8] = { 0x24, 0x05, 0x00, 0x18, 0x0C, 0x09, 0x57, 0x10 };
#endif

/* 8025DE50.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_UnicolTrailingBytesBlock11AlignmentPad[4] = { 0x08, 0x00, 0x06, 0x00 };
#endif
