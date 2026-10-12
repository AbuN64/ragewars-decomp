#include "common/types_1dc8418c21db.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_8041BEA8.h"
#include "types.h"
/* Updates every node of the 50-entry id table: nodes whose unlock bit the current player has set are enabled through func_8040E8D8_de and given the style byte, the rest are disabled. */









/* The hub names the block's root word and the Item* helpers func_8040EC30_de/func_8040E8D8_de;
   this view's player word sits at +0x10C, beyond what the hub names here, so that use casts.
   The (u16) on each id reproduces the byte-exact halfword load the original lookup used.
   EC30 hands back the Item view and the style byte is Item::alpha's slot 0x10, so the node cast
   moved to the store. */
extern TextEntry D_800DF544[];
extern PlayerRecord D_800FEB4A[];
extern s32 func_80265650_de(PlayerRecord *bits, s32 bit);

void func_8041DA5C_de(s32 style) {
    s32 i;
    func_8041F2A0_Item *node;

    for (i = 0; i < 50; i++) {
        node = func_8040EC30_de(D_800E3590->root, (u16) D_800DF544[i].id);
        if (func_80265650_de(&D_800FEB4A[((Menu_func_8041DA5C_de *) D_800E3590)->player], i) == 1) {
            func_8040E8D8_de(node, 1);
            ((Node_func_8041DA5C_de *) node)->style = style;
        } else {
            func_8040E8D8_de(node, 0);
        }
    }
}
