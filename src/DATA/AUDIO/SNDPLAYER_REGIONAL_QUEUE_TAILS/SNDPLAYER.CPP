#include "DATA/REST_SOURCE_RECORDS.H"


/* 802B243C_9.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill8 g_SndplayerTrailingBytesBlock3 = {
    { 33, 140, 255, 255, 8, 10, 182, 49 },
};
#endif

/* 802B2D5C_8.CPP */
#if defined(VERSION_US)
RestLinkerAlignmentFill8 g_SndplayerTrailingBytesBlock7 = {
    { 0, 20, 0, 0, 0, 0, 0, 19 },
};
#endif

/* 802B3128_21.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
RestLinkerAlignmentFill8 func_802B3288_eu_x = {
    { 36, 17, 0, 2, 60, 18, 128, 14 },
};
#endif
