#include "span_16E000/code_8044E2B8.h"
#include "types.h"
#include "shared/func_8044D794_de_closed.h"
#include "common/unused.h"
#include "span_C76B0/data.h"
#include "shared/func_8044DA54_de_closed.h"

/* Spawns the pickups of a level: between func_802458D8_de and func_802458C4_de it passes every item of both item tables whose kind is 1, 2, 4 or 10 to func_8028787C_de. */




extern void func_802458D8_de(void);
extern void func_802458C4_de(void);
extern void func_8028787C_de(Level *, Item_func_8044D668_de *);

void func_8044D668_de(Level *level) {
    s32 i;
    s32 n;
    Item_func_8044D668_de *item;

    func_802458D8_de();
    n = level->counts[0];
    for (i = 0; i < n; i++) {
        item = &level->items[0][i];
        if (item->kind == 1 || item->kind == 4 || item->kind == 2 || item->kind == 10) {
            func_8028787C_de(level, item);
        }
    }
    n = level->counts[1];
    for (i = 0; i < n; i++) {
        item = &level->items[1][i];
        if (item->kind == 1 || item->kind == 4 || item->kind == 2 || item->kind == 10) {
            func_8028787C_de(level, item);
        }
    }
    func_802458C4_de();
}

void func_8044D794_de(Owner_func_8044D794_de *arg0) {
    Entry_func_8044D794_de *entry;
    Entry_func_8044D794_de *next;

    entry = arg0->active;
    while (entry != 0) {
        next = entry->next;
        func_80278C10_de(entry->handle);
        func_80255ED8_de(&arg0->active, entry);
        func_80255CB8_de(&arg0->spare, entry);
        entry = next;
    }
}

extern s32 func_8028C198_de(s32, s32);

void func_8044D804_de(s32 arg0, void ***arg1) {
    void *obj;
    Group_func_8044D794_de *group;
    Piece *piece;
    s32 base;
    s32 count;
    s32 i;

    if (func_80285180_de(arg1, 0) != 0) {
        obj = **arg1;
        group = func_8028FDB4_de(obj, 2);
        count = group->count;
        piece = group->pieces;
        i = 0;
        base = (s32) func_8028FDB4_de(obj, i);
        if (count > 0) {
            do {
                if (piece[i].tag == -1) {
                    piece[i].tag = 0;
                } else {
                    piece[i].tag = func_8028C198_de(arg0, piece[i].tag);
                }
                piece[i].unk18 = base + piece[i].unk18;
                piece[i].unk1C = base + piece[i].unk1C;
                piece[i].unk20 = base + piece[i].unk20;
                piece[i].unk24 = base + piece[i].unk24;
                piece[i].unk28 = base + piece[i].unk28;
                piece[i].unk2C = base + piece[i].unk2C;
                piece[i].unk30 = base + piece[i].unk30;
                piece[i].unk34 = base + piece[i].unk34;
                piece[i].unk38 = base + piece[i].unk38;
                i++;
            } while (i < count);
        }
    }
}


void func_8044D934_de(s32 arg0, void ***arg1) {
    f32 scale;
    void *obj;
    Ent *ent;
    s32 count;
    s32 i;

    scale = D_800C5304_de;
    if (func_80285180_de(arg1, 0) != 0) {
        obj = **arg1;
        count = *(s32 *) obj;
        for (i = 0; i < count; i++) {
            ent = func_8028FDB4_de(obj, i);
            switch (ent->kind) {
            case 1:
                ent->unk28 = ent->unk28 * scale;
                ent->unk30 = ent->unk30 * scale;
                ent->unk34 = ent->unk34 * scale;
                ent->unk50 = ent->unk50 * scale;
                ent->unk54 = ent->unk54 * scale;
                ent->unk58 = ent->unk58 * scale;
                break;
            case 11:
                ent->unkEC = ent->unkEC * scale;
                ent->unkF0 = ent->unkF0 * scale;
                break;
            case 0:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                break;
            }
        }
    }
}

void func_8044DA54_de(Owner_func_8044D794_de *arg0, void ***arg1) {
    void *obj;
    Frame_func_8044D794_de *frame;
    Bank_func_8044D794_de *bank;
    struct EntryRecAt0V3 *items;
    struct EntryRecAt0V3 *item;
    SlotRecAt0V2 *slot;
    s32 count;
    s32 inner;
    s32 i;
    s32 j;
    s32 index;

    if (func_80285180_de(arg1, 0) != 0) {
        obj = **arg1;
        count = *(s32 *) obj;
        for (i = 0; i < count; i++) {
            frame = func_8028FDB4_de(func_8028FDB4_de(obj, i), 1);
            inner = frame->count;
            j = 0;
            if (j < inner) {
                slot = frame->slots;
                do {
                    index = slot->item;
                    if (index != -1) {
                        bank = func_8028FDB4_de(arg0->unk6C, 2);
                        items = bank->items;
                        if ((index < 0) || (index >= bank->count)) {
                            item = 0;
                        } else {
                            item = &items[index];
                        }
                        slot->item = (s32) item;
                    } else {
                        slot->item = 0;
                    }
                    slot++;
                    j++;
                } while (j < inner);
            }
        }
        arg0->unk7C = obj;
    }
}
