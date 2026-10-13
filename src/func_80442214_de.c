#include "span_16E000/code_8043F69C.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_8043F69C.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

/* Returns the address 0x190 bytes into the block at offset 0x20 of an object, or null when the
   object has no block. */

char *func_80442214_de(struct func_802285C4_S1 *object) {
    char *result = 0;

    if (object->unk20 != 0) {
        result = object->unk20 + 0x190;
    }
    return result;
}

/* Computes a glyph advance using character widths and special spacing before T. */
f32 func_8044222C_de(s32 arg0, u8 arg1, f32 arg2, f32 arg3) {
    f32 var_f0;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a1_2;

    temp_a0 = arg0 & 0xFF;
    var_f0 = 1.0f;
    switch (temp_a0) {
    case 0x24:
    case 0x26:
    case 0x7E:
        return arg3;
    case 0x49:
    case 0x69:
        var_f0 = 0.5f;
    default:
        break;
    case 0x4C:
    case 0x6C:
        temp_a1 = arg1 & 0xFF;
        if ((temp_a1 == 0x74) || (temp_a1 == 0x54)) {
            var_f0 = 0.7f;
        }
        break;
    case 0x41:
    case 0x61:
        temp_a1_2 = arg1 & 0xFF;
        if ((temp_a1_2 == 0x74) || (temp_a1_2 == 0x54)) {
            var_f0 = 0.8f;
        }
        break;
    case 0x4D:
    case 0x6D:
        var_f0 = 1.2f;
        break;
    case 0x21:
    case 0x2E:
        var_f0 = 0.4f;
        break;
    }
    return var_f0 * arg2;
}

/* Sums the glyph advances that func_8044222C_de returns for each character pair of a string at the given scales, stopping at a newline, the end of the string or a null pointer. */

f32 func_804422F0_de(u8 *p, f32 sx, f32 sy) {
    f32 total;
    u8 c;

    total = 0.0f;
    while (p != 0 && (c = *p) != 0 && c != '\n') {
        p++;
        total += func_8044222C_de(c, *p, sx, sy);
    }
    return total;
}

/* Returns whether func_80441EB0_de gives a non-zero answer for the third argument. */
extern s32 func_80441EB0_de(void *);

s32 func_80442384_de(void *first, void *second, void *third) {
    return func_80441EB0_de(third) != 0;
}

/* Returns zero. */
s32 func_804423A4_de(void) {
    return 0;
}

/* Returns the word at offset 0x1C of the object that offset 0x14 of a record points to. */

s32 func_804423AC_de(struct Outer *outer) {
    return outer->inner->locked;
}

/* Adjusts a value from controller input and clamps or wraps it between its limits. */

s32 func_8026437C_de(s32); /* extern */
 /* extern */
 /* extern */

s32 func_804423BC_de(func_8022A404_S1 *menu,s32 value,s32 step,s32 minimum,s32 maximum,s32 wrap) {
 if(((s32 (*)(s32))func_80264388_de)(menu->unk20))value-=step;
 if(((s32 (*)(s32))func_802643A0_de)(menu->unk20)||func_8026437C_de(menu->unk20))value+=step;
 if(value<minimum) {
  value=minimum;if(wrap)value=maximum;
 } else if(value>maximum) {
  value=maximum;if(wrap)value=minimum;
 }
 return value;
}

/* Steps a menu value left or right with optional range wrapping. */

 /* extern */
 /* extern */

s32 func_80442488_de(func_8022A404_S1 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_s0;
    s32 var_s0;
    s32 var_v0;

    var_s0 = arg1;
    if (((s32 (*)(s32))func_80264388_de)(arg0->unk20) != 0) {
        var_s0 -= arg2;
        if (var_s0 < arg3) {
            var_s0 = arg3;
            if (arg5 != 0) {
                var_s0 = arg4;
            }
        }
    }
    var_v0 = var_s0;
    if (((s32 (*)(s32))func_802643A0_de)(arg0->unk20) != 0) {
        temp_s0 = var_s0 + arg2;
        var_v0 = temp_s0;
        if (arg4 < temp_s0) {
            var_s0 = arg4;
            if (arg5 != 0) {
                var_s0 = arg3;
            }
            var_v0 = var_s0;
        }
    }
    return var_v0;
}


void func_80442544_de(void *object) {
    func_80255CA0_de(object, 0x1D0, 0x1D4);
    ((func_8025E5B0_S1 *)(object))->unk14 = 0;
}

/* Allocates a block sized for the entries of a list through func_8025343C_de, builds it with func_80440DA0_de from a zero and three arguments, registers it with func_80255CB8_de and advances the owner's rotating counter below four, returning the block or zero. Adapted from func_804427C4_de with the list and three values passed as arguments and a zero as the first value changed. */

