#include "include_asm.h"
#include "TYPES.H"

/* 8044ACCC_8.CPP */
#if defined(VERSION_EU_X)
const unsigned char s_sceneResourceIndexTagsEuX[29] = {
    0x63, 0x61, 0x72, 0x74, 0x72, 0x69, 0x64, 0x67, 0x65, 0x20, 0x69, 0x6E, 0x64, 0x65, 0x78, 0x00,
    0x6C, 0x65, 0x76, 0x65, 0x6C, 0x73, 0x20, 0x69, 0x6E, 0x64, 0x65, 0x78, 0x00,
};
#endif

/* SceneEffectMaximumColorUsRev1.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800C934C */
unsigned int g_sceneEffectMaximumColorUsRev1[1] = {
    0x437F0000,
};
#endif

/* PlayerActionStateTableUs.CPP */
#if defined(VERSION_US)
extern char g_Player_UpdateFlyModeAddress[];
extern char g_Player_UpdateStandingStateAddress[];
extern char g_Playerai_UpdateWalkingMovementAddress[];
extern char g_Player_UpdateWadingStateAddress[];
extern char g_Player_UpdateFloatingStateAddress[];
extern char g_Player_UpdateSwimmingStateAddress[];
extern char g_Playerai_ResetPlayerAfterDeathAddress[];
extern char g_PlayerInterpolateTravelTargetCallbackAddressUs[];
extern char g_PlayerUpdateHeldActorReleaseCallbackAddressUs[];
extern char g_PlayerTrackNearbyAimTargetCallbackAddressUs[];
extern char g_Player_ZeroBodyVelocityAddress[];
extern char g_Player_StartMovingOnStickInputAddress[];
extern char g_PlayerStateNoOperationCallbackAddressUs[];
extern char g_PlayerStateNoOperationCallbackAddressUsVariant2[];
extern char g_Player_UpdateGroundMoveStateAddress[];
extern char g_Player_BeginJumpAddress[];
extern char g_Player_UpdateJumpAscentAddress[];
extern char g_Player_UpdateJumpAirMotionAddress[];
extern char g_Player_BeginLateralLeapAddress[];
extern char g_Player_UpdateLateralLeapAddress[];
extern char g_Player_UpdateLeapMotionAddress[];
extern char g_Player_ClearGlobalFlagBitAddress[];
extern char g_Player_AbsorbImpactAddress[];
extern char g_Player_DampMotionAddress[];
extern char g_Player_UpdateFloatPoseAddress[];
extern char g_Player_ResetMovementInputCallbackAddressUs[];
extern char g_Player_ResetObjectVelocityAddress[];
extern char g_PlayerStateNoOperationCallbackAddressUsVariant3[];
extern char g_PlayerStateNoOperationCallbackAddressUsVariant4[];
extern char g_Player_AimPreviousPositionAtResetAddress[];
extern char g_PlayerStateNoOperationCallbackAddressUsVariant5[];
extern char g_Player_ResetStunAndReleaseHandlesAddress[];
extern char g_Player_ResetStunFlagsAddress[];
extern char g_PlayerStateNoOperationCallbackAddressUsVariant6[];
extern char g_PlayerResetStunAndMotionCallbackAddressUs[];
extern char g_PlayerEnterRunEndWaitCallbackAddressUs[];
extern char g_PlayerStateNoOperationCallbackAddressUsVariant7[];
extern char g_PlayerStateNoOperationCallbackAddressUsVariant8[];
extern char g_PlayerUpdateViewAnglesCallbackAddressUs[];
extern char g_PlayerStateNoOperationCallbackAddressUsVariant9[];
extern char g_PlayerUpdateRunEndCameraCallbackAddressUs[];
extern char g_PlayerStateNoOperationCallbackAddressUsVariant10[];
extern char g_PlayerStateNoOperationCallbackAddressUsVariant11[];
extern char g_PlayerSetSequenceFlag20CallbackAddressUs[];
extern char g_PlayerUpdateRunEndSequenceCallbackAddressUs[];
extern char g_PlayerRequestCinemaTrackCallbackAddressUs[];
extern char g_PlayerSequence10StartCallbackAddressUs[];
extern char g_PlayerSequenceRunEndUpdateCallbackAddressUs[];
extern char g_PlayerSequence50StartCallbackAddressUs[];
extern char g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant2[];
extern char g_PlayerSequence30StartCallbackAddressUs[];
extern char g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant3[];
extern char g_PlayerSequence40StartCallbackAddressUs[];
extern char g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant4[];
extern char g_PlayerSequence11StartCallbackAddressUs[];
extern char g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant5[];
extern char g_PlayerSequence12StartCallbackAddressUs[];
extern char g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant6[];
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
extern char g_Playerai_ClearPlayerWeaponLockAddress[];
extern char g_Playerai_EnterMovingSequenceStateCallbackAddressUs[];
extern char g_Playerai_ResetPlayerWeaponLockAddress[];
extern char g_Playerai_EnterStoppedSequenceStateCallbackAddressUs[];
extern char g_Playerai_OffsetActorForState15Address[];
u32 g_playerActionStateTableWordsUs[593] = {
    0x00000001, 0x3ECCCCCD, 0x3F000000, 0x3F800000, 0x3E800000, 0xBFC90FDC,
    0x3FC90FDC, 0x3E4CCCCD, 0x3E800000, 0x3F000000, 0x3E000000, 0xBFC90FDC,
    0x3FC90FDC, 0x3F83126F, 0x40F5C28F, 0x3F03126F, 0x4123D70A, 0x3F449BA6,
    0x4123D70A, 0x42999999, 0x424CCCCC, 0x00000000, (unsigned int)g_Player_ZeroBodyVelocityAddress, (unsigned int)g_Player_UpdateFlyModeAddress,
    0x800FE4F8, 0x00000000, 0x00000001, 0x00020000, 0x00000000, (unsigned int)g_Player_UpdateFlyModeAddress,
    0x800FE4F8, 0x00000000, 0x00000001, 0x00020000, (unsigned int)g_Player_StartMovingOnStickInputAddress, (unsigned int)g_Player_UpdateStandingStateAddress,
    0x800FE458, 0x00000000, 0x00000001, 0x00020000, (unsigned int)g_PlayerStateNoOperationCallbackAddressUs, (unsigned int)g_Playerai_UpdateWalkingMovementAddress,
    0x800FE458, 0x00000000, 0x000007DA, 0x00030000, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant2, (unsigned int)g_Player_UpdateGroundMoveStateAddress,
    0x800FE458, 0x00000000, 0x00000A64, 0x00030000, (unsigned int)g_Player_BeginJumpAddress, (unsigned int)g_Player_UpdateJumpAscentAddress,
    0x800FE190, 0x00000800, 0x000007EE, 0x00020000, 0x00000000, (unsigned int)g_Player_UpdateJumpAirMotionAddress,
    0x800FE190, 0x00000800, 0x000007EE, 0x00020000, (unsigned int)g_Player_BeginLateralLeapAddress, (unsigned int)g_Player_UpdateLateralLeapAddress,
    0x800FE458, 0x00000000, 0x000007EE, 0x00020000, 0x00000000, (unsigned int)g_Player_UpdateLeapMotionAddress,
    0x800FE458, 0x00000000, 0x000007EE, 0x00020000, (unsigned int)g_Player_ClearGlobalFlagBitAddress, (unsigned int)g_Player_UpdateWadingStateAddress,
    0x800FE418, 0x00000080, 0x000008A2, 0x00020000, (unsigned int)g_Player_ClearGlobalFlagBitAddress, (unsigned int)g_Player_UpdateWadingStateAddress,
    0x800FE418, 0x00000080, 0x000008A2, 0x00030000, (unsigned int)g_Player_AbsorbImpactAddress, (unsigned int)g_Player_UpdateFloatingStateAddress,
    0x800FDFB0, 0x00000040, 0x000008A2, 0x00020000, (unsigned int)g_Player_AbsorbImpactAddress, (unsigned int)g_Player_UpdateFloatingStateAddress,
    0x800FDFB0, 0x00000040, 0x000008A2, 0x00030000, (unsigned int)g_Player_DampMotionAddress, (unsigned int)g_Player_UpdateFloatPoseAddress,
    0x800FE1B0, 0x00000000, 0x000007DA, 0x00020000, (unsigned int)g_Player_DampMotionAddress, (unsigned int)g_Player_UpdateFloatPoseAddress,
    0x800FE1B0, 0x00000000, 0x000007DA, 0x00020000, (unsigned int)g_Player_ResetMovementInputCallbackAddressUs, (unsigned int)g_Player_UpdateSwimmingStateAddress,
    0x800FE358, 0x00000100, 0x00000A3C, 0x00020000, (unsigned int)g_Player_ResetObjectVelocityAddress, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant3,
    0x800FE458, 0x00080000, 0x00000001, 0x00020000, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant4, (unsigned int)g_Player_AimPreviousPositionAtResetAddress,
    0x800FE4F8, 0x00100000, 0x00000001, 0x00020000, (unsigned int)g_Playerai_ResetPlayerAfterDeathAddress, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant5,
    0x800FE2F8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)g_Player_ResetStunAndReleaseHandlesAddress, 0x00000000,
    0x800FE3D8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)g_Player_ResetStunFlagsAddress, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant6,
    0x800FE3D8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)g_PlayerResetStunAndMotionCallbackAddressUs, (unsigned int)g_PlayerEnterRunEndWaitCallbackAddressUs,
    0x800FE3D8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)g_PlayerSequence10StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUs,
    0x800FE2F8, 0x00000000, 0x00001B58, 0x00010000, (unsigned int)g_PlayerSequence30StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant3,
    0x800FE2F8, 0x00000000, 0x00001BBC, 0x00010000, (unsigned int)g_PlayerSequence70StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant11,
    0x800FE2F8, 0x00000000, 0x00001BBD, 0x00010000, (unsigned int)g_PlayerSequence11StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant5,
    0x800FE2F8, 0x00000000, 0x00001C20, 0x00010000, (unsigned int)g_Playerai_StartPlayerSequence60Address, (unsigned int)g_Playerai_UpdateSequence60RunEndPoseCallbackAddressUs,
    0x800FE2F8, 0x00000000, 0x00001C21, 0x00010000, (unsigned int)g_PlayerSequence40StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant4,
    0x800FE2F8, 0x00000000, 0x00001CE8, 0x00010000, (unsigned int)g_PlayerSequence12StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant6,
    0x800FE2F8, 0x00000000, 0x00001B5D, 0x00010000, (unsigned int)g_PlayerSequence13StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant7,
    0x800FE2F8, 0x00000000, 0x00001D4C, 0x00010000, (unsigned int)g_PlayerSequence14StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant8,
    0x800FE2F8, 0x00000000, 0x00001D51, 0x00010000, (unsigned int)g_PlayerSequence50StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant2,
    0x800FE3B8, 0x00000000, 0x00001B6C, 0x00010000, (unsigned int)g_PlayerSequence20StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant10,
    0x800FE3B8, 0x00000000, 0x00001B62, 0x00010000, (unsigned int)g_PlayerSequence15StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant9,
    0x800FE2F8, 0x00000000, 0x00001B5C, 0x00010000, (unsigned int)g_PlayerRequestCinemaTrackCallbackAddressUs, 0x00000000,
    0x800FE2F8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)g_Playerai_InitializeActorModelEffectCallbackAddressUs, (unsigned int)g_PlayerInterpolateTravelTargetCallbackAddressUs,
    0x800FE1B0, 0x00000000, 0x000007EE, 0x00010000, (unsigned int)g_Playerai_ClearPlayerWeaponLockAddress, (unsigned int)g_Playerai_EnterMovingSequenceStateCallbackAddressUs,
    0x800FE010, 0x00008000, 0x000007DA, 0x00020000, (unsigned int)g_Playerai_ResetPlayerWeaponLockAddress, (unsigned int)g_Playerai_EnterStoppedSequenceStateCallbackAddressUs,
    0x800FE010, 0x00008000, 0x000007DA, 0x00030000, (unsigned int)g_Playerai_OffsetActorForState15Address, (unsigned int)g_PlayerUpdateHeldActorReleaseCallbackAddressUs,
    0x800FE458, 0x00000000, 0x000023F0, 0x00020000, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant7, (unsigned int)g_PlayerTrackNearbyAimTargetCallbackAddressUs,
    0x800FE458, 0x00000000, 0x00000001, 0x00020000, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant8, (unsigned int)g_PlayerUpdateViewAnglesCallbackAddressUs,
    0x800FE458, 0x00000000, 0x00000001, 0x00020000, (unsigned int)g_Playerai_StartPlayerSequence71CallbackAddressUs, (unsigned int)g_Playerai_UpdateSequence71RunEndPoseCallbackAddressUs,
    0x800FE2F8, 0x00000000, 0x00001B83, 0x00010000, (unsigned int)g_Playerai_StartPlayerSequence72CallbackAddressUs, (unsigned int)g_Playerai_UpdateSequence72RunEndPoseCallbackAddressUs,
    0x800FE2F8, 0x00000000, 0x00001B84, 0x00010000, (unsigned int)g_Playerai_StartPlayerSequence73CallbackAddressUs, (unsigned int)g_Playerai_UpdateSequence73RunEndPoseCallbackAddressUs,
    0x800FE2F8, 0x00000000, 0x00001B85, 0x00010000, (unsigned int)g_Playerai_StartPlayerSequence74CallbackAddressUs, (unsigned int)g_Playerai_UpdateSequence74RunEndPoseCallbackAddressUs,
    0x800FE2F8, 0x00000000, 0x00001B86, 0x00010000, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant10, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant11,
    0x800FE458, 0x00000000, 0x00005B04, 0x00020000, (unsigned int)g_PlayerSetSequenceFlag20CallbackAddressUs, (unsigned int)g_PlayerUpdateRunEndSequenceCallbackAddressUs,
    0x800FE458, 0x00000000, 0x00005B05, 0x00020000, (unsigned int)g_Player_ZeroBodyVelocityAddress, (unsigned int)g_Player_UpdateFlyModeAddress,
    0x800FE4F8, 0x00000000, 0x00000001, 0x00020000, 0x00000000, (unsigned int)g_Player_UpdateFlyModeAddress,
    0x800FE4F8, 0x00000000, 0x00000001, 0x00020000, (unsigned int)g_Player_StartMovingOnStickInputAddress, (unsigned int)g_Player_UpdateStandingStateAddress,
    0x800FE458, 0x00000000, 0x00005E24, 0x00020000, (unsigned int)g_PlayerStateNoOperationCallbackAddressUs, (unsigned int)g_Playerai_UpdateWalkingMovementAddress,
    0x800FE458, 0x00000000, 0x00005E29, 0x00030000, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant2, (unsigned int)g_Player_UpdateGroundMoveStateAddress,
    0x800FE458, 0x00000000, 0x00000A64, 0x00030000, (unsigned int)g_Player_BeginJumpAddress, (unsigned int)g_Player_UpdateJumpAscentAddress,
    0x800FE190, 0x00000800, 0x00005E2D, 0x00020000, 0x00000000, (unsigned int)g_Player_UpdateJumpAirMotionAddress,
    0x800FE190, 0x00000800, 0x00005E2D, 0x00020000, (unsigned int)g_Player_BeginLateralLeapAddress, (unsigned int)g_Player_UpdateLateralLeapAddress,
    0x800FE458, 0x00000000, 0x00005E2D, 0x00020000, 0x00000000, (unsigned int)g_Player_UpdateLeapMotionAddress,
    0x800FE458, 0x00000000, 0x00005E2D, 0x00020000, (unsigned int)g_Player_ClearGlobalFlagBitAddress, (unsigned int)g_Player_UpdateWadingStateAddress,
    0x800FE418, 0x00000080, 0x000008A2, 0x00020000, (unsigned int)g_Player_ClearGlobalFlagBitAddress, (unsigned int)g_Player_UpdateWadingStateAddress,
    0x800FE418, 0x00000080, 0x000008A2, 0x00030000, (unsigned int)g_Player_AbsorbImpactAddress, (unsigned int)g_Player_UpdateFloatingStateAddress,
    0x800FDFB0, 0x00000040, 0x000008A2, 0x00020000, (unsigned int)g_Player_AbsorbImpactAddress, (unsigned int)g_Player_UpdateFloatingStateAddress,
    0x800FDFB0, 0x00000040, 0x000008A2, 0x00030000, (unsigned int)g_Player_DampMotionAddress, (unsigned int)g_Player_UpdateFloatPoseAddress,
    0x800FE1B0, 0x00000000, 0x00005E29, 0x00020000, (unsigned int)g_Player_DampMotionAddress, (unsigned int)g_Player_UpdateFloatPoseAddress,
    0x800FE1B0, 0x00000000, 0x00005E29, 0x00020000, (unsigned int)g_Player_ResetMovementInputCallbackAddressUs, (unsigned int)g_Player_UpdateSwimmingStateAddress,
    0x800FE358, 0x00000100, 0x00005E28, 0x00020000, (unsigned int)g_Player_ResetObjectVelocityAddress, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant3,
    0x800FE458, 0x00080000, 0x00005E24, 0x00020000, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant4, (unsigned int)g_Player_AimPreviousPositionAtResetAddress,
    0x800FE4F8, 0x00100000, 0x00005E24, 0x00020000, (unsigned int)g_Playerai_ResetPlayerAfterDeathAddress, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant5,
    0x800FE2F8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)g_Player_ResetStunAndReleaseHandlesAddress, 0x00000000,
    0x800FE3D8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)g_Player_ResetStunFlagsAddress, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant6,
    0x800FE3D8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)g_PlayerResetStunAndMotionCallbackAddressUs, (unsigned int)g_PlayerEnterRunEndWaitCallbackAddressUs,
    0x800FE3D8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)g_PlayerSequence10StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUs,
    0x800FE2F8, 0x00000000, 0x00001B58, 0x00010000, (unsigned int)g_PlayerSequence30StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant3,
    0x800FE2F8, 0x00000000, 0x00001BBC, 0x00010000, (unsigned int)g_PlayerSequence70StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant11,
    0x800FE2F8, 0x00000000, 0x00001BBD, 0x00010000, (unsigned int)g_PlayerSequence11StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant5,
    0x800FE2F8, 0x00000000, 0x00001C20, 0x00010000, (unsigned int)g_Playerai_StartPlayerSequence60Address, (unsigned int)g_Playerai_UpdateSequence60RunEndPoseCallbackAddressUs,
    0x800FE2F8, 0x00000000, 0x00001C21, 0x00010000, (unsigned int)g_PlayerSequence40StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant4,
    0x800FE2F8, 0x00000000, 0x00001CE8, 0x00010000, (unsigned int)g_PlayerSequence12StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant6,
    0x800FE2F8, 0x00000000, 0x00001B5D, 0x00010000, (unsigned int)g_PlayerSequence13StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant7,
    0x800FE2F8, 0x00000000, 0x00001D4C, 0x00010000, (unsigned int)g_PlayerSequence14StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant8,
    0x800FE2F8, 0x00000000, 0x00001D51, 0x00010000, (unsigned int)g_PlayerSequence50StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant2,
    0x800FE3B8, 0x00000000, 0x00001B6C, 0x00010000, (unsigned int)g_PlayerSequence20StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant10,
    0x800FE3B8, 0x00000000, 0x00001B62, 0x00010000, (unsigned int)g_PlayerSequence15StartCallbackAddressUs, (unsigned int)g_PlayerSequenceRunEndUpdateCallbackAddressUsVariant9,
    0x800FE2F8, 0x00000000, 0x00001B63, 0x00010000, (unsigned int)g_PlayerRequestCinemaTrackCallbackAddressUs, 0x00000000,
    0x800FE2F8, 0x00000000, 0x00000000, 0x00010000, (unsigned int)g_Playerai_InitializeActorModelEffectCallbackAddressUs, (unsigned int)g_PlayerInterpolateTravelTargetCallbackAddressUs,
    0x800FE1B0, 0x00000000, 0x00005E2D, 0x00010000, (unsigned int)g_Playerai_ClearPlayerWeaponLockAddress, (unsigned int)g_Playerai_EnterMovingSequenceStateCallbackAddressUs,
    0x800FE010, 0x00008000, 0x00005E29, 0x00020000, (unsigned int)g_Playerai_ResetPlayerWeaponLockAddress, (unsigned int)g_Playerai_EnterStoppedSequenceStateCallbackAddressUs,
    0x800FE010, 0x00008000, 0x00005E29, 0x00030000, (unsigned int)g_Playerai_OffsetActorForState15Address, (unsigned int)g_PlayerUpdateHeldActorReleaseCallbackAddressUs,
    0x800FE458, 0x00000000, 0x000023F0, 0x00020000, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant7, (unsigned int)g_PlayerTrackNearbyAimTargetCallbackAddressUs,
    0x800FE458, 0x00000000, 0x00005E24, 0x00020000, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant8, (unsigned int)g_PlayerUpdateViewAnglesCallbackAddressUs,
    0x800FE458, 0x00000000, 0x00005E24, 0x00020000, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant9, (unsigned int)g_PlayerUpdateRunEndCameraCallbackAddressUs,
    0x800FE458, 0x00000000, 0x00001B83, 0x00020000, (unsigned int)g_Playerai_StartPlayerSequence72CallbackAddressUs, (unsigned int)g_Playerai_UpdateSequence72RunEndPoseCallbackAddressUs,
    0x800FE2F8, 0x00000000, 0x00001B84, 0x00010000, (unsigned int)g_Playerai_StartPlayerSequence73CallbackAddressUs, (unsigned int)g_Playerai_UpdateSequence73RunEndPoseCallbackAddressUs,
    0x800FE2F8, 0x00000000, 0x00001B85, 0x00010000, (unsigned int)g_Playerai_StartPlayerSequence74CallbackAddressUs, (unsigned int)g_Playerai_UpdateSequence74RunEndPoseCallbackAddressUs,
    0x800FE2F8, 0x00000000, 0x00001B86, 0x00010000, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant10, (unsigned int)g_PlayerStateNoOperationCallbackAddressUsVariant11,
    0x800FE458, 0x00000000, 0x00005B04, 0x00020000, (unsigned int)g_PlayerSetSequenceFlag20CallbackAddressUs, (unsigned int)g_PlayerUpdateRunEndSequenceCallbackAddressUs,
    0x800FE458, 0x00000000, 0x00005B05, 0x00020000, 0x0000012B, 0x012B012B,
    0x012B012B, 0x012B012B, 0x012B012B, 0x012B0000, 0xBE800000,
};
#endif

/* SceneEffectTuningEu.CPP */
#if defined(VERSION_EU)
unsigned int g_sceneEffectTuningEu[4] = {
    0x3DB851EC, 0x3D4CCCCD, 0x3F000000, 0x42800000,
};
#endif
