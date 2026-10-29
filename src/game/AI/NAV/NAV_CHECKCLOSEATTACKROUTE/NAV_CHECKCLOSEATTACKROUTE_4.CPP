#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned int k_NavCheckcloseattackrouteEncodedWordsBlock1[2] = {
    0xAFBF0020, 0x0C0AC031,
};
#endif
#if defined(VERSION_US)
unsigned int k_NavCheckcloseattackrouteEncodedWordsBlock1[2] = {
    0x00000000, 0x0E6D5F6E,
};
#endif
#endif

#ifdef NON_MATCHING
#ifdef VERSION_DE
unsigned int k_NavCheckcloseattackrouteEncodedWords[6] = {
    0xAFBF0020, 0x0C0AC031, 0x42C80000, 0x44666666, 0x44000000, 0x3F490FDC,
};
#endif

#ifdef VERSION_US
unsigned int k_NavCheckcloseattackrouteEncodedWords[6] = {
    0x00000000, 0x0E6D5F6E, 0x48AFC800, 0x3ECCCCCD, 0x40490FDB, 0x3FC90FDB,
};
#endif
#endif
