#include "DATA/REST_SOURCE_RECORDS.H"


/* 802BE040_35.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill8 g_AudioLinkGapWordsB28F4TrailingBytes = {
    { 134, 34, 0, 24, 134, 35, 0, 26 },
};
#endif

/* g_audioLinkGapWords.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
RestLinkerAlignmentFill12 g_audioLinkGapWords = {
    { 175, 183, 0, 44, 0, 192, 184, 33, 175, 191, 0, 48 },
};
#endif
