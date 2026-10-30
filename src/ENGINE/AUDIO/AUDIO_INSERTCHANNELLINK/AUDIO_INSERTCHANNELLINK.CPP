

/* 80259280_7.CPP */
/* 80259280_7.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_AudioInsertchannellinkTrailingBytesAlignmentPad[4] = { 0x8E, 0x22, 0xFF, 0xF8 };
#endif

/* 8025C544_10.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_AudioInsertchannellinkObjectAlignmentPadEuX1[2] = { 0x3C048011U, 0x24842080U };
#elif defined(VERSION_US_REV1)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_AudioInsertchannellinkObjectAlignmentPadUsRev12[2] = { 0x3C048011U, 0x2484C080U };
#endif
#endif

/* 802A23A4_3.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_AudioInsertchannellinkTrailingBytesBlock2AlignmentPad[4] = { 0x10, 0x00, 0x0B, 0x00 };
#endif

/* 80259280_9.CPP */
#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_AudioInsertchannellinkTrailingBytesBlock1AlignmentPad[4] = { 0xAF, 0xBF, 0x00, 0x48 };
#endif
