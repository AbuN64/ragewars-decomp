
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_player_state_normal_callbacks_39_us_rev1.c */
extern char g_PlayerTrackNearbyAimTargetCallbackAddressUs[];
extern char g_PlayerState39EmptyHookAddress[];
unsigned int g_playerStateNormalCallbacks39Words[2] = {
    (unsigned int)g_PlayerState39EmptyHookAddress, (unsigned int)g_PlayerTrackNearbyAimTargetCallbackAddressUs,
};
#endif
