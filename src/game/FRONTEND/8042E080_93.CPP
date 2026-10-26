#include "COMMON/S1_6.H"
#include "COMMON/GAME_SESSION.H"
#include "TYPES.H"

/* Handles the menu message func_80299A08_de reports after MarkMenuEventHandled: 0x3D8 clears D_80146894, calls Tsmos_DeactivateControllerState, then calls func_8043C278_de on D_800E5558 when ScenarioSetup_StartRandomCupStage reports non-zero or else func_8040C428_de with zero and func_80298368_de with 0x14; 0x3D9 calls func_80298368_de with one. Returns zero.
   Adapted from func_80435CD8_de with the message numbers and the arms changed. */
extern s32 D_800E5558;
extern void MarkMenuEventHandled(void);
extern s32 func_80299A08_de(void);
extern void Tsmos_DeactivateControllerState(void);
extern s32 ScenarioSetup_StartRandomCupStage(void);
extern void Frontend_RequestScreenMode(s32);
extern void func_8043C278_de(s32);
extern void func_80298368_de(s32);

#if defined(VERSION_DE)
enum { MENU_8043659C_984 = 978, MENU_8043659C_985 = 979 };
#elif defined(VERSION_EU_X)
enum { MENU_8043659C_984 = 988, MENU_8043659C_985 = 989 };
#else
enum { MENU_8043659C_984 = 984, MENU_8043659C_985 = 985 };
#endif

s32 func_804363BC_de(void) {
    MarkMenuEventHandled();
    switch (func_80299A08_de()) {
    case MENU_8043659C_985:
        func_80298368_de(1);
        return 0;
    case MENU_8043659C_984:
        D_8011FAC0.clockPaused = 0;
        Tsmos_DeactivateControllerState();
        if (ScenarioSetup_StartRandomCupStage() == 0) {
            Frontend_RequestScreenMode(0);
            func_80298368_de(0x14);
        } else {
            func_8043C278_de(D_800E5558);
        }
        return 0;
    }
    return 0;
}
