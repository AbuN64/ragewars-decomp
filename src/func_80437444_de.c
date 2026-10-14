#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804366C4.h"
#if defined(VERSION_DE)
enum { MENU_RESOURCE = 0x139 };
#elif defined(VERSION_EU)
enum { MENU_RESOURCE = 0x13b };
#elif defined(VERSION_EU_X)
enum { MENU_RESOURCE = 0x13f };
#elif defined(VERSION_US_REV1)
enum { MENU_RESOURCE = 0x13b };
#endif
#include "types.h"

/* Runs the screen D_800E5780 each frame: when its menu reports 1 for the first time it marks the
   word at 0x14 and, unless bit 0 of the flag set at 0x7E of the first 400-byte record of
   D_80102B00 is set, passes 0x13B to func_802991D4_de; while the menu reports 3 it counts the delay
   at 0xC down and on expiry scrolls the list at 0x8 back one row, wrapping to the menu's own row
   count, and restarts the delay at 3; when the menu reports 4 it calls func_8029973C_de and leaves
   through func_80298368_de with the target at 0x10, or 3 when that is -1. Returns zero. Adapted from
   func_8042DAF8_de with the stage test removed, case 1 added and the -1 target mapped to 3. */







extern struct State_func_80437444_de *D_800E5780;
extern u8 D_80102B00[];
extern s32 func_8041A470_de(struct Menu_func_804241BC_de *);
extern s32 func_80265650_de(u8 *, s32);
extern void func_802991D4_de(s32);
extern void func_8029973C_de();
extern void func_80298368_de(s32);

s32 func_80437444_de(void) {
    s32 result;
    s32 target;

    switch (result = func_8041A470_de(D_800E5780->menu)) {
    case 1:
        if (D_800E5780->seen != 0) {
            return 0;
        }
        D_800E5780->seen = result;
        if (func_80265650_de(D_80102B00 + 0x7E, 0) != 0) {
            return 0;
        }
        func_802991D4_de(MENU_RESOURCE);
        return 0;
    case 3:
        if (--D_800E5780->delay <= 0) {
            D_800E5780->list->unk16--;
            if (D_800E5780->list->unk16 + D_800E5780->list->unk1A < 0) {
                D_800E5780->list->unk16 = D_800E5780->menu->list->unk1A;
            }
            D_800E5780->delay = result;
        }
        break;
    case 4:
        func_8029973C_de();
        target = D_800E5780->target;
        if (target == -1) {
            target = 3;
        }
        func_80298368_de(target);
        break;
    default:
        return 0;
    }
    return 0;
}
