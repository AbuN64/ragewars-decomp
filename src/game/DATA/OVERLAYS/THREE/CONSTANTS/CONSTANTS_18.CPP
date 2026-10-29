#include "DATA/OVLTAB3/ACTION_HANDLER_ADDRESSES.H"

#if defined(VERSION_US_REV1)
unsigned int k_ConstantsEncodedWordsBlock4[23] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (unsigned int)addrLow_Action_SetEnterHandler,
    (unsigned int)addrLow_Action_ToggleActorState, 0x00000000, 0x00000000, (unsigned int)addrLow_Action_RequestInactiveState, (unsigned int)addrLow_Action_EnableTriggerActor, (unsigned int)addrLow_Action_RequestActiveState, (unsigned int)addrLow_Action_DisableTriggerActor, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
#endif
