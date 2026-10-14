#include "span_16E000/code_8042BD40.h"
#include "types.h"
/* Draws player p's badge on the screen D_800E53C0: looks up the group item the third argument
   names in the screen window, picks its child 0x26C, 0x26B or 0x26A for kinds 1 to 3 and 0x26D
   otherwise, shows it with alpha 0x96, and sets its frame at 0x2C from the rank byte at 0x92 of
   the player's 150-byte record in D_80146398, the cartridge's jump table jtbl_800E1B48 sending
   ranks 0 to 4 to frame 0x63, 0x62, 0x61 or 0x5F or to hiding it again with frame 0x60, which any
   higher rank also gets. */
extern struct func_8042CE54_S1 *D_800E53C0;
extern u8 D_80146398[];
extern void *func_8040EC30_de(void *, s32);
extern void func_8040E8D8_de(struct Item_func_8042D304_de *, s32);
void func_8042D304_de(s32 player, s32 kind, unsigned short group) {
    struct Item_func_8042D304_de *item;
    void *parent;
    u8 *record;
    u32 rank;
    s32 id;
    s32 frame;
    record = &D_80146398[player * 150];
    parent = func_8040EC30_de(D_800E53C0->unkE0, group);
    switch (kind) {
    case 0:
    default:
#if defined(VERSION_DE)
        id = 0x268;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x26D;
#elif defined(VERSION_EU_X)
        id = 0x271;
#endif
        break;
    case 1:
#if defined(VERSION_DE)
        id = 0x267;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x26C;
#elif defined(VERSION_EU_X)
        id = 0x270;
#endif
        break;
    case 2:
#if defined(VERSION_DE)
        id = 0x266;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x26B;
#elif defined(VERSION_EU_X)
        id = 0x26F;
#endif
        break;
    case 3:
#if defined(VERSION_DE)
        id = 0x265;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x26A;
#elif defined(VERSION_EU_X)
        id = 0x26E;
#endif
        break;
    }
    item = func_8040EC30_de(parent, id);
    func_8040E8D8_de(item, 1);
    item->alpha = 0x96;
    rank = record[0x92];
    switch (rank) {
    case 0:
        frame = 0x63;
        break;
    case 1:
        frame = 0x62;
        break;
    case 2:
        frame = 0x61;
        break;
    case 3:
        frame = 0x5F;
        break;
    case 4:
        frame = 0x60;
        break;
    default:
        func_8040E8D8_de(item, 0);
        frame = 0x60;
        break;
    }
    item->frame = frame;
}
