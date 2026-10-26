#include "include_asm.h"
#include "COMMON/WIDGETRECAT1A.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJECTRECAT28.H"
#include "TYPES.H"
#include "FRONTEND/8043962C_3.H"

#if defined(VERSION_EU_X)
extern void SmpButton_WrapButtonWidget(int id);

int Frontend_WrapNodePairExtended(void) { SmpButton_WrapButtonWidget(0x3DE); SmpButton_WrapButtonWidget(0x3DF); return 0; }
#endif

/* Handles the menu message Smos_GetFocusedElementId reports after MarkMenuEventHandled: 0x3DA waits through
   SmXlate_SwitchScreen for a time chosen by setting D_801462D5 through jtbl_800DDF70 (20, 15 or 10, and
   3 for any other setting); 0x3DB sends code -1 to Frontend_SetMenuChoiceResult and calls Smos_ReturnToPreviousScreen.
   Returns zero. */
extern void MarkMenuEventHandled(void);
extern s32 Smos_GetFocusedElementId(void);
extern void SmXlate_SwitchScreen(s32);
extern void Frontend_SetMenuChoiceResult(s32);
extern void Smos_ReturnToPreviousScreen(void);

#if defined(VERSION_DE)
enum { MENU_80439F38_986 = 980, MENU_80439F38_987 = 981 };
#elif defined(VERSION_EU_X)
enum { MENU_80439F38_986 = 990, MENU_80439F38_987 = 991 };
#else
enum { MENU_80439F38_986 = 986, MENU_80439F38_987 = 987 };
#endif

s32 Frontend_UpdateTimedTransition(void) {
    s32 time;

    MarkMenuEventHandled();
    switch (Smos_GetFocusedElementId()) {
    case MENU_80439F38_986:
        switch (D_801462C8.controllerMode) {
        case 0:
            time = 20;
            break;
        case 2:
            time = 15;
            break;
        case 3:
        case 4:
            time = 10;
            break;
        case 1:
        default:
            time = 3;
            break;
        }
        SmXlate_SwitchScreen(time);
        return 0;
    case MENU_80439F38_987:
        Frontend_SetMenuChoiceResult(-1);
        Smos_ReturnToPreviousScreen();
        return 0;
    }
    return 0;
}

/* Calls MarkMenuEventHandled, then Frontend_SetMenuChoiceResult with -1, then Smos_ReturnToPreviousScreen, and returns zero. */
extern void MarkMenuEventHandled();

s32 Frontend_CancelNodePairMenu(void) {
    MarkMenuEventHandled();
    Frontend_SetMenuChoiceResult(-1);
    Smos_ReturnToPreviousScreen();
    return 0;
}

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E59B0, an actor kind at D_800E59B4 and a handler at D_800E59B8: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

typedef s32 (*Handler8043A014)(void *, s32, s32, s32, s32);


extern FieldRow D_800E59B0[];
extern FieldRow D_800E59B4[];
extern Handler8043A014 D_800E59B8;




s32 Frontend_DispatchNodePairMenuEvent(struct Tree *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E59B8 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E59B8;
        index = 0;
        do {
            if (D_800E59B0[index].value == arg1) {
                actor_kind = arg0->id;
                table_kind = D_800E59B4[index].value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(Handler8043A014 *)entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 0xC;
            index++;
        } while (*(Handler8043A014 *)entry != 0);
    }
    return 0;
}
