#include "COMMON/MANAGER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESOURCELOCKSTATE.H"
#include "SCENE/802508E0.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "SCENE/802508E0_2.H"
#include "SCENE/802508E0_9.H"
#include "sdk/os.h"

extern u32 __osDisableInt(void);


extern struct Shape_typemap_165 *func_802548B8_de(s32, s32, u32, void *);

extern s8 D_801051A0;

extern struct Shape_typemap_165 *func_802514A8_de(s32, u32);

extern s32 func_80255630_de(s8 *, void *, s32);

extern void func_80254C70_de(s32 unused, void *object);

extern void func_80254AD0_de(s32 arg0, s32 arg1);

extern void func_80254DA4_de(void *, Node80253610 *);

extern void func_80254990_de(void *, void *);

extern void func_802511AC_de(s32);

extern s32 func_80254B58_de(s32, s32, s32);

extern void func_802515F0_de(s32, s32);


extern s32 D_80101134[];

struct Shape_typemap_165 *Scene_AllocateResource(s32 arg0, s32 byteCount, u32 allocationFlags, void *arg3) {
    extern OSMesgQueue D_80101140;
    struct Shape_typemap_165 *resource;
    s32 lockUsers;
    s32 remainingLockUsers;
    u32 mask;
    u32 unlockInterruptMask;
    s32 requestedBytes;
    u32 requestedFlags;
    void *temp_s2;

    requestedBytes = byteCount;
    requestedFlags = allocationFlags;
    temp_s2 = arg3;
    mask = __osDisableInt();
    lockUsers = D_8010515C + 1;
    D_8010515C = lockUsers;
    if (lockUsers != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    resource = func_802548B8_de(0, requestedBytes, requestedFlags, temp_s2);
    unlockInterruptMask = __osDisableInt();
    remainingLockUsers = D_8010515C - 1;
    D_8010515C = remainingLockUsers;
    if (remainingLockUsers != 0) {
        __osRestoreInt(unlockInterruptMask);
        osSendMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(unlockInterruptMask);
    }
    return resource;
}

struct Shape_typemap_165 *Scene_AllocateResourceAt(void *arg0, void *arg1, s32 arg2, char *name) {
    extern OSMesgQueue D_80101140;
    struct Shape_typemap_165 *var_s0;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    u32 mask;
    u32 temp_v0_2;

    mask = __osDisableInt();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    var_s0 = func_802514A8_de(0, 0U);
    if (var_s0 != 0) {
        temp_v0 = func_80255630_de(&D_801051A0, arg1, arg2);
        var_s0->field_0 = temp_v0;
        if (temp_v0 != 0) {
            var_s0->field_4 = arg2;
            var_s0->field_C |= 3;
            func_80254C70_de(0, var_s0);
        } else {
            func_80254AD0_de(0, var_s0);
            var_s0 = 0;
        }
    }
    temp_v0_2 = __osDisableInt();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        __osRestoreInt(temp_v0_2);
        osSendMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(temp_v0_2);
    }
    return var_s0;
}

