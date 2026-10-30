#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

#if defined(VERSION_US)
RestLinkerAlignmentFill4 k_EnemyEncodedWords = {
    { 95, 69, 77, 65 },
};
#endif

#if defined(VERSION_EU_X)
#if defined(VERSION_EU_X)
extern char g_pickupTrailingRodataEuX[];
void * k_EnemyEncodedWordsBlock1[1] = {
    (void *)(g_pickupTrailingRodataEuX + 0x18),
};
#endif
#endif

#if defined(VERSION_EU)
#if defined(VERSION_EU)
RestLinkerAlignmentFill4 k_EnemyEncodedHalfwords = {
    { 128, 17, 4, 248 },
};
#endif
#endif
