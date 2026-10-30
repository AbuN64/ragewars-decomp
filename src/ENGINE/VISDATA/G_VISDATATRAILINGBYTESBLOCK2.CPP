

/* 80296FF8_5.CPP */
#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_VisdataTrailingBytesBlock1AlignmentPad[8] = { 0x00, 0x22, 0x08, 0x21, 0x8C, 0x22, 0x59, 0x08 };
#endif

/* 8029AA48_3.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_VisdataTrailingBytesBlock2AlignmentPad[12] = { 0x00, 0x43, 0x10, 0x25, 0x00, 0x05, 0x12, 0x00, 0x00, 0x05, 0x18, 0xC0 };
#endif

/* 802A0888_5.CPP */
#if defined(VERSION_US_REV1)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_VisdataTrailingBytesBlock3AlignmentPad[12] = { 0x02, 0x20, 0x20, 0x21, 0x02, 0x00, 0x28, 0x21, 0x24, 0x02, 0x00, 0x02 };
#endif
