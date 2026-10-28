#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/S1_5.H"
#include "TYPES.H"
#include "MENU_2/EXTERNS.H"
#include "COMMON/SCREEN.H"

/* 80406A88_12.CPP */
#if defined(VERSION_EU_X)
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E4EC0, an actor kind at D_800E4EC4 and a handler at D_800E4EC8: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from Menu_DispatchOptionsTransitionEvent. */

s32 Match_DispatchEuxMatchMenuEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E4EC8 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E4EC8;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E4EC0)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E4EC4)) + offset))->field_0;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(Handler802A2B50 *)entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 0xC;
            offset += 0xC;
        } while (*(Handler802A2B50 *)entry != 0);
    }
    return 0;
}
#endif

#if defined(VERSION_EU_X)
unsigned int func_80429DEC_eu_x_padding_119E7C[1] = {
    0x00000000,
};
#endif

/* 80408AC4.CPP */
#if defined(VERSION_DE)
unsigned int data_unresolved_800DDA24[3] = {
    0x004297A8, 0x00429754, 0x004297A8,
};
#endif

#if defined(VERSION_DE)
#include "COMMON/OWNERRECAT8V1.H"

s32 Match_ClearGermanLoadingHints(void) {
    SmpButton_WrapButtonWidget(0x1D5);
    SmpButton_WrapButtonWidget(0x1D6);
    return 0;
}
#endif

#if defined(VERSION_DE)
#include "FRONTEND/MATCH_MENU_MESSAGE_IDS.H"
#include "MENU/PAK_LOAD.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/REQUESTRECAT10.H"

/* Handles the menu message Menu_GetFocusedElementId reports after MarkMenuEventHandled. 0x1D5: when
   Menu_GetPreviousScreenOwner(0) reports 0x16 it stops the menu object and the menu data D_80145040, releases
   D_8011FE88, restarts Cache_SetResourceActivityState when func_8025477C_de reports it idle, sets the menu stage to 8
   and sends Random_SetMenuChoiceResult 20, 10, 15 or 10 by the controller mode (3 for any other mode); otherwise
   it sends 3. 0x1D6 sends 11 when Menu_GetPreviousScreenOwner(0) reports 11 and -1 otherwise. Either then calls
   Menu_ReturnToPreviousScreen. Returns zero. */
extern void Pools_ResetActorPools(void *, s32);
extern void Player_InitializePlayerPool(void *, s32, s32);
extern void Scene_LoadLevelResources(void *, s32, s32);
extern s32 func_8025477C_de(void);
extern void Cache_SetResourceActivityState(s32);
extern void Menu_ReturnToPreviousScreen(void);

s32 Match_HandleMatchMessage(void) {
    MarkMenuEventHandled();
    switch (Menu_GetFocusedElementId()) {
    default:
        return 0;
    case MENU_804291A8_473:
        if (Menu_GetPreviousScreenOwner(0) == 0x16) {
            Pools_ResetActorPools(&D_80145040.object, 0);
            Player_InitializePlayerPool(&D_80145040, 0, 0);
            Scene_LoadLevelResources(&g_world, 0, 0);
            if (func_8025477C_de() == 0) {
                Cache_SetResourceActivityState(1);
            }
            D_80145040.stage = 8;
            switch (D_80145040.game.controllerMode) {
            case 0:
                Random_SetMenuChoiceResult(20);
                break;
            case 1:
                Random_SetMenuChoiceResult(10);
                break;
            case 2:
                Random_SetMenuChoiceResult(15);
                break;
            case 3:
            case 4:
                Random_SetMenuChoiceResult(10);
                break;
            default:
                Random_SetMenuChoiceResult(3);
                break;
            }
        } else {
            Random_SetMenuChoiceResult(3);
        }
        break;
    case MENU_804291A8_474:
        if (Menu_GetPreviousScreenOwner(0) == 11) {
            Random_SetMenuChoiceResult(11);
        } else {
            Random_SetMenuChoiceResult(-1);
        }
        break;
    }
    Menu_ReturnToPreviousScreen();
    return 0;
}
#endif
