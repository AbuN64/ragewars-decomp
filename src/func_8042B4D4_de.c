#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80429C10.h"
#include "types.h"

/* Moves the selection of the screen D_800E4F60 back on event 1: calls func_8029973C_de and steps the
   selection at 0x438 back while it is above 0; in category 0 the second page (11 and up) instead
   steps forward while below the count func_8042B154_de gives for list 0. When it moved it plays sound
   0xE7D, calls func_8042B2E4_de, clears the words at 0x45C and 0x464, dims the item at 0x43C to alpha
   0x41 and refreshes through func_8042A990_de, and when the selection is then 0 it shows the items at
   0x440 and 0x448, moves the marker at 0x448 to x 0x7C plus 34 per category, hides the item at
   0x444 and shows model 0xEA6 plus the category in the view at 0x308. Returns zero. Adapted from
   func_8042B644_de with the step direction, page handling and final item updates changed. */





extern struct Screen_func_8042B4D4_de *D_800E4F60;
extern void func_8029973C_de();
extern void func_8025DF34_de(s32);

extern void *func_8042B294_de(s32);
extern s32 func_8042B154_de(void *);

extern void func_8040E8D8_de(struct Item_func_8042B4D4_de *, s32);
extern void func_80439C80_de(void *, s32);

s32 func_8042B4D4_de(void *arg0, void *arg1, void *arg2, s32 event) {
    struct Screen_func_8042B4D4_de *screen;
    s32 changed;
    s32 next;

    func_8029973C_de();
    if (event != 1) {
        return 0;
    }
    screen = D_800E4F60;
    changed = 0;
    if (screen->category != 0) {
        if (screen->selection > 0) {
            changed = 1;
            screen->selection = screen->selection - 1;
        }
    } else if (screen->selection >= 11) {
        next = func_8042B154_de(func_8042B294_de(0));
        screen = D_800E4F60;
        if (screen->selection + 1 < next) {
            changed = 1;
            screen->selection = screen->selection + 1;
        }
    } else if (screen->selection > 0) {
        screen->selection = screen->selection - 1;
        changed = 1;
    }
    if (changed != 1) {
        return 0;
    }
    func_8025DF34_de(0xE7D);
    func_8042B2E4_de();
    D_800E4F60->word45C = 0;
    D_800E4F60->word464 = 0;
    D_800E4F60->item->alpha = 0x41;
    func_8042A990_de();
    if (D_800E4F60->selection != 0) {
        return 0;
    }
    func_8040E8D8_de(D_800E4F60->left, 1);
    func_8040E8D8_de(D_800E4F60->marker, 1);
    D_800E4F60->marker->x = D_800E4F60->category * 34 + 0x7C;
    func_8040E8D8_de(D_800E4F60->right, 0);
    func_80439C80_de(D_800E4F60->view, D_800E4F60->category + 0xEA6);
    return 0;
}
