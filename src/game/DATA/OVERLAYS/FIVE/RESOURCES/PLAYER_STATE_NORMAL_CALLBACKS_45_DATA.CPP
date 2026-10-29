#include "DATA/OVLDAT5/PLAYER_EMPTY_ACTION_HOOK_ADDRESSES.H"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_player_state_normal_callbacks_45_us_rev1.c */
unsigned int g_PlayerStateNormalCallbacks45Words[2] = {
    (unsigned int)addrLow_Playerai_NoopShortSequenceWaitFirst_de, (unsigned int)addrLow_Playerai_NoopShortSequenceWaitSecond_de,
};
#endif
