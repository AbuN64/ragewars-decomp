
extern char g_weaponFireStateCallbackTable[];
extern char k_PlayeraiInitializeplayerhealthEncodedWords[];

#include "TYPES.H"

/* 800CA290.CPP */
#if defined(VERSION_US)
extern char addrLow_Weaponai_DecaySpinAndActivateEffect_us[];
extern char addrLow_Weaponai_ToggleFiringModeWithAmmoCheck_us[];
extern char addrLow_Weaponai_UpdateSpinAndRepeatCue_us[];
extern char addrLow_Weaponai_SettleSpinToThirdTurn_us[];
extern char addrLow_Weaponai_UpdateAnimatedFiringMode_us[];
extern char addrLow_Weaponai_TryEnterAmmoCostState_us[];
extern char addrLow_Weaponai_TryEnterAlternateStateEight_us[];
extern char addrLow_Weaponai_TryEnterAlternateAmmoMode_us[];
extern char addrLow_Weaponai_TryEnterChargedAlternateMode_us[];
extern char addrLow_Weaponai_UpdateForceMarkerTrigger_us[];
extern char addrLow_Weaponai_UpdateHeldFire_us[];
extern char addrLow_Weapon_InitializeFireStateCallbacks_eu_us[];
extern char addrLow_Weapon_ReleaseLinkedActorHandlesEntryVariant1[];
extern char addrLow_Weapon_ApplyScaledSideYaw_us[];
extern char addrLow_Weapon_ApplySideDependentYaw_us[];
extern char addrLow_Weapon_EnterChargeStateWithCues_us[];
extern char addrLow_Weapon_EmptyChargeStateHookEntryVariant1[];
extern char addrLow_Weapon_SetDelayAndRequestStateEight_us[];
extern char addrLow_Weapon_StartStateB_us[];
extern char addrLow_Weapon_UpdateStateB_us[];
extern char addrLow_Weapon_UpdateSpecialFireAndAmmo_us[];
extern char addrLow_Weapon_RequestReleaseOnEnabledEvent_us[];
extern char addrLow_Weapon_PlayStartupCue80C_us[];
extern char addrLow_Weapon_UpdateAlternateTriggerCompletion_us[];
extern char addrLow_Weapon_EaseSpinForActionFive_us[];
extern char addrLow_Weapon_ApproachSpinPhaseAndRelease_us[];
extern char addrLow_Weapon_TranslateEventSixByPitch_us[];
extern char addrLow_Gsky_FloorSurfaceNoOpEntryVariant1[];
u32 k_weaponStateRecordsUs[1026] = {
    0x800C9F68, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000002, (unsigned int)addrLow_Weapon_ReleaseLinkedActorHandlesEntryVariant1, (unsigned int)addrLow_Weaponai_ToggleFiringModeWithAmmoCheck_us, 0x00000000,
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000, 0x00000003, 0x00000000,
    (unsigned int)addrLow_Weaponai_ToggleFiringModeWithAmmoCheck_us, 0x00000000, 0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
    0x00000004, (unsigned int)addrLow_Weapon_EnterChargeStateWithCues_us, (unsigned int)addrLow_Weaponai_UpdateSpinAndRepeatCue_us, 0x00000000, 0x00004EE8, 0x3F800000,
    0x00000003, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800C9F68, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000002, 0x00000000, (unsigned int)addrLow_Weaponai_UpdateAnimatedFiringMode_us, 0x00000000, 0x00004E84, 0x3F800000,
    0x00000000, 0x00000000, 0x00000003, 0x00000000, (unsigned int)addrLow_Weaponai_UpdateAnimatedFiringMode_us, 0x00000000,
    0x00004E8E, 0x3F800000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x800C9F68, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000008, (unsigned int)addrLow_Weapon_SetDelayAndRequestStateEight_us, (unsigned int)addrLow_Weaponai_UpdateHeldFire_us, 0x00000000,
    0x800C9F28, 0x3F800000, 0x00000003, 0x00000000, 0xFFFFFFFF, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x800C9F68, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000002, 0x00000000, (unsigned int)addrLow_Weaponai_TryEnterAmmoCostState_us, 0x00000000,
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000, 0x00000003, 0x00000000,
    (unsigned int)addrLow_Weaponai_TryEnterAmmoCostState_us, 0x00000000, 0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
    0x0000000B, (unsigned int)addrLow_Weapon_StartStateB_us, (unsigned int)addrLow_Weapon_UpdateStateB_us, 0x00000000, 0x00004EE8, 0x3F800000,
    0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800C9F68, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000002, 0x00000000, (unsigned int)addrLow_Weaponai_TryEnterAlternateStateEight_us, 0x00000000, 0x00004E84, 0x3F800000,
    0x00000000, 0x00000000, 0x00000003, 0x00000000, (unsigned int)addrLow_Weaponai_TryEnterAlternateStateEight_us, 0x00000000,
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x800C9F68, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000002, 0x00000000, (unsigned int)addrLow_Weapon_UpdateSpecialFireAndAmmo_us, 0x00000000,
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000, 0x00000003, 0x00000000,
    (unsigned int)addrLow_Weapon_UpdateSpecialFireAndAmmo_us, 0x00000000, 0x00004E8E, 0x3F800000, 0x00000000, 0x00000000,
    0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x800C9F68, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, (unsigned int)addrLow_Weapon_ReleaseLinkedActorHandlesEntryVariant1,
    (unsigned int)addrLow_Weaponai_TryEnterAlternateAmmoMode_us, 0x00000000, 0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
    0x00000003, 0x00000000, (unsigned int)addrLow_Weaponai_TryEnterAlternateAmmoMode_us, 0x00000000, 0x00004E8E, 0x3F800000,
    0x00000000, 0x00000000, 0x00000005, 0x00000000, (unsigned int)addrLow_Weapon_RequestReleaseOnEnabledEvent_us, 0x00000000,
    0x00004EE8, 0x3F800000, 0x00000003, 0x00000000, 0xFFFFFFFF, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x800CA5B0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000005, (unsigned int)addrLow_Weapon_PlayStartupCue80C_us, (unsigned int)addrLow_Weapon_UpdateAlternateTriggerCompletion_us, 0x00000000,
    0x00004EE8, 0x3F800000, 0x00000003, 0x00000000, 0xFFFFFFFF, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x41F00000, 0x800C9F68, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, (unsigned int)addrLow_Weaponai_TryEnterChargedAlternateMode_us,
    0x00000000, 0x00004E84, 0x3F800000, 0x00000000, 0x00000000, 0x00000003,
    0x00000000, (unsigned int)addrLow_Weaponai_TryEnterChargedAlternateMode_us, 0x00000000, 0x00004E8E, 0x3F800000, 0x00000000,
    0x00000000, 0x00000005, 0x00000000, (unsigned int)addrLow_Weapon_ApproachSpinPhaseAndRelease_us, 0x00000000, 0x00004E84,
    0x3F800000, 0x00000003, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800C9F68,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000002, 0x00000000, (unsigned int)addrLow_Weaponai_UpdateForceMarkerTrigger_us, 0x00000000, 0x00004E84,
    0x3F800000, 0x00000000, 0x00000000, 0x00000003, 0x00000000, (unsigned int)addrLow_Weaponai_UpdateForceMarkerTrigger_us,
    0x00000000, 0x00004E8E, 0x3F800000, 0x00000000, 0x00000000, 0xFFFFFFFF,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (unsigned int)addrLow_Weapon_InitializeFireStateCallbacks_eu_us, 0x00000000, 0x00010064, 0x0414000A, 0x00010064,
    0x042D0014, 0x00010064, 0x03E8000A, 0x00010064, 0x03EB0019, 0x000000C8,
    0x03F10001, 0x000000C8, 0x04310019, 0x000000C8, 0x00070001, 0x000000C8,
    0x0439000C, 0x000000C8, 0x04330001, 0x000000C8, 0x04370001, 0x000000C8,
    0x03F90002, 0x00010064, 0x03F5000A, 0x00010064, 0x04160005, 0x00010064,
    0x04050003, 0x00010064, 0x041B0032, 0x00010064, 0x0401000A, 0x00010064,
    0x04030032, 0x0002004B, 0x03F70001, 0x0002004B, 0x04250001, 0x0002004B,
    0x03EC0001, 0x0002004B, 0x03EF0001, 0x00010064, 0x03FB000A, 0x00010064,
    0x03FE0064, 0x00010064, 0x0408000A, 0x00010064, 0x04320032, 0x00010064,
    0x03FF0005, 0x00010064, 0x04190032, 0x00030014, 0x01290001, 0x00040014,
    0x040A0001, 0x00050001, 0x040C0001, 0x00060014, 0x040E0001, 0x00010064,
    0x04B0000A, 0x00010064, 0x04B10019, 0x000000C8, 0x04BB0001, 0x000000C8,
    0x04BC0019, 0x000000C8, 0x00070001, 0x000000C8, 0x04C4000C, 0x000000C8,
    0x04C10001, 0x000000C8, 0x04C20001, 0x000000C8, 0x04CB0002, 0x00010064,
    0x04C5000A, 0x00010064, 0x04160005, 0x00010064, 0x04DA0003, 0x00010064,
    0x04DD0032, 0x00010064, 0x0401000A, 0x00010064, 0x04030032, 0x0002004B,
    0x04C90001, 0x0002004B, 0x04CA0001, 0x0002004B, 0x04B40001, 0x0002004B,
    0x03EF0001, 0x00010064, 0x04CD000A, 0x00010064, 0x04D00064, 0x00010064,
    0x04E0000A, 0x00010064, 0x04E30032, 0x00010064, 0x04D10005, 0x00010064,
    0x04D30032, 0x00030014, 0x01290001, 0x00040014, 0x040A0001, 0x00050001,
    0x040C0001, 0x00060014, 0x040E0001, 0x800D1D6C, 0x04C30BB8, 0x0000FFFF,
    0xFFFFFFFF, 0xFFFF0000, 0x00000003, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800CA650, 0x00000000, (unsigned int)addrLow_Weapon_EaseSpinForActionFive_us, 0x800D1D70, 0x04D3FFFF, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000003, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800C9F68, 0x00000000, 0x00000000, 0x800D1D74, 0x04D4FFFF, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000003, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800C9F68, 0x00000000, 0x00000000, 0x800D1D78, 0x04C40BB9, 0x0000FFFF,
    0xFFFF02F8, 0x02F90000, 0x00000003, 0x00000000, 0x3F5F66F4, 0x800CA7DC,
    0x800CA7E4, 0x00000000, 0x800CA7DC, 0x800CA7E4, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800CA330, 0x00000000, (unsigned int)addrLow_Weapon_EmptyChargeStateHookEntryVariant1, 0x800D1D7C, 0x04C50BBA, 0x0C83FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000023, 0x00000000, 0x00000000, 0x800CA7EC,
    0x800CA7F4, 0x00000000, 0x800CA8D4, 0x800CA8DC, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800C9F68, 0x00000000, 0x00000000, 0x800D1D80, 0x04C60BBB, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000003, 0x00000000, 0x3F860A93, 0x800CA7FC,
    0x800CA804, 0x00000000, 0x800CA8E4, 0x800CA8EC, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800CA410, 0x00000000, 0x00000000, 0x800D1D84, 0x04C70BBC, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000007, 0x00000000, 0x00000000, 0x800CA80C,
    0x800CA814, 0x00000000, 0x800CA8F4, 0x800CA8FC, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800CA5B0, 0x00000000, 0x00000000, 0x800D1D88, 0x04C80BBD, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000003, 0x00000000, 0x00000000, 0x800CA81C,
    0x800CA824, 0x00000000, 0x800CA904, 0x800CA90C, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800C9F68, 0x00000000, 0x00000000, 0x800D1D8C, 0x04C90BBE, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000003, 0x00000000, 0x00000000, 0x800CA82C,
    0x00000000, 0x00000000, 0x800CA914, 0x00000000, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800CA1EC, (unsigned int)addrLow_Weapon_ApplyScaledSideYaw_us, (unsigned int)addrLow_Weaponai_DecaySpinAndActivateEffect_us, 0x800D1D90, 0x04CA0BBF, 0x0C83FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000027, 0x00000000, 0x00000000, 0x800CA834,
    0x800CA83C, 0x00000000, 0x800CA91C, 0x800CA924, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800C9F68, 0x00000000, 0x00000000, 0x800D1D94, 0x04CB0BC0, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000003, 0x00000000, 0x00000000, 0x800CA844,
    0x800CA84C, 0x00000000, 0x800CA92C, 0x800CA934, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800C9F68, 0x00000000, 0x00000000, 0x800D1D98, 0x04CC0BC1, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000003, 0x00000000, 0x00000000, 0x800CA854,
    0x800CA85C, 0x00000000, 0x800CA93C, 0x800CA944, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800CA3B0, 0x00000000, 0x00000000, 0x800D1D9C, 0x04CD0BC2, 0x0000FFFF,
    0xFFFFFFFF, 0xFFFF0000, 0x00000003, 0x00000000, 0x00000000, 0x800CA864,
    0x800CA86C, 0x00000000, 0x800CA94C, 0x800CA954, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800CA4B0, 0x00000000, 0x00000000, 0x800D1DA0, 0x04CE0BC3, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000007, 0x00000000, 0x00000000, 0x800CA874,
    0x00000000, 0x00000000, 0x800CA95C, 0x00000000, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800CA754, 0x00000000, 0x00000000, 0x800D1DA4, 0x04CF0BC4, 0x0000FFFF,
    0xFFFFFFFF, 0xFFFF0000, 0x00000003, 0x00000000, 0x00000000, 0x800CA87C,
    0x00000000, 0x00000000, 0x800CA964, 0x00000000, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800CA530, 0x00000000, 0x00000000, 0x800D1DA8, 0x04D00BC5, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000003, 0x00000000, 0x00000000, 0x800CA884,
    0x800CA88C, 0x00000000, 0x800CA96C, 0x800CA974, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800CA290, (unsigned int)addrLow_Weapon_ApplySideDependentYaw_us, (unsigned int)addrLow_Weaponai_SettleSpinToThirdTurn_us, 0x800D1DAC, 0x04D10BC6, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000003, 0x00000000, 0x00000000, 0x800CA894,
    0x800CA89C, 0x00000000, 0x800CA97C, 0x800CA984, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800CA088, 0x00000000, (unsigned int)addrLow_Weapon_EaseSpinForActionFive_us, 0x800D1DB0, 0x04D20BC7, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000003, 0x00000000, 0x00000000, 0x800CA8A4,
    0x800CA8AC, 0x00000000, 0x800CA98C, 0x800CA994, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800CA6B4, (unsigned int)addrLow_Weapon_TranslateEventSixByPitch_us, 0x00000000, 0x800D1DB4, 0x04D50BC8, 0x0000FFFF,
    0xFFFF02C6, 0x02C70000, 0x00000003, 0x40800000, 0x3F490FDC, 0x800CA8B4,
    0x00000000, 0x00000000, 0x800CA99C, 0x00000000, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800C9F68, 0x00000000, 0x00000000, 0x800D1DB8, 0x04D60BC9, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000003, 0x00000000, 0x00000000, 0x800CA9A4,
    0x00000000, 0x00000000, 0x800CA8BC, 0x00000000, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800C9F68, 0x00000000, 0x00000000, 0x800D1DBC, 0x04D70BCA, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000003, 0x00000000, 0x00000000, 0x800CA8CC,
    0x00000000, 0x00000000, 0x800CA9B4, 0x00000000, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800C9F68, 0x00000000, 0x00000000, 0x800D1DC4, 0x04D90BCC, 0x0000FFFF,
    0xFFFF02DA, 0x02DA0000, 0x00000003, 0x00000000, 0x00000000, 0x800CA8C4,
    0x00000000, 0x00000000, 0x800CA9AC, 0x00000000, 0x00000000, 0x40C00000,
    0x40E00000, 0x41200000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x800C9F68, 0x00000000, 0x00000000, 0x800CA9BC, 0x800CAADC, 0x800CAB3C,
    0x800CAB9C, 0x800CABFC, 0x800CAC5C, 0x800CACBC, 0x800CAD1C, 0x800CAD7C,
    0x800CADDC, 0x800CAE3C, 0x800CAE9C, 0x800CAEFC, 0x800CAF5C, 0x800CAFBC,
    0x800CB01C, 0x800CAA1C, 0x800CAA7C, 0x800CB07C, 0x800CB0DC, 0x800CB13C,
    0x800CB19C, 0x00000000, 0x0BEA0BEB, 0x0BECFFFF, 0x0BED0BEE, 0x0BEF0BF0,
    0x800D1E8C, 0x800D1E90, 0x800D1E94, 0x800D1E98, 0x800D1E9C, 0x800D1EA0,
    0x800D1EA4, 0x585F5348, 0x4F544755, 0x4E5F5041, 0x00000000, (unsigned int)addrLow_Gsky_FloorSurfaceNoOpEntryVariant1,
};
#endif

