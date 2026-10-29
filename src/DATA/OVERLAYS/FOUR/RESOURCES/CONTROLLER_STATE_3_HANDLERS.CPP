#include "DATA/ACTOR_STATE_CALLBACKS/ACTOR_STATE_CALLBACK_LABELS.H"

#if defined(VERSION_US_REV1)
unsigned int g_controllerState3HandlerWords[3] = {
    0x00000003, (unsigned int)addrLow_Nav_InitPursuitStrafe, (unsigned int)addrLow_Nav_UpdatePursuitStrafe,
};
#endif
