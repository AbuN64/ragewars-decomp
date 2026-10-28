#include "COMMON/SCREEN.H"
#include "COMMON/S1_5.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/S1_6.H"
#include "TYPES.H"
#include "MENU/MENU_REQUESTOPTIONSSCREEN22.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "FRONTEND/FRONTEND_DISPATCHPAUSEMENUEVENT.H"

/* 8042E080_78.CPP */
#if defined(VERSION_EU_X)
enum { START_MATCH = 0x43, RETURN_MENU = 0x3E, WAIT_SHORT = 0x42, WAIT_LONG = 0x40 };
#else
enum { START_MATCH = 0x40, RETURN_MENU = 0x3C, WAIT_SHORT = 0x41, WAIT_LONG = 0x3E };
#endif

/* Handles the menu message Menu_GetFocusedElementId reports after MarkMenuEventHandled: 0x40 clears D_80146894 and
   calls Tsmos_RequestFrontendShutdown and func_8025E384_de; 0x3C clears D_80146894 and calls Menu_RequestOptionsScreen22; 0x41 and
   0x3E wait 0x1F and 0x20 through SmXlate_SwitchScreen. Returns zero. */
extern void Tsmos_RequestFrontendShutdown(void);
extern void func_8025E384_de(void);

extern void SmXlate_SwitchScreen(s32);

s32 Frontend_ActivatePauseMenuAction(void) {
    s32 time;

    MarkMenuEventHandled();
    switch (Menu_GetFocusedElementId()) {
    case START_MATCH:
        D_8011FAC0.clockPaused = 0;
        Tsmos_RequestFrontendShutdown();
        func_8025E384_de();
        return 0;
    case RETURN_MENU:
        D_8011FAC0.clockPaused = 0;
        Menu_RequestOptionsScreen22();
        return 0;
    case WAIT_SHORT:
        time = 0x1F;
        goto wait;
    case WAIT_LONG:
        time = 0x20;
    wait:
        SmXlate_SwitchScreen(time);
        return 0;
    }
    return 0;
}

/* 8042E080_79.CPP */
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E555C, an actor kind at D_800E5560 and a handler at D_800E5564: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

typedef s32 (*Handler80435F70)(void *, s32, s32, s32, s32);

extern FieldRow D_800E555C[];
extern FieldRow D_800E5560[];
extern Handler80435F70 D_800E5564;

s32 Frontend_DispatchPauseMenuEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80435F70 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E5564 != 0) {
        wildcard = 0x7530;
        entry = &D_800E5564;
        index = 0;
        do {
            if (D_800E555C[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E5560[index].value;
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

/* 8042E080_80.CPP */
/* Builds screen state D_800E5554 as Frontend_CreateTimedMenu builds D_800E5558: allocates its 0x20 bytes,
   resets through Tsmos_ActivateControllerState, sets its selection at 0x1C to -1 and opens it as page 0x67 through
   Frontend_InitMenuImage; then places the given window at 0x62, 0x45 in mode 1 of func_8040C474_de, or at x
   0x69 in mode 2. Returns zero. */

extern struct MenuRules *D_800E5554;
extern struct MenuRules *Cache_AllocateMemory(s32);
extern void Tsmos_ActivateControllerState(void);
extern void Frontend_InitMenuImage(struct MenuRules *, s32, s32, s32, s32);
extern s32 Frontend_GetScreenMode(void);

s32 Frontend_CreatePauseConfirmation(struct Pair14 *window) {
    D_800E5554 = Cache_AllocateMemory(0x20);
    Tsmos_ActivateControllerState();
    D_800E5554->locked = -1;
    Frontend_InitMenuImage(D_800E5554, 0x67, 0, 0, 0);
    if (Frontend_GetScreenMode() == 1) {
        window->first = 0x62;
        window->second = 0x45;
    } else if (Frontend_GetScreenMode() == 2) {
        window->first = 0x69;
    }
    return 0;
}
