#include "COMMON/MANAGER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESOURCELOCKSTATE.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "sdk/os.h"
#include "SCENE/CACHE_FREEMEMORY.H"

/* 802508E0_12.CPP */
extern OSMesgQueue D_80101140;

extern struct Shape_typemap_165 *Cache_AcquireResourceNodeWithEviction(s32, u32);

extern void Cache_InsertResourceByAddress(s32 unused, void *object);

extern void Cache_ReleasePendingResourceEntry(s32 unused0, s32 arg1);

/** Read the global word at VRAM 0x8010517C. */

/** Read the global word at VRAM 0x8010513C. */

struct Shape_typemap_165 *Cache_AllocResourceBlock(s32 arg0, void *handle, s32 total) {
    struct Shape_typemap_165 *node;
    s32 result;
    s32 counter;
    s32 counter2;
    u32 token;
    u32 token2;
    u32 flags;

    token = __osDisableInt();
    counter = D_8010515C + 1;
    D_8010515C = counter;
    if (counter != 1) {
        __osRestoreInt(token);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(token);
    }
    flags = ((ResourceLoadRequest *)handle)->mode;
    node = Cache_AcquireResourceNodeWithEviction(0, flags);
    if (node != 0) {
        node->field_8++;
        node->field_C |= 0x100;
        result = ((s32 (*)(s32, s32, s32, u32))Cache_AllocateHeapWithEviction)(0, total, (flags >> 5) & 1, flags);
        node->field_0 = result;
        if (result != 0) {
            node->field_4 = total;
            node->field_C |= flags;
            Cache_InsertResourceByAddress(0, node);
        } else {
            node->field_8--;
            if (node->field_8 == 0) {
                node->field_C &= ~0x100;
            }
            Cache_ReleasePendingResourceEntry(0, node);
            node = 0;
        }
    }
    token2 = __osDisableInt();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        __osRestoreInt(token2);
        osSendMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(token2);
    }
    return node;
}

struct Shape_typemap_165 *func_80254600_de(s32 unused0, s32 unused1, s32 byteCount) {
    struct Shape_typemap_165 *node;
    s32 result;
    s32 counter;
    s32 counter2;
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
    node = Cache_AcquireResourceNodeWithEviction(0, 0x22U);
    if (node != 0) {
        node->field_8++;
        node->field_C |= 0x100;
        result = ((s32 (*)(s32, s32, s32, u32))Cache_AllocateHeapWithEviction)(0, byteCount, 1, 0x22U);
        node->field_0 = result;
        if (result != 0) {
            node->field_4 = byteCount;
            node->field_C |= 0x22;
            Cache_InsertResourceByAddress(0, node);
        } else {
            node->field_8--;
            if (node->field_8 == 0) {
                node->field_C &= ~0x100;
            }
            Cache_ReleasePendingResourceEntry(0, node);
            node = 0;
        }
    }
    token2 = __osDisableInt();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        __osRestoreInt(token2);
        osSendMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(token2);
    }
    return node;
}

/** Replace the global object word. */
void Cache_SetResourceActivityState(unsigned int value) {
    extern unsigned int D_8010117C;
    D_8010117C = value;
}

int Cache_GetResourceActivityState(void) {
    extern unsigned int D_8010117C;
    return D_8010117C;
}

/** Read the global word at VRAM 0x80105108. */

int func_8025478C_de(void) {
    return D_80101108;
}

int func_8025479C_de(void) {
    return D_8010513C;
}

/** Return the global word at D_80104580. */

int func_802547AC_de(void) {
    return D_80104580;
}

/** Read the global word at VRAM 0x80104580. */

int func_802547BC_de(void) {
    return D_80104580;
}

int func_802547CC_de(void) {
    return D_80104580;
}

int func_802547DC_de(void) {
    return 0;
}

/* 802508E0_13.CPP */
extern void Cache_ReleaseResourceCompletely(void *, void *);

/* Frees a block from Cache_AllocateMemory: releases the heap node stored 16 bytes before it under the heap lock. */
void Cache_FreeMemory(void *allocation) {
    s32 lockUsers;
    s32 remainingLockUsers;
    u32 mask;
    u32 unlockInterruptMask;
    void *resource;

    resource = ((void **)allocation)[-4];
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

struct Shape_typemap_165 *func_802548B8_de(s32 arg0_unused, s32 byteCount, u32 allocationFlags) {
    struct Shape_typemap_165 *node;
    s32 result;

    node = Cache_AcquireResourceNodeWithEviction(0, allocationFlags);
    if (node != 0) {
        node->field_8++;
        node->field_C |= 0x100;
        result = ((s32 (*)(s32, s32, s32, u32))Cache_AllocateHeapWithEviction)(0, byteCount, (allocationFlags >> 5) & 1, allocationFlags);
        node->field_0 = result;
        if (result != 0) {
            node->field_4 = byteCount;
            node->field_C |= allocationFlags;
            Cache_InsertResourceByAddress(0, node);
            return node;
        }
        node->field_8--;
        if (node->field_8 == 0) {
            node->field_C &= ~0x100;
        }
        Cache_ReleasePendingResourceEntry(0, node);
        node = 0;
    }
    return node;
}
