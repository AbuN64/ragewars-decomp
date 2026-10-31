#include "include_asm.h"
#include "COMMON/OBJB.H"
#include "OVLGAME/OVLGAME_INITIALIZEDYNAMICLIGHTPOOL.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#if defined(VERSION_US)
unsigned int k_DynlightEncodedWords[1] = {
    0x4E657874,
};
#endif
#if defined(VERSION_EU_X)
unsigned int k_DynlightOneWords[1] = {
    0x3F800000,
};
#endif
#if defined(VERSION_EU)
unsigned int k_DynlightEncodedWordsBlock2[1] = {
    0x00031C00,
};
#endif
#if defined(VERSION_DE)
unsigned int k_DynlightEncodedWordsBlock1[1] = {
    0x00268D74,
};
#endif
