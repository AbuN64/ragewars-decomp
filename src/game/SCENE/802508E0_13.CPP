#include "COMMON/MANAGER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESOURCELOCKSTATE.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "sdk/os.h"
#include "SCENE/802508E0_13.H"

extern OSMesgQueue D_80101140;

extern u32 __osDisableInt(void);


extern void func_80254990_de(void *, void *);


extern struct Shape_typemap_165 *func_802514A8_de(s32 arg0, u32 arg1);

extern void func_80254C70_de(s32 unused, void *object);

extern void func_80254AD0_de(s32 arg0, s32 arg1);

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

struct Shape_typemap_165 *func_802548B8_de(s32 arg0_unused, s32 byteCount, u32 allocationFlags) {
    struct Shape_typemap_165 *node;
    s32 result;

    node = func_802514A8_de(0, allocationFlags);
    if (node != 0) {
        node->field_8++;
        node->field_C |= 0x100;
        result = ((s32 (*)(s32, s32, s32, u32))func_80254B8C_de)(0, byteCount, (allocationFlags >> 5) & 1, allocationFlags);
        node->field_0 = result;
        if (result != 0) {
            node->field_4 = byteCount;
            node->field_C |= allocationFlags;
            func_80254C70_de(0, node);
            return node;
        }
        node->field_8--;
        if (node->field_8 == 0) {
            node->field_C &= ~0x100;
        }
        func_80254AD0_de(0, node);
        node = 0;
    }
    return node;
}
