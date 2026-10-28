#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/ARG.H"
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
extern OSMesgQueue D_80101140;
extern ResourceManagerState D_8010117C;


void Cache_RunCompactionPasses(s32 unused) {
    s32 temp_v1;
    s32 temp_v1_2;
    u32 mask;
    u32 temp_v0;
    s32 var_s0;
    ResourceManagerState *resourceManager;
    void *queueAddress;
    OSMesgQueue *receive;
    OSMesgQueue *send;

    resourceManager = &D_8010117C;
    var_s0 = 1;
    resourceManager->active = var_s0;
    resourceManager->count += var_s0;
    mask = __osDisableInt();
    temp_v1 = D_8010515C + var_s0;
    D_8010515C = temp_v1;
    if (temp_v1 != var_s0) {
        __osRestoreInt(mask);
        queueAddress = (char *)resourceManager - 0x3C;
        receive = queueAddress;
        osRecvMesg(receive, 0, var_s0);
        var_s0 = 0;
    } else {
        __osRestoreInt(mask);
        var_s0 = 0;
    }
    do {
        Cache_CompactResourceHeap(0, 0);
        var_s0++;
    } while (var_s0 < 10);
    temp_v0 = __osDisableInt();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        __osRestoreInt(temp_v0);
        queueAddress = &D_80101140;
        send = queueAddress;
        osSendMesg(send, 0, 1);
    } else {
        __osRestoreInt(temp_v0);
    }
}
#endif
