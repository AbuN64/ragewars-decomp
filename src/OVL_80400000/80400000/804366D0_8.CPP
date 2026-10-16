#include "span_16E000/code_804366C4.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041B020.h"
#include "TYPES.H"

/* Releases the object D_800E5780 holds through func_802547E4_de, clears D_800E5780 and returns zero. */


extern void func_802547E4_de(void *);

#if defined(VERSION_DE)
enum { MENU_RESOURCE = 0x139 };
#elif defined(VERSION_EU)
enum { MENU_RESOURCE = 0x13b };
#elif defined(VERSION_EU_X)
enum { MENU_RESOURCE = 0x13f };
#elif defined(VERSION_US_REV1)
enum { MENU_RESOURCE = 0x13b };
#endif

/* Runs the screen D_800E5780 each frame: when its menu reports 1 for the first time it marks the
   word at 0x14 and, unless bit 0 of the flag set at 0x7E of the first 400-byte record of
   D_80102B00 is set, passes 0x13B to func_802991D4_de; while the menu reports 3 it counts the delay
   at 0xC down and on expiry scrolls the list at 0x8 back one row, wrapping to the menu's own row
   count, and restarts the delay at 3; when the menu reports 4 it calls func_8029973C_de and leaves
   through func_80298368_de with the target at 0x10, or 3 when that is -1. Returns zero. Adapted from
   func_8042DAF8_de with the stage test removed, case 1 added and the -1 target mapped to 3. */









extern u8 D_80102B00[];

extern s32 func_8041A470_de(struct Menu_func_804241BC_de *);

extern void func_802991D4_de(s32);

extern void func_8029973C_de();

extern void func_80298368_de(s32);

/* Calls func_8029973C_de, then sets the word at offset 0x10 of the object D_800E5780 points to to -1 and
   calls func_8041A430_de on the object's first word with 2, returning zero. */




/* Handles menu selection and updates the active menu state. */


 extern u8 D_800FEB0F, D_80102B7E, D_80142358;

 void func_8029973C_de(void);

 s32 func_80299A08_de(void);

 

 

s32 func_804373E4_de(void) {
    extern void *D_800E5780;
    func_802547E4_de(D_800E5780);
    D_800E5780 = 0;
    return 0;
}

/* Calls func_8041B110_de with 0x13B, 0x13A and 0x13C in turn and returns zero. */
s32 func_80437414_de(void) {
#if defined(VERSION_DE)
    func_8041B110_de(0x139);
    func_8041B110_de(0x138);
    func_8041B110_de(0x13A);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    func_8041B110_de(0x13B);
    func_8041B110_de(0x13A);
    func_8041B110_de(0x13C);
#elif defined(VERSION_EU_X)
    func_8041B110_de(0x13F);
    func_8041B110_de(0x13E);
    func_8041B110_de(0x140);
#endif
    return 0;
}

s32 func_80437444_de(void) {
    extern s32 func_80265650_de(u8 *, s32);
    extern struct State_func_80437444_de *D_800E5780;
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

s32 func_80437574_de(void) {
    extern void func_8041A430_de(void *, s32);
    extern struct State_func_80421D94_de *D_800E5780;
    struct State_func_80421D94_de *state;

    func_8029973C_de();
    state = D_800E5780;
    state->value = -1;
    func_8041A430_de(state->first, 2);
    return 0;
}

s32 func_804375B0_de(void) {
    void func_8041A430_de(s32,s32);
    s32 func_80265650_de(void *,s32);
    extern func_8029A838_S1 *D_800E5780;
    s32 temp_v0;
    s32 var_v0;
    func_8029973C_de();
    temp_v0 = func_80299A08_de();
    switch (temp_v0) { /* irregular */
#if defined(VERSION_DE)
    case 0x138 + 2:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x13A + 2:
#elif defined(VERSION_EU_X)
    case 0x13E + 2:
#endif
        D_800E5780->unk10 = -1;
        break;
#if defined(VERSION_DE)
    case 0x138 + 1:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x13A + 1:
#elif defined(VERSION_EU_X)
    case 0x13E + 1:
#endif
        if (func_80265650_de(&D_80102B7E, 0) == 0) {
            D_800E5780->unk10 = 7;
        } else {
            D_800E5780->unk10 = 0x1E;
        }
        break;
#if defined(VERSION_DE)
    case 0x138:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x13A:
#elif defined(VERSION_EU_X)
    case 0x13E:
#endif
        D_80142358 = D_800FEB0F;
        D_800E5780->unk10 = 0xA;
        break;
    }
    func_8041A430_de(D_800E5780->unk0, 2);
    return 0;
}
