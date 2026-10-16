#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80442BC8.h"
#include "TYPES.H"
#include "common/unused.h"
#include "shared/func_80245BC0_de_closed.h"

/* Runs the optional callback at offset 0xC of an object's handler table at 0x14, then clears the
   words at offsets 0xB0, 0xB4 and 0xBC of the object at 0x20. */






void func_804431E4_de(struct ObjectRecAt20 *object) {
    struct StateRecAtBCV2 *state;

    if (object->handlers->callback != 0) {
        object->handlers->callback();
    }
    state = object->state;
    state->a = 0;
    state->b = 0;
    state->c = 0;
}

/* Allocates a block sized for the entries of a list through func_8025343C_de, builds it with func_80440DA0_de from four arguments, registers it with func_80255CB8_de and advances the owner's rotating counter below four, returning the block or zero. Adapted from func_804427C4_de with the list and all four values passed as arguments instead of read from a parameter block changed. */






extern void **func_8025343C_de(s32, s32, s32, char *);
extern void func_80255CB8_de(struct func_8025E5B0_S1 *, void *);

void *func_8044322C_de(struct func_8025E5B0_S1 *owner, struct Dialog *list, s32 a, s32 b, s32 c, s32 d) {
    s32 size = list->count * 40 + 0x1D8;
    s32 i;
    void **block;
    void *first;

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
    if (first == 0) {
        return 0;
    }
    func_80440DA0_de(first, block, list, a, b, c, d, owner);
    func_80255CB8_de(owner, first);
    if (++owner->unk14 >= 4) {
        owner->unk14 = 0;
    }
    return first;
}

/* Removes an item from a list: runs the item's optional callback at offset 0xC of its handler table
   with the item and the list, clears three words of its state at 0x20, unlinks it through
   func_80255ED8_de and releases its resource at offset 8 through func_80253838_de. */






extern void func_80255ED8_de(void *, struct ItemRecAt20V2 *);

void func_8044334C_de(void *list, struct ItemRecAt20V2 *item) {
    struct StateRecAtBCV2 *state;

    if (item->handlers->callback != 0) {
        item->handlers->callback(item, list);
    }
    state = item->state;
    state->a = 0;
    state->b = 0;
    state->c = 0;
    func_80255ED8_de(list, item);
    func_80253838_de(0, item->resource);
}
