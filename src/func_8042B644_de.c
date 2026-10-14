#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80429C10.h"
#include "types.h"

/* Moves the selection of the screen D_800E4F60 on event 1: calls func_8029973C_de and steps the
   selection at 0x438 forward while it stays below the count func_8042B154_de gives for the category's
   list; in category 0 the first page (below 11) steps forward unless it would reach the count of
   list 0 or 11, and the second page steps back unless it would reach 10. When it moved it plays
   sound 0xE7D, calls func_8042B2E4_de, clears the words at 0x45C and 0x464, dims the item at 0x43C to
   alpha 0x41, refreshes through func_8042A990_de, hides the items at 0x440 and 0x448 and shows the
   one at 0x444. Returns zero. */





extern struct Screen_func_8042B644_de *D_800E4F60;
extern void func_8029973C_de();
extern void func_8025DF34_de(s32);

extern void *func_8042B294_de(s32);
extern s32 func_8042B154_de(void *);

extern void func_8040E8D8_de(struct Resource_func_80419E54_de *, s32);

s32 func_8042B644_de(void *arg0, void *arg1, void *arg2, s32 event) {
    struct Screen_func_8042B644_de *screen;
    s32 changed;
    s32 count;
    s32 next;
    s32 limit;

    func_8029973C_de();
    if (event != 1) {
        return 0;
    }
    changed = 0;
    count = func_8042B154_de(func_8042B294_de(D_800E4F60->category));
    screen = D_800E4F60;
    if (screen->category != 0) {
        next = screen->selection + 1;
        if (next < count) {
            changed = 1;
            screen->selection = next;
        }
    } else {
        if (screen->selection >= 11) {
            next = screen->selection - 1;
            limit = 10;
        } else {
            limit = func_8042B154_de(func_8042B294_de(0));
            screen = D_800E4F60;
            next = screen->selection + 1;
            if (next == limit) {
                goto moved;
            }
            limit = 11;
        }
        if (next != limit) {
            changed = 1;
            screen->selection = next;
        }
    }
moved:
    if (changed != 1) {
        return 0;
    }
    func_8025DF34_de(0xE7D);
    func_8042B2E4_de();
    D_800E4F60->word45C = 0;
    D_800E4F60->word464 = 0;
    D_800E4F60->item->value = 0x41;
    func_8042A990_de();
    func_8040E8D8_de(D_800E4F60->left, 0);
    func_8040E8D8_de(D_800E4F60->right, 1);
    func_8040E8D8_de(D_800E4F60->marker, 0);
    return 0;
}
