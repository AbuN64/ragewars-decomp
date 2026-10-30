#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/ALFXPARAM.H"
#include "../../include/libultra/io/pirawread.H"
#include "../../include/os.h"
#include "UI/X_FILES/X_PLUS.H"

extern OSPiHandle_s *g_peripheralHandleList;

OSPiHandle_s *osCartRomInit(void)
{
    u32 domain = 0;
    u32 saveMask;
    OSPiHandle_s *h = &g_diskPiHandle;
    OSPiHandle_s **table;

    if (h->baseAddress == 0xB0000000)
        return h;

    h->type = 0;
    h->baseAddress = 0xB0000000;
    osPiRawReadIo(0, &domain);
    h->latency = domain & 0xff;
    h->pulse = (domain >> 8) & 0xff;
    h->pageSize = (domain >> 0x10) & 0xf;
    h->relDuration = (domain >> 0x14) & 0xf;
    h->domain = 0;
    h->speed = 0;

    XPlus_FillMemory(&h->transferInfo.bytes, 0, sizeof(h->transferInfo.bytes));

    saveMask = __osDisableInt();
    table = &g_peripheralHandleList;
    h->next = *table;
    *table = h;
    __osRestoreInt(saveMask);

    return h;
}

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1) || defined(VERSION_US)
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
extern void __osResetGlobalIntMask(s32);
extern void __osSetGlobalIntMask(s32);
extern s32 osEPiRawWriteIo(OSPiHandle_s *, u32, u32);
extern s32 osEPiRawReadIo(OSPiHandle_s *, u32, u32 *);
extern void osYieldThread(void);

/* The PI manager thread: serves DMA and 64DD disk requests from the command queue for ever. */
void __osDevMgrMain(void *argument) {
    PiManager *manager = argument;
    PiRequest *request = 0;
    OSMesg access, event;
    OSPiHandle_s *handle;
    PiDiskBlock *block;
    PiDiskTransfer *transfer;
    u32 status;
    s32 twoBlocks, result;

    for (;;) {
        osRecvMesg(manager->commandQueue, (OSMesg *)&request, 1);
        handle = (OSPiHandle_s *)request->handle;
        if (handle != 0 && handle->type == 2 &&
            (transfer = &handle->transferInfo.transfer)->command <= 1) {
            block = &transfer->blocks[handle->transferInfo.transfer.blockNumber];
            handle->transferInfo.transfer.sectorNumber = -1;
            if (handle->transferInfo.transfer.mode != 3) {
                block->dramAddress -= block->sectorSize;
            }
            twoBlocks = 0;
            if (handle->transferInfo.transfer.mode == 2) {
                twoBlocks = ((PiDiskTransfer *)request->handle->transferInfo.bytes)->command == 0;
            }
            osRecvMesg(manager->accessQueue, &access, 1);
            __osResetGlobalIntMask(0x100401);
            osEPiRawWriteIo(request->handle, 0x05000510, handle->transferInfo.transfer.control | 0x80000000);
            diskEvent:
            {
                osRecvMesg(manager->eventQueue, &event, 1);
                handle = (OSPiHandle_s *)request->handle;
                transfer = &handle->transferInfo.transfer;
                block = &transfer->blocks[handle->transferInfo.transfer.blockNumber];
                if (block->error == 29) {
                    osEPiRawWriteIo((OSPiHandle_s *)handle, 0x05000510, handle->transferInfo.transfer.control | 0x10000000);
                    osEPiRawWriteIo(request->handle, 0x05000510, handle->transferInfo.transfer.control);
                    osEPiRawReadIo(request->handle, 0x05000508, &status);
                    if (status & 0x02000000) {
                        osEPiRawWriteIo(request->handle, 0x05000510, handle->transferInfo.transfer.control | 0x01000000);
                    }
                    block->error = 4;
                    *(volatile u32 *)0xA4600010 = 2;
                    __osSetGlobalIntMask(0x100C01);
                }
                osSendMesg(request->replyQueue, request, 0);
                if (twoBlocks == 1 &&
                    ((PiDiskTransfer *)request->handle->transferInfo.bytes)->blocks[0].error == 0) {
                    twoBlocks = 0;
                    goto diskEvent;
                }
            }
            osSendMesg(manager->accessQueue, 0, 0);
            if (((PiDiskTransfer *)request->handle->transferInfo.bytes)->blockNumber == 1) {
                osYieldThread();
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
#if VERSION_EU
unsigned int System_RunPiManager_padding_BA248[2] = { 0xAFB00018, 0x00808021 };
#endif
#if VERSION_DE
unsigned int System_RunPiManager_padding_B9FA8[2] = { 0x00808021, 0xAFB10014 };
#endif

#endif
#if defined(VERSION_US)
unsigned int System_RunPiManager_padding_B9ED8[2] = { 0x53535F48U, 0x4149525FU };
#endif
