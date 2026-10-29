#include "DATA/OVL1_D/DATA_800CE204.H"
#include "DATA/OVL1_D/DATA_800CE208.H"

/* 800C9010.CPP */
#if defined(VERSION_US)
unsigned int g_playerControllerStateAndTuningWordsUs[19] = {
    0x00000000, 0x00000000, 0x00000001, 0x00000898, 0x00000000, 0x00000000, 0x71755200, 0x00E60200,
    0x00010000, 0x00050000, 0x00040000, 0x000C0000, 0x00080000, 0x000A0000, 0x00020000, 0x00030000,
    0x41F00000, 0x42400000, 0x43020000,
};
#endif

/* DATA_800CE1EC.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CDA3C_unclaimed_CE6E0_unclaimed_CE750_unclaimed_CEBCC_unclaimed_CEC6C_unclaimed_CEC8C_unclaimed_CECAC_unclaimed_CECCC_unclaimed_CECEC_unclaimed_CED0C_unclaimed_CED2C_unclaimed_CED4C_unclaimed_CED6C_unclaimed_CED8C_unclaimed_CEDAC_unclaimed_CEDCC_unclaimed_CEDEC */
unsigned int g_playerControllerStateHeaderUsRev1[5] = {
    0x00000000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000,
};

/* ROM-grounded data: src/rw_controller_state_id_CEE00_us_rev1.c */
unsigned int g_playerControllerStateIdThirteenUsRev1[1] = {
    0x0000000D,
};
#endif

/* DATA_800CE204.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CDA3C_unclaimed_CE6E0_unclaimed_CE750_unclaimed_CEBCC_unclaimed_CEC6C_unclaimed_CEC8C_unclaimed_CECAC_unclaimed_CECCC_unclaimed_CECEC_unclaimed_CED0C_unclaimed_CED2C_unclaimed_CED4C_unclaimed_CED6C_unclaimed_CED8C_unclaimed_CEDAC_unclaimed_CEDCC_unclaimed_CEDEC_unclaimed_CEE04 */
unsigned int g_playerControllerStartCallbackUsRev1[1] = {
    (unsigned int)D_002125F0,
};
#endif

/* DATA_800CE208.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_controller_state_update_CEE08_us_rev1.c */
unsigned int g_playerControllerUpdateCallbackUsRev1[1] = {
    (unsigned int)addrLow_Nav_UpdateVisiblePursuit,
};
#endif

/* DATA_800CE20C.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CDA3C_unclaimed_CE6E0_unclaimed_CE750_unclaimed_CEBCC_unclaimed_CEC6C_unclaimed_CEC8C_unclaimed_CECAC_unclaimed_CECCC_unclaimed_CECEC_unclaimed_CED0C_unclaimed_CED2C_unclaimed_CED4C_unclaimed_CED6C_unclaimed_CED8C_unclaimed_CEDAC_unclaimed_CEDCC_unclaimed_CEDEC_unclaimed_CEE04_unclaimed_CEE0C */
unsigned int g_playerControllerStateHeaderAlternateUsRev1[5] = {
    0x00000000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000,
};

/* ROM-grounded data: src/rw_controller_state_end_CEE20_us_rev1.c */
unsigned int g_playerControllerStateEndUsRev1[1] = {
    0xFFFFFFFF,
};
#endif

/* DATA_800CE224.CPP */

/* DATA_800CE298.CPP */
#if defined(VERSION_EU)
unsigned char g_playerControllerStateByteLookupEu[40] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x05, 0x06, 0x08, 0x09, 0x0A, 0x0B,
    0x0C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x05, 0x07, 0x08, 0x0A, 0x0B, 0x0D, 0x0E, 0x0F, 0x0F,
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
};
#endif
