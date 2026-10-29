#include "DATA/OVLDAT2/ACTOR_STATE_CALLBACK_LABELS.H"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_controller_state_dispatch_CED40_us_rev1.c */
unsigned int g_controllerState7HandlerWords[3] = {
    0x00000007, (unsigned int)addrLow_Nav_InitRetreatMovement, (unsigned int)addrLow_Nav_UpdateRetreatMovement,
};
#endif
