#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_166000/code_80426310.h"
#include "types.h"




/* Handles the menu message func_80299A08_de reports after func_8029973C_de. 0x1D9 sends code 3 to
   func_8042E988_de unless func_802999A0_de(0) reports 0x16; then it stops the match objects at D_80145088
   and 0x48 bytes before it, releases D_8011FE88, restarts func_8025476C_de when func_8025477C_de reports
   it idle, sets the word at 0x17F0 of the objects to 8 and sends 20, 10, 15 or 10 by the byte at
   0x124D through jtbl_800E1A40, or 3 for any other value. 0x1DA sends 11 when func_802999A0_de(0)
   reports 11 and -1 otherwise. Either then calls func_802998A8_de. Returns zero. */
extern char D_80145088[];

extern void func_8029973C_de(void);
extern s32 func_80299A08_de(void);
extern s32 func_802999A0_de(s32);
extern void func_8044A370_de(void *, s32);
extern void func_804499B0_de(void *, s32, s32);
extern void func_80286AA8_de(void *, s32, s32);
extern s32 func_8025477C_de(void);
extern void func_8025476C_de(s32);
extern void func_8042E988_de(s32);
extern void func_802998A8_de(void);


enum { MENU_804291A8_473 = 469, MENU_804291A8_474 = 470 };

s32 func_80428FC8_de(void) {
    char *objects;
    s32 code;
    u32 level;

    func_8029973C_de();
    switch (func_80299A08_de()) {
    case MENU_804291A8_473:
        if (func_802999A0_de(0) != 0x16) {
            goto send_3;
        }
        objects = D_80145088;
        func_8044A370_de(objects, 0);
        func_804499B0_de(objects - 0x48, 0, 0);
        func_80286AA8_de(&D_8011FE88, 0, 0);
        if (func_8025477C_de() == 0) {
            func_8025476C_de(1);
        }
        level = (u8)objects[0x124D];
        ((MatchMenuObjects *)(objects))->transition = 8;
        if (level >= 5) {
            goto send_3;
        }
        switch (level) {
        case 0: goto send_20;
        case 1: goto send_10;
        case 2: goto send_15;
        case 3: goto send_10_again;
        case 4: goto send_10_again;
        }
    send_20:
        code = 20;
        goto send;
    send_10:
        code = 10;
        goto send;
    send_15:
        code = 15;
        goto send;
    send_10_again:
        code = 10;
        goto send_typed;
    send_3:
        code = 3;
        goto send;
    case MENU_804291A8_474:
        if (func_802999A0_de(0) == 11) {
            code = 11;
        } else {
            code = -1;
        }
    send_typed:
        func_8042E988_de(code);
        func_802998A8_de();
        return 0;
    send:
        func_8042E988_de(code);
        func_802998A8_de();
        return 0;
    }
    return 0;
}
