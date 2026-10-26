#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RECRECAT4.H"
#include "TYPES.H"

/* Calls MarkMenuEventHandled, sets the word at offset 0x20 of the object g_optionsPage points to to -1,
   calls SmpSlider_SetTransitionMode on the object's first word with 2 and then Menu_CommitOptionsPage, returning zero. */


extern struct StateFrontendUpdateOptionsPageExit *g_optionsPage;
extern void MarkMenuEventHandled();
extern void SmpSlider_SetTransitionMode(void *, s32);
extern void Menu_CommitOptionsPage();

s32 Frontend_CloseOptionsPage(void) {
    struct StateFrontendUpdateOptionsPageExit *state;

    MarkMenuEventHandled();
    state = g_optionsPage;
    state->value = -1;
    SmpSlider_SetTransitionMode(state->menu, 2);
    Menu_CommitOptionsPage();
    return 0;
}
