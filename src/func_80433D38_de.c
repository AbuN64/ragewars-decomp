#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8042F988.h"
#include "types.h"
/* Updates the four player control rows, their visibility, and the selected player label. */
extern struct Shared_Block *D_800E54A4;
extern s32 func_80264614_de(s32);
extern struct Shared_Item *func_8040EC30_de(void *, u16);
extern void func_8040E950_de(struct Shared_Item *, s32);
extern struct Shared_Item *func_8041B7FC_de(void *, s32);
void func_80433D38_de(s32 player) {
    struct Shared_Item *item;
    struct func_8028469C_S2 *label;
    u16 id;
    s32 i;
    i = 0;
    do {
        if (i == 1) goto row_one;
        if (i < 2) {
            if (i == 0) goto row_zero;
#if defined(VERSION_DE)
            id = 0x296 + 6;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
            id = 0x299 + 6;
#elif defined(VERSION_EU_X)
            id = 0x29F + 6;
#endif
            goto row_done;
        }
        if (i == 2) goto row_two;
#if defined(VERSION_DE)
        id = 0x296 + 6;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x299 + 6;
#elif defined(VERSION_EU_X)
        id = 0x29F + 6;
#endif
        goto row_done;
    row_zero:
#if defined(VERSION_DE)
        id = 0x296;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x299;
#elif defined(VERSION_EU_X)
        id = 0x29F;
#endif
        goto row_done;
    row_one:
#if defined(VERSION_DE)
        id = 0x296 + 2;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x299 + 2;
#elif defined(VERSION_EU_X)
        id = 0x29F + 2;
#endif
        goto row_done;
    row_two:
#if defined(VERSION_DE)
        id = 0x296 + 4;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x299 + 4;
#elif defined(VERSION_EU_X)
        id = 0x29F + 4;
#endif
    row_done:
        item = func_8040EC30_de(D_800E54A4->window, id);
        if (func_80264614_de(i) == 1) {
            func_8040E950_de(item, 0);
        } else {
            func_8040E950_de(item, 1);
        }
        label = item->label;
        if (player != -1 && item == func_8041B7FC_de(D_800E54A4->list, player)) {
            label->unk38 = D_800E54A4->players[player].slots[D_800E54A4->players[player].chosen];
        } else {
            label->unk38 = 0;
        }
        i += 1;
    } while (i < 4);
}
