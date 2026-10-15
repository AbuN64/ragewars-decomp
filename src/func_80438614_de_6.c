#include "span_16E000/code_804379C8.h"
#include "common/types_1dc8418c21db.h"
#include "shared/menu_match_globals.h"
#include "shared/world.h"
#include "types.h"
#include "common/unused.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "span_16E000/code_804264F0.h"

/* Resets three words of the object D_800E5830 points to: the words at 0x9C and 0xB0 to -1 and
   the word at 0x188 to zero. */




/* Releases the object D_800E5830 holds through func_802547E4_de, clears D_800E5830 and returns zero. */


extern void func_802547E4_de(void *);

/* Handles event 1 on the screen D_800E5830: unless func_8043C308_de reports its menu in state 1 it
   calls func_80438828_de; otherwise it advances the menu with func_8043C080_de and func_8043C2A4_de and,
   once func_8043C308_de reports 2, acts on the choice at 0x1C: choice 0 calls func_8029973C_de, clears
   D_80146918 and D_801468F4 and leaves through func_80298368_de for screen 0xA unless D_80146948 is 1
   and D_8015402C is at least 35, in which case it leaves for screen 7 when option D_801462D5 is 1
   and screen 3 otherwise; choice 1 calls func_8040C428_de(0), shows the window argument, stops the
   objects at D_80145088 and 0x48 before it, releases D_8011FE88 through func_80286AA8_de and sets the
   word at 0x17F0 of D_80145088 to 8. Returns zero. Adapted from func_8042D4FC_de with the option cases written in the order that reproduces the
   cartridge's decision tree. */










extern s32 func_8043C308_de(struct MenuRules *);

extern void func_8043C080_de(struct MenuRules *);

extern void func_8043C2A4_de(struct MenuRules *);



extern void func_8040E8D8_de(void *, s32);

extern void func_8044A370_de(void *, s32);

extern void func_804499B0_de(void *, s32, s32);

extern void func_80286AA8_de(void *, s32, s32);

extern void func_8029973C_de();

extern void func_80298368_de(s32);

/* Runs the screen D_800E5830 each frame until stage 1 of D_800E28E0: on its first frame it marks
   the word at 0x90, passes 0x272 to func_802991D4_de, or 0x273 when func_8040EBD0_de
   reports zero for item 0x273 of the window argument, also 0x272 when D_80146948 is clear, and calls func_802A2360_de; then, once the
   reply pair ending at D_80154024 is marked, it clears the mark and either hides the item at 0x24,
   clears the word at 0x1C0, calls func_8029973C_de and leaves through func_80298368_de with the reply,
   or for a reply of -1 shows the item again and sets 0x1C0 to one. Returns zero. Written from the
   assembly; the conditional tests the zero case first. */


extern void *func_8040EC30_de(void *, s32);

extern s32 func_8040EBD0_de(void *);

extern void func_802991D4_de(s32);

extern void func_802A2360_de();

void func_80438A88_de(void) {
    extern struct State_func_80438A88_de *D_800E5830;
    struct State_func_80438A88_de *state = D_800E5830;

    state->first = -1;
    state->second = -1;
    state->third = 0;
}

s32 func_80438AA4_de(void) {
    extern void *D_800E5830;
    func_802547E4_de(D_800E5830);
    D_800E5830 = 0;
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80438AD4_de(void) {
    return 0;
}

s32 func_80438ADC_de(void *window, void *arg1, s32 event) {
    extern struct MenuRules *D_800E5830;
    s32 state;
    char *object;
    s32 next;

    if (event != 1) {
        return 0;
    }
    state = func_8043C308_de(D_800E5830);
    if (state == event) {
        func_8043C080_de(D_800E5830);
        func_8043C2A4_de(D_800E5830);
        if (func_8043C308_de(D_800E5830) != 2) {
            return 0;
        }
        if (D_800E5830->locked != 0) {
            if (D_800E5830->locked != state) {
                return 0;
            }
            func_8040C428_de(0);
            func_8040E8D8_de(window, 1);
            object = &D_80145088;
            func_8044A370_de(object, 0);
            func_804499B0_de(object - 0x48, 0, 0);
            func_80286AA8_de(&D_8011FE88, 0, 0);
            ((MatchMenuObjects *)(object))->transition = 8;
        } else {
            func_8029973C_de();
            D_80146918 = 0;
            D_801468F4 = 0;
            if (D_80146948 == state && D_8015402C >= 35) {
                switch (D_801462D5) {
                case 4:
                    next = 3;
                    break;
                default:
                    next = 3;
                    break;
                case 1:
                    next = 7;
                    break;
                case 3:
                    next = 3;
                    break;
                }
            } else {
                next = 0xA;
            }
            func_80298368_de(next);
            return 0;
        }
    } else {
        func_80438828_de();
    }
    return 0;
}

s32 func_80438C84_de(void *window) {
    extern struct State_func_80438C84_de *D_800E5830;
    s32 *pair;
    s32 marked;
    if (D_800E28E0 > 0) {
        return 0;
    }
    if (D_800E5830->started == 0) {
        D_800E5830->started = 1;
#if defined(VERSION_DE)
        func_802991D4_de(func_8040EBD0_de(func_8040EC30_de(window, 0x26F)) == 0 ? 0x26F : 0x26E);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        func_802991D4_de(func_8040EBD0_de(func_8040EC30_de(window, 0x273)) == 0 ? 0x273 : 0x272);
#elif defined(VERSION_EU_X)
        func_802991D4_de(func_8040EBD0_de(func_8040EC30_de(window, 0x278)) == 0 ? 0x278 : 0x277);
#endif
        if (D_80146948 == 0) {
#if defined(VERSION_DE)
            func_802991D4_de(0x26E);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
            func_802991D4_de(0x272);
#elif defined(VERSION_EU_X)
            func_802991D4_de(0x277);
#endif
        }
        func_802A2360_de();
    }
    pair = &D_80154024;
    marked = pair[0];
    if (marked == 1) {
        pair[0] = 0;
        if (pair[-1] != -1) {
            func_8040E8D8_de(D_800E5830->item, 0);
            D_800E5830->busy = 0;
            func_8029973C_de();
            func_80298368_de(pair[-1]);
            return 0;
        }
        func_8040E8D8_de(D_800E5830->item, 1);
        D_800E5830->busy = marked;
    }
    return 0;
}
