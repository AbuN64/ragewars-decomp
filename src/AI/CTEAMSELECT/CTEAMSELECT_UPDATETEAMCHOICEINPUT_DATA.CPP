#include "include_asm.h"

/* ROM-grounded data: src/g_teamWheelPlayerShieldDuration_StorageWords_CteamselectUpdateteamchoiceinputData.c */
const unsigned int g_teamWheelPlayerShieldDuration_StorageWords[1] = {
    0x40000000,
};

#if defined(VERSION_EU_X)
unsigned int k_CteamselectUpdateteamchoiceinputQuarterWords[1] = {
    0x3E800000,
};
#endif

#if defined(VERSION_EU)
unsigned int k_CteamselectUpdateteamchoiceinputEncodedWordsBlock1[1] = {
    0x2529FFF0,
};
#endif

#if defined(VERSION_DE)
unsigned int k_CteamselectUpdateteamchoiceinputEncodedWords[1] = {
    0xBF350481,
};
#endif
