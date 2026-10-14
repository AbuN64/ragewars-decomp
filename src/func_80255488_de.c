#include "span_1000/code_80254CE4.h"
#include "types.h"

extern s32 D_80101190;
extern s32 D_80101194;









void func_80255488_de(s32 arg0) {
    s32 key;
    EntryRecAtCV1 *temp_v0;
    EntryRecAtCV1 *var_a0;
    EntryRecAtCV1 *var_a2;
    EntryRecAtCV1 *var_v1;

    key = arg0;
    var_v1 = (EntryRecAtCV1 *)(D_80101194 + ((((key << 5) ^ ((u32)key >> 1) ^
                                      ((u32)key >> 9) ^ ((u32)key >> 0x11)) &
                                     D_80101190) * 0x10));
    var_a2 = 0;
    if (var_v1->key != key) {
loop:
        var_a2 = var_v1;
        var_v1 = var_v1->next;
        if (var_v1 != 0) {
            if (var_v1->key == key) {
                goto found;
            }
            goto loop;
        }
    } else {
found:
        if (var_v1 != 0) {
            var_a0 = var_v1->next;
            if (var_a0 != 0) {
                var_v1->value = var_a0->value;
                var_v1->key = var_a0->key;
                var_v1->next = var_a0->next;
                temp_v0 = var_v1;
                var_v1 = var_a0;
                var_a0 = temp_v0;
            }
            if (var_a2 != 0) {
                var_a2->next = var_a0;
            }
            var_v1->value = 0;
            var_v1->key = 0;
            var_v1->next = 0;
        }
    }
}
