#include "include_asm.h"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/MANAGER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ENTRYRECAT18V3.H"
#include "TEXTURE/80254CE4.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "sdk/os.h"
#include "RESMGR/802A0888.H"

extern void func_802BAC90_de(void *thread, s32 id, void *entry, void *argument, void *stack, s32 priority);
extern void func_802BB750_de(void *thread);

void func_802550F0_de(ResourceLoadWorker *worker, s32 id) {
    osCreateMesgQueue(&worker->requests, worker->messages, 0x80);
    func_802A001C_de(worker->stack, id, 0x1000);
    func_802BAC90_de(worker, id, &D_00255280, worker,
                     worker->stack + sizeof(worker->stack), D_800CD8AC_de);
    func_802BB750_de(worker);
}

extern s32 func_802BB5F0_de(void *, s32);
extern s32 func_802BB160_de(OSMesgQueue *queue, void *message, s32 block);







s32 func_80255170_de(ResourceLoadWorker *arg0, ResourceLoadRequest *message) {
    OSMesgQueue sp10;
    s32 sp28;
    void *sp2C;
    s32 temp;

    osCreateMesgQueue(&sp10, &sp28, 1);
    temp = D_800CD8B8_de;
    message->replyQueue = &sp10;
    D_800CD704 = 2;
    func_802BB5F0_de(arg0, temp);
    func_802BB160_de(&arg0->requests, message, 1);
    func_802BB2A0_de(&sp10, &sp2C, 1);
    return 1;
}

s32 func_802551FC_de(ResourceLoadWorker *worker, ResourceRequest *request, void *replyQueue) {
    request->replyQueue = replyQueue;
    return ~func_802BB420_de(&worker->requests, request, 0) != 0;
}

extern s32 func_802BB5F0_de(void *, s32);





s32 func_80255228_de(ResourceLoadWorker *resourceLoadWorker) {
    if (resourceLoadWorker->requests.validCount != 0) {
        do {
            func_802BB5F0_de(resourceLoadWorker, D_800CD8B8_de);
        } while (resourceLoadWorker->requests.validCount != 0);
    }
    return func_802BB5F0_de(resourceLoadWorker, D_800CD8AC_de);
}

#if defined(VERSION_US)
void func_80255220_us(ResourceLoadWorker *worker)
{
    ResourceRequest *request;
    extern s32 D_800D2978;

    for (;;) {
        func_802BB2A0_de(&worker->requests, (void **)&request, 1);
        worker->timestamp = D_800D2978;
        request->dispatch(request->argument, request);
        func_802BB420_de(request->replyQueue, request, 1);
    }
}
#endif

#if defined(VERSION_EU)
void func_80255240_eu(ResourceLoadWorker *worker)
{
    ResourceRequest *request;
    extern s32 D_800D2978;

    for (;;) {
        func_802BB2A0_de(&worker->requests, (void **)&request, 1);
        worker->timestamp = D_800D2978;
        request->dispatch(request->argument, request);
        func_802BB420_de(request->replyQueue, request, 1);
    }
}
#endif

#if defined(VERSION_DE)
void func_80255280_de(ResourceLoadWorker *worker)
{
    ResourceRequest *request;
    extern s32 D_800D2978;

    for (;;) {
        func_802BB2A0_de(&worker->requests, (void **)&request, 1);
        worker->timestamp = D_800D2978;
        request->dispatch(request->argument, request);
        func_802BB420_de(request->replyQueue, request, 1);
    }
}
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
void func_80255270_eu_x(ResourceLoadWorker *worker)
{
    ResourceRequest *request;
    extern s32 D_800D2978;

    for (;;) {
        func_802BB2A0_de(&worker->requests, (void **)&request, 1);
        worker->timestamp = D_800D2978;
        request->dispatch(request->argument, request);
        func_802BB420_de(request->replyQueue, request, 1);
    }
}
#endif
