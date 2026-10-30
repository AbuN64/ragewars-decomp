#include "include_asm.h"

/* 800C6B74_2.CPP */
#if defined(VERSION_US)
const unsigned int k_actionLinkGapWords[2] = {
    0x00000800, 0x08000C00,
};
#endif

/* 800C6E84_14.CPP */
#if defined(VERSION_EU_X)
unsigned int k_ActionMixedConstantFragmentsEncodedWordsBlock1[2] = {
    0x3C5F0B72, 0x3FE52EDF,
};
#endif

#if defined(VERSION_EU)
unsigned int k_ActionMixedConstantFragmentsEncodedWords[2] = {
    0x01014824, 0x40896000,
};
#endif
