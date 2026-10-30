#include "DATA/REST_SOURCE_RECORDS.H"


/* 802B63E4_10.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill8 g_LookatLinkerAlignmentFill200 = {
    { 18, 32, 0, 5, 0, 0, 0, 0 },
};
#endif

/* 802B7488_7.CPP */
#if defined(VERSION_US)
RestLinkerAlignmentFill8 g_LookatBlock1LinkerAlignmentFill201 = {
    { 87, 104, 101, 101, 108, 73, 110, 100 },
};
#endif

/* 802BA5F0_21.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
RestLinkerAlignmentFill8 g_eu_xLinkerAlignmentFill202 = {
    { 0, 7, 0, 13, 36, 1, 255, 255 },
};
#endif