/* 800CA434.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CA434 */
float g_PlayeraiInitializeplayerhealthEncodedWordsBlock1[3] = {
    3.0e+02f, 255.0f, 3.0e+02f,
};
#endif

/* 800CAACC.CPP */
#if defined(VERSION_EU_X)
extern char addrLow_Player_UpdateFlyMode_eu_x[];
extern char addrLow_Player_UpdateStandingState_eu_x[];
extern char addrLow_Playerai_UpdateWalkingMovement_eu_x[];
extern char addrLow_Player_UpdateWadingState_eu_x[];
extern char addrLow_Player_UpdateFloatingState_eu_x[];
extern char addrLow_Player_UpdateSwimmingState_eu_x[];
extern char addrLow_Playerai_ResetPlayerAfterDeath_eu_x[];
extern char addrLow_Playerai_UpdateTravelSequenceEntryVariant2[];
extern char addrLow_Playerai_UpdateHazardDamageEntryVariant2[];
extern char addrLow_Playerai_UpdateTargetFacingEntryVariant2[];
extern char addrLow_Player_ZeroBodyVelocity_eu_x[];
extern char addrLow_Player_StartMovingOnStickInput_eu_x[];
extern char addrLow_Playerai_StartWalkingMovement_eu_x[];
extern char addrLow_Player_StartGroundMoveState_eu_x[];
extern char addrLow_Player_UpdateGroundMoveState_eu_x[];
extern char addrLow_Player_BeginJump_eu_x[];
extern char addrLow_Player_UpdateJumpAscent_eu_x[];
extern char addrLow_Player_UpdateJumpAirMotion_eu_x[];
extern char addrLow_Player_BeginLateralLeap_eu_x[];
extern char addrLow_Player_UpdateLateralLeap_eu_x[];
extern char addrLow_Player_UpdateLeapMotion_eu_x[];
extern char addrLow_Player_ClearGlobalFlagBit[];
extern char addrLow_Player_AbsorbImpact[];
extern char addrLow_Player_DampMotion_eu_x[];
extern char g_Player_ResetMovementInputCallbackAddressDe[];
extern char g_Player_ResetMovementInputAddress[];
extern char addrLow_Player_ResetObjectVelocity[];
extern char addrLow_Player_UpdateAfterResetObjectVelocity_eu_x[];
extern char addrLow_Player_StartAimPreviousPositionAtReset_eu_x[];
extern char addrLow_Player_AimPreviousPositionAtReset_eu_x[];
extern char addrLow_Playerai_UpdateAfterResetPlayerAfterDeath_eu_x[];
extern char addrLow_Player_ResetStunAndReleaseHandles_eu_x[];
extern char addrLow_Player_ResetStunFlags_eu_eu_x[];
extern char addrLow_Player_UpdateAfterResetStunFlags_eu_x[];
extern char addrLow_Playerai_BeginRoundEndWaitEntryVariant2[];
extern char addrLow_Playerai_UpdateRoundEndWaitEntryVariant3[];
extern char addrLow_Playerai_StartTargetFacing_eu_x[];
extern char addrLow_Playerai_StartRequestCinemaTrack_eu_x[];
extern char g_PlayerRequestCinemaTrackCallbackAddressUs[];
extern char addrLow_Playerai_StartRequestCinemaTrackDe_eu_x[];
extern char g_PlayerRequestCinemaTrackCallbackAddressDe[];
extern char addrLow_Playerai_StartEntry5B04_eu_x[];
extern char addrLow_Playerai_UpdateEntry5B04_eu_x[];
extern char addrLow_Playerai_SetRunEndFlagEntryVariant2[];
extern char g_PlayerSequenceRunEndUpdateCallbackAddressUs[];
extern char addrLow_Playerai_RequestTrackFifty[];
extern char g_PlayerSequence13StartCallbackAddressUs[];
extern char g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant7[];
extern char g_PlayerSequence14StartCallbackAddressUs[];
extern char g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant8[];
extern char g_PlayerSequence15StartCallbackAddressUs[];
extern char g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant9[];
extern char g_PlayerSequence20StartCallbackAddressUs[];
extern char g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant10[];
extern char g_PlayerSequence70StartCallbackAddressUs[];
extern char g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant11[];
extern char g_Playerai_StartPlayerSequence60Address[];
extern char g_Playerai_UpdateSequence60RunEndPoseCallbackAddressUs[];
extern char g_Playerai_StartPlayerSequence71CallbackAddressUs[];
extern char g_Playerai_UpdateSequence71RunEndPoseCallbackAddressUs[];
extern char g_Playerai_StartPlayerSequence72CallbackAddressUs[];
extern char g_Playerai_UpdateSequence72RunEndPoseCallbackAddressUs[];
extern char g_Playerai_StartPlayerSequence73CallbackAddressUs[];
extern char g_Playerai_UpdateSequence73RunEndPoseCallbackAddressUs[];
extern char g_Playerai_StartPlayerSequence74CallbackAddressUs[];
extern char g_Playerai_UpdateSequence74RunEndPoseCallbackAddressUs[];
extern char g_Playerai_InitializeActorModelEffectCallbackAddressUs[];
extern char addrLow_Playerai_InitializeActorModelEffect[];
extern char addrLow_Playerai_StartPlayerSequence60_eu_x[];
extern char addrLow_Playerai_UpdateSequence60RunEndPose_eu_x[];
extern char addrLow_Playerai_StartPlayerSequence71_eu_x[];
extern char addrLow_Playerai_UpdateSequence71RunEndPose_eu_x[];
extern char addrLow_Playerai_StartPlayerSequence72_eu_x[];
extern char addrLow_Playerai_UpdateSequence72RunEndPose_eu_x[];
extern char addrLow_Playerai_StartPlayerSequence73_eu_x[];
extern char addrLow_Playerai_UpdateSequence73RunEndPose_eu_x[];
extern char addrLow_Playerai_StartPlayerSequence74[];
extern char addrLow_Playerai_UpdateSequence74RunEndPose_eu_x[];
extern char addrLow_Playerai_InitializeActorModelEffect_eu_x[];
extern char addrLow_Playerai_StartMovingSequenceState_eu_x[];
extern char addrLow_Playerai_EnterMovingSequenceState[];
extern char addrLow_Playerai_StartStoppedSequenceState_eu_x[];
extern char addrLow_Playerai_EnterStoppedSequenceState[];
extern char addrLow_Playerai_OffsetActorForState15_eu_x[];
unsigned int g_playerMovementStateWordsUs[662] = {
    0x3FDD2F1C, 0x4030F27C, 0x41A5E354, 0x3F84B5DE, 0x00000000, 0x00000000, 0x00000000, 0x403851EC,
    0x41ACCCCC, 0x3F8A3D71, 0x3FDD2F1C, 0x414F5C2A, 0x3F25E355, 0x00000000, 0x00000000, 0x00000000,
    0x4123D70A, 0x41F5C28F, 0x41570A3D, 0x4123D70A, 0x420F5C29, 0x41570A3D, 0x00000000, 0x00000000,
    0x00000000, 0x40A3D70A, 0x4175C28F, 0x4075C28F, 0x40A3D70A, 0x418F5C29, 0x4075C28F, 0x00000000,
    0x00000000, 0x00000000, 0x3E800000, 0x3F666666, 0x3F19999A, 0x3E99999A, 0xBFC90FDC, 0x3FC90FDC,
    0x3E800000, 0x3F666666, 0x3F19999A, 0x3E99999A, 0xBF490FDC, 0x3FC90FDC, 0x00000000, 0x00000000,
    0x3F000000, 0x3E800000, 0xBD8EFA36, 0x3FC90FDC, 0x40F5C28F, 0x41B851EB, 0x40B851EB, 0x40F5C28F,
    0x41D70A3E, 0x40B851EB, 0x4123D70A, 0x3F449BA6, 0x00000001, 0x4003126F, 0x4175C28F, 0x3F83126F,
    0x41A3D70A, 0x3FC49BA6, 0x41A3D70A, 0x43199999, 0x42CCCCCC, 0x00000001, 0x3ECCCCCD, 0x3F000000,
    0x3F800000, 0x3E800000, 0xBFC90FDC, 0x3FC90FDC, 0x3E4CCCCD, 0x3E800000, 0x3F000000, 0x3E000000,
    0xBFC90FDC, 0x3FC90FDC, 0x3F83126F, 0x40F5C28F, 0x3F03126F, 0x4123D70A, 0x3F449BA6, 0x4123D70A,
    0x42999999, 0x424CCCCC, 0x00000000, (unsigned int)addrLow_Player_ZeroBodyVelocity_eu_x, (unsigned int)addrLow_Player_UpdateFlyMode_eu_x, 0x8010A4F8, 0x00000000, 0x00000001,
    0x00020000, 0x00000000, (unsigned int)addrLow_Player_UpdateFlyMode_eu_x, 0x8010A4F8, 0x00000000, 0x00000001, 0x00020000, (unsigned int)addrLow_Player_StartMovingOnStickInput_eu_x,
    (unsigned int)addrLow_Player_UpdateStandingState_eu_x, 0x8010A458, 0x00000000, 0x00000001, 0x00020000, (unsigned int)addrLow_Playerai_StartWalkingMovement_eu_x, (unsigned int)addrLow_Playerai_UpdateWalkingMovement_eu_x, 0x8010A458,
    0x00000000, 0x000007DA, 0x00030000, (unsigned int)addrLow_Player_StartGroundMoveState_eu_x, (unsigned int)addrLow_Player_UpdateGroundMoveState_eu_x, 0x8010A458, 0x00000000, 0x00000A64,
    0x00030000, (unsigned int)addrLow_Player_BeginJump_eu_x, (unsigned int)addrLow_Player_UpdateJumpAscent_eu_x, 0x8010A190, 0x00000800, 0x000007EE, 0x00020000, 0x00000000,
    (unsigned int)addrLow_Player_UpdateJumpAirMotion_eu_x, 0x8010A190, 0x00000800, 0x000007EE, 0x00020000, (unsigned int)addrLow_Player_BeginLateralLeap_eu_x, (unsigned int)addrLow_Player_UpdateLateralLeap_eu_x, 0x8010A458,
    0x00000000, 0x000007EE, 0x00020000, 0x00000000, (unsigned int)addrLow_Player_UpdateLeapMotion_eu_x, 0x8010A458, 0x00000000, 0x000007EE,
    0x00020000, (unsigned int)addrLow_Player_ClearGlobalFlagBit, (unsigned int)addrLow_Player_UpdateWadingState_eu_x, 0x8010A418, 0x00000080, 0x000008A2, 0x00020000, (unsigned int)addrLow_Player_ClearGlobalFlagBit,
    (unsigned int)addrLow_Player_UpdateWadingState_eu_x, 0x8010A418, 0x00000080, 0x000008A2, 0x00030000, (unsigned int)addrLow_Player_AbsorbImpact, (unsigned int)addrLow_Player_UpdateFloatingState_eu_x, 0x80109FB0,
    0x00000040, 0x000008A2, 0x00020000, (unsigned int)addrLow_Player_AbsorbImpact, (unsigned int)addrLow_Player_UpdateFloatingState_eu_x, 0x80109FB0, 0x00000040, 0x000008A2,
    0x00030000, (unsigned int)addrLow_Player_DampMotion_eu_x, (unsigned int)g_Player_ResetMovementInputCallbackAddressDe, 0x8010A1B0, 0x00000000, 0x000007DA, 0x00020000, (unsigned int)addrLow_Player_DampMotion_eu_x,
    (unsigned int)g_Player_ResetMovementInputCallbackAddressDe, 0x8010A1B0, 0x00000000, 0x000007DA, 0x00020000, (unsigned int)g_Player_ResetMovementInputAddress, (unsigned int)addrLow_Player_UpdateSwimmingState_eu_x, 0x8010A358,
    0x00000100, 0x00000A3C, 0x00020000, (unsigned int)addrLow_Player_ResetObjectVelocity, (unsigned int)addrLow_Player_UpdateAfterResetObjectVelocity_eu_x, 0x8010A458, 0x00080000, 0x00000001,
    0x00020000, (unsigned int)addrLow_Player_StartAimPreviousPositionAtReset_eu_x, (unsigned int)addrLow_Player_AimPreviousPositionAtReset_eu_x, 0x8010A4F8, 0x00100000, 0x00000001, 0x00020000, (unsigned int)addrLow_Playerai_ResetPlayerAfterDeath_eu_x,
    (unsigned int)addrLow_Playerai_UpdateAfterResetPlayerAfterDeath_eu_x, 0x8010A2F8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)addrLow_Player_ResetStunAndReleaseHandles_eu_x, 0x00000000, 0x8010A3D8,
    0x00000000, 0x00000000, 0x00010000, (unsigned int)addrLow_Player_ResetStunFlags_eu_eu_x, (unsigned int)addrLow_Player_UpdateAfterResetStunFlags_eu_x, 0x8010A3D8, 0x00000000, 0x00000000,
    0x00010000, (unsigned int)addrLow_Playerai_BeginRoundEndWaitEntryVariant2, (unsigned int)addrLow_Playerai_UpdateRoundEndWaitEntryVariant3, 0x8010A3D8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)g_PlayerSequence13StartCallbackAddressUs,
    (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant7, 0x8010A2F8, 0x00000000, 0x00001B58, 0x00010000, (unsigned int)g_PlayerSequence15StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant9, 0x8010A2F8,
    0x00000000, 0x00001BBC, 0x00010000, (unsigned int)g_Playerai_InitializeActorModelEffectCallbackAddressUs, (unsigned int)addrLow_Playerai_InitializeActorModelEffect, 0x8010A2F8, 0x00000000, 0x00001BBD,
    0x00010000, (unsigned int)g_PlayerSequence70StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant11, 0x8010A2F8, 0x00000000, 0x00001C20, 0x00010000, (unsigned int)addrLow_Playerai_StartPlayerSequence60_eu_x,
    (unsigned int)addrLow_Playerai_UpdateSequence60RunEndPose_eu_x, 0x8010A2F8, 0x00000000, 0x00001C21, 0x00010000, (unsigned int)g_PlayerSequence20StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant10, 0x8010A2F8,
    0x00000000, 0x00001CE8, 0x00010000, (unsigned int)g_Playerai_StartPlayerSequence60Address, (unsigned int)g_Playerai_UpdateSequence60RunEndPoseCallbackAddressUs, 0x8010A2F8, 0x00000000, 0x00001B5D,
    0x00010000, (unsigned int)g_Playerai_StartPlayerSequence71CallbackAddressUs, (unsigned int)g_Playerai_UpdateSequence71RunEndPoseCallbackAddressUs, 0x8010A2F8, 0x00000000, 0x00001D4C, 0x00010000, (unsigned int)g_Playerai_StartPlayerSequence72CallbackAddressUs,
    (unsigned int)g_Playerai_UpdateSequence72RunEndPoseCallbackAddressUs, 0x8010A2F8, 0x00000000, 0x00001D51, 0x00010000, (unsigned int)g_PlayerSequence14StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant8, 0x8010A3B8,
    0x00000000, 0x00001B6C, 0x00010000, (unsigned int)g_Playerai_StartPlayerSequence74CallbackAddressUs, (unsigned int)g_Playerai_UpdateSequence74RunEndPoseCallbackAddressUs, 0x8010A3B8, 0x00000000, 0x00001B62,
    0x00010000, (unsigned int)g_Playerai_StartPlayerSequence73CallbackAddressUs, (unsigned int)g_Playerai_UpdateSequence73RunEndPoseCallbackAddressUs, 0x8010A2F8, 0x00000000, 0x00001B5C, 0x00010000, (unsigned int)addrLow_Playerai_RequestTrackFifty,
    0x00000000, 0x8010A2F8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)addrLow_Playerai_InitializeActorModelEffect_eu_x, (unsigned int)addrLow_Playerai_UpdateTravelSequenceEntryVariant2, 0x8010A1B0,
    0x00000000, 0x000007EE, 0x00010000, (unsigned int)addrLow_Playerai_StartMovingSequenceState_eu_x, (unsigned int)addrLow_Playerai_EnterMovingSequenceState, 0x8010A010, 0x00008000, 0x000007DA,
    0x00020000, (unsigned int)addrLow_Playerai_StartStoppedSequenceState_eu_x, (unsigned int)addrLow_Playerai_EnterStoppedSequenceState, 0x8010A010, 0x00008000, 0x000007DA, 0x00030000, (unsigned int)addrLow_Playerai_OffsetActorForState15_eu_x,
    (unsigned int)addrLow_Playerai_UpdateHazardDamageEntryVariant2, 0x8010A458, 0x00000000, 0x000023F0, 0x00020000, (unsigned int)addrLow_Playerai_StartTargetFacing_eu_x, (unsigned int)addrLow_Playerai_UpdateTargetFacingEntryVariant2, 0x8010A458,
    0x00000000, 0x00000001, 0x00020000, (unsigned int)addrLow_Playerai_StartRequestCinemaTrack_eu_x, (unsigned int)g_PlayerRequestCinemaTrackCallbackAddressUs, 0x8010A458, 0x00000000, 0x00000001,
    0x00020000, (unsigned int)addrLow_Playerai_StartPlayerSequence71_eu_x, (unsigned int)addrLow_Playerai_UpdateSequence71RunEndPose_eu_x, 0x8010A2F8, 0x00000000, 0x00001B83, 0x00010000, (unsigned int)addrLow_Playerai_StartPlayerSequence72_eu_x,
    (unsigned int)addrLow_Playerai_UpdateSequence72RunEndPose_eu_x, 0x8010A2F8, 0x00000000, 0x00001B84, 0x00010000, (unsigned int)addrLow_Playerai_StartPlayerSequence73_eu_x, (unsigned int)addrLow_Playerai_UpdateSequence73RunEndPose_eu_x, 0x8010A2F8,
    0x00000000, 0x00001B85, 0x00010000, (unsigned int)addrLow_Playerai_StartPlayerSequence74, (unsigned int)addrLow_Playerai_UpdateSequence74RunEndPose_eu_x, 0x8010A2F8, 0x00000000, 0x00001B86,
    0x00010000, (unsigned int)addrLow_Playerai_StartEntry5B04_eu_x, (unsigned int)addrLow_Playerai_UpdateEntry5B04_eu_x, 0x8010A458, 0x00000000, 0x00005B04, 0x00020000, (unsigned int)addrLow_Playerai_SetRunEndFlagEntryVariant2,
    (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUs, 0x8010A458, 0x00000000, 0x00005B05, 0x00020000, (unsigned int)addrLow_Player_ZeroBodyVelocity_eu_x, (unsigned int)addrLow_Player_UpdateFlyMode_eu_x, 0x8010A4F8,
    0x00000000, 0x00000001, 0x00020000, 0x00000000, (unsigned int)addrLow_Player_UpdateFlyMode_eu_x, 0x8010A4F8, 0x00000000, 0x00000001,
    0x00020000, (unsigned int)addrLow_Player_StartMovingOnStickInput_eu_x, (unsigned int)addrLow_Player_UpdateStandingState_eu_x, 0x8010A458, 0x00000000, 0x00005E24, 0x00020000, (unsigned int)addrLow_Playerai_StartWalkingMovement_eu_x,
    (unsigned int)addrLow_Playerai_UpdateWalkingMovement_eu_x, 0x8010A458, 0x00000000, 0x00005E29, 0x00030000, (unsigned int)addrLow_Player_StartGroundMoveState_eu_x, (unsigned int)addrLow_Player_UpdateGroundMoveState_eu_x, 0x8010A458,
    0x00000000, 0x00000A64, 0x00030000, (unsigned int)addrLow_Player_BeginJump_eu_x, (unsigned int)addrLow_Player_UpdateJumpAscent_eu_x, 0x8010A190, 0x00000800, 0x00005E2D,
    0x00020000, 0x00000000, (unsigned int)addrLow_Player_UpdateJumpAirMotion_eu_x, 0x8010A190, 0x00000800, 0x00005E2D, 0x00020000, (unsigned int)addrLow_Player_BeginLateralLeap_eu_x,
    (unsigned int)addrLow_Player_UpdateLateralLeap_eu_x, 0x8010A458, 0x00000000, 0x00005E2D, 0x00020000, 0x00000000, (unsigned int)addrLow_Player_UpdateLeapMotion_eu_x, 0x8010A458,
    0x00000000, 0x00005E2D, 0x00020000, (unsigned int)addrLow_Player_ClearGlobalFlagBit, (unsigned int)addrLow_Player_UpdateWadingState_eu_x, 0x8010A418, 0x00000080, 0x000008A2,
    0x00020000, (unsigned int)addrLow_Player_ClearGlobalFlagBit, (unsigned int)addrLow_Player_UpdateWadingState_eu_x, 0x8010A418, 0x00000080, 0x000008A2, 0x00030000, (unsigned int)addrLow_Player_AbsorbImpact,
    (unsigned int)addrLow_Player_UpdateFloatingState_eu_x, 0x80109FB0, 0x00000040, 0x000008A2, 0x00020000, (unsigned int)addrLow_Player_AbsorbImpact, (unsigned int)addrLow_Player_UpdateFloatingState_eu_x, 0x80109FB0,
    0x00000040, 0x000008A2, 0x00030000, (unsigned int)addrLow_Player_DampMotion_eu_x, (unsigned int)g_Player_ResetMovementInputCallbackAddressDe, 0x8010A1B0, 0x00000000, 0x00005E29,
    0x00020000, (unsigned int)addrLow_Player_DampMotion_eu_x, (unsigned int)g_Player_ResetMovementInputCallbackAddressDe, 0x8010A1B0, 0x00000000, 0x00005E29, 0x00020000, (unsigned int)g_Player_ResetMovementInputAddress,
    (unsigned int)addrLow_Player_UpdateSwimmingState_eu_x, 0x8010A358, 0x00000100, 0x00005E28, 0x00020000, (unsigned int)addrLow_Player_ResetObjectVelocity, (unsigned int)addrLow_Player_UpdateAfterResetObjectVelocity_eu_x, 0x8010A458,
    0x00080000, 0x00005E24, 0x00020000, (unsigned int)addrLow_Player_StartAimPreviousPositionAtReset_eu_x, (unsigned int)addrLow_Player_AimPreviousPositionAtReset_eu_x, 0x8010A4F8, 0x00100000, 0x00005E24,
    0x00020000, (unsigned int)addrLow_Playerai_ResetPlayerAfterDeath_eu_x, (unsigned int)addrLow_Playerai_UpdateAfterResetPlayerAfterDeath_eu_x, 0x8010A2F8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)addrLow_Player_ResetStunAndReleaseHandles_eu_x,
    0x00000000, 0x8010A3D8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)addrLow_Player_ResetStunFlags_eu_eu_x, (unsigned int)addrLow_Player_UpdateAfterResetStunFlags_eu_x, 0x8010A3D8,
    0x00000000, 0x00000000, 0x00010000, (unsigned int)addrLow_Playerai_BeginRoundEndWaitEntryVariant2, (unsigned int)addrLow_Playerai_UpdateRoundEndWaitEntryVariant3, 0x8010A3D8, 0x00000000, 0x00000000,
    0x00010000, (unsigned int)g_PlayerSequence13StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant7, 0x8010A2F8, 0x00000000, 0x00001B58, 0x00010000, (unsigned int)g_PlayerSequence15StartCallbackAddressUs,
    (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant9, 0x8010A2F8, 0x00000000, 0x00001BBC, 0x00010000, (unsigned int)g_Playerai_InitializeActorModelEffectCallbackAddressUs, (unsigned int)addrLow_Playerai_InitializeActorModelEffect, 0x8010A2F8,
    0x00000000, 0x00001BBD, 0x00010000, (unsigned int)g_PlayerSequence70StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant11, 0x8010A2F8, 0x00000000, 0x00001C20,
    0x00010000, (unsigned int)addrLow_Playerai_StartPlayerSequence60_eu_x, (unsigned int)addrLow_Playerai_UpdateSequence60RunEndPose_eu_x, 0x8010A2F8, 0x00000000, 0x00001C21, 0x00010000, (unsigned int)g_PlayerSequence20StartCallbackAddressUs,
    (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant10, 0x8010A2F8, 0x00000000, 0x00001CE8, 0x00010000, (unsigned int)g_Playerai_StartPlayerSequence60Address, (unsigned int)g_Playerai_UpdateSequence60RunEndPoseCallbackAddressUs, 0x8010A2F8,
    0x00000000, 0x00001B5D, 0x00010000, (unsigned int)g_Playerai_StartPlayerSequence71CallbackAddressUs, (unsigned int)g_Playerai_UpdateSequence71RunEndPoseCallbackAddressUs, 0x8010A2F8, 0x00000000, 0x00001D4C,
    0x00010000, (unsigned int)g_Playerai_StartPlayerSequence72CallbackAddressUs, (unsigned int)g_Playerai_UpdateSequence72RunEndPoseCallbackAddressUs, 0x8010A2F8, 0x00000000, 0x00001D51, 0x00010000, (unsigned int)g_PlayerSequence14StartCallbackAddressUs,
    (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant8, 0x8010A3B8, 0x00000000, 0x00001B6C, 0x00010000, (unsigned int)g_Playerai_StartPlayerSequence74CallbackAddressUs, (unsigned int)g_Playerai_UpdateSequence74RunEndPoseCallbackAddressUs, 0x8010A3B8,
    0x00000000, 0x00001B62, 0x00010000, (unsigned int)g_Playerai_StartPlayerSequence73CallbackAddressUs, (unsigned int)g_Playerai_UpdateSequence73RunEndPoseCallbackAddressUs, 0x8010A2F8, 0x00000000, 0x00001B63,
    0x00010000, (unsigned int)addrLow_Playerai_RequestTrackFifty, 0x00000000, 0x8010A2F8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)addrLow_Playerai_InitializeActorModelEffect_eu_x,
    (unsigned int)addrLow_Playerai_UpdateTravelSequenceEntryVariant2, 0x8010A1B0, 0x00000000, 0x00005E2D, 0x00010000, (unsigned int)addrLow_Playerai_StartMovingSequenceState_eu_x, (unsigned int)addrLow_Playerai_EnterMovingSequenceState, 0x8010A010,
    0x00008000, 0x00005E29, 0x00020000, (unsigned int)addrLow_Playerai_StartStoppedSequenceState_eu_x, (unsigned int)addrLow_Playerai_EnterStoppedSequenceState, 0x8010A010, 0x00008000, 0x00005E29,
    0x00030000, (unsigned int)addrLow_Playerai_OffsetActorForState15_eu_x, (unsigned int)addrLow_Playerai_UpdateHazardDamageEntryVariant2, 0x8010A458, 0x00000000, 0x000023F0, 0x00020000, (unsigned int)addrLow_Playerai_StartTargetFacing_eu_x,
    (unsigned int)addrLow_Playerai_UpdateTargetFacingEntryVariant2, 0x8010A458, 0x00000000, 0x00005E24, 0x00020000, (unsigned int)addrLow_Playerai_StartRequestCinemaTrack_eu_x, (unsigned int)g_PlayerRequestCinemaTrackCallbackAddressUs, 0x8010A458,
    0x00000000, 0x00005E24, 0x00020000, (unsigned int)addrLow_Playerai_StartRequestCinemaTrackDe_eu_x, (unsigned int)g_PlayerRequestCinemaTrackCallbackAddressDe, 0x8010A458, 0x00000000, 0x00001B83,
    0x00020000, (unsigned int)addrLow_Playerai_StartPlayerSequence72_eu_x, (unsigned int)addrLow_Playerai_UpdateSequence72RunEndPose_eu_x, 0x8010A2F8, 0x00000000, 0x00001B84, 0x00010000, (unsigned int)addrLow_Playerai_StartPlayerSequence73_eu_x,
    (unsigned int)addrLow_Playerai_UpdateSequence73RunEndPose_eu_x, 0x8010A2F8, 0x00000000, 0x00001B85, 0x00010000, (unsigned int)addrLow_Playerai_StartPlayerSequence74, (unsigned int)addrLow_Playerai_UpdateSequence74RunEndPose_eu_x, 0x8010A2F8,
    0x00000000, 0x00001B86, 0x00010000, (unsigned int)addrLow_Playerai_StartEntry5B04_eu_x, (unsigned int)addrLow_Playerai_UpdateEntry5B04_eu_x, 0x8010A458, 0x00000000, 0x00005B04,
    0x00020000, (unsigned int)addrLow_Playerai_SetRunEndFlagEntryVariant2, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUs, 0x8010A458, 0x00000000, 0x00005B05, 0x00020000, 0x0000012B,
    0x012B012B, 0x012B012B, 0x012B012B, 0x012B012B, 0x012B0000, 0xBE800000,
};
#endif

/* 800CABD0.CPP */
#if defined(VERSION_EU)
extern char addrLow_Weaponai_UpdateAlternateFire_eu[];
extern char addrLow_Weaponai_UpdateAfterAmmoModeChange[];
extern char addrLow_Weaponai_UpdateSpinAndAlternateFire_eu[];
extern char addrLow_Weaponai_SelectReleasedFireState_de_eu[];
extern char addrLow_Weaponai_UpdateHeldFire_eu[];
extern char addrLow_Weapon_InitializeChargeForWeaponFive_eu_us[];
extern char addrLow_Weapon_StartState0_eu[];
extern char addrLow_Weapon_UpdateState0_eu[];
extern char addrLow_Weapon_ReleaseLinkedActorHandles[];
extern char addrLow_Weapon_InitializeChargeForWeaponEight_eu[];
extern char addrLow_Weapon_UpdateTriggerReleaseState_eu[];
extern char addrLow_Weapon_ReleaseHandlesAndExitState39_eu[];
extern char addrLow_Weapon_PlayStartupCue9E2_eu[];
extern char addrLow_Weapon_AdvanceSpinAndTriggerMode_eu[];
#if defined(VERSION_EU)
struct {
    f32 targetFacingEaseRate;
    f32 reactionReserveApproachRate;
    f32 aimRates[3];
    s16 weaponAnimationDurationPairs[30];
    s32 handMirrorAxesAndFlags[5];
    f32 weaponRestOffset;
    void * nextTable;
    u32 stateTableHeaderReserved[7];
    s32 state0Id;
    void * state0Enter;
    void * state0Update;
    u32 state0Reserved;
    s32 state0Animation;
    f32 state0Rate;
    s32 state0Threshold;
    u32 state0Flags;
    s32 state1Id;
    void * state1Enter;
    void * state1Update;
    u32 state1Reserved;
    s32 state1Animation;
    f32 state1Rate;
    s32 state1Threshold;
    u32 state1Flags;
    s32 state2Id;
    void * state2Enter;
    void * state2Update;
    u32 state2Reserved;
    s32 state2Animation;
    f32 state2Rate;
    s32 state2Threshold;
    u32 state2Flags;
    s32 state3Id;
    void * state3Enter;
    void * state3Update;
    u32 state3Reserved;
    s32 state3Animation;
    f32 state3Rate;
    s32 state3Threshold;
    u32 state3Flags;
    s32 state4Id;
    void * state4Enter;
    void * state4Update;
    u32 state4Reserved;
    void * state4AnimationList;
    f32 state4Rate;
    s32 state4Threshold;
    u32 state4Flags;
    s32 state5Id;
    void * state5Enter;
    void * state5Update;
    u32 state5Reserved;
    void * state5AnimationList;
    f32 state5Rate;
    s32 state5Threshold;
    u32 state5Flags;
    s32 state6Id;
    void * state6Enter;
    void * state6Update;
    u32 state6Reserved;
    s32 state6Animation;
    f32 state6Rate;
    s32 state6Threshold;
    u32 state6Flags;
    s32 state7Id;
    void * state7Enter;
    void * state7Update;
    u32 state7Reserved;
    s32 state7Animation;
    f32 state7Rate;
    s32 state7Threshold;
    u32 state7Flags;
    void * table8Next;
    u32 table8HeaderReserved[7];
    s32 state9Id;
    void * state9Enter;
    void * state9Update;
    u32 state9Reserved;
    s32 state9Animation;
    f32 state9Rate;
    s32 state9Threshold;
    u32 state9Flags;
    s32 state10Id;
    void * state10Enter;
    void * state10Update;
    u32 state10Reserved;
    s32 state10Animation;
    f32 state10Rate;
    s32 state10Threshold;
    u32 state10Flags;
    s32 state11Id;
    void * state11Enter;
    void * state11Update;
    u32 state11Reserved;
    s32 state11Animation;
    f32 state11Rate;
    s32 state11Threshold;
    u32 state11Flags;
    s32 state12Id;
    void * state12Enter;
    void * state12Update;
    u32 state12Reserved;
    s32 state12Animation;
    f32 state12Rate;
    s32 state12Threshold;
    u32 state12Flags;
    void * table13Next;
    u32 table13HeaderReserved[7];
    s32 state14Id;
    void * state14Enter;
    void * state14Update;
    u32 state14Reserved;
    s32 state14Animation;
    f32 state14Rate;
    s32 state14Threshold;
    u32 state14Flags;
    s32 state15Id;
    void * state15Enter;
    void * state15Update;
    u32 state15Reserved;
    s32 state15Animation;
    f32 state15Rate;
    s32 state15Threshold;
    u32 state15Flags;
    s32 state16Id;
    void * state16Enter;
    void * state16Update;
    u32 state16Reserved;
    s32 state16Animation;
    f32 state16Rate;
    s32 state16Threshold;
    u32 state16Flags;
    s32 state17Id;
    void * state17Enter;
    void * state17Update;
    u32 state17Reserved;
    s32 state17Animation;
    f32 state17Rate;
    s32 state17Threshold;
    u32 state17Flags;
    s32 state18Id;
    void * state18Enter;
    void * state18Update;
    u32 state18Reserved;
    s32 state18Animation;
    f32 state18Rate;
    s32 state18Threshold;
    u32 state18Flags;
} k_PlayeraiInitializeplayerhealthEncodedWords __attribute__((aligned(4))) = {
    0.349999994f,
    0.00625000009f,
    { 0.166666672f, 1.0f, 1.0f },
    { 20210, 10, 20220, 10, 20230, 10, 20240, 10, -1, 0, 20550, 10, 20551, 10, 20552, 10, 20553, 10, -1, 0, 20510, 10, 20520, 10, 20530, 10, 20540, 10, -1, 0 },
    { 0, 0, 0, 0, 0 },
    -3.0f,
    0,
    { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
    0,
    (void *)&addrLow_Weapon_StartState0_eu,
    (void *)&addrLow_Weapon_UpdateState0_eu,
    0x0,
    20000,
    1.0f,
    0,
    0x0,
    1,
    (void *)&addrLow_Weapon_ReleaseHandlesAndExitState39_eu,
    (void *)&addrLow_Weaponai_UpdateAfterAmmoModeChange,
    0x0,
    20010,
    1.0f,
    2,
    0x0,
    2,
    (void *)&addrLow_Weapon_ReleaseLinkedActorHandles,
    (void *)&addrLow_Weaponai_UpdateAlternateFire_eu,
    0x0,
    20100,
    1.0f,
    0,
    0x0,
    3,
    0,
    (void *)&addrLow_Weaponai_UpdateAlternateFire_eu,
    0x0,
    20110,
    1.0f,
    0,
    0x0,
    4,
    (void *)&addrLow_Weapon_InitializeChargeForWeaponEight_eu,
    (void *)&addrLow_Weapon_UpdateTriggerReleaseState_eu,
    0x0,
    (void *)((char *)&k_PlayeraiInitializeplayerhealthEncodedWords + 20),
    1.0f,
    3,
    0x0,
    8,
    (void *)&addrLow_Weapon_InitializeChargeForWeaponFive_eu_us,
    (void *)&addrLow_Weaponai_UpdateHeldFire_eu,
    0x0,
    (void *)((char *)&k_PlayeraiInitializeplayerhealthEncodedWords + 40),
    1.0f,
    3,
    0x0,
    7,
    0,
    (void *)&addrLow_Weaponai_UpdateAfterAmmoModeChange,
    0x0,
    20249,
    1.0f,
    3,
    0x0,
    -1,
    0,
    0,
    0x0,
    0,
    0.0f,
    0,
    0x0,
    (void *)&g_weaponFireStateCallbackTable,
    { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
    2,
    0,
    (void *)&addrLow_Weaponai_UpdateSpinAndAlternateFire_eu,
    0x0,
    20100,
    1.0f,
    0,
    0x0,
    3,
    0,
    (void *)&addrLow_Weaponai_UpdateSpinAndAlternateFire_eu,
    0x0,
    20110,
    1.0f,
    0,
    0x0,
    5,
    (void *)&addrLow_Weapon_PlayStartupCue9E2_eu,
    (void *)&addrLow_Weapon_AdvanceSpinAndTriggerMode_eu,
    0x0,
    20200,
    1.0f,
    3,
    0x0,
    -1,
    0,
    0,
    0x0,
    0,
    0.0f,
    0,
    0x0,
    (void *)&g_weaponFireStateCallbackTable,
    { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
    4,
    0,
    (void *)&addrLow_Weaponai_SelectReleasedFireState_de_eu,
    0x0,
    20200,
    1.0f,
    3,
    0x0,
    8,
    0,
    (void *)&addrLow_Weaponai_SelectReleasedFireState_de_eu,
    0x0,
    20200,
    1.0f,
    3,
    0x20,
    5,
    0,
    (void *)&addrLow_Weapon_UpdateTriggerReleaseState_eu,
    0x0,
    20210,
    1.0f,
    3,
    0x20,
    9,
    0,
    (void *)&addrLow_Weapon_UpdateTriggerReleaseState_eu,
    0x0,
    20550,
    1.0f,
    3,
    0x20,
    -1,
    0,
    0,
    0x0,
    0,
    0.0f,
    0,
    0x0
};
typedef char k_PlayeraiInitializeplayerhealthEncodedWordsSizeCheck[(sizeof(k_PlayeraiInitializeplayerhealthEncodedWords) == 744) ? 1 : -1];
#endif
#endif
