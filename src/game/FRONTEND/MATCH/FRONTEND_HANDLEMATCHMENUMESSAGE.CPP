#include "COMMON/SCREEN.H"
#include "COMMON/WORLD.H"
#include "include_asm.h"
#include "FRONTEND/OPTIONS.H"
#include "TYPES.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ITEMRECAT20V1.H"

/* 80423280_45.CPP */
#if !defined(VERSION_DE)
#include "FRONTEND/MATCH_MENU_MESSAGE_IDS.H"
#include "TYPES.H"

/* Handles the menu message Menu_GetFocusedElementId reports after MarkMenuEventHandled. 0x1D9: when
   Menu_GetPreviousScreenOwner(0) reports 0x16 it stops the menu object and the menu data D_80145040, releases
   D_8011FE88, restarts Cache_SetResourceActivityState when func_8025477C_de reports it idle, sets the menu stage to 8
   and sends Random_SetMenuChoiceResult 20, 10, 15 or 10 by the controller mode (3 for any other mode); otherwise
   it sends 3. 0x1DA sends 11 when Menu_GetPreviousScreenOwner(0) reports 11 and -1 otherwise. Either then calls
   Menu_ReturnToPreviousScreen. Returns zero. */
#include "MENU/PAK_LOAD.H"

extern void Pools_ResetActorPools(void *, s32);
extern void Player_InitializePlayerPool(void *, s32, s32);
extern void Scene_LoadLevelResources(void *, s32, s32);
extern s32 func_8025477C_de(void);
extern void Cache_SetResourceActivityState(s32);

s32 Frontend_HandleMatchMenuMessage(void) {
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

/* Calls MarkMenuEventHandled, then passes 0xB to Random_SetMenuChoiceResult when Menu_GetPreviousScreenOwner reports 0xB for zero
   and -1 otherwise, then calls Menu_ReturnToPreviousScreen. Returns zero. */

s32 Frontend_CloseMatchMenu(void) {
    MarkMenuEventHandled();
    Random_SetMenuChoiceResult(Menu_GetPreviousScreenOwner(0) == 0xB ? 0xB : -1);
    Menu_ReturnToPreviousScreen();
    return 0;
}

/* 80423280_46.CPP */
#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E4EC0, an actor kind at D_800E4EC4 and a handler at D_800E4EC8: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

typedef s32 (*Handler8042931C)(void *, s32, s32, s32, s32);

extern FieldRow D_800E4EC0[];
extern FieldRow D_800E4EC4[];
extern Handler8042931C D_800E4EC8;

struct ObjRecAtCV1;

s32 Frontend_DispatchMatchMenuEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler8042931C *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E4EC8 != 0) {
        wildcard = 0x7530;
        entry = &D_800E4EC8;
        index = 0;
        do {
            if (D_800E4EC0[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E4EC4[index].value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 3;
            index++;
        } while (*entry != 0);
    }
    return 0;
}
#endif
