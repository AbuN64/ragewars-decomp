#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

/* ROM-grounded data: src/g_trackOpacityStepWords_TrackEvaluatetrackopacityData.c */
const float g_trackOpacityStepWords[1] = {
    0.2f,
};

#if defined(VERSION_US)
RestLinkerAlignmentFill4 k_TrackEvaluatetrackopacityEncodedWords = {
    { 0, 0, 102, 0 },
};
#endif

#if defined(VERSION_EU_X)
RestLinkerAlignmentFill4 k_TrackEvaluatetrackopacityEncodedWordsBlock2 = {
    { 0, 0, 0, 6 },
};
#endif

#if defined(VERSION_EU)
RestLinkerAlignmentFill4 k_TrackEvaluatetrackopacityEncodedWordsBlock3 = {
    { 234, 226, 11, 9 },
};
#endif

#if defined(VERSION_DE)
RestLinkerAlignmentFill4 k_TrackEvaluatetrackopacityEncodedWordsBlock1 = {
    { 0, 126, 126, 126 },
};
#endif
