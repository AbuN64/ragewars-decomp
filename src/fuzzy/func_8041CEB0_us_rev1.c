/* Builds the player-selection menu block at 0x800E3590 for one menu tree: it allocates the block
 * with a 528-byte window request, remembers the tree and the pool func_8041B610_de returns for it,
 * arms the tree's four option groups with id 513, hands the pool back to func_8041B968_de, and
 * keeps the windows 492, 491, 486, 563, 510, 512, 511 and their lookup results in the block. The
 * window geometry is nudged by whole groups of four pixels so each window snaps to a 4-pixel grid;
 * the menu item window 488 and the two label windows 496/497 get fixed alpha bytes 110/120, window
 * 493 gets 110, and window 511 is cleared before the block is handed to func_8041DB30_de. */
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_8041BEA8.h"
#include "types.h"

/* The block six neighbouring units keep as Menu_func_8041D960_de, Menu_func_8041DA5C_de and
 * Menu_func_8041D134_de views; here every slot this unit writes is named, with the focus, item and
 * player slots matching the names those views already publish. */
struct Menu_func_8041CEB0_us_rev1 {
    void *root;                      /* +0x000 the menu tree this unit was called for */
    s32 list;                        /* +0x004 the pool func_8041B610_de(root, 4) returns */
    char pad8[0xC8 - 0x08];
    func_8041F2A0_Item *item492;    /* +0x0C8 window id 492 */
    s32 round492;                    /* +0x0CC item492's y extent in groups of four pixels */
    func_8041F2A0_Item *item491;    /* +0x0D0 window id 491 */
    s32 round491;                    /* +0x0D4 item491's y extent in groups of four pixels */
    s32 unk216;                      /* +0x0D8 set to 1 */
    s32 unk220;                      /* +0x0DC set to 4 */
    s32 lookup486;                   /* +0x0E0 func_80419E54_de(486, 255) */
    func_8041F2A0_Item *item486;    /* +0x0E4 window id 486 */
    func_8041F2A0_Item *item563;    /* +0x0E8 window id 563 */
    s32 focus;                       /* +0x0EC cleared; neighbours read it as a focus node */
    func_8041F2A0_Item *item510;    /* +0x0F0 window id 510 */
    func_8041F2A0_Item *item512;    /* +0x0F4 window id 512 */
    s32 unk248;                      /* +0x0F8 set to 27 */
    s32 style;                       /* +0x0FC cleared and read back by func_8041DA5C_de */
    func_8041F2A0_Item *item511;    /* +0x100 window id 511 */
    s32 unk260;                      /* +0x104 set to 25 */
    s32 player;                      /* +0x108 cleared; neighbours read it as a player index */
    s32 unk268;                      /* +0x10C set to -1, then func_8041DB30_de writes through it */
};

extern struct Menu_func_8041CEB0_us_rev1 *D_800E3590;

/* No header declares these three; the spellings match how the landed units that own them define
 * them (func_8041DA5C_de takes the style word this block keeps at +0x0FC). */
extern void func_8041B968_de(s32 pool, s32 arg1);
extern s32 func_8041DB30_de(s32 *slot);
extern void func_8041DA5C_de(s32 style);

/* The pool and style helpers take a word, while this unit and the window lookups carry the menu
 * tree as a pointer; the cast carries that pointer through unchanged. */
s32 func_8041CEB0_us_rev1(void *arg0) {
    func_8041F2A0_Item *item;
    s32 shift;

    D_800E3590 = (struct Menu_func_8041CEB0_us_rev1 *) func_8025305C_de(528);
    D_800E3590->root = arg0;
    D_800E3590->list = func_8041B610_de((s32) arg0, 4);
    func_8041B6E8_de((s32) arg0, 0, 513);
    func_8041B6E8_de((s32) arg0, 1, 513);
    func_8041B6E8_de((s32) arg0, 2, 513);
    func_8041B6E8_de((s32) arg0, 3, 513);
    func_8041B968_de(D_800E3590->list, 1);

    D_800E3590->unk216 = 1;
    D_800E3590->unk220 = 4;
    D_800E3590->item492 = func_8040EC30_de(arg0, 492);
    D_800E3590->item492->x = D_800E3590->item492->x - D_800E3590->item492->w;
    shift = D_800E3590->item492->w;
    if (shift < 0) {
        shift += 3;
    }
    D_800E3590->round492 = shift >> 2;
    D_800E3590->item492->x = D_800E3590->item492->x + (D_800E3590->item492->w - ((shift >> 2) << 2));

    D_800E3590->item491 = func_8040EC30_de(arg0, 491);
    D_800E3590->item491->x = D_800E3590->item491->x + D_800E3590->item491->w;
    shift = D_800E3590->item491->w;
    if (shift < 0) {
        shift += 3;
    }
    D_800E3590->round491 = shift >> 2;
    D_800E3590->item491->x = D_800E3590->item491->x - (D_800E3590->item491->w - ((shift >> 2) << 2));

    func_8040EC30_de(arg0, 488)->alpha = 110;
    D_800E3590->lookup486 = func_80419E54_de(486, 255);

    item = func_8040EC30_de(arg0, 486);
    D_800E3590->item486 = item;
    func_8040E8D8_de(item, 0);

    item = func_8040EC30_de(arg0, 563);
    D_800E3590->item563 = item;
    func_8040E8D8_de(item, 0);

    func_8040EC30_de(arg0, 496)->alpha = 110;
    func_8040EC30_de(arg0, 497)->alpha = 120;

    item = func_8040EC30_de(arg0, 512);
    D_800E3590->item512 = item;
    func_8040E8D8_de(item, 0);

    D_800E3590->style = 0;
    D_800E3590->unk248 = 27;
    item = func_8040EC30_de(arg0, 511);
    D_800E3590->item511 = item;
    func_8040E8D8_de(item, 0);

    D_800E3590->item511->alpha = 0;
    D_800E3590->unk260 = 25;
    item = func_8040EC30_de(arg0, 510);
    D_800E3590->item510 = item;

    D_800E3590->player = 0;
    D_800E3590->unk268 = -1;
    func_8041DB30_de(&D_800E3590->unk268);
    func_8041D6A8_de();
    func_8041DA5C_de(D_800E3590->style);
    func_8040EC30_de(arg0, 493)->alpha = 110;
    D_800E3590->focus = 0;
    return 0;
}
