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
#include "DATA/WEAPON_CALLBACKS/WEAPON_FIRE_STATE_TABLE.H"

#if defined(VERSION_US_REV1)
extern char addrLow_Weapon_ReleaseLinkedActorHandles[];

/* Rates read by Playerai_UpdateTargetFacing and Playerai_UpdateReactionReserve. */
f32 g_playerTargetFacingEaseRate = 0.35f;
f32 g_playerReactionReserveApproachRate = 0.00625f;

/* Linker fill between the rate and the next constant: no instruction reads it and the other builds hold other words here. */
u32 g_playerReactionReserveApproachRatePad[2] = {
    0xFFFFFFFF, 0xFFFF0000,
};

f32 k_PlayeraiInitializeplayerhealthOneWords = 1.0f;

struct WeaponAnimationChoice g_weaponAnimationChoicesA[5] = {
    { 20210, 10 }, { 20220, 10 }, { 20230, 10 }, { 20240, 10 }, { -1, 0 },
};

struct WeaponAnimationChoice g_weaponAnimationChoicesB[5] = {
    { 20550, 10 }, { 20551, 10 }, { 20552, 10 }, { 20553, 10 }, { -1, 0 },
};

struct WeaponAnimationChoice g_weaponAnimationChoicesC[5] = {
    { 20510, 10 }, { 20520, 10 }, { 20530, 10 }, { 20540, 10 }, { -1, 0 },
};

/* Mirror flags read by Player_BuildWeaponHandTransform, followed by two unused zero words. */
s32 g_weaponHandMirrorX = 0;
s32 g_weaponHandMirrorY = 0;
s32 g_weaponHandMirrorZ = 0;
s32 g_weaponHandMirrorPad[2] = { 0, 0 };

f32 k_PlayeraiInitializeplayerhealthNegativeThree = -3.0f;

/* Base state table of the weapon fire state machine (Weapon_InitializeFireStateCallbacks installs it). */
WEAPON_STATE_TABLE(8) g_weaponFireStateCallbackTable = {
    0,
    { 0 },
    {
        { 0, addrLow_Weaponai_InitializeSwitchForSingleRound, g_Weapon_ResetControllerAndSpinEncodedCallback, 0, 20000, 1.0f, 0, 0 },
        { 1, addrLow_Weapon_ReleaseHandlesAndExitState39, addrLow_Weapon_UpdateIdleWeaponSelection, 0, 20010, 1.0f, 2, 0 },
        { 2, addrLow_Weapon_ReleaseLinkedActorHandlesEntryVariant2, addrLow_Weaponai_UpdateAlternateFire, 0, 20100, 1.0f, 0, 0 },
        { 3, 0, addrLow_Weaponai_UpdateAlternateFire, 0, 20110, 1.0f, 0, 0 },
        { 4, addrLow_Weapon_ReleaseLinkedActorHandles, addrLow_Weapon_UpdateTriggerReleaseState, 0, (u32)g_weaponAnimationChoicesA, 1.0f, 3, 0 },
        { 8, addrLow_Weapon_InitializeChargeForWeaponFive, addrLow_Weaponai_UpdateHeldFire, 0, (u32)g_weaponAnimationChoicesB, 1.0f, 3, 0 },
        { 7, 0, addrLow_Weapon_UpdateIdleWeaponSelection, 0, 20249, 1.0f, 3, 0 },
        { -1 },
    },
};

/* Spin weapon states searched before the base table. */
WEAPON_STATE_TABLE(4) g_weaponSpinFireStateTable = {
    (struct WeaponStateTable *)&g_weaponFireStateCallbackTable,
    { 0 },
    {
        { 2, 0, addrLow_Weaponai_UpdateSpinAndAlternateFire, 0, 20100, 1.0f, 0, 0 },
        { 3, 0, addrLow_Weaponai_UpdateSpinAndAlternateFire, 0, 20110, 1.0f, 0, 0 },
        { 5, addrLow_Weapon_PlayStartupCue9E2, addrLow_Weapon_AdvanceSpinAndTriggerMode, 0, 20200, 1.0f, 3, 0 },
        { -1 },
    },
};

/* Trigger release weapon states searched before the base table. */
WEAPON_STATE_TABLE(5) g_weaponTriggerReleaseFireStateTable = {
    (struct WeaponStateTable *)&g_weaponFireStateCallbackTable,
    { 0 },
    {
        { 4, 0, addrLow_Weaponai_SelectReleasedFireState, 0, 20200, 1.0f, 3, 0 },
        { 8, 0, addrLow_Weaponai_SelectReleasedFireState, 0, 20200, 1.0f, 3, 0x20 },
        { 5, 0, addrLow_Weapon_UpdateTriggerReleaseState, 0, 20210, 1.0f, 3, 0x20 },
        { 9, 0, addrLow_Weapon_UpdateTriggerReleaseState, 0, 20550, 1.0f, 3, 0x20 },
        { -1 },
    },
};
#endif
