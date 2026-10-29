#include "DATA/ACTOR_STATE_CALLBACKS/ACTOR_STATE_CALLBACK_LABELS.H"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_controller_state_dispatch_CECA0_us_rev1.c */
unsigned int g_controllerState2HandlerWords[3] = {
    0x00000002, (unsigned int)addrLow_Nav_InitRoamingWithJumps, (unsigned int)addrLow_Nav_UpdateRoamingWithJumps,
};
#endif
