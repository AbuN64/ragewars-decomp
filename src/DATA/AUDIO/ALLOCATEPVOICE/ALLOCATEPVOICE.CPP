#include "DATA/REST_SOURCE_RECORDS.H"


/* 802B3128_15.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill8 g_AllocatepvoiceTrailingBytesBlock1 = {
    { 16, 64, 0, 8, 2, 32, 32, 33 },
};
#endif

/* 802B7058_23.CPP */
#if defined(VERSION_US)
RestLinkerAlignmentFill8 g_AllocatepvoiceTrailingBytesBlock3 = {
    { 0, 0, 0, 8, 0, 13, 0, 0 },
};
#endif

/* 802B7058_53.CPP */
#if defined(VERSION_US_REV1)
RestLinkerAlignmentFill4 g_AllocatepvoiceTrailingBytesBlock4 = {
    { 12, 11, 20, 200 },
};
#endif

/* 802B7058_9.CPP */
#if defined(VERSION_EU_X)
RestLinkerAlignmentFill8 g_AllocatepvoiceTrailingBytesBlock2 = {
    { 8, 10, 225, 220, 36, 2, 0, 11 },
};
#endif
