#include "DATA/OVLDAT2/ACTOR_STATE_CALLBACK_LABELS.H"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_controller_state_dispatch_CED20_us_rev1.c */
unsigned int g_controllerState6HandlerWords[3] = {
    0x00000006, (unsigned int)addrLow_Nav_InitCombatTargetApproach, (unsigned int)addrLow_Nav_ApproachCombatTargetAlongRoute,
};
#endif
