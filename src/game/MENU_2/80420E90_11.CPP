#include "COMMON/NUMBERPADSCREEN.H"
#include "MENU_2/STATE.H"
#include "TYPES.H"

#if !(defined(VERSION_DE))
/* Calls MarkMenuEventHandled, then Menu_ShowExtraOptionsPanel when the word at offset 0x34 of the object D_800E4400
   points to is clear, or func_8041A430_de on its first word with 2 and Menu_ApplyExtraOptionFlags otherwise.
   Returns zero. */
struct StateMenuConfirmGermanExtraOptions;

extern struct StateMenuConfirmGermanExtraOptions *D_800E4400;
extern void MarkMenuEventHandled();

extern void func_8041A430_de(void *, s32);


s32 Menu_ConfirmExtraOptions(void) {
    struct StateMenuConfirmGermanExtraOptions *state;

    MarkMenuEventHandled();
    state = D_800E4400;
    if (state->ready == 0) {
        Menu_ShowExtraOptionsPanel();
    } else {
        func_8041A430_de(state->first, 2);
        Menu_ApplyExtraOptionFlags();
    }
    return 0;
}
#endif
