#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8042F988.h"
/* Relabels the four slot rows of the block D_800E54A4 points to: for each row item (0x28B, 0x28D,
   0x28F, then 0x291) of the block's window it calls func_8040E950_de(0) and points the text at 0x38
   of the item's label at 0x8 at player p's chosen slot (the index at 0xAEC of p's 2920-byte record
   at 0x58, slots of 400 bytes from 0x18) when p is not -1 and func_8041B7FC_de reports
   this row as p's focus in the list at 0x4, otherwise at the row's 400-byte record in D_80102B00
   when its owner byte 0xD is not negative, or at nothing. */
/* The first row item's id: eu-x numbers its items 9 higher and de 1 higher, as each cartridge's
   own bytes show; us, us-rev1 and eu share 0x28B. */
extern struct Block_func_80433BCC_de *D_800E54A4;
extern char D_80102B00[];
extern s8 D_80102B0D[];
extern struct Item_func_80433BCC_de *func_8040EC30_de(void *, s32);
extern void func_8040E950_de(struct Item_func_80433BCC_de *, s32);
extern struct Item_func_80433BCC_de *func_8041B7FC_de(void *, s32);
void func_80433BCC_de(s32 player) {
    struct Item_func_80433BCC_de *item;
    struct func_8028469C_S2 *label;
    s32 id;
    s32 i;
    for (i = 0; i < 4; i++) {
        switch (i) {
        case 0:
#if defined(VERSION_DE)
            id = 0x28C;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
            id = 0x28B;
#elif defined(VERSION_EU_X)
            id = 0x294;
#endif
            break;
        case 1:
#if defined(VERSION_DE)
            id = 0x28C + 2;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
            id = 0x28B + 2;
#elif defined(VERSION_EU_X)
            id = 0x294 + 2;
#endif
            break;
        case 2:
#if defined(VERSION_DE)
            id = 0x28C + 4;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
            id = 0x28B + 4;
#elif defined(VERSION_EU_X)
            id = 0x294 + 4;
#endif
            break;
        default:
#if defined(VERSION_DE)
            id = 0x28C + 6;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
            id = 0x28B + 6;
#elif defined(VERSION_EU_X)
            id = 0x294 + 6;
#endif
            break;
        }
        item = func_8040EC30_de(D_800E54A4->window, id);
        func_8040E950_de(item, 0);
        label = item->label;
        if (player != -1 && item == func_8041B7FC_de(D_800E54A4->list, player)) {
            label->unk38 = D_800E54A4->players[player].slots[D_800E54A4->players[player].chosen];
        } else if (D_80102B0D[i * 400] >= 0) {
            label->unk38 = &D_80102B00[i * 400];
        } else {
            label->unk38 = 0;
        }
    }
}
