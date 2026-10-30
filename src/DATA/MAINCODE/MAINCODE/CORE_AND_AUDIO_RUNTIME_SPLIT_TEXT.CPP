#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

/* 802AD544_6.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill12 g_CoreAndAudioRuntimeSplitTextTrailingBytes = {
    { 172, 98, 0, 40, 60, 2, 243, 0, 172, 224, 0, 4 },
};
#endif

/* CORE_AND_AUDIO_RUNTIME_SPLIT_TEXT_ZERO_WORD.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_80207FE4_de_padding_8BF8 */
RestLinkerAlignmentFill4 g_actorRuntimeSplitTextZeroWordUsRev1 = {
    { 0, 0, 0, 0 },
};
#endif

/* TURRETAI_8.CPP */
#if defined(VERSION_EU_X)
RestLinkerAlignmentFill4 func_8020402C_eu_x_padding_4C2C = {
    { 48, 66, 4, 0 },
};
#endif
