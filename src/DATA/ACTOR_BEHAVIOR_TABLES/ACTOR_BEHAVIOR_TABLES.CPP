#include "include_asm.h"
#include "TYPES.H"
#include "DATA/OVL1_C/NAVIGATION_CALLBACK_ADDRESS.H"
#include "DATA/OVL1_D/NAV_INITVISIBLEPURSUIT.H"
#include "DATA/OVL1_D/NAV_UPDATEVISIBLEPURSUIT_Nav4.H"
#include "DATA/ACTOR_STATE_CALLBACKS/ACTOR_STATE_CALLBACK_LABELS.H"

/* 000C99C4.CPP */
#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU_X)
unsigned int g_Ovldat2EncodedWords[5] = {
    0x00000000, 0x00000005, 0x00000005, 0x3FF00000, 0x00000000,
};
#endif

/* 800C873C.CPP */

/* 800C87B0.CPP */
#if defined(VERSION_US)
u32 k_Ovldat2ConstantWords[472] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x3F800000, 0x3F3504F3, 0x00000000, 0x3F3504F3, 0x3F800000, 0x00000000,
    0x00000000, 0x3F3504F3, 0x00000000, 0xBF3504F3, 0x00000000, 0x00000000,
    0xBF800000, 0xBF3504F3, 0x00000000, 0xBF3504F3, 0xBF800000, 0x00000000,
    0x00000000, 0xBF3504F3, 0x00000000, 0x3F3504F3, (unsigned int)addrLow_Nav_CollectEnemyTargets, (unsigned int)addrLow_Target_UpdateTargetSelection,
    (unsigned int)addrLow_Wheel_AdvanceWheelProbe, (unsigned int)addrLow_Nav_RefineBallisticAim, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute, (unsigned int)addrLow_Nav_CollectEnemyTargets, (unsigned int)addrLow_Target_UpdateTargetSelection, (unsigned int)addrLow_Nav_SelectPlayerState, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (unsigned int)addrLow_Nav_UpdateRouteIntermediateGoal, (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute, (unsigned int)addrLow_Nav_CollectEnemyTargets, (unsigned int)addrLow_Target_UpdateTargetSelection,
    (unsigned int)addrLow_Nav_CheckCloseAttackRoute, (unsigned int)addrLow_Nav_RefineBallisticAim, (unsigned int)addrLow_Nav_SelectPlayerState, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute, (unsigned int)addrLow_Nav_CollectEnemyTargets,
    (unsigned int)addrLow_Target_UpdateTargetSelection, (unsigned int)addrLow_Nav_SelectPlayerState, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute, (unsigned int)addrLow_Nav_CollectEnemyTargets, (unsigned int)addrLow_Target_UpdateTargetSelection, (unsigned int)addrLow_UpdateCloseAttack, (unsigned int)addrLow_Nav_AdvancePickupRouteSelection, (unsigned int)addrLow_Nav_SelectWeaponFromThirdAmmoGroup,
    (unsigned int)addrLow_Nav_RefineBallisticAim, (unsigned int)addrLow_Nav_SelectPlayerState, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute, (unsigned int)addrLow_Nav_CollectEnemyTargets, (unsigned int)addrLow_Target_UpdateTargetSelection, (unsigned int)addrLow_UpdateCloseAttack,
    (unsigned int)addrLow_Nav_AdvancePickupRouteSelection, (unsigned int)addrLow_Nav_SelectWeaponFromSecondAmmoGroup, (unsigned int)addrLow_Nav_RefineBallisticAim, (unsigned int)addrLow_Nav_SelectPlayerState, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute, (unsigned int)addrLow_Nav_CollectEnemyTargets,
    (unsigned int)addrLow_Target_UpdateTargetSelection, (unsigned int)addrLow_UpdateCloseAttack, (unsigned int)addrLow_Nav_SelectWeaponFromFirstAmmoGroup, (unsigned int)addrLow_Nav_RefineBallisticAim, (unsigned int)addrLow_Nav_SelectPlayerState, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute, (unsigned int)addrLow_Nav_CollectEnemyTargets, (unsigned int)addrLow_Target_UpdateTargetSelection, (unsigned int)addrLow_Nav_SelectSecondAmmoGroupVariantOne, (unsigned int)addrLow_Nav_RefineBallisticAim, (unsigned int)addrLow_Nav_SelectPlayerState,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute, (unsigned int)addrLow_Nav_CollectEnemyTargets, (unsigned int)addrLow_Target_UpdateTargetSelection, (unsigned int)addrLow_Nav_SelectSecondAmmoGroupVariantTwo,
    (unsigned int)addrLow_Nav_RefineBallisticAim, (unsigned int)addrLow_Nav_SelectPlayerState, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (unsigned int)addrLow_Nav_SelectPickupGoal, (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute,
    (unsigned int)addrLow_Nav_CollectEnemyTargets, (unsigned int)addrLow_Target_UpdateTargetSelection, (unsigned int)addrLow_Nav_SelectSecondAmmoGroupVariantTwo, (unsigned int)addrLow_Nav_RefineBallisticAim, (unsigned int)addrLow_Nav_SelectPlayerState, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (unsigned int)addrLow_Nav_SelectCloseAttackPickupGoal, (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute, (unsigned int)addrLow_Nav_CollectEnemyTargets, (unsigned int)addrLow_Target_UpdateTargetSelection, (unsigned int)addrLow_Nav_SelectPlayerState, (unsigned int)addrLow_Nav_SelectWeaponFromSecondAmmoGroup,
    (unsigned int)addrLow_Nav_RefineBallisticAim, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (unsigned int)addrLow_Nav_SelectChaseObjectGoal, (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute, (unsigned int)addrLow_Nav_CollectEnemyTargets, (unsigned int)addrLow_Target_UpdateTargetSelection,
    (unsigned int)addrLow_Nav_SelectWeaponFromSecondAmmoGroup, (unsigned int)addrLow_Nav_RefineBallisticAim, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (unsigned int)addrLow_Nav_SelectStationaryObjectGoal, (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute,
    (unsigned int)addrLow_Nav_CollectEnemyTargets, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute, (unsigned int)addrLow_Nav_CollectEnemyTargets, (unsigned int)addrLow_Target_UpdateTargetSelection, (unsigned int)addrLow_Nav_SelectWeaponFromThirdAmmoGroup,
    (unsigned int)addrLow_Nav_RefineBallisticAim, (unsigned int)addrLow_Nav_SelectPlayerState, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800C8870, 0x800C88C0,
    0x800C8910, 0x800C8960, 0x800C89B0, 0x800C8A00, 0x800C8A50, 0x800C8AA0,
    0x800C8AF0, 0x800C8B40, 0x800C8B90, 0x800C8BE0, 0x800C8C30, 0x800C8C80,
    0x4F545F46, 0x4C414765, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (unsigned int)addrLow_Nav_ResetPatrolRouteSelection,
    (unsigned int)addrLow_Nav_UpdatePatrolRoute, 0x00000000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000,
    0x00000001, (unsigned int)addrLow_Nav_ResetTargetFollowStateDe, (unsigned int)addrLow_Nav_UpdateTargetRouteFollow, 0x00000000, 0x00000000, 0x3F800000,
    0x00000005, 0x00000000, 0x00000002, (unsigned int)addrLow_Nav_InitRoamingWithJumps, (unsigned int)addrLow_Nav_UpdateRoamingWithJumps, 0x00000000,
    0x00000000, 0x3F800000, 0x00000005, 0x00000000, 0x00000003, (unsigned int)addrLow_Nav_InitPursuitStrafe,
    (unsigned int)addrLow_Nav_UpdatePursuitStrafe, 0x00000000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000,
    0x00000004, (unsigned int)addrLow_Nav_InitRangedCombat, (unsigned int)addrLow_Nav_UpdateRangedCombat, 0x00000000, 0x00000000, 0x3F800000,
    0x00000005, 0x00000000, 0x00000005, (unsigned int)addrLow_Nav_InitCloseCombat, (unsigned int)addrLow_Nav_UpdateCloseCombat, 0x00000000,
    0x00000000, 0x3F800000, 0x00000005, 0x00000000, 0x00000006, (unsigned int)addrLow_Nav_InitCombatTargetApproach,
    (unsigned int)addrLow_Nav_ApproachCombatTargetAlongRoute, 0x00000000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000,
    0x00000007, (unsigned int)addrLow_Nav_InitRetreatMovement, (unsigned int)addrLow_Nav_UpdateRetreatMovement, 0x00000000, 0x00000000, 0x3F800000,
    0x00000005, 0x00000000, 0x00000008, (unsigned int)addrLow_Nav_ResetObjectArrivalChase, (unsigned int)addrLow_Nav_UpdateObjectArrivalChase, 0x00000000,
    0x00000000, 0x3F800000, 0x00000005, 0x00000000, 0x00000009, (unsigned int)addrLow_Nav_InitUnclaimedMarkerSearch,
    (unsigned int)addrLow_Nav_SeekUnclaimedMarker, 0x00000000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000,
    0x0000000A, (unsigned int)addrLow_Nav_InitCarrierRoute, (unsigned int)addrLow_Nav_FollowMarkerCarrierRoute, 0x00000000, 0x00000000, 0x3F800000,
    0x00000005, 0x00000000, 0x0000000B, (unsigned int)addrLow_Nav_InitTimedJumpRoute, (unsigned int)addrLow_Nav_UpdateTransientJumpRoute, 0x00000000,
    0x00000000, 0x3F800000, 0x00000005, 0x00000000, 0x0000000C, (unsigned int)addrLow_Nav_InitNearbyUnrestrictedGoal,
    (unsigned int)addrLow_Nav_SeekNearbyUnrestrictedGoal, 0x00000000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000,
    0x0000000D, (unsigned int)addrLow_Nav_InitVisiblePursuit, (unsigned int)addrLow_Nav_UpdateVisiblePursuit, 0x00000000, 0x00000000, 0x3F800000,
    0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
#endif

/* 800C8858.CPP */
#if defined(VERSION_EU)
unsigned int k_Ovldat2EncodedWords[22] = {
    0x41700000, 0x00269390, 0x40240000, 0x00000000, 0x40590000, 0x00000000, 0x40C38800, 0x00000000,
    0x4197D784, 0x00000000, 0x4341C379, 0x37E08000, 0x4693B8B5, 0xB5056E17, 0x4D384F03, 0xE93FF9F5,
    0x5A827748, 0xF9301D32, 0x75154FDD, 0x7F73BF3C, 0x46A00000, 0x40449BA6,
};
#endif
