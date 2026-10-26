#include "COMMON/CHEATCODE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU_2/STATE.H"
#include "TYPES.H"

#if defined(VERSION_DE)
#if defined(VERSION_DE)
enum { menu_id_3ac = 0x3A6, menu_id_3b6 = 0x3B0 };
#endif

/* After MarkMenuEventHandled, opens screen D_800E4400 through Menu_ShowExtraOptionsPanel while its word at 0x34 is
   zero; otherwise handles the menu message func_80299A08_de reports: menu_id_3ac closes the screen's first
   word through func_8041A430_de with 2 and calls Menu_ApplyExtraOptionFlags, and menu_id_3b6 calls Menu_OpenOptionsKeypad.
   Returns zero. */




extern void MarkMenuEventHandled(void);

extern s32 func_80299A08_de(void);

extern void Menu_ShowExtraOptionsPanel(void);

extern void Menu_ApplyExtraOptionFlags(void);

extern void Menu_OpenOptionsKeypad(void);

/* Calls MarkMenuEventHandled, then Menu_ShowExtraOptionsPanel when the word at offset 0x34 of the object D_800E4400
   points to is clear, or func_8041A430_de on its first word with 2 and Menu_ApplyExtraOptionFlags otherwise.
   Returns zero. */




extern void MarkMenuEventHandled();

extern void Menu_ShowExtraOptionsPanel();

extern void Menu_ApplyExtraOptionFlags();

s32 Menu_HandleGermanExtraOptionsChoice(void) {
    extern s32 func_8041A470_de(s32);
    extern void func_8041A430_de(s32, s32);
    extern struct Record_func_80439C80_de *D_800E4400;
    if (func_8041A470_de(D_800E4400->count) != 3) {
        return 0;
    }
    MarkMenuEventHandled();
    if (D_800E4400->handle == 0) {
        Menu_ShowExtraOptionsPanel();
    } else {
        switch (func_80299A08_de()) {
        case menu_id_3ac:
            func_8041A430_de(D_800E4400->count, 2);
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
    extern s32 func_8041A470_de(void *);
    extern void func_8041A430_de(void *, s32);
    extern struct StateMenuConfirmGermanExtraOptions *D_800E4400;
    struct StateMenuConfirmGermanExtraOptions *state;

    MarkMenuEventHandled();
    if (func_8041A470_de(D_800E4400->first) != 3) {
        return 0;
    }
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
