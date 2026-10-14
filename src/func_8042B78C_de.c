#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80429C10.h"
#include "types.h"

/* Moves the screen D_800E4F60 to its previous category on event 1: calls func_8029973C_de and steps
   the category at 0x434 back unless it is 0; in category 0 a selection at 0x438 from 5 to 10 is
   mirrored to 21 minus it when that stays below the count func_8042B154_de gives for list 0. When
   anything changed it plays sound 0xE7D, calls func_8042B2E4_de, clears the words at 0x45C and 0x464,
   dims the item at 0x43C to alpha 0x41, clamps the selection below the count for the category's
   list, refreshes through func_8042A990_de and, when the selection is 0, shows model 0xEA6 plus the
   category in the view at 0x308 and moves the marker item at 0x448 to x 0x7C plus 34 per category.
   Returns zero. Adapted from func_8042B904_de with the step direction and the mirror test changed. */





extern struct Screen_func_8042B78C_de *D_800E4F60;
extern void func_8029973C_de();
extern void func_8025DF34_de(s32);

extern void *func_8042B294_de(s32);
extern s32 func_8042B154_de(void *);

extern void func_80439C80_de(void *, s32);
extern void func_8040E8D8_de(struct Item_func_8042B4D4_de *, s32);

s32 func_8042B78C_de(void *arg0, void *arg1, void *arg2, s32 event) {
    struct Screen_func_8042B78C_de *screen;
    s32 changed;
    s32 count;
    s32 mirror;

    func_8029973C_de();
    if (event != 1) {
        return 0;
    }
    screen = D_800E4F60;
    changed = 0;
    if (screen->category != 0) {
        changed = 1;
        screen->category = screen->category - 1;
    } else if ((u32)(screen->selection - 5) < 6) {
        mirror = 21 - screen->selection;
        if (mirror < func_8042B154_de(func_8042B294_de(0))) {
            changed = 1;
            D_800E4F60->selection = mirror;
        }
    }
    if (changed != 1) {
        return 0;
    }
    func_8025DF34_de(0xE7D);
    func_8042B2E4_de();
    D_800E4F60->word45C = 0;
    D_800E4F60->word464 = 0;
    D_800E4F60->item->alpha = 0x41;
    count = func_8042B154_de(func_8042B294_de(D_800E4F60->category));
    if (D_800E4F60->selection >= count) {
        D_800E4F60->selection = count - 1;
    }
    func_8042A990_de();
    if (D_800E4F60->selection == 0) {
        func_80439C80_de(D_800E4F60->view, D_800E4F60->category + 0xEA6);
        func_8040E8D8_de(D_800E4F60->marker, 1);
        D_800E4F60->marker->x = D_800E4F60->category * 34 + 0x7C;
    }
    return 0;
}
