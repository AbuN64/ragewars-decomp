#include "COMMON/S1_6.H"
#include "FRONTEND/FRONTEND_OPENGAMEPLAYFRONTEND.H"
#include "COMMON/MENURECAT20V1.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"
#include "stddef.h"
#include "FRONTEND/NODE_FINDWIDGETBYRESOURCEID.H"

/* Calls InitFrontendMenus and then SmXlate_SwitchScreen with 1. */
#if defined(VERSION_EU)
extern void Tsmos_InitializeEuropeanFrontend();
#else
extern void InitFrontendMenus();
#endif
extern void SmXlate_SwitchScreen(int);

void Frontend_OpenGameplayFrontend(void) {
    
#if defined(VERSION_EU)
Tsmos_InitializeEuropeanFrontend
#else
InitFrontendMenus
#endif
();
    SmXlate_SwitchScreen(1);
}

/* Allocates menu state, selects the language-dependent title and enables the appropriate menu item. */
extern s32 *D_800E5550;
extern s32 *Cache_AllocateMemory(s32);
extern void Tsmos_ActivateControllerState(void); extern void Widget_SetWidgetFlag100(s32, s32);
extern s32 Frontend_GetScreenMode(void),ScenarioSetup_IsCupSelected(void);
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
enum { MENU_80435D14_62 = 62 };
#elif defined(VERSION_EU_X)
enum { MENU_80435D14_62 = 64 };
#endif
s32 Frontend_CreatePauseMenu(MenuWidget *root) {
    s32 *temp_v0;
    temp_v0 = Cache_AllocateMemory(0x14);
    D_800E5550 = temp_v0;
    *temp_v0 = 0;
    func_8025E214_de(-1);
    Control_SaveControllerSetup();
    if (Frontend_GetScreenMode() == 1) {
        root->x = 0x62;
        root->y = 0x45;
    } else if (Frontend_GetScreenMode() == 2) {
        root->x = 0x69;
    }
    Tsmos_ActivateControllerState();
    if ((D_801462C8.controllerMode != 0) || (ScenarioSetup_IsCupSelected() == 0)) {
        Widget_SetWidgetFlag100((s32)Node_FindWidgetByResourceId(root, MENU_80435D14_62), 1);
    }
    D_8011FAC0.clockPaused = 1;
    return 0;
}
