#include "DATA/REST_SOURCE_RECORDS.H"


/* 802B661C.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill4 g_VisetmodeTrailingBytes = {
    { 8, 10, 197, 145 },
};
#endif

/* 802BA5F0_6.CPP */
#if defined(VERSION_US)
unsigned char s_ctorText[4] = { 0x63, 0x74, 0x6F, 0x72 };
#endif

/* 802BE040_11.CPP */
#if defined(VERSION_EU_X)
RestLinkerAlignmentFill12 g_VisetmodeTrailingBytesBlock1 = {
    { 20, 64, 0, 11, 0, 0, 0, 0, 12, 10, 234, 72 },
};
#endif

/* 802BE040_64.CPP */
#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
RestLinkerAlignmentFill8 func_802BED98_us_rev1 = {
    { 36, 132, 24, 92, 0, 128, 24, 33 },
};
#endif
