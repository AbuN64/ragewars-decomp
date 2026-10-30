#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"
#include "TYPES.H"

/* 800C6B40.CPP */
#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* ROM-grounded data: src/overlayOneAFloatConstantWords.c */
#if !(defined(VERSION_US_REV1) || defined(VERSION_DE) || defined(VERSION_US))
const float k_overlayOneAFloatConstantWords[1] = {
    122.88f,
};
#endif
#endif

/* 802624A0_25.CPP */
#if defined(VERSION_EU_X)
RestLinkerAlignmentFill4 g_OvlAMaxFiniteFloatLinkerAlignmentFill614 = {
    { 127, 127, 255, 255 },
};
#endif

/* 802ABDBC_18.CPP */
#if defined(VERSION_US)
RestLinkerAlignmentFill4 g_Ovl1ALinkerAlignmentFill615 = {
    { 110, 95, 116, 4 },
};
#endif

/* 802ABDBC_22.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill4 g_Ovl1ABlock1LinkerAlignmentFill616 = {
    { 0, 103, 24, 35 },
};
#endif
