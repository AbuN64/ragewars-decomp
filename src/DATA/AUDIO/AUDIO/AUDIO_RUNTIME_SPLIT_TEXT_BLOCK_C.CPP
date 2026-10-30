#include "DATA/REST_SOURCE_RECORDS.H"


/* 802B63E4_7.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill12 g_AudioRuntimeSplitTextBlockCTrailingBytes = {
    { 160, 103, 0, 49, 160, 101, 0, 50, 160, 102, 0, 51 },
};
#endif

/* 802BA5F0_2.CPP */
#if defined(VERSION_US)
RestLinkerAlignmentFill8 g_AudioRuntimeSplitTextBlockCTrailingBytesBlock1 = {
    { 7, 0, 0, 8, 0, 6, 0, 0 },
};
#endif

/* 802BA5F0_26.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
RestLinkerAlignmentFill4 g_audioRuntimeSplitTextEuX = {
    { 174, 2, 0, 16 },
};
#endif
