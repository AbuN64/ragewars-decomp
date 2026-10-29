#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "COMMON/CONTROLLER_MOTOR_STATE.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "COMMON/MANAGER.H"
#include "SCENE/RESOURCE_BINDING_AND_FADE_VIEWS.H"
#include "SCENE/CACHE_INITIALIZERESOURCECACHE.H"
#include "sdk/os.h"

#if (defined(VERSION_US)) && !defined(NON_MATCHING)
INCLUDE_ASM("span_1000", Cache_RunCompactionPasses);
#endif

#if !(defined(VERSION_US)) || defined(NON_MATCHING)
/* Fuzzy draft: the other versions' body, not diffed against this version's asm. */
extern OSMesgQueue g_resourceHeapLockQueue;
extern ResourceManagerState g_resourceActivityState;


void Cache_RunCompactionPasses(s32 unused) {
    s32 pendingPasses;
    s32 remainingPasses;
    u32 mask;
    u32 interruptMask;
    s32 passIndex;
    ResourceManagerState *resourceManager;
    void *queueAddress;
    OSMesgQueue *receive;
    OSMesgQueue *send;

    resourceManager = &g_resourceActivityState;
    passIndex = 1;
    resourceManager->active = passIndex;
    resourceManager->count += passIndex;
    mask = __osDisableInt();
    pendingPasses = g_resourceHeapLockUsers + passIndex;
    g_resourceHeapLockUsers = pendingPasses;
    if (pendingPasses != passIndex) {
        __osRestoreInt(mask);
        queueAddress = (char *)resourceManager - 0x3C;
        receive = queueAddress;
        osRecvMesg(receive, 0, passIndex);
        passIndex = 0;
    } else {
        __osRestoreInt(mask);
        passIndex = 0;
    }
    do {
        Cache_CompactResourceHeap(0, 0);
        passIndex++;
    } while (passIndex < 10);
    interruptMask = __osDisableInt();
    remainingPasses = g_resourceHeapLockUsers - 1;
    g_resourceHeapLockUsers = remainingPasses;
    if (remainingPasses != 0) {
        __osRestoreInt(interruptMask);
        queueAddress = &g_resourceHeapLockQueue;
        send = queueAddress;
        osSendMesg(send, 0, 1);
    } else {
        __osRestoreInt(interruptMask);
    }
}
#endif
