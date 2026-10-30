#include "DATA/REST_SOURCE_RECORDS.H"


/* 802B243C_8.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill4 g_AlunlinkTrailingBytesBlock1 = {
    { 143, 179, 0, 12 },
};
#endif

/* 802B2D5C_7.CPP */
#if defined(VERSION_US)
RestLinkerAlignmentFill4 g_AlunlinkTrailingBytesBlock2 = {
    { 8, 0, 24, 0 },
};
#endif

/* 802B3128_10.CPP */
#if defined(VERSION_EU_X)
RestLinkerAlignmentFill4 g_AlunlinkTrailingBytesBlock3 = {
    { 60, 2, 0, 43 },
};
#endif

/* 802B63E4_12.CPP */
#if defined(VERSION_US_REV1)
RestLinkerAlignmentFill8 g_AlunlinkTrailingBytesBlock4 = {
    { 48, 226, 0, 255, 44, 66, 0, 17 },
};
#endif
