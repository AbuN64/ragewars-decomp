#include "include_asm.h"


/* Maps an id from 1 to 33 to the address of its data block, returning 0 for any other id. */
#include "TYPES.H"
#include "MENU/EVENT.H"


/* The German cartridge numbers its screens from 0, the others from 1. */
#if defined(VERSION_DE)
#define SCREEN_EVENT_ID(n) ((n) - 1)
#else
#define SCREEN_EVENT_ID(n) (n)
#endif

void *Level_GetScreenEventTable(s32 id) {
    switch (id) {
    case SCREEN_EVENT_ID(1):
        return g_Frontend_DispatchPauseMenuEventAddress;
    case SCREEN_EVENT_ID(31):
        return g_Frontend_DispatchConfirmationEventAddress;
    case SCREEN_EVENT_ID(32):
        return g_Frontend_DispatchResidentActorEventAddress;
    case SCREEN_EVENT_ID(7):
        return g_Selection_DispatchCharacterSelectionEventAddress;
    case SCREEN_EVENT_ID(8):
        return g_Frontend_DispatchEquipmentEventAddress;
    case SCREEN_EVENT_ID(10):
        return g_CTrialCatalogue_DispatchCatalogueEventAddress;
    case SCREEN_EVENT_ID(15):
        return g_CTrialCatalogue_DispatchOptionsEventAddress;
    case SCREEN_EVENT_ID(3):
        return g_Frontend_DispatchPlayModeEventAddress;
    case SCREEN_EVENT_ID(4):
        return g_Frontend_DispatchOptionsPageEventAddress;
    case SCREEN_EVENT_ID(6):
        return g_Menu_DispatchSoundOptionsEventAddress;
    case SCREEN_EVENT_ID(5):
        return g_Player_DispatchPlayerSettingsEventAddress;
    case SCREEN_EVENT_ID(11):
        return g_Frontend_DispatchCompactOptionsEventAddress;
    case SCREEN_EVENT_ID(12):
        return g_Player_DispatchAlternatePlayerSettingsEventAddress;
    case SCREEN_EVENT_ID(13):
        return g_Menu_DispatchSoundSliderEventAddress;
    case SCREEN_EVENT_ID(16):
        return g_Menu_DispatchSelectionMenuEventAddress;
    case SCREEN_EVENT_ID(17):
        return g_Frontend_DispatchResultsEventAddress;
    case SCREEN_EVENT_ID(18):
        return g_Achieve_DispatchResultsActorEventAddress;
    case SCREEN_EVENT_ID(9):
        return g_Menu_DispatchScrollingChoiceEventAddress;
    case SCREEN_EVENT_ID(30):
        return g_Menu_DispatchTitleButtonEventAddress;
    case SCREEN_EVENT_ID(20):
        return g_ScenarioSetup_DispatchCatalogueEventAddress;
    case SCREEN_EVENT_ID(21):
        return g_Frontend_DispatchMatchOptionsEventAddress;
    case SCREEN_EVENT_ID(23):
        return g_Join_DispatchJoinOptionsEventAddress;
    case SCREEN_EVENT_ID(14):
        return g_Frontend_DispatchMatchMenuEventAddress;
    case SCREEN_EVENT_ID(19):
        return g_Frontend_DispatchPakProfileEventAddress;
    case SCREEN_EVENT_ID(22):
        return g_Frontend_DispatchTabOptionsEventAddress;
    case SCREEN_EVENT_ID(24):
        return g_Frontend_DispatchProfileResetEventAddress;
    case SCREEN_EVENT_ID(25):
        return g_Menu_DispatchOptionsTransitionEventAddress;
    case SCREEN_EVENT_ID(27):
        return g_Menu_DispatchSixChoiceEventAddress;
    case SCREEN_EVENT_ID(26):
        return g_Frontend_DispatchPlayerCountEventAddress;
    case SCREEN_EVENT_ID(29):
        return g_SmpOverlay_DispatchPakDialogEventAddress;
    case SCREEN_EVENT_ID(28):
        return g_Menu_DispatchExtraOptionsEventAddress;
    case SCREEN_EVENT_ID(33):
        return g_Frontend_DispatchNodePairMenuEventAddress;
    default:
        return 0;
    }
}
#if VERSION_US
INCLUDE_DATA("ovl_frontendMenu", g_screenEventTablePadding_us);
#endif
#if VERSION_EU_X
INCLUDE_DATA("ovl_frontendMenu", g_screenEventTablePadding_eu_x);
#endif
#if VERSION_EU
INCLUDE_DATA("ovl_frontendMenu", g_screenEventTablePadding_eu);
#endif
#if VERSION_DE
INCLUDE_DATA("ovl_frontendMenu", g_screenEventTablePadding_de);
#endif
