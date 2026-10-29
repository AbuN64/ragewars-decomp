#include "DATA/OVL1_J/ScreenPointerWordBlock.H"

/* 80408CB0_12.CPP */
#if defined(VERSION_EU)
unsigned char g_ScreenRegionalStorageTrailingBytesBlock1[8] = { 0x8C, 0x25, 0x25, 0xB4, 0x0C, 0x0A, 0x81, 0x27 };
#endif

/* ScreenPointerWordBlock.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E5834_unclaimed_E644C */
unsigned int g_Screen1PointerWords1[3] = {
    0x00000E06, 0x00000012, (unsigned int)g_Achieve_CreateResultsScreenAddress,
};

unsigned int g_MenuEventHandlersPointerWords1[15] = {
    0x00000E03, 0x00000012, (unsigned int)g_CPlayerPreview_CloseSelectionMessageScreenAddress, 0x00000002, 0x00000012, (unsigned int)g_Achieve_AcknowledgeResultsEventAddress, 0x00000001, 0x00000012,
    (unsigned int)g_Achieve_HandleResultsMenuChoiceAddress, 0x00000E0A, 0x00000012, (unsigned int)g_Achieve_UpdateResultsScreenAddress, 0x00000000, 0x00000000, 0x00000000,
};
#endif

/* ScreenRetainedTextFragment.CPP */
#if defined(VERSION_US_REV1)
char g_frontendScreenRetainedTextFragment[12] = "RE_WAR_CRYeq";
#endif
