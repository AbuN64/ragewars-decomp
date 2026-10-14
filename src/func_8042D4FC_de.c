#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8042BD40.h"
#include "types.h"

/* Handles event 1 on the screen D_800E53C0: unless func_8043C308_de reports its menu in state 1 it
   calls func_8042D28C_de; otherwise it advances the menu with func_8043C080_de and func_8043C2A4_de and,
   once func_8043C308_de reports 2, acts on the choice at 0x1C: choice 0 hides the window argument,
   calls func_8029973C_de, clears D_80146918 and D_801468F4 and leaves for screen 0xF when option
   D_801462D5 is set, otherwise through func_8042DEA0_de when func_8042AF28_de and func_8042ACD8_de both
   agree or for screen 0x14; choice 1 calls func_8040C428_de(0), shows the window, stops the objects
   at D_80145088 and 0x48 before it, releases D_8011FE88 through func_80286AA8_de and sets the word at
   0x17F0 of D_80145088 to 8. Returns zero. */



extern struct MenuRules *D_800E53C0;
extern u8 D_801462D5;
extern s32 D_80146918;
extern s32 D_801468F4;
extern char D_80145088[];

extern s32 func_8043C308_de(struct MenuRules *);
extern void func_8043C080_de(struct MenuRules *);
extern void func_8043C2A4_de(struct MenuRules *);
extern void func_8042D28C_de();
extern void func_8040C428_de(s32);
extern void func_8040E8D8_de(void *, s32);
extern void func_8044A370_de(void *, s32);
extern void func_804499B0_de(void *, s32, s32);
extern void func_80286AA8_de(void *, s32, s32);
extern void func_8029973C_de();
extern s32 func_8042AF28_de();
extern s32 func_8042ACD8_de();
extern void func_8042DEA0_de();
extern void func_80298368_de(s32);




s32 func_8042D4FC_de(void *window, void *arg1, s32 event) {
    s32 state;
    char *object;
    s32 next;

    if (event != 1) {
        return 0;
    }
    state = func_8043C308_de(D_800E53C0);
    if (state == event) {
        func_8043C080_de(D_800E53C0);
        func_8043C2A4_de(D_800E53C0);
        if (func_8043C308_de(D_800E53C0) != 2) {
            return 0;
        }
        if (D_800E53C0->locked != 0) {
            if (D_800E53C0->locked != state) {
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
            func_8040E8D8_de(window, 0);
            func_8029973C_de();
            if (D_801462D5 == 0) {
                D_80146918 = 0;
                D_801468F4 = 0;
                if (func_8042AF28_de() != 0 && func_8042ACD8_de() != 0) {
                    func_8042DEA0_de();
                    return 0;
                }
                next = 0x14;
            } else {
                D_80146918 = 0;
                D_801468F4 = 0;
                next = 0xF;
            }
            func_80298368_de(next);
            return 0;
        }
    } else {
        func_8042D28C_de();
    }
    return 0;
}
