#include "DATA/OVLDAT2/ACTOR_STATE_CALLBACK_LABELS.H"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_controller_state_dispatch_CEC60_us_rev1.c */
unsigned int g_controllerState0HandlerWords[3] = {
    0x00000000, (unsigned int)addrLow_Nav_ResetPatrolRouteSelection, (unsigned int)addrLow_Nav_UpdatePatrolRoute,
};
#endif
