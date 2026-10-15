#include "span_166000/code_80426310.h"
#include "common/types_1dc8418c21db.h"
#include "span_166000/code_80403E88.h"
#include "types.h"

#if defined(VERSION_DE)
enum { menu_id_3ac = 0x3A6, menu_id_3b6 = 0x3B0 };
#endif

/* After func_8029973C_de, opens screen D_800E4400 through func_8042177C_de while its word at 0x34 is
   zero; otherwise handles the menu message func_80299A08_de reports: menu_id_3ac closes the screen's first
   word through func_8041A430_de with 2 and calls func_804210E8_de, and menu_id_3b6 calls func_804213DC_de.
   Returns zero. */




extern void func_8029973C_de(void);

extern s32 func_80299A08_de(void);

extern void func_8042177C_de(void);

extern void func_804210E8_de(void);

extern void func_804213DC_de(void);

/* Calls func_8029973C_de, then func_8042177C_de when the word at offset 0x34 of the object D_800E4400
   points to is clear, or func_8041A430_de on its first word with 2 and func_804210E8_de otherwise.
   Returns zero. */




extern void func_8029973C_de();

extern void func_8042177C_de();

extern void func_804210E8_de();

s32 func_80421928_de(void) {
    extern s32 func_8041A470_de(s32);
    extern void func_8041A430_de(s32, s32);
    extern struct Record_func_80439C80_de *D_800E4400;
    if (func_8041A470_de(D_800E4400->count) != 3) {
        return 0;
    }
    func_8029973C_de();
    if (D_800E4400->handle == 0) {
        func_8042177C_de();
    } else {
        switch (func_80299A08_de()) {
        case menu_id_3ac:
            func_8041A430_de(D_800E4400->count, 2);
            func_804210E8_de();
            break;
        case menu_id_3b6:
            func_804213DC_de();
            break;
        }
    }
    return 0;
}

s32 func_804219E0_de(void) {
    extern s32 func_8041A470_de(void *);
    extern void func_8041A430_de(void *, s32);
    extern struct State_func_804219E0_de *D_800E4400;
    struct State_func_804219E0_de *state;

    func_8029973C_de();
    if (func_8041A470_de(D_800E4400->first) != 3) {
        return 0;
    }
    state = D_800E4400;
    if (state->ready == 0) {
        func_8042177C_de();
    } else {
        func_8041A430_de(state->first, 2);
        func_804210E8_de();
    }
    return 0;
}
