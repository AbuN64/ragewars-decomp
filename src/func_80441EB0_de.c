#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043F69C.h"
#include "types.h"

/* Allocates a block sized for the entries of the list the parameters point at through func_8025343C_de, builds it with func_80440DA0_de from the list's own value and three parameters, registers it with func_80255CB8_de and advances the owner's rotating counter below four, returning the block or zero. Adapted from func_804427C4_de with the list read from the parameters at 0x18, a null list returning zero, and the first value read from the list at 0x20 instead of the parameters at 0x14 changed. */








extern char D_800DE4E8[];
extern void **func_8025343C_de(s32, s32, s32, char *);
extern void func_80440DA0_de(void *, void **, struct List_func_80442574_de *, s32, s32, s32, s32, struct func_8025E5B0_S1 *);
extern void func_80255CB8_de(struct func_8025E5B0_S1 *, void *);

void *func_80441EB0_de(struct func_8025E5B0_S1 *owner, struct ParamsRecAt24V1 *params) {
    struct List_func_80442574_de *list = params->list;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 size;
    s32 i;
    void **block;
    void *first;

    if (list != 0) {
        a = list->value;
        b = params->b;
        c = params->c;
        d = params->d;
        size = list->count * 40 + 0x1D8;
        for (i = 0; i < list->count; i++) {
            s32 extra = 0;
            if (list->entries[i].type == 3) {
                extra = 0x480;
            }
            size += extra;
        }
        block = func_8025343C_de(0, size, 0x3B, D_800DE4E8 + 4);
        if (block == 0) {
            return 0;
        }
        first = *block;
        if (first != 0) {
            func_80440DA0_de(first, block, list, a, b, c, d, owner);
            func_80255CB8_de(owner, first);
            if (++owner->unk14 >= 4) {
                owner->unk14 = 0;
            }
            return first;
        }
    }
    return 0;
}
