#include "span_1000/code_80245980.h"
#include "span_16E000/code_80400000.h"
#include "types.h"
/* When the entry table is available, loads it through func_8028FE3C_de and func_8025193C_de and finds
   the first 0x4C-byte entry whose key matches; for it the current record takes the entry id unless
   its mode bits 0..1 are set, the key, the entry index and a pending flag. The table is released
   through func_80253754_de, func_80245AC8_de applies the selection, and the record's id is returned; 0
   when the table is unavailable. Adapted from func_80402FB4_de. */





extern s32 D_800DE7E8;
extern s32 *D_8011FEFC;
extern s32 D_8011BDFC;
extern Record_func_804030E0_de *D_800E2830;
extern char D_800E0B2C;

extern s32 func_8028FE3C_de(s32 *, s32, s32, s32 *);
extern s32 **func_8025193C_de(s32, s32, s32, s32, s32, s32, s32, char *, s32);
extern void func_80253754_de(s32, s32 **);



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
