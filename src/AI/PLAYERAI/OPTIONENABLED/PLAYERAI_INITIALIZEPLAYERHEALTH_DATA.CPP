#include "DATA/WEAPON_CALLBACKS/ADDRLOW_WEAPONAI_INITIALIZESWITCHFORSINGLEROUND.H"
#include "DATA/WEAPON_CALLBACKS/G_WEAPON_RESETCONTROLLERANDSPINENCODEDCALLBACK.H"
#include "DATA/WEAPON_CALLBACKS/ADDRLOW_WEAPON_RELEASEHANDLESANDEXITSTATE39.H"
#include "DATA/WEAPON_CALLBACKS/PLAYER_HEALTH_CALLBACK_LABELS.H"
#include "DATA/OVL1_F/WEAPON_CHARGE_CALLBACK_ADDRESS.H"
#include "DATA/WEAPON_CALLBACKS/OVERLAY_SIX_FIRST_CALLBACK_ROM_ENTRY.H"
#include "DATA/WEAPON_CALLBACKS/WEAPON_UPDATE_TRIGGER_RELEASE_STATE_ADDRESS.H"
#include "DATA/OVL1_D/WEAPON_CHARGE_FIVE_CALLBACK_ADDRESS.H"
#include "DATA/OVL1_F/WEAPON_UPDATE_HELD_FIRE_CALLBACK_ADDRESS.H"
#include "DATA/WEAPON_CALLBACKS/WEAPON_STATE_CALLBACK_ADDRESS.H"
#include "DATA/WEAPON_CALLBACKS/WEAPON_STARTUP_CUE_ADDRESS.H"
#include "DATA/WEAPON_CALLBACKS/ADDRLOW_WEAPON_ADVANCESPINANDTRIGGERMODE.H"
#include "DATA/WEAPON_CALLBACKS/WEAPONAI_SELECTRELEASEDFIRESTATE_ADDRESS.H"

/* 800CF230.CPP */
#if defined(VERSION_US_REV1)
unsigned int g_playerTargetFacingEaseRate[] = {
    0x3EB33333, 0x3BCCCCCD, 0xFFFFFFFF, 0xFFFF0000, 0x3F800000, 0x4EF2000A, 0x4EFC000A, 0x4F06000A,
    0x4F10000A, 0xFFFF0000, 0x5046000A, 0x5047000A, 0x5048000A, 0x5049000A, 0xFFFF0000, 0x501E000A,
    0x5028000A, 0x5032000A, 0x503C000A, 0xFFFF0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0xC0400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000,
};
#endif

/* 800CF230_2.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_CFEB8_us_rev1.c */
unsigned int g_WeaponStateEntryCFEB8UsRev1[2] = {
    0x00000000, (unsigned int)addrLow_Weaponai_InitializeSwitchForSingleRound,
};
#endif

/* 800CF2C0.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF230_unclaimed_CFEC0 */
unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock2[2] = {
    (unsigned int)g_Weapon_ResetControllerAndSpinEncodedCallback, 0x00000000,
};

unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock13[4] = {
    0x00004E20, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* 800CF2D8.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_CFED8_us_rev1.c */
unsigned int g_WeaponStateEntryCFED8UsRev1[2] = {
    0x00000001, (unsigned int)addrLow_Weapon_ReleaseHandlesAndExitState39,
};
#endif

/* 800CF2E0.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF230_unclaimed_CFEC0_unclaimed_CFED8_unclaimed_CFEE0 */
unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock6[2] = {
    (unsigned int)addrLow_Weapon_UpdateIdleWeaponSelection, 0x00000000,
};

unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock15[4] = {
    0x00004E2A, 0x3F800000, 0x00000002, 0x00000000,
};
#endif

/* 800CF2F8.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_CFEF8_us_rev1.c */
unsigned int g_WeaponStateEntryCFEF8UsRev1[2] = {
    0x00000002, (unsigned int)addrLow_Weapon_ReleaseLinkedActorHandlesEntryVariant2,
};
#endif

/* 800CF300.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF230_unclaimed_CFEC0_unclaimed_CFED8_unclaimed_CFEE0_unclaimed_CFEF8_unclaimed_CFF00 */
unsigned int g_PlayeraiInitializeplayerhealthEncodedWords[2] = {
    (unsigned int)addrLow_Weaponai_UpdateAlternateFire, 0x00000000,
};

unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock16[4] = {
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* 800CF318.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_CFF18_us_rev1.c */
unsigned int g_WeaponStateEntryCFF18UsRev1[2] = {
    0x00000003, 0x00000000,
};
#endif

/* 800CF320.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF230_unclaimed_CFEC0_unclaimed_CFED8_unclaimed_CFEE0_unclaimed_CFEF8_unclaimed_CFF00_unclaimed_CFF18_unclaimed_CFF20 */
unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock5[2] = {
    (unsigned int)addrLow_Weaponai_UpdateAlternateFire, 0x00000000,
};
#endif

/* 800CF320_2.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_resource_animation_CFF28_us_rev1.c */
unsigned int g_WeaponStateResourceAnimationCFF28UsRev1[4] = {
    0x00004E8E, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* 800CF338.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_CFF38_us_rev1.c */
extern char addrLow_Weapon_ReleaseLinkedActorHandles[];
unsigned int g_WeaponStateEntryCFF38UsRev1[2] = {
    0x00000004, (unsigned int)addrLow_Weapon_ReleaseLinkedActorHandles,
};
#endif

/* 800CF340.CPP */
#if defined(VERSION_US_REV1)
unsigned int g_WeaponStateEntryCFF38UsRev12[3] = {
    (unsigned int)addrLow_Weapon_UpdateTriggerReleaseState, 0x00000000, 0x800CF244,
};
#endif

/* 800CF340_2.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_animation_CFF4C_us_rev1.c */
unsigned int g_WeaponStateAnimationCFF4CUsRev1[3] = {
    0x3F800000, 0x00000003, 0x00000000,
};
#endif

/* 800CF358.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_CFF58_us_rev1.c */
unsigned int g_WeaponStateEntryCFF58UsRev1[2] = {
    0x00000008, (unsigned int)addrLow_Weapon_InitializeChargeForWeaponFive,
};
#endif

/* 800CF360.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF230_unclaimed_CFEC0_unclaimed_CFED8_unclaimed_CFEE0_unclaimed_CFEF8_unclaimed_CFF00_unclaimed_CFF18_unclaimed_CFF20_unclaimed_CFF38_unclaimed_CFF40_unclaimed_CFF58_unclaimed_CFF60 */
unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock8[3] = {
    (unsigned int)addrLow_Weaponai_UpdateHeldFire, 0x00000000, 0x800CF258,
};

/* ROM-grounded data: src/rw_weapon_state_animation_CFF6C_us_rev1.c */
unsigned int g_WeaponStateAnimationCFF6CUsRev1[3] = {
    0x3F800000, 0x00000003, 0x00000000,
};
#endif

/* 800CF378.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_CFF78_us_rev1.c */
unsigned int g_WeaponStateEntryCFF78UsRev1[2] = {
    0x00000007, 0x00000000,
};
#endif

/* 800CF380.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF230_unclaimed_CFEC0_unclaimed_CFED8_unclaimed_CFEE0_unclaimed_CFEF8_unclaimed_CFF00_unclaimed_CFF18_unclaimed_CFF20_unclaimed_CFF38_unclaimed_CFF40_unclaimed_CFF58_unclaimed_CFF60_unclaimed_CFF78_unclaimed_CFF80 */
unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock10[2] = {
    (unsigned int)addrLow_Weapon_UpdateIdleWeaponSelection, 0x00000000,
};

unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock14[4] = {
    0x00004F19, 0x3F800000, 0x00000003, 0x00000000,
};
#endif

/* 800CF398.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_end_CFF98_us_rev1.c */
unsigned int g_WeaponStateEndCFF98UsRev1[1] = {
    0xFFFFFFFF,
};
#endif

/* 800CF39C.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF230_unclaimed_CFEC0_unclaimed_CFED8_unclaimed_CFEE0_unclaimed_CFEF8_unclaimed_CFF00_unclaimed_CFF18_unclaimed_CFF20_unclaimed_CFF38_unclaimed_CFF40_unclaimed_CFF58_unclaimed_CFF60_unclaimed_CFF78_unclaimed_CFF80_unclaimed_CFF98_unclaimed_CFF9C */
unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock7[15] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800CF298,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

/* ROM-grounded data: src/rw_weapon_state_entry_CFFD8_us_rev1.c */
unsigned int g_WeaponStateEntryCFFD8UsRev1[2] = {
    0x00000002, 0x00000000,
};
#endif

/* 800CF3E0.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF230_unclaimed_CFEC0_unclaimed_CFED8_unclaimed_CFEE0_unclaimed_CFEF8_unclaimed_CFF00_unclaimed_CFF18_unclaimed_CFF20_unclaimed_CFF38_unclaimed_CFF40_unclaimed_CFF58_unclaimed_CFF60_unclaimed_CFF78_unclaimed_CFF80_unclaimed_CFF98_unclaimed_CFF9C_unclaimed_CFFE0 */
unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock11[2] = {
    (unsigned int)addrLow_Weaponai_UpdateSpinAndAlternateFire, 0x00000000,
};
#endif

/* 800CF3E0_2.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_resource_animation_CFFE8_us_rev1.c */
unsigned int g_WeaponStateResourceAnimationCFFE8UsRev1[4] = {
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* 800CF3F8.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_CFFF8_us_rev1.c */
unsigned int g_WeaponStateEntryCFFF8UsRev1[2] = {
    0x00000003, 0x00000000,
};
#endif

/* 800CF400.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF230_unclaimed_CFEC0_unclaimed_CFED8_unclaimed_CFEE0_unclaimed_CFEF8_unclaimed_CFF00_unclaimed_CFF18_unclaimed_CFF20_unclaimed_CFF38_unclaimed_CFF40_unclaimed_CFF58_unclaimed_CFF60_unclaimed_CFF78_unclaimed_CFF80_unclaimed_CFF98_unclaimed_CFF9C_unclaimed_CFFE0_unclaimed_CFFF8_unclaimed_D0000 */
unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock3[2] = {
    (unsigned int)addrLow_Weaponai_UpdateSpinAndAlternateFire, 0x00000000,
};

unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock12[4] = {
    0x00004E8E, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* 800CF418.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_D0018_us_rev1.c */
unsigned int g_WeaponStateEntryD0018UsRev1[2] = {
    0x00000005, (unsigned int)addrLow_Weapon_PlayStartupCue9E2,
};
#endif

/* 800CF420.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF230_unclaimed_CFEC0_unclaimed_CFED8_unclaimed_CFEE0_unclaimed_CFEF8_unclaimed_CFF00_unclaimed_CFF18_unclaimed_CFF20_unclaimed_CFF38_unclaimed_CFF40_unclaimed_CFF58_unclaimed_CFF60_unclaimed_CFF78_unclaimed_CFF80_unclaimed_CFF98_unclaimed_CFF9C_unclaimed_CFFE0_unclaimed_CFFF8_unclaimed_D0000_unclaimed_D0018_unclaimed_D0020 */
unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock4[2] = {
    (unsigned int)addrLow_Weapon_AdvanceSpinAndTriggerMode, 0x00000000,
};

unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock17[4] = {
    0x00004EE8, 0x3F800000, 0x00000003, 0x00000000,
};
#endif

/* 800CF438.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_end_D0038_us_rev1.c */
unsigned int g_WeaponStateEndD0038UsRev1[1] = {
    0xFFFFFFFF,
};

/* ROM-grounded data: rodata/unresolved/800CF230_unclaimed_CFEC0_unclaimed_CFED8_unclaimed_CFEE0_unclaimed_CFEF8_unclaimed_CFF00_unclaimed_CFF18_unclaimed_CFF20_unclaimed_CFF38_unclaimed_CFF40_unclaimed_CFF58_unclaimed_CFF60_unclaimed_CFF78_unclaimed_CFF80_unclaimed_CFF98_unclaimed_CFF9C_unclaimed_CFFE0_unclaimed_CFFF8_unclaimed_D0000_unclaimed_D0018_unclaimed_D0020_unclaimed_D0038_unclaimed_D003C */
unsigned int g_PlayeraiInitializeplayerhealthEncodedWordsBlock9[55] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800CF298,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004,
    0x00000000, (unsigned int)addrLow_Weaponai_SelectReleasedFireState, 0x00000000, 0x00004EE8, 0x3F800000, 0x00000003, 0x00000000, 0x00000008,
    0x00000000, (unsigned int)addrLow_Weaponai_SelectReleasedFireState, 0x00000000, 0x00004EE8, 0x3F800000, 0x00000003, 0x00000020, 0x00000005,
    0x00000000, (unsigned int)addrLow_Weapon_UpdateTriggerReleaseState, 0x00000000, 0x00004EF2, 0x3F800000, 0x00000003, 0x00000020, 0x00000009,
    0x00000000, (unsigned int)addrLow_Weapon_UpdateTriggerReleaseState, 0x00000000, 0x00005046, 0x3F800000, 0x00000003, 0x00000020, 0xFFFFFFFF,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
#endif
