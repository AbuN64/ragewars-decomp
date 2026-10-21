#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/WORLD.H"
#include "COMMON/ENTRYRECAT8V4.H"
#include "SCENE/802508E0_9.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ACCESS_S8_10F.H"
#include "TYPES.H"
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"

/* When the entry table is available, loads it through func_8028FE3C_de and func_8025193C_de, finds the
   last 0x4C-byte entry whose ids match the object's u16 ids at 4 and 0xA, and on a match records
   the owner, the id, the entry index and a pending flag in the current record; the loaded table
   is then released through func_80253754_de. */







extern s32 D_800DE7E8;

extern s32 *D_8011FEFC;

extern s32 D_8011BDFC;

extern char D_800E0B2C;

extern s32 func_8028FE3C_de(s32 *, s32, s32, s32 *);



/* Returns 1 unless one of the current record's track-2 references names an item, in the first or
   second item table of D_8011FE88 by its side flag, whose kind and subkind are 1 and 5, 9 and 4,
   or 10 and 3. */













void func_80402FB4_de(struct SharedTrackObject *owner, func_8020478C_S1 *obj) {
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
            D_800E2830->target = owner;
            D_800E2830->targetD8 = idA;
            D_800E2830->resourceDC = found;
            D_800E2830->field58 = 1;
        }
        func_80253754_de(0, table);
    }
}

s32 func_804030E0_de(s32 key) {
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
                D_800E2830->targetD8 = entries[i].id0;
            }
            D_800E2830->requestE0 = key;
            D_800E2830->resourceDC = i;
            D_800E2830->field58 = 1;
            break;
        }
    }
    func_80253754_de(0, table);
    func_80245AC8_de();
    return D_800E2830->targetD8;
}

void func_80403200_de(char *name) {
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
                D_800E2830->requestE0 = entries[i].id8;
                id = entries[i].id0;
                D_800E2830->resourceDC = i;
                D_800E2830->field58 = 1;
                D_800E2830->targetD8 = id;
                break;
            }
        }
        func_80253754_de(0, table);
    }
}

s32 func_8040332C_de(void) {
    s32 found;
    s32 *track;
    Triple *refs;
    ItemRecAt12 *item;
    s32 i;
    s32 n;
    s32 hit;

    Shared_World *tables;
    found = 0;
    track = func_8028FDB4_de(D_800E2830->resource, 2);
    n = track[1];
    refs = (Triple *)(track + 2);
    for (i = 0; i < n; i++) {
        tables = &D_8011FE88;
        if (refs[i].y == 0) {
            item = &((ItemRecAt12 *)tables->recordArray)[refs[i].z];
        } else {
            item = &((ItemRecAt12 *)tables->alternateRecordArray)[refs[i].z];
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
