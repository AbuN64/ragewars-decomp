

/* 80265370_4.CPP */
#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_DefsTogglesavedflagTrailingBytesAlignmentPad[8] = { 0x00, 0x80, 0xA0, 0x21, 0xAF, 0xB6, 0x00, 0x58 };
#endif

/* 80265370_5.CPP */
/* 80265370_5.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_DefsTogglesavedflagObjectAlignmentPadEuX1[2] = { 0xAE4305E4U, 0x00601021U };
#endif

/* 80268160_4.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_DefsTogglesavedflagTrailingBytesBlock1AlignmentPad[8] = { 0x44, 0x84, 0x00, 0x00, 0x46, 0x80, 0x00, 0x20 };
#endif
