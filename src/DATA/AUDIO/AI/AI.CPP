#include "DATA/REST_SOURCE_RECORDS.H"


/* 802B7058_14.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill12 g_AiTrailingBytes = {
    { 60, 3, 128, 14, 36, 99, 70, 240, 175, 191, 0, 16 },
};
#endif

/* 802BE040_18.CPP */
#if defined(VERSION_US)
RestLinkerAlignmentFill8 g_AiTrailingBytesBlock1 = {
    { 0, 0, 16, 67, 80, 108, 97, 121 },
};
#endif

/* 802BE040_5.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
RestLinkerAlignmentFill4 func_802B41EC_eu_x = {
    { 60, 2, 3, 8 },
};
#endif
