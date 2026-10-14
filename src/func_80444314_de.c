#include "span_16E000/code_80444030.h"
#include "types.h"



extern u32 D_801462D0;
extern s32 D_80146878;
extern u8 D_800D35A8[];
extern u8 D_800D35AC[];
extern u8 D_800D35B0[];

/* Sets bit 24 of the item's flags when D_80146878 is 8 (clears it otherwise) and points the item at the text table for the configuration D_801462D0 (8, 0x10 or 0x20); returns 0. */
s32 func_80444314_de(MenuItemRecAt14 *item) {
    if (D_80146878 == 8) {
        item->flags |= 0x01000000;
    } else {
        item->flags &= ~0x01000000;
    }
    switch (D_801462D0) {
    case 8:
        item->table = D_800D35A8;
        break;
    case 0x10:
        item->table = D_800D35AC;
        break;
    case 0x20:
        item->table = D_800D35B0;
        break;
    }
    return 0;
}
