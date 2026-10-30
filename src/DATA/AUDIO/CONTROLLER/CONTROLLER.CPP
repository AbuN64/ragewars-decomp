#include "DATA/REST_SOURCE_RECORDS.H"


/* 802B7488_10.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill4 g_ControllerTrailingBytesBlock1 = {
    { 2, 0, 40, 33 },
};
#endif

/* 802BE040_73.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
RestLinkerAlignmentFill4 func_802BA46C_eu_x = {
    { 175, 177, 0, 20 },
};
#endif

/* g_ControllerEncodedWords.CPP */
#if defined(VERSION_US)
RestLinkerAlignmentFill12 g_ControllerEncodedWords = {
    { 0, 92, 8, 0, 0, 8, 0, 4, 0, 0, 0, 0 },
};
#endif
