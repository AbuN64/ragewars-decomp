#include "include_asm.h"

#if defined(VERSION_US)
unsigned int k_EnemyEncodedWords[1] = {
    0x5F454D41,
};
#endif

#if defined(VERSION_EU_X)
#if defined(VERSION_EU_X)
extern char g_pickupTrailingRodataEuX[];
unsigned int k_EnemyEncodedWordsBlock1[1] = {
    (unsigned int)g_pickupTrailingRodataEuX + 0x18,
};
#endif
#endif

#if defined(VERSION_EU)
#if defined(VERSION_EU)
unsigned short k_EnemyEncodedHalfwords[2] = {
    0x8011, 0x04F8,
};
#endif
#endif
