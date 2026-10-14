#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_80400000.h"
#include "types.h"
/* Returns 1 unless one of the current record's track-2 references names an item, in the first or
   second item table of D_8011FE88 by its side flag, whose kind and subkind are 1 and 5, 9 and 4,
   or 10 and 3. */









extern func_80203E78_S1 *D_800E2830;
extern Tables D_8011FE88;

extern s32 *func_8028FDB4_de(s32 resource, s32 index);

s32 func_8040332C_de(void) {
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
