#include "TYPES.H"

#include "include_asm.h"

/* 800C6E84_20.CPP */
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* ROM-grounded data: src/k_navUpdateobjectarrivalchaseDataFloatConstantWords_NavUpdateobjectarrivalchaseData.c */
#if defined(VERSION_EU)
const f32 k_navUpdateobjectarrivalchaseDataFloatConstantWords[2] = {
    102.399994f, 51.1999969f
};
#endif
#if defined(VERSION_EU_X)
const f32 k_navUpdateobjectarrivalchaseDataFloatConstantWords[2] = {
    102.399994f, 51.1999969f
};
#endif
#if defined(VERSION_US_REV1)
const f32 k_navUpdateobjectarrivalchaseDataFloatConstantWords[2] = {
    102.399994f, 51.1999969f
};
#endif
#endif

#if defined(VERSION_EU_X)
float k_NavUpdateobjectarrivalchaseEncodedWordsBlock2[2] = {
    48.0f, 255.0f,
};
#endif

#if defined(VERSION_EU)
#if defined(VERSION_EU)
struct {
    u8 alignmentFill[8];
} k_NavUpdateobjectarrivalchaseEncodedWordsBlock1 __attribute__((aligned(4))) = {
    { 0x00, 0x0B, 0x58, 0x42, 0x01, 0x64, 0x60, 0x24 }
};
#endif
#endif

/* 800C71D8.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800C71D8 */
#if defined(VERSION_US_REV1)
f32 g_navUpdateobjectarrivalchaseDataFloatConstantWords[2] = {
    30.0f, 0.0f
};
#endif
#endif
