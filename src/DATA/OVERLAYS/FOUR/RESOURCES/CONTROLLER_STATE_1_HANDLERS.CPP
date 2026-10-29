#include "DATA/ACTOR_STATE_CALLBACKS/ACTOR_STATE_CALLBACK_LABELS.H"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_controller_state_dispatch_CEC80_us_rev1.c */
unsigned int g_controllerState1HandlerWords[3] = {
    0x00000001, (unsigned int)addrLow_Nav_ResetTargetFollowStateDe, (unsigned int)addrLow_Nav_UpdateTargetRouteFollow,
};
#endif
