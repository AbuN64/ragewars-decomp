#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

/* ROM-grounded data: src/k_SndplayerEncodedWordsBlock1_SndplayerData.c */
const unsigned int k_SndplayerEncodedWordsBlock1[2] = {
    0x41DFFFFF, 0xFFC00000,
};

#if defined(VERSION_US)
char s_SndplayerTOptiText[8] =
    "t\011m_Opti";
#endif

#if defined(VERSION_EU)
extern char Weapon_FireStateEnterCallbackEntry[];
void *k_SndplayerEncodedWordsBlock4[2] = {
    (void *)(Weapon_FireStateEnterCallbackEntry + 1120), (void *)(Weapon_FireStateEnterCallbackEntry + 1120),
};
#endif

#if defined(VERSION_DE)
char s_SndplayerOSyntheText[8] =
    "o/synthe";
#endif
