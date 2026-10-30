#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

/* ROM-grounded data: src/g_videoScaleUnsignedBias_StorageWords_VideoScaleUnsignedBiasData.c */
const RestvideoScaleUnsignedBias_StorageWordsLayout386 g_videoScaleUnsignedBias_StorageWords = {
    { 3e+01f, 0.0f, 2.1474836e+09f },
};

#if defined(VERSION_US)
RestLinkerAlignmentFill4 k_VideoScaleUnsignedBiasEncodedWords = {
    { 0, 15, 83, 77 },
};
#endif

#if defined(VERSION_EU)
RestLinkerAlignmentFill4 k_VideoScaleUnsignedBiasThirtyWords = {
    { 65, 240, 0, 0 },
};
#endif

#if defined(VERSION_DE)
RestLinkerAlignmentFill4 k_VideoScaleUnsignedBiasEncodedWordsBlock1 = {
    { 114, 101, 97, 100 },
};
#endif
