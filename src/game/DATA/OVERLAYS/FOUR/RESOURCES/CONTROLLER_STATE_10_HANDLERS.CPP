#include "DATA/OVLDAT2/ACTOR_STATE_CALLBACK_LABELS.H"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_controller_state_dispatch_CEDA0_us_rev1.c */
unsigned int g_controllerState10HandlerWords[3] = {
    0x0000000A, (unsigned int)addrLow_Nav_InitCarrierRoute, (unsigned int)addrLow_Nav_FollowMarkerCarrierRoute,
};
#endif
