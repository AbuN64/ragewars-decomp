#include "DATA/OVLDAT2/ACTOR_STATE_CALLBACK_LABELS.H"

#if defined(VERSION_US_REV1)
unsigned int g_controllerState8HandlerWords[3] = {
    0x00000008, (unsigned int)addrLow_Nav_ResetObjectArrivalChase, (unsigned int)addrLow_Nav_UpdateObjectArrivalChase,
};
#endif
