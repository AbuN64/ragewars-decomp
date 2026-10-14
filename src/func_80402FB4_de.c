#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80400000.h"
#include "types.h"
/* When the entry table is available, loads it through func_8028FE3C_de and func_8025193C_de, finds the
   last 0x4C-byte entry whose ids match the object's u16 ids at 4 and 0xA, and on a match records
   the owner, the id, the entry index and a pending flag in the current record; the loaded table
   is then released through func_80253754_de. */







extern s32 D_800DE7E8;
extern s32 *D_8011FEFC;
extern s32 D_8011BDFC;
extern Record_func_80402FB4_de *D_800E2830;
extern char D_800E0B2C;

extern s32 func_8028FE3C_de(s32 *, s32, s32, s32 *);
extern s32 **func_8025193C_de(s32, s32, s32, s32, s32, s32, s32, char *, s32);
extern void func_80253754_de(s32, s32 **);

void func_80402FB4_de(s32 owner, func_8020478C_S1 *obj) {
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
