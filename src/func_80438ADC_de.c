#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804379C8.h"
#include "types.h"

/* Handles event 1 on the screen D_800E5830: unless func_8043C308_de reports its menu in state 1 it
   calls func_80438828_de; otherwise it advances the menu with func_8043C080_de and func_8043C2A4_de and,
   once func_8043C308_de reports 2, acts on the choice at 0x1C: choice 0 calls func_8029973C_de, clears
   D_80146918 and D_801468F4 and leaves through func_80298368_de for screen 0xA unless D_80146948 is 1
   and D_8015402C is at least 35, in which case it leaves for screen 7 when option D_801462D5 is 1
   and screen 3 otherwise; choice 1 calls func_8040C428_de(0), shows the window argument, stops the
   objects at D_80145088 and 0x48 before it, releases D_8011FE88 through func_80286AA8_de and sets the
   word at 0x17F0 of D_80145088 to 8. Returns zero. Adapted from func_8042D4FC_de with the option cases written in the order that reproduces the
   cartridge's decision tree. */



extern struct MenuRules *D_800E5830;
extern s32 D_80146948;
extern s32 D_8015402C;
extern u8 D_801462D5;
extern s32 D_80146918;
extern s32 D_801468F4;
extern char D_80145088[];

extern s32 func_8043C308_de(struct MenuRules *);
extern void func_8043C080_de(struct MenuRules *);
extern void func_8043C2A4_de(struct MenuRules *);
extern void func_80438828_de();
extern void func_8040C428_de(s32);
extern void func_8040E8D8_de(void *, s32);
extern void func_8044A370_de(void *, s32);
extern void func_804499B0_de(void *, s32, s32);
extern void func_80286AA8_de(void *, s32, s32);
extern void func_8029973C_de();
extern void func_80298368_de(s32);




s32 func_80438ADC_de(void *window, void *arg1, s32 event) {
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
            object = D_80145088;
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
