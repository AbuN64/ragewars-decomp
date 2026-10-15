#include "span_16E000/code_80400000.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80245980.h"
#include "types.h"

/* When the entry table is available, loads it through func_8028FE3C_de and func_8025193C_de, finds the
   last 0x4C-byte entry whose ids match the object's u16 ids at 4 and 0xA, and on a match records
   the owner, the id, the entry index and a pending flag in the current record; the loaded table
   is then released through func_80253754_de. */







extern s32 D_800DE7E8;

extern s32 *D_8011FEFC;

extern s32 D_8011BDFC;

extern char D_800E0B2C;

extern s32 func_8028FE3C_de(s32 *, s32, s32, s32 *);

extern s32 **func_8025193C_de(s32, s32, s32, s32, s32, s32, s32, char *, s32);

extern void func_80253754_de(s32, s32 **);

/* Returns 1 unless one of the current record's track-2 references names an item, in the first or
   second item table of D_8011FE88 by its side flag, whose kind and subkind are 1 and 5, 9 and 4,
   or 10 and 3. */











extern Tables D_8011FE88;

extern s32 *func_8028FDB4_de(s32 resource, s32 index);

void func_80402FB4_de(s32 owner, func_8020478C_S1 *obj) {
    extern Record_func_80402FB4_de *D_800E2830;
    s32 size;
    s32 **table;
    s32 key;
    s32 found;
    s32 i;
    s32 n;
    EntryRecAt4V2 *entry;
    s32 id4;
    s32 idA;

    found = -1;
    if (D_800DE7E8 != 0) {
        id4 = obj->unk4;
        idA = obj->unkA;
        key = func_8028FE3C_de(D_8011FEFC, D_8011BDFC, 0, &size);
        if (key == 0) {
            table = 0;
        } else {
            table = func_8025193C_de(0, key, key, size, 0x33, 0, 0, &D_800E0B2C, 1);
        }
        n = *D_8011FEFC - 1;
        entry = (EntryRecAt4V2 *)(*table + 2);
        for (i = 0; i < n; i++, entry++) {
            if (entry->id4 == id4 && entry->id0 == idA) {
                found = i;
            }
        }
        if (found != -1) {
            D_800E2830->owner = owner;
            D_800E2830->id = idA;
            D_800E2830->index = found;
            D_800E2830->pending = 1;
        }
        func_80253754_de(0, table);
    }
}

s32 func_804030E0_de(s32 key) {
    extern Record_func_804030E0_de *D_800E2830;
    s32 size;
    s32 **table;
    s32 loaded;
    s32 i;
    s32 n;
    EntryRecAt48 *entries;

    if (D_800DE7E8 == 0) {
        return 0;
    }
    loaded = func_8028FE3C_de(D_8011FEFC, D_8011BDFC, 0, &size);
    if (loaded == 0) {
        table = 0;
    } else {
        table = func_8025193C_de(0, loaded, loaded, size, 0x33, 0, 0, &D_800E0B2C, 1);
    }
    i = 0;
    entries = (EntryRecAt48 *)(*table + 2);
    n = *D_8011FEFC - 1;
    for (; i < n; i++) {
        if (entries[i].id8 == key) {
            if ((entries[i].flags & 3) == 0) {
                D_800E2830->id = entries[i].id0;
            }
            D_800E2830->key = key;
            D_800E2830->index = i;
            D_800E2830->pending = 1;
            break;
        }
    }
    func_80253754_de(0, table);
    func_80245AC8_de();
    return D_800E2830->id;
}

void func_80403200_de(char *name) {
    extern Record_func_804030E0_de *D_800E2830;
    s32 size;
    s32 **table;
    s32 loaded;
    s32 i;
    s32 id;
    s32 n;
    EntryRecAt18V5 *entries;

    if (D_800DE7E8 != 0) {
        loaded = func_8028FE3C_de(D_8011FEFC, D_8011BDFC, 0, &size);
        if (loaded == 0) {
            table = 0;
        } else {
            table = func_8025193C_de(0, loaded, loaded, size, 0x33, 0, 0, &D_800E0B2C, 1);
        }
        i = 0;
        entries = (EntryRecAt18V5 *)(*table + 2);
        n = *D_8011FEFC - 1;
        for (; i < n; i++) {
            if (((s32 (*)(char *, char *))func_80293440_de)(name, entries[i].name) == 0) {
                D_800E2830->key = entries[i].id8;
                id = entries[i].id0;
                D_800E2830->index = i;
                D_800E2830->pending = 1;
                D_800E2830->id = id;
                break;
            }
        }
        func_80253754_de(0, table);
    }
}

s32 func_8040332C_de(void) {
    extern func_80203E78_S1 *D_800E2830;
    s32 found;
    s32 *track;
    Triple *refs;
    ItemRecAt12 *item;
    s32 i;
    s32 n;
    s32 hit;
    Tables *tables;

    found = 0;
    track = func_8028FDB4_de(D_800E2830->unk4, 2);
    n = track[1];
    refs = (Triple *)(track + 2);
    for (i = 0; i < n; i++) {
        tables = &D_8011FE88;
        if (refs[i].y == 0) {
            item = &tables->items[0][refs[i].z];
        } else {
            item = &tables->items[1][refs[i].z];
        }
        hit = 0;
        switch (item->kind) {
            case 1:
                if (item->subkind == 5) {
                    hit = 1;
                }
                break;
            case 9:
                if (item->subkind == 4) {
                    hit = 1;
                }
                break;
            case 10:
                if (item->subkind == 3) {
                    hit = 1;
                }
                break;
            default:
                hit = 0;
                break;
        }
        if (hit) {
            found = 1;
        }
    }
    return found ^ 1;
}
