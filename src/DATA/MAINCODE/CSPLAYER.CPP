#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

/* 802AFD5C_3.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill4 g_CsplayerTrailingBytesBlock1 = {
    { 68, 7, 184, 0 },
};
#endif

/* s_firePodReaText_Csplayer.CPP */
#if defined(VERSION_US)
char s_firePodReaText[12] =
    "FIRE_POD_REA";
#endif

#if defined(VERSION_US_REV1)
RestLinkerAlignmentFill12 g_csplayerLinkGapWords = {
    { 12, 9, 202, 109, 36, 7, 0, 1, 2, 32, 32, 33 },
};
#endif
