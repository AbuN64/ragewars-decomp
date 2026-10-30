#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

/* 800E2774.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/playerDrawPulsingMenuSpriteConstantWordsPoolUsRev1.c */
const float g_Player_DrawPulsingMenuSpriteConstantWords_us_rev1[1] = {
    0.5f,
};
#endif

/* 80442BC8_5.CPP */
#if defined(VERSION_US)
/* ROM-grounded data: rodata/Player_FormatPlayerPartnerStatus/800E2738 (US: shared with the next table) */
#endif

#if defined(VERSION_US)
const float g_Player_DrawPulsingMenuSpriteConstantWords_us[1] = {
    0.5f,
};
#endif

#if defined(VERSION_US)
RestLinkerAlignmentFill8 g_AmmoBlock1LinkerAlignmentFill24 = {
    { 0, 10, 0, 4, 0, 0, 0, 20 },
};
#endif

/* ammoEncodedWordsBlock1UsRev1Data.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E2778 */
RestLinkerAlignmentFill8 g_AmmoBlock1LinkerAlignmentFill25 = {
    { 0, 0, 0, 1, 0, 0, 0, 16 },
};
#endif

/* ammoCountFormatData.CPP */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
const char s_ammoCountFormat[8] =
    " %03d\000\000\000";
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif
