#include "span_16E000/code_804264F0.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "decomp/argb_color.h"
#include "shared/func_8042854C_de_closed.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8022A274.h"
#include "span_1000/code_8023B9A0.h"
#include "span_1000/code_80243A80.h"
#include "span_1000/code_80246E34.h"
#include "span_1000/code_802508E0.h"
#include "span_1000/code_80256220.h"
#include "span_1000/code_8025A3EC.h"
#include "span_1000/code_8025C544.h"
#include "span_1000/code_80265370.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_8027302C.h"
#include "span_1000/code_8028308C.h"
#include "span_1000/code_8028CCB8.h"
#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_8028FC98.h"
#include "span_1000/code_802944E8.h"
#include "span_1000/code_80297CD0.h"
#include "span_1000/code_802A6AC0.h"
#include "span_1000/code_802B0388.h"
#include "span_1000/code_802B243C.h"
#include "span_1000/code_802B4730.h"
#include "span_1000/code_802B53FC.h"
#include "span_1000/code_802B8DD0.h"
#include "span_1000/code_802B9ED8.h"
#include "span_1000/code_802BA23C.h"
#include "span_1000/code_802BBC68.h"
#include "span_1000/code_802BE0D0.h"
#include "span_166000/code_80426310.h"
#include "span_16E000/code_80403BCC.h"
#include "span_16E000/code_8040B45C.h"
#include "span_16E000/code_8040F1E0.h"
#include "span_16E000/code_804143D8.h"
#include "span_16E000/code_8041BEA8.h"
#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_8041F1FC.h"
#include "span_16E000/code_804221A0.h"
#include "span_16E000/code_804251F4.h"
#include "span_16E000/code_8042BD40.h"
#include "span_16E000/code_8043962C.h"
#include "span_16E000/code_8043E9A8.h"
#include "span_16E000/code_8044ACCC.h"
#include "types.h"
#include "common/draft_fields_func_8026DC24_de.h"
#include "common/draft_fields_func_80283278_de.h"
#include "common/draft_fields_func_8028D474_de.h"
#include "common/draft_fields_func_8028D964_de.h"
#include "shared/func_80425674_de_layout.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_80286080_de_closed.h"
/* Hides every model named by the sixty-four 12-byte entries of D_800E4A84: for each entry it looks
   up the first and second identifier in the current screen's context at 0x970 through func_8040EC30_de
   and disables the object with func_8040E8D8_de, and does the same for the third identifier unless it
   is -1. The identifiers are passed as their low halfword, and the loop walks a manual byte offset
   so the table address is not hoisted. */
extern struct Pair D_800E4A84[];
void func_804273D4_de(void) {
    s32 missing;
    s32 offset;
    s32 i;
    i = 0;
    missing = -1;
    offset = i;
loop:
    func_8040E8D8_de(func_8040EC30_de(D_800E4690->root, ((struct Pair *)((u8 *)D_800E4A84 + (offset)))->a & 0xFFFF), 0);
    func_8040E8D8_de(func_8040EC30_de(D_800E4690->root, ((struct Pair *)((u8 *)D_800E4A84 + (offset)))->b & 0xFFFF), 0);
    if (((struct Pair *)((u8 *)D_800E4A84 + (offset)))->c.id != missing) {
        func_8040E8D8_de(func_8040EC30_de(D_800E4690->root, ((struct Pair *)((u8 *)D_800E4A84 + (offset)))->c.half.low), 0);
    }
    i += 1;
    offset += 0xC;
    if (i < 0x40) {
        goto loop;
    }
}

extern struct EntryRecAt0V1 D_800E4694[];
extern struct Pair D_800E4A84[];
extern void func_80265688_de(u8 *, s32, s32);
extern s32 func_80265650_de(s32, s32);
extern Preset *func_80425C70_de(s32, s32, s32);

