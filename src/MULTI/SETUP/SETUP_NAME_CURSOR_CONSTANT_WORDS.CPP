#include "include_asm.h"

#if defined(VERSION_US) || defined(VERSION_US_REV1)
const float g_multiplayerNameEntryTimingLimits = 15.0f;
#endif
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded data: src/g_multiplayerNameCursorConstantWordsUsRev1_SetupNameCursorConstantWords.c */
const unsigned int g_multiplayerNameCursorConstantWordsUsRev1[2] = {
    0x40C00000, 0x3B66C2B4,
};
#endif