extern char D_800DE4E8[];
extern void **func_8025343C_de(s32, s32, s32, char *);
extern void func_80440DA0_de(void *, void **, struct List_func_80442574_de *, s32, s32, s32, s32, struct func_8025E5B0_S1 *);
extern void func_80255CB8_de(struct func_8025E5B0_S1 *, void *);

void *func_80442574_de(struct func_8025E5B0_S1 *owner, struct List_func_80442574_de *list, s32 b, s32 c, s32 d) {
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
    func_80440DA0_de(first, block, list, 0, b, c, d, owner);
    func_80255CB8_de(owner, first);
    if (++owner->unk14 >= 4) {
        owner->unk14 = 0;
    }
    return first;
}

/* Allocates a block sized for the entries of a list (forty bytes each plus 0x480 for every entry of type three, over a 0x1D8 header) through func_8025343C_de, builds it with func_80440DA0_de from four parameters, registers it with func_80255CB8_de and advances the owner's rotating counter below four, returning the block or zero. */
extern char D_800DE4E8[];
extern void **func_8025343C_de(s32, s32, s32, char *);
extern void func_80440DA0_de(void *, void **, struct List_func_80442574_de *, s32, s32, s32, s32, struct func_8025E5B0_S1 *);
extern void func_80255CB8_de(struct func_8025E5B0_S1 *, void *);

void *func_80442690_de(struct func_8025E5B0_S1 *owner, struct Params_func_80442690_de *params, struct List_func_80442574_de *list) {
    s32 a = params->a;
    s32 b = params->b;
    s32 c = params->c;
    s32 d = params->d;
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

/* Allocates a block sized for the entries of a list through func_8025343C_de, builds it with func_80440DA0_de from four parameters, registers it with func_80255CB8_de and advances the owner's rotating counter below four, returning the block or zero. Adapted from func_80442690_de with the first parameter read from offset 0x14 instead of 0x18. */
extern char D_800DE4E8[];
extern void **func_8025343C_de(s32, s32, s32, char *);
extern void func_80440DA0_de(void *, void **, struct List_func_80442574_de *, s32, s32, s32, s32, struct func_8025E5B0_S1 *);
extern void func_80255CB8_de(struct func_8025E5B0_S1 *, void *);

void *func_804427C4_de(struct func_8025E5B0_S1 *owner, struct Params_func_804427C4_de *params, struct List_func_80442574_de *list) {
    s32 a = params->a;
    s32 b = params->b;
    s32 c = params->c;
    s32 d = params->d;
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

/* Tears down every node of one list: walks it from the head, saving the successor at 0x1D4 first,
   skips nodes of kind 2 while the list is not the global one at D_8014561C and that list's flag at
   0x10 is set, and for each remaining node asks func_80441214_de whether it may go; when it may, calls
   the node's optional handler at 0xC of its table at 0x14, clears the three words at 0xB0, 0xB4 and
   0xBC of the state it owns at 0x20, unlinks it with func_80255ED8_de and releases its handle at 0x8
   through func_80253838_de. */
extern List_func_804428F8_de D_8014561C;
extern s32 func_80441214_de(Node_func_804428F8_de *, List_func_804428F8_de *);
extern void func_80255ED8_de(List_func_804428F8_de *, Node_func_804428F8_de *);
extern void func_80253838_de(s32, s32);

void func_804428F8_de(List_func_804428F8_de *list) {
    Node_func_804428F8_de *node;
    Node_func_804428F8_de *next;
    State_func_804428F8_de *state;

    node = list->head;
    while (node != 0) {
        next = node->next;
        if (!((node->kind == 2) && (list != &D_8014561C) && (D_8014561C.flag != 0))) {
            if (func_80441214_de(node, list) != 0) {
                if (node->table->handler != 0) {
                    node->table->handler(node, list);
                }
                state = node->state;
                state->field_B0 = 0;
                state->field_B4 = 0;
                state->field_BC = 0;
                func_80255ED8_de(list, node);
                func_80253838_de(0, node->handle);
            }
        }
        node = next;
    }
}

void func_804429D4_de(struct Owner_func_804429D4_de *owner) {
    struct Node_func_804429D4_de *node = owner->head;

    while (node != 0) {
        ((void (*)(struct Node_func_804429D4_de *, struct Owner_func_804429D4_de *))node->vtable[4])(node, owner);
        node = node->next;
    }
}

int func_80442A28_de(Node_func_80442A28_de **head) {
    Node_func_80442A28_de *node = *head;
    int count = 0;
    while (node != 0) {
        if (node->kind != 4) {
            count++;
        }
        node = node->next;
    }
    return count;
}
