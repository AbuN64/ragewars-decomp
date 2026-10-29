#include "DATA/OVLDAT2/ACTOR_STATE_CALLBACK_LABELS.H"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_controller_state_dispatch_CED00_us_rev1.c */
unsigned int g_controllerState5HandlerWords[3] = {
    0x00000005, (unsigned int)D_00212524, (unsigned int)addrLow_Nav_UpdateCloseCombat,
};
#endif
