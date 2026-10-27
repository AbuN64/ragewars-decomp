#include "include_asm.h"
#include "COMMON/NUMBERPADSCREEN.H"
#include "COMMON/CHEATCODE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU_2/STATE.H"
#include "TYPES.H"

/* 80406A88_5.CPP */
#if defined(VERSION_EU_X)
#include "COMMON/SCREEN.H"

s32 Menu_HandleEuxExtraOptionsChoice(void) {
    s32 message;
    MarkMenuEventHandled();
    if (D_800E4400->open == 0) {
        Menu_ShowExtraOptionsPanel();
    } else {
        message = Smos_GetFocusedElementId();
        switch (message) {
        case 0x3BA:
            SmpSlider_SetTransitionMode(D_800E4400->dialog, 2);
            Menu_ApplyExtraOptionFlags();
            break;
        case 0x3B2:
            Menu_OpenOptionsKeypad();
            break;
        }
    }
    return 0;
}
#endif

/* 80408AC4_23.CPP */
#if defined(VERSION_DE)
#if defined(VERSION_DE)
enum { menu_id_3ac = 0x3A6, menu_id_3b6 = 0x3B0 };
#endif

/* After MarkMenuEventHandled, opens screen D_800E4400 through Menu_ShowExtraOptionsPanel while its word at 0x34 is
   zero; otherwise handles the menu message Smos_GetFocusedElementId reports: menu_id_3ac closes the screen's first
   word through SmpSlider_SetTransitionMode with 2 and calls Menu_ApplyExtraOptionFlags, and menu_id_3b6 calls Menu_OpenOptionsKeypad.
   Returns zero. */

extern void MarkMenuEventHandled(void);

extern s32 Smos_GetFocusedElementId(void);

/* Calls MarkMenuEventHandled, then Menu_ShowExtraOptionsPanel when the word at offset 0x34 of the object D_800E4400
   points to is clear, or SmpSlider_SetTransitionMode on its first word with 2 and Menu_ApplyExtraOptionFlags otherwise.
   Returns zero. */

extern void MarkMenuEventHandled();

s32 Menu_HandleGermanExtraOptionsChoice(void) {
    extern s32 SmpSlider_GetTransitionMode(s32);
    extern void SmpSlider_SetTransitionMode(s32, s32);
    extern struct RecordFrontendSetPreviewModel *D_800E4400;
    if (SmpSlider_GetTransitionMode(D_800E4400->count) != 3) {
        return 0;
    }
    MarkMenuEventHandled();
    if (D_800E4400->handle == 0) {
        Menu_ShowExtraOptionsPanel();
    } else {
        switch (Smos_GetFocusedElementId()) {
        case menu_id_3ac:
            SmpSlider_SetTransitionMode(D_800E4400->count, 2);
            Menu_ApplyExtraOptionFlags();
            break;
        case menu_id_3b6:
            Menu_OpenOptionsKeypad();
            break;
        }
    }
    return 0;
}

s32 Menu_ConfirmGermanExtraOptions(void) {
    extern s32 SmpSlider_GetTransitionMode(void *);
    extern void SmpSlider_SetTransitionMode(void *, s32);
    extern struct StateMenuConfirmGermanExtraOptions *D_800E4400;
    struct StateMenuConfirmGermanExtraOptions *state;

    MarkMenuEventHandled();
    if (SmpSlider_GetTransitionMode(D_800E4400->first) != 3) {
        return 0;
    }
    state = D_800E4400;
    if (state->ready == 0) {
        Menu_ShowExtraOptionsPanel();
    } else {
        SmpSlider_SetTransitionMode(state->first, 2);
        Menu_ApplyExtraOptionFlags();
    }
    return 0;
}
#endif
