#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RECRECAT4.H"
#include "TYPES.H"

/* Calls MarkMenuEventHandled, sets the word at offset 0x20 of the object g_optionsPage points to to -1,
   calls func_8041A430_de on the object's first word with 2 and then func_80422FC0_de, returning zero. */


extern struct State_func_804232AC_de *g_optionsPage;
extern void MarkMenuEventHandled();
extern void func_8041A430_de(void *, s32);
extern void func_80422FC0_de();

s32 func_804233E8_de(void) {
    struct State_func_804232AC_de *state;

    MarkMenuEventHandled();
    state = g_optionsPage;
    state->value = -1;
    func_8041A430_de(state->menu, 2);
    func_80422FC0_de();
    return 0;
}
