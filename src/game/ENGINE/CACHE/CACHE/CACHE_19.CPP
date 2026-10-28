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



extern struct Shape_typemap_165 *func_802548B8_de(s32, s32, u32, void *);

extern s8 D_801051A0;

extern struct Shape_typemap_165 *Cache_AcquireResourceNodeWithEviction(s32, u32);

extern s32 func_80255630_de(s8 *, void *, s32);

extern void Cache_InsertResourceByAddress(s32 unused, void *object);

extern void Cache_ReleasePendingResourceEntry(s32 arg0, s32 arg1);

extern void Cache_TouchResource(void *, Node80253610 *);

extern void Cache_ReleaseResourceCompletely(void *, void *);

extern void Cache_WaitForResourceSlotRelease(s32);

extern s32 Cache_SelectAllocationCandidate(s32, s32, s32);



extern s32 D_80101134[];

struct Shape_typemap_165 *Cache_AllocateResource(s32 arg0, s32 byteCount, u32 allocationFlags, void *arg3) {
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

struct Shape_typemap_165 *Cache_AllocateResourceAt(void *arg0, void *requestedAddress, s32 byteCount, char *name) {
    extern OSMesgQueue D_80101140;
    struct Shape_typemap_165 *allocatedResource;
    s32 allocatedAddress;
    s32 lockClaimCount;
    s32 lockReleaseCount;
    u32 mask;
    u32 releaseInterruptMask;

    mask = __osDisableInt();
    lockClaimCount = D_8010515C + 1;
    D_8010515C = lockClaimCount;
    if (lockClaimCount != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    allocatedResource = Cache_AcquireResourceNodeWithEviction(0, 0U);
    if (allocatedResource != 0) {
        allocatedAddress = func_80255630_de(&D_801051A0, requestedAddress, byteCount);
        allocatedResource->field_0 = allocatedAddress;
        if (allocatedAddress != 0) {
            allocatedResource->field_4 = byteCount;
            allocatedResource->field_C |= 3;
            Cache_InsertResourceByAddress(0, allocatedResource);
        } else {
            Cache_ReleasePendingResourceEntry(0, allocatedResource);
            allocatedResource = 0;
        }
    }
    releaseInterruptMask = __osDisableInt();
    lockReleaseCount = D_8010515C - 1;
    D_8010515C = lockReleaseCount;
    if (lockReleaseCount != 0) {
        __osRestoreInt(releaseInterruptMask);
        osSendMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(releaseInterruptMask);
    }
    return allocatedResource;
}

void Cache_LockResource(void *arg0, Node80253610 *resource) {
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
    Cache_TouchResource(0, resourceNode);
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

void Cache_UnlockResource(void *arg0, Node80253610 *resource) {
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

void Cache_ReleaseResource(void *arg0, void *resource) {
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
    Cache_ReleaseResourceCompletely(0, resource);
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
    Cache_WaitForResourceSlotRelease(0);
    while (Cache_SelectAllocationCandidate(0, 0, 0) != 0) {
    }
    Cache_CompactResourceHeap(0, 1);
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

void Cache_SelectResourceSlot(s32 unused, s32 resourceSlot) {
    s32 lockClaimCount;
    s32 lockReleaseCount;
    ResourceLockState *base;
    u32 mask;
    u32 releaseInterruptMask;

    mask = __osDisableInt();
    lockClaimCount = D_8010515C + 1;
    D_8010515C = lockClaimCount;
    if (lockClaimCount != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&((ResourceLockState *)&D_801005A8)->waitQueue, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    base = (ResourceLockState *)&D_801005A8;
    base->slot = resourceSlot;
    D_80100598[resourceSlot] = 1;
    releaseInterruptMask = __osDisableInt();
    lockReleaseCount = D_8010515C - 1;
    D_8010515C = lockReleaseCount;
    if (lockReleaseCount != 0) {
        __osRestoreInt(releaseInterruptMask);
        osSendMesg(&base->waitQueue, 0, 1);
        return;
    }
    __osRestoreInt(releaseInterruptMask);
}

s32 Cache_FinishResourceSlot(void) {
    s32 lockClaimCount;
    s32 lockReleaseCount;
    s32 *base;
    u32 mask;
    u32 releaseInterruptMask;
    s32 result;

    mask = __osDisableInt();
    lockClaimCount = D_8010515C + 1;
    D_8010515C = lockClaimCount;
    if (lockClaimCount != 1) {
        __osRestoreInt(mask);
        osRecvMesg(((char *)&D_801005A8 + 0xB98), 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    base = &D_801005A8;
    result = *(s32 *)((char *)D_80100598 + (*base << 2));
    *base = -1;
    releaseInterruptMask = __osDisableInt();
    lockReleaseCount = D_8010515C - 1;
    D_8010515C = lockReleaseCount;
    if (lockReleaseCount != 0) {
        __osRestoreInt(releaseInterruptMask);
        osSendMesg((char *)base + 0xB98, 0, 1);
    } else {
        __osRestoreInt(releaseInterruptMask);
    }
    return result;
}

void Cache_MarkResourceInUse(s32 unused0, Node80253610 *resource) {
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
