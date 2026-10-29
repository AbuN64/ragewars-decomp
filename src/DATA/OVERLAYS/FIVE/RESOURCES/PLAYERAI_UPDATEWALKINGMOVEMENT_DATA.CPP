
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_player_state_special_callbacks_00_us_rev1.c */
extern char g_Player_UpdateFlyModeAddress[];
extern char g_Player_ZeroBodyVelocityAddressVariant2[];
unsigned int g_playerStateSpecialCallbacks00Words[2] = {
    (unsigned int)g_Player_ZeroBodyVelocityAddressVariant2, (unsigned int)g_Player_UpdateFlyModeAddress,
};
#endif
