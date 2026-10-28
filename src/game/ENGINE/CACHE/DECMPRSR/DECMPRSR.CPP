#include "include_asm.h"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/MANAGER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ENTRYRECAT18V3.H"
#include "TEXTURE/CACHE_RECYCLELOADREQUEST.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "sdk/os.h"
#include "RESMGR/802A0888.H"

extern void osCreateThread(void *thread, s32 id, void *entry, void *argument, void *stack, s32 priority);
extern void osStartThread(void *thread);

void func_802550F0_de(ResourceLoadWorker *worker, s32 id) {
    osCreateMesgQueue(&worker->requests, worker->messages, 0x80);
    XPlus_FillMemory(worker->stack, id, 0x1000);
    osCreateThread(worker, id, &D_00255280, worker,
                     worker->stack + sizeof(worker->stack), D_800CD8AC_de);
    osStartThread(worker);
}

extern s32 Scene_SetThreadPriority(void *, s32);
extern s32 osJamMesg(OSMesgQueue *queue, void *message, s32 block);







s32 func_80255170_de(ResourceLoadWorker *worker, ResourceLoadRequest *message) {
    OSMesgQueue completionQueue;
    s32 replyMessageStorage;
    void *completedRequest;
    s32 temp;

    osCreateMesgQueue(&completionQueue, &replyMessageStorage, 1);
    temp = D_800CD8B8_de;
    message->replyQueue = &completionQueue;
    D_800CD704 = 2;
    Scene_SetThreadPriority(worker, temp);
    osJamMesg(&worker->requests, message, 1);
    osRecvMesg(&completionQueue, &completedRequest, 1);
    return 1;
}

s32 func_802551FC_de(ResourceLoadWorker *worker, ResourceRequest *request, void *replyQueue) {
    request->replyQueue = replyQueue;
    return ~osSendMesg(&worker->requests, request, 0) != 0;
}






s32 func_80255228_de(ResourceLoadWorker *resourceLoadWorker) {
    if (resourceLoadWorker->requests.validCount != 0) {
        do {
            Scene_SetThreadPriority(resourceLoadWorker, D_800CD8B8_de);
        } while (resourceLoadWorker->requests.validCount != 0);
    }
    return Scene_SetThreadPriority(resourceLoadWorker, D_800CD8AC_de);
}

#if defined(VERSION_US)
void func_80255220_us(ResourceLoadWorker *worker)
{
    ResourceRequest *request;
    extern s32 D_800D2978;

    for (;;) {
        osRecvMesg(&worker->requests, (void **)&request, 1);
        worker->timestamp = D_800D2978;
        request->dispatch(request->argument, request);
        osSendMesg(request->replyQueue, request, 1);
    }
}
#endif

#if defined(VERSION_EU)
void func_80255240_eu(ResourceLoadWorker *worker)
{
    ResourceRequest *request;
    extern s32 D_800D2978;

    for (;;) {
        osRecvMesg(&worker->requests, (void **)&request, 1);
        worker->timestamp = D_800D2978;
        request->dispatch(request->argument, request);
        osSendMesg(request->replyQueue, request, 1);
    }
}
#endif

#if defined(VERSION_DE)
void func_80255280_de(ResourceLoadWorker *worker)
{
    ResourceRequest *request;
    extern s32 D_800D2978;

    for (;;) {
        osRecvMesg(&worker->requests, (void **)&request, 1);
        worker->timestamp = D_800D2978;
        request->dispatch(request->argument, request);
        osSendMesg(request->replyQueue, request, 1);
    }
}
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
void func_80255270_eu_x(ResourceLoadWorker *worker)
{
    ResourceRequest *request;
    extern s32 D_800D2978;

    for (;;) {
        osRecvMesg(&worker->requests, (void **)&request, 1);
        worker->timestamp = D_800D2978;
        request->dispatch(request->argument, request);
        osSendMesg(request->replyQueue, request, 1);
    }
}
#endif
