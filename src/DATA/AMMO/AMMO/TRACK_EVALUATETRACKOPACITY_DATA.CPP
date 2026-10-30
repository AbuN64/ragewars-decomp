#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

/* ROM-grounded data: src/g_trackOpacityStepWords_TrackEvaluatetrackopacityData.c */
const float g_trackOpacityStepWords[1] = {
    0.2f,
};

#if defined(VERSION_US)
RestLinkerAlignmentFill4 g_TrackEvaluatetrackopacityLinkerAlignmentFill20 = {
    { 0, 0, 102, 0 },
};
#endif

#if defined(VERSION_EU_X)
RestLinkerAlignmentFill4 g_TrackEvaluatetrackopacityBlock2LinkerAlignmentFill21 = {
    { 0, 0, 0, 6 },
};
#endif

#if defined(VERSION_EU)
RestLinkerAlignmentFill4 g_TrackEvaluatetrackopacityBlock3LinkerAlignmentFill22 = {
    { 234, 226, 11, 9 },
};
#endif

#if defined(VERSION_DE)
RestLinkerAlignmentFill4 g_TrackEvaluatetrackopacityBlock1LinkerAlignmentFill23 = {
    { 0, 126, 126, 126 },
};
#endif
