#include "span_1000/code_802BB15C.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802508E0.h"
#include "types.h"
/* Looks up a key in the hash table under the queue lock and, if found, bumps the object's reference count, flags it, stamps it and passes it to func_80255FB8_de, returning the object. Adapted from func_80253F8C_de, with the count/flag updates added and the object returned. */





extern s32 D_80100570;
extern OSMesgQueue D_80101140;



extern struct Shape_func_8021A2D4_de_2 D_80105180;

extern struct Shape_func_8021A2D4_de_2 D_80101190;

extern struct Shape_func_8021A2D4_de_2 D_80101194;

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);
extern void func_80255FB8_de(void *, s32);




void *func_802517B4_de(s32 arg0, s32 arg1) {
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_a0;
    u32 temp_v0;
    HashNode *node;
    void *value;
    void **out;
    struct IntrusiveList *object;

    temp_a0 = func_802BCF30_de();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        func_802BCF50_de(temp_a0);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(temp_a0);
    }

    out = &value;
    node = (HashNode *)((s32)D_80101194.field_0 +
        ((((arg1 << 5) ^ ((u32)arg1 >> 1) ^ ((u32)arg1 >> 9) ^
           ((u32)arg1 >> 17)) & D_80101190.field_0) * 0x10));
    if (node->key != arg1) {
        goto not_initial;
    }
    value = node->value;
    goto found;
loop_found:
    *out = node->value;
    goto found;
not_initial:
    value = 0;
    if (node == 0) {
        goto found;
    }
loop:
    if (node->key == arg1) {
        goto loop_found;
    }
    node = node->next;
    if (node != 0) {
        goto loop;
    }
found:

    object = 0;
    if (value != 0) {
        object = *(void **)value;
        object->prevOffset += 1;
        object->nextOffset |= 0x100;
        object->count = D_80105180.field_0;
        func_80255FB8_de(&D_80100570, object);
    }

    temp_v0 = func_802BCF30_de();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        func_802BCF50_de(temp_v0);
        func_802BB420_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(temp_v0);
    }
    return object;
}
