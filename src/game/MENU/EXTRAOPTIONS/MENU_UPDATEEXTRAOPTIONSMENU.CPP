#include "COMMON/SCREEN.H"
#include "COMMON/NUMBERPADSCREEN.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "stddef.h"
#include "TYPES.H"
#include "MENU/80420E90.H"
#include "MENU/80420E90_9.H"
#include "SCENE/802508E0_13.H"
extern MenuWidget *Frontend_FindWidgetByResourceId(void *, s32);

/* Calls func_8040E8D8_de with zero on the object at offset 0x20 of the structure D_800E4400 points
   to, and with one on the entry 0x3AB that Frontend_FindWidgetByResourceId finds in the list at offset 8, then sets
   the word at offset 0x34. */


extern void Frontend_SetWidgetFlag08(void *, s32);

/* Advances the animation frame countdown and wraps exhausted frames. */


 /* extern */
void Menu_AdvanceTextRows(void *, void *);

 /* extern */


/* Releases the object D_800E4400 holds through Cache_FreeMemory, clears D_800E4400 and returns zero. */



/* Polls the dialog of screen D_800E4400 through SmpSlider_GetTransitionMode: state 3 opens the screen through
   Menu_ScrollOptionsKeypad while its word at 0x34 is zero, and otherwise, when D_8010B0E0.buttons is 0x433, marks the
   screen confirmed at 0x38 and calls Menu_RefreshExtraOptionLocks; state 4 calls MarkMenuEventHandled and waits 3
   through SmXlate_SwitchScreen. Returns zero. */





extern s32 SmpSlider_GetTransitionMode(s32);


extern void SmXlate_SwitchScreen(s32);

void Menu_ShowExtraOptionsPanel(void) {
    Frontend_SetWidgetFlag08(D_800E4400->pad, 0);
#if defined(VERSION_DE)
    Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E4400->window, 0x3A5), 1);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E4400->window, 0x3AB), 1);
#elif defined(VERSION_EU_X)
    Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E4400->window, 0x3AF), 1);
#endif
    D_800E4400->open = 1;
}

void Menu_ScrollOptionsKeypad(void) {
    s32 currentMode;
    MenuWidget *temp_a0;
    MenuWidget *temp_a0_2;
    MenuWidget *temp_v0_2;
    currentMode = D_800E4400->mode - 1;
    D_800E4400->mode = currentMode;
    if (currentMode <= 0) {
#if defined(VERSION_DE)
        temp_v0_2 = Frontend_FindWidgetByResourceId(D_800E4400->window, 0x3B2);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        temp_v0_2 = Frontend_FindWidgetByResourceId(D_800E4400->window, 0x3B8);
#elif defined(VERSION_EU_X)
        temp_v0_2 = Frontend_FindWidgetByResourceId(D_800E4400->window, 0x3BC);
#endif
        temp_a0 = D_800E4400->pad;
        temp_a0->y = (u16) (temp_a0->y - 1);
        temp_a0_2 = D_800E4400->pad;
        if (((s16) temp_a0_2->y + temp_v0_2->height) < 0) {
            temp_a0_2->y = 2U;
            Menu_AdvanceTextRows(temp_a0_2, D_800E4400);
        }
        D_800E4400->mode = 1;
    }
}

s32 Menu_DestroyExtraOptionsMenu(void) {
    Cache_FreeMemory(D_800E4400);
    D_800E4400 = 0;
    return 0;
}

s32 Menu_UpdateExtraOptionsMenu(void) {
    switch (SmpSlider_GetTransitionMode(D_800E4400->dialog)) {
    case 3:
        if (D_800E4400->open == 0) {
            Menu_ScrollOptionsKeypad();
            return 0;
        }
        if (D_8010B0E0.buttons != 0x433) {
            return 0;
        }
        D_800E4400->confirmed = 1;
        Menu_RefreshExtraOptionLocks();
        return 0;
    case 4:
        MarkMenuEventHandled();
        SmXlate_SwitchScreen(3);
        return 0;
    }
    return 0;
}
