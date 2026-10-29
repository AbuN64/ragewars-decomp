#include "DATA/PLAYER_CALLBACKS/PLAYER_SEQUENCE_CALLBACK_ADDRESSES.H"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_player_state_normal_callbacks_37_us_rev1.c */
unsigned int g_PlayerStateNormalCallbacks37Words[2] = {
    (unsigned int)g_overlayFiveLinkRecordRomLinkTarget_ResetPlayerWeaponLock, (unsigned int)g_overlayFiveLinkRecordRomLinkTarget_EnterStoppedSequenceState,
};
#endif