void func_804274B0_de(void) {
    u8 bits[8];
    Preset *unlocks;
    func_8041F2A0_Item *widget;
    s32 i, j, index;
    s32 search;
    s32 value;
    s32 key;
    Shared_Game *game, *settings;
    u8 alpha;
    func_804273D4_de();
    for (i = 0; i < 36; i++) {
        func_80265688_de(bits, i, 0);
    }
    func_80265688_de(bits, 0, 1);
    settings = &D_801462C8;
    if (settings->controllerMode == 1) {
        game = settings;
        for (i = 0; i < 36; i++) {
            unlocks = func_80425C70_de(i, 0, *(s8 *)((char *)game + D_800E4690->player * 0x96 + 0x150));
            value = unlocks->bytes[1];
            if (value > 0) func_80265688_de(bits, value - 1, 1);
            for (j = 0; j < 3; j++) {
                value = *((u8 *)unlocks + j + 2);
                if (value > 0) func_80265688_de(bits, value - 1, 1);
            }
        }
    } else {
        for (i = 0; i < 36; i++) {
            func_80265688_de(bits, i, 1);
        }
    }
    for (i = 0; i < 64; i++) {
        key = D_800E4A84[i].a;
        for (search = 0; search < 36; search++) {
            if (D_800E4694[search].value == key) { index = search; goto found1; }
        }
        index = 0;
found1:;
        if (func_80265650_de((s32)bits, index) == 1) {
            widget = func_8040EC30_de(D_800E4690->parent, (u16)D_800E4A84[i].a);
            func_8040E8D8_de(widget, 1);
            widget->alpha = 20;
            key = D_800E4A84[i].b;
            for (search = 0; search < 36; search++) {
                if (D_800E4694[search].value == key) { index = search; goto found2; }
            }
            index = 0;
found2:;
            if (func_80265650_de((s32)bits, index) == 1) {
                widget = func_8040EC30_de(D_800E4690->parent, (u16)D_800E4A84[i].b);
                func_8040E8D8_de(widget, 1);
                widget->alpha = 20;
                if (D_800E4A84[i].c.id != -1) {
                    widget = func_8040EC30_de(D_800E4690->parent, D_800E4A84[i].c.half.low);
                    func_8040E8D8_de(widget, 1);
                    widget->alpha = 20;
                }
            }
        }
    }
    for (i = 0; i < 36; i++) {
        if (func_80265650_de((s32)D_800E4690->owned, i) == 1) ((void (*)(s32))func_80427D70_de)(i);
    }
    for (i = 0; i < 36; i++) {
        if (func_80265650_de((s32)D_800E4690->pending, i) == 1) func_80265688_de(D_800E4690->owned, i, 1);
    }
    for (i = 0; i < 64; i++) {
        alpha = 170;
        key = D_800E4A84[i].a;
        for (search = 0; search < 36; search++) {
            if (D_800E4694[search].value == key) { index = search; goto found3; }
        }
        index = 0;
found3:;
        if (func_80265650_de((s32)D_800E4690->owned, index) == 1) {
            widget = func_8040EC30_de(D_800E4690->parent, (u16)D_800E4A84[i].a);
            if (func_80265650_de((s32)D_800E4690->pending, index) == 1) { widget->alpha = 70; alpha = 70; }
            else widget->alpha = 170;
            key = D_800E4A84[i].b;
            for (search = 0; search < 36; search++) {
                if (D_800E4694[search].value == key) { index = search; goto found4; }
            }
            index = 0;
found4:;
            if (func_80265650_de((s32)D_800E4690->owned, index) == 1) {
                widget = func_8040EC30_de(D_800E4690->parent, (u16)D_800E4A84[i].b);
                if (func_80265650_de((s32)D_800E4690->pending, index) == 1) { widget->alpha = 70; alpha = 70; }
                else widget->alpha = 170;
                if (D_800E4A84[i].c.id != -1) {
                    widget = func_8040EC30_de(D_800E4690->parent, D_800E4A84[i].c.half.low);
                    widget->alpha = alpha;
                }
            }
        }
    }
}
