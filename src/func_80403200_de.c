#include "span_16E000/code_80400000.h"
#include "types.h"
/* When the entry table is available, loads it through func_8028FE3C_de and func_8025193C_de and finds
   the first 0x4C-byte entry whose name matches the given one through func_80293440_de; for it the
   current record takes the entry's key, index, id and a pending flag. The table is then released
   through func_80253754_de. Adapted from func_804030E0_de and matched the same way. */





extern s32 D_800DE7E8;
extern s32 *D_8011FEFC;
extern s32 D_8011BDFC;
extern Record_func_804030E0_de *D_800E2830;
extern char D_800E0B2C;

extern s32 func_8028FE3C_de(s32 *, s32, s32, s32 *);
extern s32 **func_8025193C_de(s32, s32, s32, s32, s32, s32, s32, char *, s32);
extern void func_80253754_de(s32, s32 **);



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
