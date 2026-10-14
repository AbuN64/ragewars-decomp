#include "span_1000/code_8025A3EC.h"
#include "types.h"
#include "shared/func_8025B920_de_closed.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "packed_float.h"

/* Stops the selected sound slot and sets its release flag; split unsigned offset-to-pointer casts and a one-pass statement group preserve the separate table and offset schedule. */


extern void func_802B2D80_de(void *);
void func_8025B8BC_de(SlotRecAtB8 *base, s16 index)
{
  unsigned int offset = index * (sizeof(SlotRecAtB8));
  char *entry = (char *) offset;
  SlotRecAtB8 *slots;
  SlotRecAtB8 *selected;
  entry += (unsigned int) base;
  slots = base;
 do { func_802B2D80_de(0x84 + ((SlotRecAtB8 *) entry)->owner); entry = (char *) slots; entry += offset; selected = (SlotRecAtB8 *) entry; } while (0);
  selected->flags |= 8;
}

s32 func_8025B920_de(void *record, s16 value, s16 id) {
    s32 i;
    SlotCC *cur = ((RecordD90 *)record)->slots;

    for (i = 0; i < 16; cur++, i++) {
        if (cur->used != -1 && ((RecordD90 *)record)->header->local != i && cur->value == value && (cur->mode & 0x40) &&
            cur->id == id) {
            release(&((RecordD90 *)record)->slots[(s16)i]);
            return (s16)i;
        }
    }
    return -1;
}

/* Returns whether any of the sixteen occupied slots of a record, other than the one its header marks as local, holds the given value at slot offset 0xA8. */

s32 func_8025BA4C_de(RecordRecAt4V3 *record, s32 value) {
    s32 i;
    SlotRecAtA8 *slot = record->slots;

    for (i = 0; i < 16; i++, slot++) {
        if (slot->used != -1 && record->header->local != i && slot->value == value) {
            return 1;
        }
    }
    return 0;
}

extern void func_802B2F00_de(void *arg0, s16 arg1);
extern s32 func_802B2620_de(void *arg0);
extern void func_802B2F60_de(void *arg0);

void func_8025BA9C_de(s32 arg0, s16 arg1) {
    s32 base;
    s32 a0;
    void *s1;

    base = (arg1 * 0xCC) + arg0;
    base = base + 4;
    a0 = ((struct IntegerStateB4 *) base)->unk_B0;
    ((struct IntegerStateB4 *) base)->unk_AC = 1;
    ((struct IntegerStateB4 *) base)->unk_50 = 0;
    s1 = (void *)(a0 + 0x84);
    if (((struct IntegerStateB4 *) base)->unk_10 != ((struct func_80245A10_S1 *) a0)->unk104) {
        s32 idx = ((struct IntegerStateB4 *) base)->unk_0;
        s32 addr = a0 + idx * 2;
        func_802B2F00_de(s1, ((struct ObjRecAtDC *) addr)->unkDC);
        if (func_802B2620_de(s1) != 0) {
            func_802B2F60_de(s1);
        }
        ((struct IntegerStateB4 *) base)->unk_4 = -1;
    }
}

void func_8025BB3C_de(s32 a) {
    s32 var_v0;
    void *var_a0;
    var_a0 = a + 4;
    var_v0 = 0x10;
    do {
        ((SlotCC *)var_a0)->flag = 0;
        var_v0 -= 1;
        var_a0 += 0xCC;
    } while (var_v0 >= 0);
}

void func_8025BB5C_de(void *arg0, void *arg1, int arg2) {
    ((struct View_func_8025AE1C_de *)(arg0))->position = *(Triple *)arg1;
    ((struct View_func_8025AE1C_de *)(arg0))->tracked = (Triple *)arg2;
}

void func_8025BB7C_de(void *arg0, int arg1) {
    ((struct View_func_8025AE1C_de *)(arg0))->trackId = arg1;
}
extern void func_80259C5C_de(void *arg0, void *arg1, s32 arg2);
extern void func_80259F68_de(void *arg0, void *arg1, s32 arg2);
extern void *func_80258BF4_de(void *arg0, s32 arg1);
extern s32 func_80258D2C_de(void *arg0);
extern s16 func_80259B10_de(void *arg0, s32 arg1);

void func_8025BB84_de(void *arg0, void *arg1, s32 arg2) {
    f32 first;
    s16 index;
    s16 value;
    void *record;

    func_80259C5C_de(arg0, arg1, arg2);
    func_80259F68_de(arg0, arg1, arg2);
    ((struct View_func_8025AE1C_de *)(arg0))->priority = 0x40;
    index = ((struct Shared_Body *)(arg1))->kind;
    if (index != -1) {
        record = func_80258BF4_de(((struct View_func_8025AE1C_de *)(arg0))->context, index);
        ((struct View_func_8025AE1C_de *)(arg0))->envelope = *(SoundEnvelope *)record;
        first = RW_BITS_TO_FLOAT(((struct View_func_8025AE1C_de *)(arg0))->envelope.initial);
        ((struct View_func_8025AE1C_de *)(arg0))->step =
            (first - RW_BITS_TO_FLOAT(((struct View_func_8025AE1C_de *)(arg0))->envelope.target)) /
            ((struct View_func_8025AE1C_de *)(arg0))->envelope.frames;
        ((struct View_func_8025AE1C_de *)(arg0))->value =
            RW_BITS_TO_FLOAT(((struct View_func_8025AE1C_de *)(arg0))->envelope.initial);
        ((struct View_func_8025AE1C_de *)(arg0))->priority =
            (s16)(s32)RW_BITS_TO_FLOAT(((struct View_func_8025AE1C_de *)(arg0))->envelope.initial);
        ((struct View_func_8025AE1C_de *)(arg0))->sweeping = 1;
        return;
    }

    ((struct View_func_8025AE1C_de *)(arg0))->sweeping = 0;
    if (((struct View_func_8025AE1C_de *)(arg0))->trackId < 0x100) {
        if (((struct View_func_8025AE1C_de *)(arg0))->fixed == 0 &&
            func_80258D2C_de(((struct View_func_8025AE1C_de *)(arg0))->context) != 0) {
            value = (s8)((ContextRecAt2BC0 *)((struct View_func_8025AE1C_de *)arg0)->context)->field2B94;
            goto store_value;
        }
    } else if (((struct View_func_8025AE1C_de *)(arg0))->fixed == 0 &&
               func_80258D2C_de(((struct View_func_8025AE1C_de *)(arg0))->context) != 0) {
        value = func_80259B10_de(&((struct View_func_8025AE1C_de *)(arg0))->position,
            ((struct View_func_8025AE1C_de *)arg0)->context->result);
store_value:
        ((struct View_func_8025AE1C_de *)(arg0))->priority = value;
    }
}


extern void func_8025AE1C_de(void *arg0);
void func_8025BD00_de(void **arg0) {
    s32 var_s0;
    s32 var_s2;
    char *var_s1;

    var_s2 = 0;
    var_s1 = (char *)((RecordD90 *)arg0)->slots;
    var_s0 = 0;
    do {
        if (((SlotCC *)var_s1)->used != -1 && ((HeaderRecAt102 *)(*arg0))->local != var_s0) {
            func_8025AE1C_de(var_s1);
            var_s2 += 1;
        }
        var_s0 += 1;
        var_s1 += 0xCC;
    } while (var_s0 < 0x10);
    D_800CBAFC = var_s2;
    if (D_800CBB00 < var_s2) {
        D_800CBB00 = var_s2;
    }
}
