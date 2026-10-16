#include "span_16E000/code_80423280.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "shared/world.h"
#include "span_16E000/code_804264F0.h"
#include "types.h"
#include "span_16E000/code_8043A0A4.h"

/* Formats the name of entry D_800E4690's word at 0xA44 into a local 0x40-byte buffer through
   func_8028D380_de from D_8011FE88, passes the length func_802A0494_de measures to func_802A025C_de for the
   text object at offset 0xA04, and points word 0x38 of the object at 0x998 to that text object. */






extern void func_8028D380_de(Shared_World *, s32, char *, s32);

extern s32 func_802A0494_de(char *);

extern void func_802A025C_de(void *, s32);

/* Returns the index of the entry among the 0x24 28-byte entries of D_800E4694 whose identifier
   matches, or zero when none does. */


extern struct EntryRecAt0V1 D_800E4694[];

/* Returns one when the two arguments are equal or when any of the sixty-four 12-byte pairs of D_800E4A84 holds exactly that ordered pair, zero otherwise.
   Adapted from func_8041F1D8_de with the single-key slot scan changed to an ordered-pair lookup over 64 twelve-byte entries. */



extern struct Pair D_800E4A84[];

/* Sets the byte at offset 0x10 of the two objects at offsets 0xA64 and 0xA60 of the structure D_800E4690
   points to to 0xFF, shows both through func_8040E8D8_de and clears the word at 0xA68. */







extern void func_8040E8D8_de(struct Resource_func_80419E54_de *, s32);

/* Reports every set entry of each ready slot to the handler, stopping after two slots. */







extern void func_8042854C_de(s32, s32, s32);

/* Rebuilds the item list for the player D_800E4690 selects: clears it through func_80428700_de, looks
   up that player's model in D_8011FE88, and for each of the model's eight slot ids at 0x4C that is
   at least 0x4C3 adds the nonzero id less 0x4C3 as the next row through func_8042854C_de when
   func_8022F4DC_de accepts it for the player's 400-byte record in D_80102B00. */








extern char D_80102B00[];

extern struct Model *func_8028CFA0_de(Shared_World *, s32, s32);

extern s32 func_8022F4DC_de(char *, s32);

/* Rebuilds the weapon menu for the player D_800E4690 selects: clears it through func_80428700_de, then
   for each of the 0x16 weapon ids (excluding id 0) whose owned flag in D_801462C8 (offset 0x11C,
   player stride 0x96) is set, appends a row through func_8042854C_de. */







extern void func_8042854C_de(s32 arg0, s32 arg1, s32 arg2);

/* Enumerates the eight item identifiers of the record func_8028D474_de finds for a key and registers each nonzero identifier above 0x4C3 through func_8042854C_de, translated by 0x4C3 and numbered in order. */





extern Record_func_804284C0_de *func_8028D474_de(void *table, s32 key);

extern void func_8042854C_de(s32 slot, s32 item, s32 arg2);

void func_804280BC_de(void) {
    extern struct State_func_804280BC_de *D_800E4690;
    char buffer[0x40];

    func_8028D380_de(&D_8011FE88, D_800E4690->name, buffer, 0x3F);
    func_802A025C_de(D_800E4690->text, func_802A0494_de(buffer));
    D_800E4690->owner->unk38 = D_800E4690->text;
}

s32 func_80428120_de(s32 id) {
    s32 i;

    for (i = 0; i < 0x24; i++) {
        if (D_800E4694[i].value == id) {
            return i;
        }
    }
    return 0;
}

s32 func_80428158_de(s32 a, s32 b) {
    s32 i;

    if (a == b) {
        return 1;
    }
    for (i = 0; i < 64; i++) {
        if (D_800E4A84[i].a == a && D_800E4A84[i].b == b) {
            return 1;
        }
    }
    return 0;
}

void func_804281A8_de(void) {
    extern func_80428388_S1 *D_800E4690;
    (D_800E4690->unkA64)->value = 0xFF;
    (D_800E4690->unkA60)->value = 0xFF;
    func_8040E8D8_de(D_800E4690->unkA60, 1);
    func_8040E8D8_de(D_800E4690->unkA64, 1);
    D_800E4690->unkA68 = 0;
}

void func_80428214_de(void) {
    extern State_func_80428214_de D_801462C8;
    State_func_80428214_de *st;
    s32 n;
    s32 k;
    s32 i;
    State_func_80428214_de *base;
    s32 j;

    k = 0;
    st = &D_801462C8;
    for (n = 0; n < 4; n++) {
        if (st->slots[n].ready == 1) {
            j = 0;
            for (i = 0; i < 0x16; i++) {
                if (((base = &D_801462C8)->slots[n].flags[i] == 1) && (i != 0)) {
                    func_8042854C_de(j, i, k);
                    j++;
                }
            }
            k++;
            if (k >= 2) {
                return;
            }
        }
    }
}

void func_80428300_de(void) {
    extern struct ResultsOptionsScreen *D_800E4690;
    struct Model *model;
    s32 player;
    s32 id;
    s32 row;
    s32 i;

    func_80428700_de();
    player = D_800E4690->player;
    model = func_8028CFA0_de(&D_8011FE88, 0xB, D_80142358[player * 150]);
    row = 0;
    for (i = 0; i < 8; i++) {
        id = model->slots[i];
        if (id >= 0x4C3) {
            id -= 0x4C3;
            if (func_8022F4DC_de(&D_80102B00[player * 400], id) == 1 && id != 0) {
                func_8042854C_de(row, id, 0);
                row++;
            }
        }
    }
}

void func_8042840C_de(void) {
    extern char D_801462C8[];
    extern struct ResultsOptionsScreen *D_800E4690;
    s32 count;
    s32 weapon;
    s32 base;

    func_80428700_de();
    count = 0;
    base = D_800E4690->player * 0x96;
    for (weapon = 0; weapon < 0x16; weapon++) {
        if (((EntryRecAt11C *) (weapon + base + D_801462C8))->owned == 1) {
            if (weapon != 0) {
                func_8042854C_de(count, weapon, 0);
                count += 1;
            }
        }
    }
}

void func_804284C0_de(s32 key) {
    Record_func_804284C0_de *record;
    s32 count;
    s32 i;
    s32 item;

    func_80428700_de();
    record = func_8028D474_de(&D_8011FE88, key);
    count = 0;
    for (i = 0; i < 8; i++) {
        item = record->items[i];
        if (item >= 0x4C3) {
            item -= 0x4C3;
            if (item != 0) {
                func_8042854C_de(count, item, 0);
                count++;
            }
        }
    }
}
