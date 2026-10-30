#include "DATA/REST_SOURCE_RECORDS.H"
#include "DATA/OVL1_D/NAV_INITVISIBLEPURSUIT.H"
#include "DATA/OVL1_D/NAV_UPDATEVISIBLEPURSUIT_Nav4.H"

/* 800C9010.CPP */
#if defined(VERSION_US)
RestplayerControllerStateAndTuningWordsUsLayout395 g_playerControllerStateAndTuningWordsUs = {
    { 0, 0, 1, 2200, 0, 0 },
    "quR\000",
    { 15073792, 65536, 327680, 262144, 786432, 524288, 655360, 131072, 196608 },
    { 3e+01f, 48.0f, 1.3e+02f },
};
#endif

/* PLAYER_CONTROLLER_STATE_HEADER_US_REV1.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CDA3C_unclaimed_CE6E0_unclaimed_CE750_unclaimed_CEBCC_unclaimed_CEC6C_unclaimed_CEC8C_unclaimed_CECAC_unclaimed_CECCC_unclaimed_CECEC_unclaimed_CED0C_unclaimed_CED2C_unclaimed_CED4C_unclaimed_CED6C_unclaimed_CED8C_unclaimed_CEDAC_unclaimed_CEDCC_unclaimed_CEDEC */
RestplayerControllerStateHeaderUsRev1Layout396 g_playerControllerStateHeaderUsRev1 = {
    { 0, 0 },
    1.0f,
    { 5, 0 },
};

/* ROM-grounded data: src/rw_controller_state_id_CEE00_us_rev1.c */
RestplayerControllerStateIdThirteenUsRev1Record397 g_playerControllerStateIdThirteenUsRev1 = {
    13,
};
#endif

/* NAV_INITVISIBLEPURSUIT.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CDA3C_unclaimed_CE6E0_unclaimed_CE750_unclaimed_CEBCC_unclaimed_CEC6C_unclaimed_CEC8C_unclaimed_CECAC_unclaimed_CECCC_unclaimed_CECEC_unclaimed_CED0C_unclaimed_CED2C_unclaimed_CED4C_unclaimed_CED6C_unclaimed_CED8C_unclaimed_CEDAC_unclaimed_CEDCC_unclaimed_CEDEC_unclaimed_CEE04 */
unsigned int g_playerControllerStartCallbackUsRev1[1] = {
    (unsigned int)addrLow_Nav_InitVisiblePursuit,
};
#endif

/* NAV_UPDATEVISIBLEPURSUIT_Nav4.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_controller_state_update_CEE08_us_rev1.c */
unsigned int g_playerControllerUpdateCallbackUsRev1[1] = {
    (unsigned int)addrLow_Nav_UpdateVisiblePursuit,
};
#endif

/* PLAYER_CONTROLLER_STATE_HEADER_ALTERNATE_US_REV1.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CDA3C_unclaimed_CE6E0_unclaimed_CE750_unclaimed_CEBCC_unclaimed_CEC6C_unclaimed_CEC8C_unclaimed_CECAC_unclaimed_CECCC_unclaimed_CECEC_unclaimed_CED0C_unclaimed_CED2C_unclaimed_CED4C_unclaimed_CED6C_unclaimed_CED8C_unclaimed_CEDAC_unclaimed_CEDCC_unclaimed_CEDEC_unclaimed_CEE04_unclaimed_CEE0C */
RestplayerControllerStateHeaderAlternateUsRev1Layout398 g_playerControllerStateHeaderAlternateUsRev1 = {
    { 0, 0 },
    1.0f,
    { 5, 0 },
};

/* ROM-grounded data: src/rw_controller_state_end_CEE20_us_rev1.c */
RestplayerControllerStateEndUsRev1Record399 g_playerControllerStateEndUsRev1 = {
    -1,
};
#endif

/* PLAYER_CONTROLLER_STATE_EMPTY_RANGE.CPP */

/* PLAYER_CONTROLLER_STATE_BYTE_LOOKUP_EU.CPP */
#if defined(VERSION_EU)
unsigned char g_playerControllerStateByteLookupEu[40] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x05, 0x06, 0x08, 0x09, 0x0A, 0x0B,
    0x0C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x05, 0x07, 0x08, 0x0A, 0x0B, 0x0D, 0x0E, 0x0F, 0x0F,
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
};
#endif
