

/* PPDECOM_1.CPP */
/* 8028469C_10.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_recordSortSplitTextWordEuXAlignmentPad[1] = { 0x46140542U };
#endif

/* 8028469C_20.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_PpdecomTrailingBytesBlock1AlignmentPad[4] = { 0xE6, 0xE0, 0x01, 0x58 };
#endif

/* PPDECOM_2.CPP */
#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_PpdecomTrailingBytesAlignmentPad[4] = { 0xAC, 0x82, 0x00, 0x00 };
#endif
