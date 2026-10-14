#include "span_16E000/code_80400000.h"
#include "types.h"
/* Releases the current record's track-2 timed items whose time has come (or all live ones once the
   record's end time has passed): special items (kind and subkind 1 and 5, 9 and 4, 10 and 3) go to
   func_80402FB4_de and clear the record's pending flag, others to func_80278E7C_de, then each entry is
   marked spent and its item is flagged and refreshed through func_8028BB1C_de. Adapted from func_8040332C_de: indexed entry
   access and the table base taken inside the loop. */









extern Record_func_80403458_de *D_800E2830;
extern Tables_func_80403458_de D_8011FE88;

extern s32 func_80245784_de(void);
extern s32 *func_8028FDB4_de(s32 resource, s32 index);
extern void func_80402FB4_de(s32 mode, Item_func_80403458_de *item);
extern void func_80278E7C_de(Item_func_80403458_de *item);
extern void func_8028BB1C_de(Tables_func_80403458_de *tables, Item_func_80403458_de *item, s32 mode);

void func_80403458_de(void) {
    f32 time;
    s32 late;
    s32 *track;
    EntryRecAt8V4 *entry;
    Item_func_80403458_de *item;
    s32 n;
    s32 i;
    s32 hit;
    Tables_func_80403458_de *tables;

    time = D_800E2830->time;
    late = 0;
    if (func_80245784_de() == 0) {
        return;
    }
    if (D_800E2830->active == 0) {
        return;
    }
    track = func_8028FDB4_de(D_800E2830->resource, 2);
    n = track[1];
    entry = (EntryRecAt8V4 *)(track + 2);
    if (n == 0) {
        return;
    }
    if (D_800E2830->endTime <= time) {
        late = 1;
    }
    for (i = 0; i < n; i++) {
        tables = &D_8011FE88;
        if (entry[i].time <= -10000.0f) {
            continue;
        }
        if (time < entry[i].time && late == 0) {
            continue;
        }
        if (entry[i].side == 0) {
            item = &tables->items[0][entry[i].index];
        } else {
            item = &tables->items[1][entry[i].index];
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
            func_80402FB4_de(0, item);
            D_800E2830->pending = 0;
        } else {
            func_80278E7C_de(item);
        }
        entry[i].time = -20000.0f;
        item->flags = (item->flags | 1) & 0xEF;
        func_8028BB1C_de(&D_8011FE88, item, 0);
    }
}
