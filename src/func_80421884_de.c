#include "span_16E000/code_80420E90.h"
#include "types.h"

/* Polls the dialog of screen D_800E4400 through func_8041A470_de: state 3 opens the screen through
   func_804217D4_de while its word at 0x34 is zero, and otherwise, when D_8010F190 is 0x433, marks the
   screen confirmed at 0x38 and calls func_80421234_de; state 4 calls func_8029973C_de and waits 3
   through func_80298368_de. Returns zero. */


extern struct Screen_func_80421884_de *D_800E4400;
extern s32 D_8010F190;
extern s32 func_8041A470_de(s32);


extern void func_8029973C_de(void);
extern void func_80298368_de(s32);

s32 func_80421884_de(void) {
    switch (func_8041A470_de(D_800E4400->dialog)) {
    case 3:
        if (D_800E4400->open == 0) {
            func_804217D4_de();
            return 0;
        }
        if (D_8010F190 != 0x433) {
            return 0;
        }
        D_800E4400->confirmed = 1;
        func_80421234_de();
        return 0;
    case 4:
        func_8029973C_de();
        func_80298368_de(3);
        return 0;
    }
    return 0;
}
