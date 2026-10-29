#include "include_asm.h"

/* 800C9F00.CPP */
#if defined(VERSION_US)
extern char addrLow_Weaponai_InitializeSwitchForSingleRound_us[];
extern char addrLow_Weaponai_UpdateAlternateFire_us[];
extern char addrLow_Weapon_UpdateIdleWeaponSelection_us[];
extern char addrLow_Weaponai_UpdateSpinAndAlternateFire_us[];
extern char addrLow_Weaponai_SelectReleasedFireState_us[];
extern char addrLow_Weaponai_UpdateHeldFire_us[];
extern char addrLow_Weapon_InitializeChargeForWeaponFive_eu_us[];
extern char D_00232B44[];
extern char addrLow_Weapon_ReleaseLinkedActorHandlesEntryVariant1[];
extern char D_00232C68[];
extern char addrLow_Weapon_UpdateTriggerReleaseState_us[];
extern char addrLow_Weapon_ReleaseHandlesAndExitState39_us[];
extern char addrLow_Weapon_PlayStartupCue9E2_us[];
extern char addrLow_Weapon_AdvanceSpinAndTriggerMode_us[];
unsigned int g_weaponSwitchStateWordsUs[186] = {
    0x3EB33333, 0x3BCCCCCD, 0x6F735200, 0x00000000, 0x3F800000, 0x4EF2000A, 0x4EFC000A, 0x4F06000A,
    0x4F10000A, 0xFFFF0000, 0x5046000A, 0x5047000A, 0x5048000A, 0x5049000A, 0xFFFF0000, 0x501E000A,
    0x5028000A, 0x5032000A, 0x503C000A, 0xFFFF0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0xC0400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (unsigned int)addrLow_Weaponai_InitializeSwitchForSingleRound_us, (unsigned int)D_00232B44, 0x00000000, 0x00004E20, 0x3F800000,
    0x00000000, 0x00000000, 0x00000001, (unsigned int)addrLow_Weapon_ReleaseHandlesAndExitState39_us, (unsigned int)addrLow_Weapon_UpdateIdleWeaponSelection_us, 0x00000000, 0x00004E2A, 0x3F800000,
    0x00000002, 0x00000000, 0x00000002, (unsigned int)addrLow_Weapon_ReleaseLinkedActorHandlesEntryVariant1, (unsigned int)addrLow_Weaponai_UpdateAlternateFire_us, 0x00000000, 0x00004E84, 0x3F800000,
    0x00000000, 0x00000000, 0x00000003, 0x00000000, (unsigned int)addrLow_Weaponai_UpdateAlternateFire_us, 0x00000000, 0x00004E8E, 0x3F800000,
    0x00000000, 0x00000000, 0x00000004, (unsigned int)D_00232C68, (unsigned int)addrLow_Weapon_UpdateTriggerReleaseState_us, 0x00000000, 0x800C9F14, 0x3F800000,
    0x00000003, 0x00000000, 0x00000008, (unsigned int)addrLow_Weapon_InitializeChargeForWeaponFive_eu_us, (unsigned int)addrLow_Weaponai_UpdateHeldFire_us, 0x00000000, 0x800C9F28, 0x3F800000,
    0x00000003, 0x00000000, 0x00000007, 0x00000000, (unsigned int)addrLow_Weapon_UpdateIdleWeaponSelection_us, 0x00000000, 0x00004F19, 0x3F800000,
    0x00000003, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x800C9F68, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000002, 0x00000000, (unsigned int)addrLow_Weaponai_UpdateSpinAndAlternateFire_us, 0x00000000, 0x00004E84, 0x3F800000,
    0x00000000, 0x00000000, 0x00000003, 0x00000000, (unsigned int)addrLow_Weaponai_UpdateSpinAndAlternateFire_us, 0x00000000, 0x00004E8E, 0x3F800000,
    0x00000000, 0x00000000, 0x00000005, (unsigned int)addrLow_Weapon_PlayStartupCue9E2_us, (unsigned int)addrLow_Weapon_AdvanceSpinAndTriggerMode_us, 0x00000000, 0x00004EE8, 0x3F800000,
    0x00000003, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x800C9F68, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000004, 0x00000000, (unsigned int)addrLow_Weaponai_SelectReleasedFireState_us, 0x00000000, 0x00004EE8, 0x3F800000,
    0x00000003, 0x00000000, 0x00000008, 0x00000000, (unsigned int)addrLow_Weaponai_SelectReleasedFireState_us, 0x00000000, 0x00004EE8, 0x3F800000,
    0x00000003, 0x00000020, 0x00000005, 0x00000000, (unsigned int)addrLow_Weapon_UpdateTriggerReleaseState_us, 0x00000000, 0x00004EF2, 0x3F800000,
    0x00000003, 0x00000020, 0x00000009, 0x00000000, (unsigned int)addrLow_Weapon_UpdateTriggerReleaseState_us, 0x00000000, 0x00005046, 0x3F800000,
    0x00000003, 0x00000020, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000,
};
#endif

/* 800C9FAC.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800C9FAC */
unsigned int g_WeaponSwitchStateTableUsEncodedWords[1] = {
    0x002A51C8,
};
#endif

/* 800CA258_5.CPP */
#if defined(VERSION_EU)
const char g_overlayLevelInfoText[12] =
    "level info\000\000";
#endif

/* 800CA270_6.CPP */
#if defined(VERSION_EU_X)
const char g_overlayLevelNavVisionLabelText[20] =
    "level nav vision\000\000\000\000";
#endif
