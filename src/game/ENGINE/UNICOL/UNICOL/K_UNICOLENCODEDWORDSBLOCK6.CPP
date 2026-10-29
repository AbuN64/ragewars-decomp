#include "include_asm.h"

/* 800C8710.CPP */
#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned int k_UnicolEncodedWordsBlock6[1] = {
    0xAFB40020,
};
#endif
#if defined(VERSION_US)
unsigned int k_UnicolEncodedWordsBlock6[1] = {
    0x4175746F,
};
#endif
#endif

/* 800C8710_2.CPP */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU)
unsigned int k_UnicolZeroWords[1] = {
    0x26310008,
};
#endif
#if defined(VERSION_EU_X)
unsigned int k_UnicolZeroWords[1] = {
    0x00000000,
};
#endif
#endif
