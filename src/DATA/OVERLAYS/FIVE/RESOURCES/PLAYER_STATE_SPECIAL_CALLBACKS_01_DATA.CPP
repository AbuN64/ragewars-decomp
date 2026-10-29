
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_player_state_special_callbacks_01_us_rev1.c */
extern char g_Player_UpdateFlyModeAddress[];
unsigned int g_playerStateSpecialCallbacks01Words[2] = {
    0x00000000, (unsigned int)g_Player_UpdateFlyModeAddress,
};
#endif
