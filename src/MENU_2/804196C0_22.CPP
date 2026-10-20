#include "COMMON/ANIMATION.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "COMMON/STATEPAIR.H"
#include "MENU_2/SCROLL.H"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "MENU_2/804196C0_22.H"
#include "RENDER_2/8025DE50_5.H"
#include "SCENE/802508E0_13.H"

/* Sets the word at 0x54 of arg0 to 2, calls func_8025DF34_de with 0xE74, and sets the byte at 0x10 of every child in the list at 0x8 whose halfword at 0xE is not 8 to 100, returning zero. Adapted from func_802A1E5C_de with the two stores to 0x5C and 0x48 replaced by a single store of 2 to 0x54. */


/* Marks a menu's state word at offset 0x54 as 2 when func_8029DB58_de's value for the fifth argument
   is below func_80299B4C_de's; then, when the fourth argument is one, stores the fourth argument as the state and scrolls down through func_8041A910_de. Returns zero. */



extern s32 func_80299B4C_de();

extern void func_8041A910_de(struct func_8022FD9C_Record *);

extern void func_8041A8E8_de(struct func_8022FD9C_Record *);

/* Scrolls a menu one step in the direction its state word at offset 0x54 records: up through
   func_8041A8E8_de for state 0, down through func_8041A910_de for state 1, and returns zero. */



extern void func_8041A8E8_de(struct func_8022FD9C_Record *menu);

extern void func_8041A910_de(struct func_8022FD9C_Record *menu);

/* Calls func_802547E4_de with the arguments it was given and returns zero. */

s32 func_8041A9B0_de(struct CommandListMenu *arg0) {
    struct LinkedCommandEntry *p;

    arg0->state = 2;
    func_8025DF34_de(0xE74);
    p = arg0->entries;
    if (p != 0) {
        do {
            if (p->kind != 8) {
                p->command = 0x64;
            }
            p = p->next;
        } while (p != 0);
    }
    return 0;
}

s32 func_8041AA10_de(struct func_8022FD9C_Record *menu, void *second, void *third, s32 active, s32 fifth) {
    if (func_8029DB58_de(fifth) < func_80299B4C_de()) {
        menu->unk54 = 2;
    }
    if (active == 1) {
        menu->unk54 = active;
        func_8041A910_de(menu);
        return 0;
    }
    return 0;
}

s32 func_8041AA80_de(struct func_8022FD9C_Record *menu, void *second, void *third, s32 active, s32 fifth) {
    if (func_8029DB58_de(fifth) < func_80299B4C_de()) {
        menu->unk54 = 2;
    }
    if (active == 1) {
        menu->unk54 = 0;
        func_8041A8E8_de(menu);
        return 0;
    }
    return 0;
}

/* Sets the word at offset 0x54 of an object to 2 when the event's upper halfword is 3 and its
   value is 6 or 7, and returns zero. */


s32 func_8041AAF0_de(struct func_8022FD9C_Record *object, void *unused, u32 event, s32 value) {
    if ((event >> 16) == 3 && value < 8 && value >= 6) {
        object->unk54 = 2;
    }
    return 0;
}

s32 func_8041AB1C_de(struct func_8022FD9C_Record *menu)
{
    struct func_8022FD9C_Record *target = menu;

    switch (menu->unk54) {
    case 0:
        func_8041A8E8_de(menu);
        break;
    case 1:
        func_8041A910_de(target);
        break;
    case 2:
        break;
    }
    return 0;
}

s32 func_8041AB70_de(void *arg0) {
    func_802547E4_de(arg0);
    return 0;
}

void func_8041AB90_de(void) {
    func_802982C4_de(0xB64, D_0041AD7C, D_0041AE0C, 3);
}
