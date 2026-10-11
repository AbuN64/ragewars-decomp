/* Builds the shared 0x20-byte join-screen block at 0x800E39C0 for one course-tree handle: it
 * allocates the block, remembers the handle and what func_8041B610_de says about it, resets the
 * four option windows (id 0x389) that hang off the handle, colours the option window 0x38B with
 * alpha 0x8C and gives that window back when func_802999A0_de reports 22, then keeps the windows
 * 0x38C (twice), 0x395 and 0x396 as the three option rows and the value func_8041EB50_de returns
 * as the row step. Every row is advanced by func_8041E408_de and hidden through func_8040E8D8_de;
 * after func_802A2360_de the row named by the selection field is looked up again and shown. */
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_8041DF04.h"
#include "types.h"

/* Same block the neighbouring menu units keep as Menu_func_8041EE08_de and Screen_func_8041ECB4_de;
 * here the three row slots hold window pointers and the selection field is read, so the block gets
 * a view of its own with those members named. func_8025305C_de hands out exactly 0x20 bytes. */
struct Screen_func_8041DFC0_us_rev1 {
    void *handle;        /* +0x00 the course-tree handle this screen was built for */
    s32 mode;            /* +0x04 what func_8041B610_de reports for that handle */
    void *rows[3];       /* +0x08 the three option rows, addressed as block + (row << 2) + 8 */
    s32 selection;       /* +0x14 the row a join request edits */
    s32 timer;           /* +0x18 */
    s32 step;            /* +0x1C */
};

extern struct Screen_func_8041DFC0_us_rev1 *D_800E39C0;

/* The window helpers take their first argument as a word, while this unit and the window lookups
 * carry the handle as a pointer; the cast carries that handle through unchanged. */
s32 func_8041DFC0_us_rev1(void *arg0) {
    func_8041F2A0_Item *item;
    s32 row;

    D_800E39C0 = (struct Screen_func_8041DFC0_us_rev1 *) func_8025305C_de(0x20);
    D_800E39C0->handle = arg0;
    D_800E39C0->mode = func_8041B610_de((s32) arg0, 4);
    func_8041B6E8_de((s32) arg0, 0, 0x389);
    func_8041B6E8_de((s32) arg0, 1, 0x389);
    func_8041B6E8_de((s32) arg0, 2, 0x389);
    func_8041B6E8_de((s32) arg0, 3, 0x389);

    item = func_8040EC30_de(arg0, 0x38B);
    item->alpha = 0x8C;
    if (func_802999A0_de(0) != 22) {
        func_8040E8D8_de(arg0, 0);
    }

    D_800E39C0->timer = 0;
    item = func_8040EC30_de(arg0, 0x38C);
    item->x = 0;
    item->y = 0;
    item = func_8040EC30_de(arg0, 0x38C);
    D_800E39C0->rows[0] = item;
    item = func_8040EC30_de(arg0, 0x395);
    D_800E39C0->rows[1] = item;
    item = func_8040EC30_de(arg0, 0x396);
    D_800E39C0->rows[2] = item;
    D_800E39C0->step = func_8041EB50_de();

    for (row = 0; row < 3; row++) {
        func_8041E408_de(row);
        item = func_8040EC30_de(D_800E39C0->rows[row], 0x392);
        func_8040E8D8_de(item, 0);
    }

    func_802A2360_de();

    item = func_8040EC30_de(D_800E39C0->rows[D_800E39C0->selection], 0x392);
    func_8040E8D8_de(item, 1);
    return 0;
}
