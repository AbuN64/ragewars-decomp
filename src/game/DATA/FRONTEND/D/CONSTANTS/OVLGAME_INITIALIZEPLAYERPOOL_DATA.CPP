#include "include_asm.h"

/* DATA_800CE82C.CPP */
#if defined(VERSION_US) || defined(VERSION_US_REV1)
unsigned int g_playerMovementTuningProfileThreeUsRev1[8] = {
    0x40F5C28F, 0x41B851EB, 0x40B851EB, 0x40F5C28F, 0x41D70A3E, 0x40B851EB, 0x4123D70A, 0x3F449BA6,
};
#endif

#if defined(VERSION_US)
unsigned int k_OvlgameInitializeplayerpoolEncodedWords[1] = {
    0x00000001,
};
#endif

#if defined(VERSION_US_REV1)
unsigned int k_OvlgameInitializeplayerpoolEncodedWordsBlock1[1] = {
    0x00000001,
};
#endif

#if defined(VERSION_US_REV1)
/* bytes live in the preceding array */
#endif

/* DATA_800CE850.CPP */
#if defined(VERSION_US) || defined(VERSION_US_REV1)
unsigned int g_playerMovementTuningProfileFourUsRev1[8] = {
    0x4003126F, 0x4175C28F, 0x3F83126F, 0x41A3D70A, 0x3FC49BA6, 0x41A3D70A, 0x43199999, 0x42CCCCCC,
};
#endif

#if defined(VERSION_US_REV1)
unsigned int k_OvlgameInitializeplayerpoolEncodedWordsBlock2[1] = {
    0x00000001,
};
#endif

#if defined(VERSION_US_REV1)
/* bytes live in the preceding array */
#endif

/* DATA_800CE874.CPP */
#if defined(VERSION_US_REV1)
unsigned int g_playerViewTuningProfileThreeUsRev1[6] = {
    0x3ECCCCCD, 0x3F000000, 0x3F800000, 0x3E800000, 0xBFC90FDC, 0x3FC90FDC,
};
#endif

/* DATA_800CE88C.CPP */
#if defined(VERSION_US_REV1)
unsigned int g_playerViewTuningProfileFourUsRev1[6] = {
    0x3E4CCCCD, 0x3E800000, 0x3F000000, 0x3E000000, 0xBFC90FDC, 0x3FC90FDC,
};
#endif

/* DATA_800CE8A4.CPP */
#if defined(VERSION_US_REV1)
unsigned int g_playerViewTuningProfileTailUsRev1[9] = {
    0x3F83126F, 0x40F5C28F, 0x3F03126F, 0x4123D70A, 0x3F449BA6, 0x4123D70A, 0x42999999, 0x424CCCCC,
    0x00000000,
};
#endif

/* DATA_800CE8C8.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_player_state_normal_callbacks_00_us_rev1.c */
extern char g_Player_UpdateFlyModeAddress[];
extern char g_Player_ZeroBodyVelocityAddressVariant2[];
unsigned int g_playerMovementProfileFiveStateFlagUsRev1[2] = {
    (unsigned int)g_Player_ZeroBodyVelocityAddressVariant2, (unsigned int)g_Player_UpdateFlyModeAddress,
};
#endif

/* DATA_800CE8D0.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CE75C_unclaimed_CF474_unclaimed_CF4A4_unclaimed_CF4D0 */
unsigned int g_playerMovementProfileThreeStateFlagUsRev1[1] = {
    0x801044F8,
};
#endif

/* DATA_800CE8D4.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_player_state_normal_timing_00_us_rev1.c */
unsigned int g_playerMovementProfileFourStateFlagUsRev1[2] = {
    0x00000000, 0x00000001,
};
#endif
