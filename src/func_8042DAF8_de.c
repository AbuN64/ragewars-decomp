#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8042BD40.h"
#include "types.h"

/* Runs the screen D_800E5430 each frame: past stage 1 of D_800E28E0 it only calls func_802A2394_de;
   otherwise it calls func_802A2360_de and, while its menu reports 3, counts the delay at 0xC down and
   on expiry scrolls the list at 0x8 back one row, wrapping to the menu's own row count, and
   restarts the delay at 3; when the menu reports 4 it calls func_8029973C_de and leaves through
   func_80298368_de with the stored target or func_802998A8_de when that is -1. Returns zero. Written
   from the assembly as a switch on the menu result, matching on the first trial. */







extern s32 D_800E28E0;
extern struct State_func_8042DAF8_de *D_800E5430;
extern void func_802A2394_de();
extern void func_802A2360_de();
extern s32 func_8041A470_de(struct Menu_func_804241BC_de *);
extern void func_8029973C_de();
extern void func_80298368_de(s32);
extern void func_802998A8_de();

s32 func_8042DAF8_de(void) {
    s32 result;

    if (D_800E28E0 >= 2) {
        func_802A2394_de();
        return 0;
    }
    func_802A2360_de();
    switch (result = func_8041A470_de(D_800E5430->menu)) {
    case 3:
        if (--D_800E5430->delay <= 0) {
            D_800E5430->list->unk16--;
            if (D_800E5430->list->unk16 + D_800E5430->list->unk1A < 0) {
                D_800E5430->list->unk16 = D_800E5430->menu->list->unk1A;
            }
            D_800E5430->delay = result;
        }
        break;
    case 4:
        func_8029973C_de();
        if (D_800E5430->target != -1) {
            func_80298368_de(D_800E5430->target);
            return 0;
        }
        func_802998A8_de();
        break;
    default:
        return 0;
    }
    return 0;
}
