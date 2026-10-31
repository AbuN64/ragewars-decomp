#include "include_asm.h"
#include "COMMON/NUMBERPADSCREEN.H"
#include "COMMON/CHEATCODE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/STATE.H"
#include "TYPES.H"
#if defined(VERSION_EU_X)
#include "COMMON/SCREEN.H"
#endif
#if defined(VERSION_DE)
#if defined(VERSION_DE)
/* 80408AC4_23.CPP */
enum { menu_id_3ac = 934, menu_id_3b6 = 944 };
#endif
/* After MarkMenuEventHandled, opens screen g_extraOptionsScreen through Menu_ShowExtraOptionsPanel while its word at 0x34 is
   zero; otherwise handles the menu message Menu_GetFocusedElementId reports: menu_id_3ac closes the screen's first
   word through SmpSlider_SetTransitionMode with 2 and calls Menu_ApplyExtraOptionFlags, and menu_id_3b6 calls Menu_OpenOptionsKeypad.
   Returns zero. */
extern void MarkMenuEventHandled(void);
/* Calls MarkMenuEventHandled, then Menu_ShowExtraOptionsPanel when the word at offset 0x34 of the object g_extraOptionsScreen
   points to is clear, or SmpSlider_SetTransitionMode on its first word with 2 and Menu_ApplyExtraOptionFlags otherwise.
   Returns zero. */
extern void MarkMenuEventHandled();
s32 Menu_ConfirmGermanExtraOptions(void) {
    extern s32 SmpSlider_GetTransitionMode(void *);
    extern void SmpSlider_SetTransitionMode(void *, s32);
    extern struct StateMenuConfirmGermanExtraOptions *g_extraOptionsScreen;
    struct StateMenuConfirmGermanExtraOptions *state;

    MarkMenuEventHandled();
    if (SmpSlider_GetTransitionMode(g_extraOptionsScreen->first) != 3) {
        return 0;
    }
    state = g_extraOptionsScreen;
    if (state->ready == 0) {
        Menu_ShowExtraOptionsPanel();
    } else {
        SmpSlider_SetTransitionMode(state->first, 2);
        Menu_ApplyExtraOptionFlags();
    }
    return 0;
}
#endif