void Scene_LockResource(void *arg0, Node80253610 *resource) {
    extern OSMesgQueue D_80101140;
    s32 lockUsers;
    s32 remainingLockUsers;
    u32 mask;
    u32 unlockInterruptMask;
    Node80253610 *resourceNode;

    resourceNode = resource;
    mask = __osDisableInt();
    lockUsers = D_8010515C + 1;
    D_8010515C = lockUsers;
    if (lockUsers != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    func_80254DA4_de(0, resourceNode);
    resourceNode->references += 1;
    resourceNode->flags |= 0x100;
    unlockInterruptMask = __osDisableInt();
    remainingLockUsers = D_8010515C - 1;
    D_8010515C = remainingLockUsers;
    if (remainingLockUsers != 0) {
        __osRestoreInt(unlockInterruptMask);
        osSendMesg(&D_80101140, 0, 1);
        return;
    }
    __osRestoreInt(unlockInterruptMask);
}

void Scene_UnlockResource(void *arg0, Node80253610 *resource) {
    extern OSMesgQueue D_80101140;
    s32 lockUsers;
    s32 remainingLockUsers;
    u32 mask;
    u32 unlockInterruptMask;
    Node80253610 *resourceNode;

    resourceNode = resource;
    mask = __osDisableInt();
    lockUsers = D_8010515C + 1;
    D_8010515C = lockUsers;
    if (lockUsers != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    resourceNode->references -= 1;
    if (resourceNode->references == 0) {
        resourceNode->flags &= ~0x100;
    }
    unlockInterruptMask = __osDisableInt();
    remainingLockUsers = D_8010515C - 1;
    D_8010515C = remainingLockUsers;
    if (remainingLockUsers != 0) {
        __osRestoreInt(unlockInterruptMask);
        osSendMesg(&D_80101140, 0, 1);
        return;
    }
    __osRestoreInt(unlockInterruptMask);
}

void Scene_ReleaseResource(void *arg0, void *resource) {
    extern OSMesgQueue D_80101140;
    s32 lockUsers;
    s32 remainingLockUsers;
    u32 mask;
    u32 unlockInterruptMask;

    mask = __osDisableInt();
    lockUsers = D_8010515C + 1;
    D_8010515C = lockUsers;
    if (lockUsers != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    func_80254990_de(0, resource);
    unlockInterruptMask = __osDisableInt();
    remainingLockUsers = D_8010515C - 1;
    D_8010515C = remainingLockUsers;
    if (remainingLockUsers != 0) {
        __osRestoreInt(unlockInterruptMask);
        osSendMesg(&D_80101140, 0, 1);
        return;
    }
    __osRestoreInt(unlockInterruptMask);
}

void func_80253908_de(s32 unusedHeap) {
    extern OSMesgQueue D_80101140;
    s32 lockUsers;
    s32 remainingLockUsers;
    u32 mask;
    u32 unlockInterruptMask;

    mask = __osDisableInt();
    lockUsers = D_8010515C + 1;
    D_8010515C = lockUsers;
    if (lockUsers != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    func_802511AC_de(0);
    while (func_80254B58_de(0, 0, 0) != 0) {
    }
    func_802515F0_de(0, 1);
    unlockInterruptMask = __osDisableInt();
    remainingLockUsers = D_8010515C - 1;
    D_8010515C = remainingLockUsers;
    if (remainingLockUsers != 0) {
        __osRestoreInt(unlockInterruptMask);
        osSendMesg(&D_80101140, 0, 1);
        return;
    }
    __osRestoreInt(unlockInterruptMask);
}

void func_802539EC_de(s32 unused, s32 arg1) {
    s32 temp_v1;
    s32 temp_v1_2;
    ResourceLockState *base;
    u32 mask;
    u32 temp_v0;

    mask = __osDisableInt();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&((ResourceLockState *)&D_801005A8)->waitQueue, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    base = (ResourceLockState *)&D_801005A8;
    base->slot = arg1;
    D_80100598[arg1] = 1;
    temp_v0 = __osDisableInt();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        __osRestoreInt(temp_v0);
        osSendMesg(&base->waitQueue, 0, 1);
        return;
    }
    __osRestoreInt(temp_v0);
}

s32 func_80253AD4_de(void) {
    s32 temp_v1;
    s32 temp_v1_2;
    s32 *base;
    u32 mask;
    u32 temp_v0;
    s32 result;

    mask = __osDisableInt();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        __osRestoreInt(mask);
        osRecvMesg(((char *)&D_801005A8 + 0xB98), 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    base = &D_801005A8;
    result = *(s32 *)((char *)D_80100598 + (*base << 2));
    *base = -1;
    temp_v0 = __osDisableInt();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        __osRestoreInt(temp_v0);
        osSendMesg((char *)base + 0xB98, 0, 1);
    } else {
        __osRestoreInt(temp_v0);
    }
    return result;
}

void Scene_MarkResourceInUse(s32 unused0, Node80253610 *resource) {
    extern OSMesgQueue D_80101140;
    s32 index;
    s32 mask;
    s32 flags;
    s32 counter;
    s32 counter2;
    s32 *base;
    u32 token;
    u32 token2;

    base = &D_801005A8;
    index = *base;
    token = __osDisableInt();
    counter = D_8010515C + 1;
    D_8010515C = counter;
    if (counter != 1) {
        __osRestoreInt(token);
        osRecvMesg(((char *)base + 0xB98), 0, 1);
    } else {
        __osRestoreInt(token);
    }

    if (D_80100598[index] != 0) {
        mask = 0x200;
        if (index != 0) {
            mask = 0x400;
        }
        flags = resource->flags;
        if (!(flags & mask)) {
            resource->flags = flags | mask;
            D_80101134[index]++;
        }
    }

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
