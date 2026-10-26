#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/EXTERNS_2.H"
#include "sdk/libultra/io/pirawread.H"
#include "sdk/os.h"
#include "RESMGR/802A0888.H"

#if !(defined(VERSION_US))
extern OSPiHandle_s *D_800D437C;
extern u32 __osDisableInt(void);

OSPiHandle_s *func_802B8F48_de(void)
{
    u32 domain = 0;
    u32 saveMask;
    OSPiHandle_s *h = &D_801486C0;
    OSPiHandle_s **table;

    if (h->baseAddress == 0xB0000000)
        return h;

    h->type = 0;
    h->baseAddress = 0xB0000000;
    func_802B9B20_de(0, &domain);
    h->latency = domain & 0xff;
    h->pulse = (domain >> 8) & 0xff;
    h->pageSize = (domain >> 0x10) & 0xf;
    h->relDuration = (domain >> 0x14) & 0xf;
    h->domain = 0;
    h->speed = 0;

    Resmgr_FillMemory(&h->transferInfo, 0, sizeof(h->transferInfo));

    saveMask = __osDisableInt();
    table = &D_800D437C;
    h->next = *table;
    *table = h;
    __osRestoreInt(saveMask);

    return h;
}
#endif

#if defined(VERSION_EU)
INCLUDE_ASM("span_1000", func_802B92B0_eu);
#endif

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_802B9010_de);
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
typedef struct PiRequest {
    u16 type;
    u8 priority, status;
    OSMesgQueue *replyQueue;
    void *dramAddress;
    u32 deviceAddress, size;
    OSPiHandle_s *handle;
} PiRequest;
typedef struct PiManager {
    s32 active;
    void *thread;
    OSMesgQueue *commandQueue, *eventQueue, *accessQueue;
    s32 (*dma)(s32, u32, void *, u32);
    s32 (*extendedDma)(OSPiHandle_s *, s32, u32, void *, u32);
} PiManager;
typedef struct PiDiskBlock {
    s32 error;
    u8 *dramAddress;
    u32 c2Address, sectorSize;
    u8 remaining[0x14];
} PiDiskBlock;
typedef struct PiDiskTransfer {
    u32 command;
    u16 mode, blockNumber;
    s32 sectorNumber;
    u32 deviceAddress, control, sequenceControl;
    PiDiskBlock blocks[2];
} PiDiskTransfer;
typedef struct PiDiskHandle {
    OSPiHandle_s *next;
    u8 type, latency, pageSize, relDuration, pulse, domain;
    u32 baseAddress, speed;
    PiDiskTransfer transfer;
} PiDiskHandle;
extern void func_802BB3D0_de(s32);
extern void func_802BB850_eu(s32);
extern s32 func_802B9730_de(OSPiHandle_s *, u32, u32);
extern s32 func_802B9590_de(OSPiHandle_s *, u32, u32 *);
extern void func_802BBC20_de(void);

/* The PI manager thread: serves DMA and 64DD disk requests from the command queue for ever. */
void System_RunPiManager(void *argument) {
    PiManager *manager = argument;
    PiRequest *request = 0;
    OSMesg access, event;
    PiDiskHandle *handle;
    PiDiskBlock *block;
    PiDiskTransfer *transfer;
    u32 status;
    s32 twoBlocks, result;

    for (;;) {
        osRecvMesg(manager->commandQueue, (OSMesg *)&request, 1);
        handle = (PiDiskHandle *)request->handle;
        if (handle != 0 && handle->type == 2 &&
            (transfer = &handle->transfer)->command <= 1) {
            block = &transfer->blocks[handle->transfer.blockNumber];
            handle->transfer.sectorNumber = -1;
            if (handle->transfer.mode != 3) {
                block->dramAddress -= block->sectorSize;
            }
            twoBlocks = 0;
            if (handle->transfer.mode == 2) {
                twoBlocks = ((PiDiskTransfer *)request->handle->transferInfo)->command == 0;
            }
            osRecvMesg(manager->accessQueue, &access, 1);
            func_802BB3D0_de(0x100401);
            func_802B9730_de(request->handle, 0x05000510, handle->transfer.control | 0x80000000);
            diskEvent:
            {
                osRecvMesg(manager->eventQueue, &event, 1);
                handle = (PiDiskHandle *)request->handle;
                transfer = &handle->transfer;
                block = &transfer->blocks[handle->transfer.blockNumber];
                if (block->error == 29) {
                    func_802B9730_de((OSPiHandle_s *)handle, 0x05000510, handle->transfer.control | 0x10000000);
                    func_802B9730_de(request->handle, 0x05000510, handle->transfer.control);
                    func_802B9590_de(request->handle, 0x05000508, &status);
                    if (status & 0x02000000) {
                        func_802B9730_de(request->handle, 0x05000510, handle->transfer.control | 0x01000000);
                    }
                    block->error = 4;
                    *(volatile u32 *)0xA4600010 = 2;
                    func_802BB850_eu(0x100C01);
                }
                osSendMesg(request->replyQueue, request, 0);
                if (twoBlocks == 1 &&
                    ((PiDiskTransfer *)request->handle->transferInfo)->blocks[0].error == 0) {
                    twoBlocks = 0;
                    goto diskEvent;
                }
            }
            osSendMesg(manager->accessQueue, 0, 0);
            if (((PiDiskTransfer *)request->handle->transferInfo)->blockNumber == 1) {
                func_802BBC20_de();
            }
            continue;
        }
        switch (request->type) {
        case 11:
            osRecvMesg(manager->accessQueue, &access, 1);
            result = manager->dma(0, request->deviceAddress, request->dramAddress, request->size);
            break;
        case 12:
            osRecvMesg(manager->accessQueue, &access, 1);
            result = manager->dma(1, request->deviceAddress, request->dramAddress, request->size);
            break;
        case 15:
            osRecvMesg(manager->accessQueue, &access, 1);
            result = manager->extendedDma(request->handle, 0, request->deviceAddress, request->dramAddress, request->size);
            break;
        case 16:
            osRecvMesg(manager->accessQueue, &access, 1);
            result = manager->extendedDma(request->handle, 1, request->deviceAddress, request->dramAddress, request->size);
            break;
        case 10:
            osSendMesg(request->replyQueue, request, 0);
            /* A loopback message has no DMA completion to wait for. */
        default:
            result = -1;
            break;
        }
        if (result == 0) {
            osRecvMesg(manager->eventQueue, &event, 1);
            osSendMesg(request->replyQueue, request, 0);
            osSendMesg(manager->accessQueue, 0, 0);
        }
    }
}
#if defined(VERSION_EU_X)
unsigned int System_RunPiManager_padding_BA288[2] = {
    0x02202821, 0x3C068015,
};
#endif
#if defined(VERSION_US_REV1)
unsigned int System_RunPiManager_padding_BF098[2] = {
    0x02202821, 0x3C068015,
};
#endif

#endif
