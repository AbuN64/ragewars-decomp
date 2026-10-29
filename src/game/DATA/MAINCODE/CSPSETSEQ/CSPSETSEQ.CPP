

/* 802AFEEC_7.CPP */
#if defined(VERSION_EU)
unsigned char g_CspsetseqTrailingBytesBlock1[4] = { 0x02, 0x14, 0x00, 0x18 };
#endif

/* g_sequencePlayerSetSequenceSplitTextEuX_Cspsetseq.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
#if defined(VERSION_EU_X)
unsigned int g_sequencePlayerSetSequenceSplitTextEuX[2] = { 0x3C01800DU, 0xD42088B0U };
#elif defined(VERSION_US_REV1)
unsigned int g_sequencePlayerSetSequenceSplitTextEuX[2] = { 0x3C01800DU, 0xD420C540U };
#endif
#endif
