#include "COMMON/MANAGER.H"
#include "COMMON/LONE/D_801051A0.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESOURCELOCKSTATE.H"
#include "SCENE/802508E0.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "sdk/os.h"
#include "SCENE/802508E0_4.H"

extern u32 __osDisableInt(void);


extern void func_80254DD0_de(void *arg0, void *arg1);

extern void func_80255B2C_de(void *arg0, s32 arg1);

extern void func_80254AD0_de(s32 arg0, s32 arg1);



extern s32 D_80100570;

extern s32 D_80105180;

extern s32 D_80101190;

extern s32 D_80101194;

extern void func_80255FB8_de(void *, s32);

extern void func_80254990_de(void *, void *);

extern char D_800C3EA0_de;

/* Allocates a four-byte probe from Scene_RequestResource to read a count, frees it under the D_8010515C lock, then allocates count*4+15 rounded to eight bytes and stores its first word through arg1, returning the allocation. Adapted from func_802540F4_de with the null checks removed, tag 0x1B and flag 1 passed as the fifth and ninth arguments, and the constant 1 held in a local changed. */





extern s32 Render_LocatePackSection(void *arg0, s32 arg1, s32 arg2, s32 *arg3);

void Scene_ReplaceResourceBlock(s32 unused, struct Shape_typemap_165 **handle, struct Shape_typemap_165 *arg2) {
    extern OSMesgQueue D_80101140;
    s32 counter;
    s32 counter2;
    s32 count;
    struct Shape_typemap_165 *node;
    u32 token;
    u32 token2;

    token = __osDisableInt();
    counter = D_8010515C + 1;
    D_8010515C = counter;
    if (counter != 1) {
        __osRestoreInt(token);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(token);
    }

    node = *handle;
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
    *handle = arg2;

    token2 = __osDisableInt();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        __osRestoreInt(token2);
        osSendMesg(&D_80101140, 0, 1);
        return;
    }
    __osRestoreInt(token2);
}

void func_80253E64_de(s32 arg0, NodePair80253E04 *arg1, Node80253610 *arg2) {
    extern OSMesgQueue D_80101140;
    s32 temp_v1;
    s32 temp_v1_2;
    u32 mask;
    u32 temp_v0;
    NodePair80253E04 *temp_s0;
    Node80253610 *temp_s1;
    Node80253610 *node;

    temp_s0 = arg1;
    temp_s1 = arg2;
    mask = __osDisableInt();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
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

    temp_v0 = __osDisableInt();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        __osRestoreInt(temp_v0);
        osSendMesg(&D_80101140, 0, 1);
        return;
    }
    __osRestoreInt(temp_v0);
}

void func_80253F8C_de(s32 arg0, s32 arg1) {
    extern OSMesgQueue D_80101140;
    s32 temp_v1;
    s32 temp_v1_2;
    u32 mask;
    u32 temp_v0;
    HashNode *node;
    void *value;
    void **out;

    mask = __osDisableInt();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
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

    temp_v0 = __osDisableInt();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        __osRestoreInt(temp_v0);
        osSendMesg(&D_80101140, 0, 1);
        return;
    }
    __osRestoreInt(temp_v0);
}

void **func_802540F4_de(s32 arg0, void **arg1, s32 arg2, void *arg3, s32 direct) {
    extern OSMesgQueue D_80101140;
    void **resource;
    s32 size;
    s32 counter;
    s32 counter2;
    u32 token;
    u32 token2;

    resource = Scene_RequestResource(0, arg2, arg2, 4, 0, 0, 0, &D_800C3EA0_de, direct);
    if (resource != 0) {
        size = **(s32 **)resource;
        token = __osDisableInt();
        counter = D_8010515C + 1;
        D_8010515C = counter;
        if (counter != 1) {
            __osRestoreInt(token);
            osRecvMesg(&D_80101140, 0, 1);
        } else {
            __osRestoreInt(token);
        }
        func_80254990_de(0, resource);
        token2 = __osDisableInt();
        counter2 = D_8010515C - 1;
        D_8010515C = counter2;
        if (counter2 != 0) {
            __osRestoreInt(token2);
            osSendMesg(&D_80101140, 0, 1);
        } else {
            __osRestoreInt(token2);
        }
        resource = Scene_RequestResource(0, arg2, arg2, ((size * 4) + 0xF) & ~7,
                                 0, 0, 0, arg3, direct);
        if (resource != 0) {
            *arg1 = *resource;
            return resource;
        }
    }
    return 0;
}

s32 func_80254284_de(s32 arg0, void **handle, s32 tempv0, void *arg3) {
    extern OSMesgQueue D_80101140;
    void **resource;
    s32 size;
    s32 counter;
    s32 counter2;
    u32 token;
    u32 token2;
    s32 one = 1;

    resource = Scene_RequestResource(0, tempv0, tempv0, 4, 0x1B, 0, 0, &D_800C3EA0_de, one);
    size = **(s32 **)resource;
    token = __osDisableInt();
    counter = D_8010515C + one;
    D_8010515C = counter;
    if (counter != one) {
        __osRestoreInt(token);
        osRecvMesg(&D_80101140, 0, one);
    } else {
        __osRestoreInt(token);
    }
    func_80254990_de(0, resource);
    token2 = __osDisableInt();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        __osRestoreInt(token2);
        osSendMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(token2);
    }
    resource = Scene_RequestResource(0, tempv0, tempv0, ((size * 4) + 0xF) & ~7, 0x1B, 0, 0, arg3, 1);
    *handle = *resource;
    return (s32)resource;
}

void **func_80254408_de(s32 arg0, void *handle, s32 arg2, s32 tempv0, void *world, void *arg5, void *arg6) {
    s32 sp28;
    s32 temp_v0;

    temp_v0 = Render_LocatePackSection(handle, tempv0, arg2, &sp28);
    return (void **)Scene_RequestResource(0, temp_v0, temp_v0, sp28, 0x1B, world, arg5, arg6, 1);
}
