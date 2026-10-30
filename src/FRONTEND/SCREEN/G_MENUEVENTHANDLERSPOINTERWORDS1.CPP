#include "DATA/OVL1_J/ScreenPointerWordBlock.H"
#include "DATA/UI/EVENT_HANDLER_RECORD.H"

/* 80408CB0_12.CPP */
#if defined(VERSION_EU)
unsigned char g_ScreenRegionalStorageTrailingBytesBlock1[8] = { 0x8C, 0x25, 0x25, 0xB4, 0x0C, 0x0A, 0x81, 0x27 };
#endif

/* ScreenPointerWordBlock.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E5834_unclaimed_E644C */
EventHandlerRecord g_Screen1PointerWords1[1] = {
    { 3590, 18, g_Achieve_CreateResultsScreenAddress },
};

EventHandlerRecord g_MenuEventHandlersPointerWords1[5] = {
    { 3587, 18, g_CPlayerPreview_CloseSelectionMessageScreenAddress },
    { 2, 18, g_Achieve_AcknowledgeResultsEventAddress },
    { 1, 18, g_Achieve_HandleResultsMenuChoiceAddress },
    { 3594, 18, g_Achieve_UpdateResultsScreenAddress },
    { 0, 0, 0 },
};
#endif

/* ScreenRetainedTextFragment.CPP */
#if defined(VERSION_US_REV1)
char g_frontendScreenRetainedTextFragment[12] = "RE_WAR_CRYeq";
#endif
