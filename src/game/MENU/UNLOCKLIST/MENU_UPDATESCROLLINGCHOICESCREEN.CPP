#include "include_asm.h"
#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "TYPES.H"
#include "SCENE/CACHE_FREEMEMORY.H"
extern struct StateMenuUpdateScrollingChoiceScreen *D_800E5780;
extern void SmpSlider_SetTransitionMode(void *, s32);
extern s32 Defs_TestBit(void *, s32);

/* Releases the object D_800E5780 holds through Cache_FreeMemory, clears D_800E5780 and returns zero. */

#if defined(VERSION_DE)
enum { MENU_RESOURCE = 0x139 };
#elif defined(VERSION_EU)
enum { MENU_RESOURCE = 0x13b };
#elif defined(VERSION_EU_X)
enum { MENU_RESOURCE = 0x13f };
#elif defined(VERSION_US_REV1) || defined(VERSION_US)
enum { MENU_RESOURCE = 0x13b };
#endif

/* Runs the screen D_800E5780 each frame: when its menu reports 1 for the first time it marks the
   word at 0x14 and, unless bit 0 of the flag set at 0x7E of the first 400-byte record of
   D_80102B00 is set, passes 0x13B to Menu_SetFocusedElement; while the menu reports 3 it counts the delay
   at 0xC down and on expiry scrolls the list at 0x8 back one row, wrapping to the menu's own row
   count, and restarts the delay at 3; when the menu reports 4 it calls MarkMenuEventHandled and leaves
   through SmXlate_SwitchScreen with the target at 0x10, or 3 when that is -1. Returns zero. Adapted from
   Frontend_UpdatePlayerCountScreen with the stage test removed, case 1 added and the -1 target mapped to 3. */

extern u8 D_80102B00[];

extern s32 SmpSlider_GetTransitionMode(struct MenuFrontendUpdatePlayModeMenu *);

extern void Menu_SetFocusedElement(s32);

extern void MarkMenuEventHandled();

extern void SmXlate_SwitchScreen(s32);

/* Calls MarkMenuEventHandled, then sets the word at offset 0x10 of the object D_800E5780 points to to -1 and
   calls SmpSlider_SetTransitionMode on the object's first word with 2, returning zero. */

/* Handles menu selection and updates the active menu state. */

extern u8 D_800FEB0F;
extern u8 D_80102B7E;
extern u8 D_80142358;

 void MarkMenuEventHandled(void);

 s32 Menu_GetFocusedElementId(void);

 

 

s32 Menu_FreeScrollingChoiceScreen(void) {
    Cache_FreeMemory(D_800E5780);
    D_800E5780 = 0;
    return 0;
}

/* Calls SmpButton_WrapButtonWidget with 0x13B, 0x13A and 0x13C in turn and returns zero. */
s32 Menu_WrapScrollingChoiceNodes(void) {
#if defined(VERSION_DE)
    SmpButton_WrapButtonWidget(0x139);
    SmpButton_WrapButtonWidget(0x138);
    SmpButton_WrapButtonWidget(0x13A);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    SmpButton_WrapButtonWidget(0x13B);
    SmpButton_WrapButtonWidget(0x13A);
    SmpButton_WrapButtonWidget(0x13C);
#elif defined(VERSION_EU_X)
    SmpButton_WrapButtonWidget(0x13F);
    SmpButton_WrapButtonWidget(0x13E);
    SmpButton_WrapButtonWidget(0x140);
#endif
    return 0;
}

s32 Menu_UpdateScrollingChoiceScreen(void) {
    s32 result;
    s32 target;

    switch (result = SmpSlider_GetTransitionMode(D_800E5780->menu)) {
    case 1:
        if (D_800E5780->seen != 0) {
            return 0;
        }
        D_800E5780->seen = result;
        if (Defs_TestBit(D_80102B00 + 0x7E, 0) != 0) {
            return 0;
        }
        Menu_SetFocusedElement(MENU_RESOURCE);
        return 0;
    case 3:
        if (--D_800E5780->delay <= 0) {
            D_800E5780->list->unk16--;
            if (D_800E5780->list->unk16 + D_800E5780->list->unk1A < 0) {
                D_800E5780->list->unk16 = D_800E5780->menu->list->unk1A;
            }
            D_800E5780->delay = result;
        }
        break;
    case 4:
        MarkMenuEventHandled();
        target = D_800E5780->target;
        if (target == -1) {
            target = 3;
        }
        SmXlate_SwitchScreen(target);
        break;
    default:
        return 0;
    }
    return 0;
}

s32 Menu_CancelScrollingChoiceScreen(void) {
    struct StateMenuUpdateScrollingChoiceScreen *state;

    MarkMenuEventHandled();
    state = D_800E5780;
    state->target = -1;
    SmpSlider_SetTransitionMode(state->menu, 2);
    return 0;
}

s32 Menu_HandleScrollingChoice(void) {
    s32 focusedElementIdResult;
    s32 var_v0;
    MarkMenuEventHandled();
    focusedElementIdResult = Menu_GetFocusedElementId();
    switch (focusedElementIdResult) { /* irregular */
#if defined(VERSION_DE)
    case 0x138 + 2:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x13A + 2:
#elif defined(VERSION_EU_X)
    case 0x13E + 2:
#endif
        D_800E5780->target = -1;
        break;
#if defined(VERSION_DE)
    case 0x138 + 1:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x13A + 1:
#elif defined(VERSION_EU_X)
    case 0x13E + 1:
#endif
        if (Defs_TestBit(&D_80102B7E, 0) == 0) {
            D_800E5780->target = 7;
        } else {
            D_800E5780->target = 0x1E;
        }
        break;
#if defined(VERSION_DE)
    case 0x138:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x13A:
#elif defined(VERSION_EU_X)
    case 0x13E:
#endif
        D_80142358 = D_800FEB0F;
        D_800E5780->target = 0xA;
        break;
    }
    SmpSlider_SetTransitionMode(D_800E5780->menu, 2);
    return 0;
}
