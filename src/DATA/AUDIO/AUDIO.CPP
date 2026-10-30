#include "DATA/REST_SOURCE_RECORDS.H"


/* 8023A284_35.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill4 g_AudioTrailingBytes = {
    { 2, 32, 32, 33 },
};
#endif

/* 8025DE50_12.CPP */
#if defined(VERSION_US)
RestLinkerAlignmentFill12 g_AudioTrailingBytesBlock4 = {
    { 196, 0, 0, 0, 8, 0, 17, 0, 0, 0, 0, 0 },
};
#endif

/* 8025DE50_16.CPP */
#if defined(VERSION_EU_X)
RestLinkerAlignmentFill8 g_AudioTrailingBytesBlock5 = {
    { 60, 6, 0, 43, 36, 198, 88, 32 },
};
#endif

/* 8025DE50_22.CPP */
#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
RestLinkerAlignmentFill8 func_802B8548_us_rev1 = {
    { 60, 6, 0, 44, 36, 198, 166, 16 },
};
#endif

/* 802B7058_42.CPP */
#if defined(VERSION_DE)
RestLinkerAlignmentFill8 g_AudioTrailingBytesBlock21 = {
    { 3, 224, 0, 8, 0, 0, 0, 0 },
};
#endif
