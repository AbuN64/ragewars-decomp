#include "COMMON/SCREEN.H"
#include "COMMON/S1_6.H"
#include "COMMON/GAME_SESSION.H"
#include "TYPES.H"
#include "FRONTEND/SCREEN.H"

/* Handles the menu message Smos_GetFocusedElementId reports after MarkMenuEventHandled: 0x3D8 clears D_80146894, calls Tsmos_DeactivateControllerState, then calls Frontend_StartMenuImageTransition on D_800E5558 when ScenarioSetup_StartRandomCupStage reports non-zero or else func_8040C428_de with zero and SmXlate_SwitchScreen with 0x14; 0x3D9 calls SmXlate_SwitchScreen with one. Returns zero.
   Adapted from Frontend_ActivatePauseMenuAction with the message numbers and the arms changed. */
extern s32 D_800E5558;
extern void Tsmos_DeactivateControllerState(void);
extern s32 ScenarioSetup_StartRandomCupStage(void);
extern void Frontend_StartMenuImageTransition(s32);
extern void SmXlate_SwitchScreen(s32);

#if defined(VERSION_DE)
enum { MENU_8043659C_984 = 978, MENU_8043659C_985 = 979 };
#elif defined(VERSION_EU_X)
enum { MENU_8043659C_984 = 988, MENU_8043659C_985 = 989 };
#else
enum { MENU_8043659C_984 = 984, MENU_8043659C_985 = 985 };
#endif

s32 Frontend_HandlePage67Choice(void) {
    MarkMenuEventHandled();
    switch (Smos_GetFocusedElementId()) {
    case MENU_8043659C_985:
        SmXlate_SwitchScreen(1);
        return 0;
    case MENU_8043659C_984:
        D_8011FAC0.clockPaused = 0;
        Tsmos_DeactivateControllerState();
        if (ScenarioSetup_StartRandomCupStage() == 0) {
            Frontend_RequestScreenMode(0);
            SmXlate_SwitchScreen(0x14);
        } else {
            Frontend_StartMenuImageTransition(D_800E5558);
        }
        return 0;
    }
    return 0;
}
