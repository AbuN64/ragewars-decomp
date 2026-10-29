#include "DATA/OVL1_F/WEAPON_CHARGE_CALLBACK_ADDRESS.H"
#include "DATA/WEAPON_CALLBACKS/WEAPON_UPDATENORMALFIREACTION_ADDRESS.H"
#include "DATA/WEAPON_CALLBACKS/SECONDARY_ACTOR_CALLBACK_LABELS.H"
#include "DATA/WEAPON_CALLBACKS/OVERLAY_SIX_SECOND_CALLBACK_ROM_ENTRY.H"

/* 800CF51C.CPP */
#if defined(VERSION_US_REV1)
extern char g_weaponFireStateCallbackTable[];
void * k_ResourcesEncodedWordsBlock3[8] = {
    (void *)&g_weaponFireStateCallbackTable, 0, 0, 0,
    0, 0, 0, 0,
};
#endif

/* 800CF51C_2.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_D013C_us_rev1.c */
unsigned int g_ResourcesEncodedWordsBlock8[2] = {
    0x00000002, (unsigned int)addrLow_Weapon_ReleaseLinkedActorHandlesEntryVariant2,
};
#endif

/* 800CF544.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF51C_unclaimed_D0144 */
unsigned int g_ResourcesEncodedWordsBlock33[2] = {
    (unsigned int)Weapon_UpdateNormalFireAction_Address, 0x00000000,
};

unsigned int g_ResourcesEncodedWordsBlock72[4] = {
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* 800CF55C.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_D015C_us_rev1.c */
unsigned int g_ResourcesEncodedWordsBlock25[2] = {
    0x00000003, 0x00000000,
};
#endif

/* 800CF564.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF51C_unclaimed_D0144_unclaimed_D015C_unclaimed_D0164 */
unsigned int g_ResourcesEncodedWordsBlock21[2] = {
    (unsigned int)Weapon_UpdateNormalFireAction_Address, 0x00000000,
};
#endif

/* 800CF564_2.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_resource_animation_D016C_us_rev1.c */
unsigned int g_ResourcesEncodedWordsBlock36[4] = {
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* 800CF57C.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_D017C_us_rev1.c */
unsigned int g_ResourcesEncodedWordsBlock45[2] = {
    0x00000004, (unsigned int)Weapon_InitializeChargeAndStartupCues_Address,
};
#endif

/* 800CF584.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF51C_unclaimed_D0144_unclaimed_D015C_unclaimed_D0164_unclaimed_D017C_unclaimed_D0184 */
unsigned int g_ResourcesEncodedWordsBlock57[2] = {
    (unsigned int)Weaponai_UpdateChargeAndRepeatCue_Address, 0x00000000,
};

unsigned int g_ResourcesEncodedWordsBlock74[4] = {
    0x00004EE8, 0x3F800000, 0x00000003, 0x00000000,
};
#endif

/* 800CF59C.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_end_D019C_us_rev1.c */
unsigned int g_ResourcesEncodedWordsBlock43[1] = {
    0xFFFFFFFF,
};
#endif

/* 800CF5A0.CPP */

