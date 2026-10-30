

/* 80279208_10.CPP */
/* 80279208_10.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_MapReseObjectAlignmentPadEuX1[3] = { 0x0C09C61EU, 0x26450174U, 0xC641001CU };
#elif defined(VERSION_US_REV1)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_MapReseObjectAlignmentPadUsRev12[3] = { 0x0C09C622U, 0x26450174U, 0xC641001CU };
#endif
#endif

/* 80279208_9.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_MapReseTrailingBytesBlock1AlignmentPad[12] = { 0xC4, 0x22, 0x4C, 0x34, 0x46, 0x02, 0x73, 0x81, 0x46, 0x0E, 0x08, 0x3C };
#endif

/* 80279208_8.CPP */
#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_MapReseTrailingBytesAlignmentPad[12] = { 0xAF, 0xB1, 0x00, 0x14, 0x00, 0x80, 0x88, 0x21, 0xAF, 0xBF, 0x00, 0x1C };
#endif
