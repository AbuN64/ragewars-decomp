#include "include_asm.h"

#if !defined(__i386__) && !defined(__x86_64__)
#define L_udivdi3
#include "../../libgcc/libgcc2.inc.c"
#endif

#if defined(VERSION_US)
unsigned int k_Udivdi3EncodedWords[3] = {
    0x00660000, 0x00040000, 0x00000009,
};
#endif

#if defined(VERSION_EU_X)
float k_Udivdi3EncodedWordsBlock1[3] = {
    3.0f, 3.0f, 23.0f,
};
#endif
