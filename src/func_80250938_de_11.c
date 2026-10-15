#include "span_1000/code_802508E0.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802536F4.h"
#include "span_1000/code_802BB15C.h"
#include "types.h"

extern u32 func_802BCF30_de(void);

extern void func_802BCF50_de(u32 arg0);

extern void func_80254DD0_de(void *arg0, void *arg1);

extern void func_80255B2C_de(void *arg0, s32 arg1);

extern void func_80254AD0_de(s32 arg0, s32 arg1);

extern char D_801051A0;

extern void func_802BCF50_de(u32);

extern s32 D_80100570;

extern s32 D_80105180;

extern s32 D_80101190;

extern s32 D_80101194;

extern void func_80255FB8_de(void *, s32);

extern void func_80254990_de(void *, void *);

extern char D_800C3EA0_de;

/* Allocates a four-byte probe from func_8025193C_de to read a count, frees it under the D_8010515C lock, then allocates count*4+15 rounded to eight bytes and stores its first word through arg1, returning the allocation. Adapted from func_802540F4_de with the null checks removed, tag 0x1B and flag 1 passed as the fifth and ninth arguments, and the constant 1 held in a local changed. */





extern s32 func_8028FE3C_de(void *arg0, s32 arg1, s32 arg2, s32 *arg3);

void func_80253D10_de(s32 unused, struct Shape_typemap_165 **arg1, struct Shape_typemap_165 *arg2) {
    extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);
    extern s32 D_80101140;
    s32 counter;
    s32 counter2;
    s32 count;
    struct Shape_typemap_165 *node;
    u32 token;
    u32 token2;

    token = func_802BCF30_de();
    counter = D_8010515C + 1;
    D_8010515C = counter;
    if (counter != 1) {
        func_802BCF50_de(token);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(token);
    }

    node = *arg1;
    node->field_C &= ~2;
    if (node->field_8 != 0) {
    loop_1:
        do {
            count = node->field_8 - 1;
            node->field_8 = count;
            if (count != 0) {
                goto loop_1;
            }
            node->field_C &= ~0x100;
        } while (node->field_8 != 0);
    }
    if (!(node->field_C & 0x702)) {
        func_80254DD0_de(0, node);
        func_80255B2C_de(&D_801051A0, node->field_0);
        func_80254AD0_de(0, node);
    }
    *arg1 = arg2;

    token2 = func_802BCF30_de();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        func_802BCF50_de(token2);
        func_802BB420_de(&D_80101140, 0, 1);
        return;
    }
    func_802BCF50_de(token2);
}

void func_80253E64_de(s32 arg0, NodePair80253E04 *arg1, Node80253610 *arg2) {
    extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);
    extern OSMesgQueue D_80101140;
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_a0;
    u32 temp_v0;
    NodePair80253E04 *temp_s0;
    Node80253610 *temp_s1;
    Node80253610 *node;

    temp_s0 = arg1;
    temp_s1 = arg2;
    temp_a0 = func_802BCF30_de();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        func_802BCF50_de(temp_a0);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(temp_a0);
    }

    node = temp_s0->first;
    if (node != 0) {
        node->references -= 1;
        if (node->references == 0) {
            node->flags &= ~0x100;
        }
    }
    node = temp_s0->second;
    if (node != 0) {
        node->references -= 1;
        if (node->references == 0) {
            node->flags &= ~0x100;
        }
    }
    temp_s0->first = temp_s1;

    temp_v0 = func_802BCF30_de();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        func_802BCF50_de(temp_v0);
        func_802BB420_de(&D_80101140, 0, 1);
        return;
    }
    func_802BCF50_de(temp_v0);
}

void func_80253F8C_de(s32 arg0, s32 arg1) {
    extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);
    extern OSMesgQueue D_80101140;
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_a0;
    u32 temp_v0;
    HashNode *node;
    void *value;
    void **out;

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
    node = (HashNode *)((s32)D_80101194 +
        ((((arg1 << 5) ^ ((u32)arg1 >> 1) ^ ((u32)arg1 >> 9) ^
           ((u32)arg1 >> 17)) & D_80101190) * 0x10));
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

    if (value != 0) {
        void *object = *(void **)value;
        ((CachedResource *)object)->stamp = D_80105180;
        func_80255FB8_de(&D_80100570, object);
    }

    temp_v0 = func_802BCF30_de();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        func_802BCF50_de(temp_v0);
        func_802BB420_de(&D_80101140, 0, 1);
        return;
    }
    func_802BCF50_de(temp_v0);
}

void **func_802540F4_de(s32 arg0, void **arg1, s32 arg2, void *arg3, s32 arg4) {
    extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);
    extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
    extern OSMesgQueue D_80101140;
    void **resource;
    s32 size;
    s32 counter;
    s32 counter2;
    u32 token;
    u32 token2;

    resource = func_8025193C_de(0, arg2, arg2, 4, 0, 0, 0, &D_800C3EA0_de, arg4);
    if (resource != 0) {
        size = **(s32 **)resource;
        token = func_802BCF30_de();
        counter = D_8010515C + 1;
        D_8010515C = counter;
        if (counter != 1) {
            func_802BCF50_de(token);
            func_802BB2A0_de(&D_80101140, 0, 1);
        } else {
            func_802BCF50_de(token);
        }
        func_80254990_de(0, resource);
        token2 = func_802BCF30_de();
        counter2 = D_8010515C - 1;
        D_8010515C = counter2;
        if (counter2 != 0) {
            func_802BCF50_de(token2);
            func_802BB420_de(&D_80101140, 0, 1);
        } else {
            func_802BCF50_de(token2);
        }
        resource = func_8025193C_de(0, arg2, arg2, ((size * 4) + 0xF) & ~7,
                                 0, 0, 0, arg3, arg4);
        if (resource != 0) {
            *arg1 = *resource;
            return resource;
        }
    }
    return 0;
}

s32 func_80254284_de(s32 arg0, void **arg1, s32 arg2, void *arg3) {
    extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);
    extern void **func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
    extern OSMesgQueue D_80101140;
    void **resource;
    s32 size;
    s32 counter;
    s32 counter2;
    u32 token;
    u32 token2;
    s32 one = 1;

    resource = func_8025193C_de(0, arg2, arg2, 4, 0x1B, 0, 0, &D_800C3EA0_de, one);
    size = **(s32 **)resource;
    token = func_802BCF30_de();
    counter = D_8010515C + one;
    D_8010515C = counter;
    if (counter != one) {
        func_802BCF50_de(token);
        func_802BB2A0_de(&D_80101140, 0, one);
    } else {
        func_802BCF50_de(token);
    }
    func_80254990_de(0, resource);
    token2 = func_802BCF30_de();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        func_802BCF50_de(token2);
        func_802BB420_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(token2);
    }
    resource = func_8025193C_de(0, arg2, arg2, ((size * 4) + 0xF) & ~7, 0x1B, 0, 0, arg3, 1);
    *arg1 = *resource;
    return (s32)resource;
}

void **func_80254408_de(s32 arg0, void *arg1, s32 arg2, s32 arg3, void *arg4, void *arg5, void *arg6) {
    extern void * *func_8025193C_de(s32, s32, s32, s32, s32, void *, void *, void *, s32);
    s32 sp28;
    s32 temp_v0;

    temp_v0 = func_8028FE3C_de(arg1, arg3, arg2, &sp28);
    func_8025193C_de(0, temp_v0, temp_v0, sp28, 0x1B, arg4, arg5, arg6, 1);
}
