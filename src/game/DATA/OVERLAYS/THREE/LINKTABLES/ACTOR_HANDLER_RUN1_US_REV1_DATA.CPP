#include "DATA/OVL1_C/NAVIGATION_CALLBACK_ADDRESS.H"
#include "DATA/OVLDAT2/ACTOR_STATE_CALLBACK_LABELS.H"

#if defined(VERSION_US_REV1)
unsigned int k_ActorHandlerRun1UsRev1EncodedWords[20] = {
    (unsigned int)addrLow_Nav_CollectEnemyTargets, (unsigned int)addrLow_Target_UpdateTargetSelection, (unsigned int)addrLow_Wheel_AdvanceWheelProbe, (unsigned int)addrLow_Nav_RefineBallisticAim, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

/* ROM-grounded data: src/ragewars_actor_handler_run_CE7A0_us_rev1.c */
unsigned int g_actorHandlerRun1_us_rev1[2] = {
    (unsigned int)addrLow_Nav_RebuildRequestedGoalRoute, (unsigned int)addrLow_Nav_CollectEnemyTargets,
};
#endif
