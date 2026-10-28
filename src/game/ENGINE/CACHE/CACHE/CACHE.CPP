#include "COMMON/RESOURCELOCKSTATE.H"
#include "TYPES.H"
#include "sdk/os.h"
#include "COMMON/MANAGER.H"
#include "COMMON/LONE/D_801051A0.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "SCENE/802508E0.H"
#include "COMMON/EXTERNS_18.H"
#include "SCENE/802508E0_4.H"

/* 802508E0_10.CPP */
extern s32 D_801047E0;
void Cache_SendCompletionMessage(s32 arg0, s32 message)
{
  osSendMesg(&D_801047E0, message, 1);
}

/* 802508E0_11.CPP */
extern void Cache_DetachResourceRequest(void *arg0, void *arg1);

extern void func_80255B2C_de(void *arg0, s32 arg1);

extern void Cache_ReleasePendingResourceEntry(s32 arg0, s32 arg1);

extern s32 D_80100570;

extern s32 D_80105180;

extern s32 D_80101190;

extern s32 D_80101194;

extern void func_80255FB8_de(void *, s32);

extern void Cache_ReleaseResourceCompletely(void *, void *);

extern char s_headerText;

/* Allocates a four-byte probe from Cache_RequestResource to read a count, frees it under the D_8010515C lock, then allocates count*4+15 rounded to eight bytes and stores its first word through arg1, returning the allocation. Adapted from Cache_RequestWordCountedResource with the null checks removed, tag 0x1B and flag 1 passed as the fifth and ninth arguments, and the constant 1 held in a local changed. */

extern s32 SetN64_LocatePackSection(void *arg0, s32 arg1, s32 arg2, s32 *arg3);

void Cache_ReplaceResourceBlock(s32 unused, struct Shape_typemap_165 **handle, struct Shape_typemap_165 *replacement) {
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
        Cache_DetachResourceRequest(0, node);
        func_80255B2C_de(&D_801051A0, node->field_0);
        Cache_ReleasePendingResourceEntry(0, node);
    }
    *handle = replacement;

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

void Cache_ReplaceResourcePairFirst(s32 arg0, NodePair80253E04 *resourcePair, Node80253610 *replacementResource) {
    extern OSMesgQueue D_80101140;
    s32 lockClaimCount;
    s32 lockReleaseCount;
    u32 mask;
    u32 releaseInterruptMask;
    NodePair80253E04 *pairToUpdate;
    Node80253610 *newFirstResource;
    Node80253610 *node;

    pairToUpdate = resourcePair;
    newFirstResource = replacementResource;
    mask = __osDisableInt();
    lockClaimCount = D_8010515C + 1;
    D_8010515C = lockClaimCount;
    if (lockClaimCount != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }

    node = pairToUpdate->first;
    if (node != 0) {
        node->references -= 1;
        if (node->references == 0) {
            node->flags &= ~0x100;
        }
    }
    node = pairToUpdate->second;
    if (node != 0) {
        node->references -= 1;
        if (node->references == 0) {
            node->flags &= ~0x100;
        }
    }
    pairToUpdate->first = newFirstResource;

    releaseInterruptMask = __osDisableInt();
    lockReleaseCount = D_8010515C - 1;
    D_8010515C = lockReleaseCount;
    if (lockReleaseCount != 0) {
        __osRestoreInt(releaseInterruptMask);
        osSendMesg(&D_80101140, 0, 1);
        return;
    }
    __osRestoreInt(releaseInterruptMask);
}

void Cache_TouchResourceByKey(s32 arg0, s32 resourceKey) {
    extern OSMesgQueue D_80101140;
    s32 lockClaimCount;
    s32 lockReleaseCount;
    u32 mask;
    u32 releaseInterruptMask;
    HashNode *node;
    void *value;
    void **out;

    mask = __osDisableInt();
    lockClaimCount = D_8010515C + 1;
    D_8010515C = lockClaimCount;
    if (lockClaimCount != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }

    out = &value;
    node = (HashNode *)((s32)D_80101194 +
        ((((resourceKey << 5) ^ ((u32)resourceKey >> 1) ^ ((u32)resourceKey >> 9) ^
           ((u32)resourceKey >> 17)) & D_80101190) * 0x10));
    if (node->key != resourceKey) {
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
    if (node->key == resourceKey) {
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

    releaseInterruptMask = __osDisableInt();
    lockReleaseCount = D_8010515C - 1;
    D_8010515C = lockReleaseCount;
    if (lockReleaseCount != 0) {
        __osRestoreInt(releaseInterruptMask);
        osSendMesg(&D_80101140, 0, 1);
        return;
    }
    __osRestoreInt(releaseInterruptMask);
}

void **Cache_RequestWordCountedResource(s32 arg0, void **arg1, s32 resourceKey, void *loadTag, s32 direct) {
    extern OSMesgQueue D_80101140;
    void **resource;
    s32 size;
    s32 counter;
    s32 counter2;
    u32 token;
    u32 token2;

    resource = Cache_RequestResource(0, resourceKey, resourceKey, 4, 0, 0, 0, &s_headerText, direct);
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
        Cache_ReleaseResourceCompletely(0, resource);
        token2 = __osDisableInt();
        counter2 = D_8010515C - 1;
        D_8010515C = counter2;
        if (counter2 != 0) {
            __osRestoreInt(token2);
            osSendMesg(&D_80101140, 0, 1);
        } else {
            __osRestoreInt(token2);
        }
        resource = Cache_RequestResource(0, resourceKey, resourceKey, ((size * 4) + 0xF) & ~7,
                                 0, 0, 0, loadTag, direct);
        if (resource != 0) {
            *arg1 = *resource;
            return resource;
        }
    }
    return 0;
}

s32 Cache_RequestWordCountedResourcePinned(s32 arg0, void **handle, s32 tempv0, void *loadTag) {
    extern OSMesgQueue D_80101140;
    void **resource;
    s32 size;
    s32 counter;
    s32 counter2;
    u32 token;
    u32 token2;
    s32 one = 1;

    resource = Cache_RequestResource(0, tempv0, tempv0, 4, 0x1B, 0, 0, &s_headerText, one);
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
    Cache_ReleaseResourceCompletely(0, resource);
    token2 = __osDisableInt();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        __osRestoreInt(token2);
        osSendMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(token2);
    }
    resource = Cache_RequestResource(0, tempv0, tempv0, ((size * 4) + 0xF) & ~7, 0x1B, 0, 0, loadTag, 1);
    *handle = *resource;
    return (s32)resource;
}

void **Cache_RequestPackSection(s32 arg0, void *handle, s32 sectionSelector, s32 tempv0, void *world, void *resourceTag, void *loadTag) {
    s32 sectionByteCount;
    s32 sectionSource;

    sectionSource = SetN64_LocatePackSection(handle, tempv0, sectionSelector, &sectionByteCount);
    return (void **)Cache_RequestResource(0, sectionSource, sectionSource, sectionByteCount, 0x1B, world, resourceTag, loadTag, 1);
}
