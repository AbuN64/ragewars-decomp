#include "sdk/thread_queue.h"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "TEXTURE/CARTRIDGE_DMA_AND_AUDIO_TIMING_VIEWS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/S1.H"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "TYPES.H"
#include "sdk/os.h"
#include "RESMGR/X_PLUS.H"
#include "include_asm.h"
#include "SYSTEM/LIST.H"
#include "SYSTEM/LIST.H"

extern void osSetEventMesg(s32 event, s32 queue, s32 message);


extern void osCreateThread(s32 thread, s32 threadId, void *entry, s32 arg, s32 stackTop, s32 priority);


extern char g_packedCodeAddress24_0025657C;

void *Cartridge_AcquireReadRequest(CartridgeReadWorker *cartridgeReadWorker);

extern s32 osJamMesg(void *messageQueue, void *message, s32 waitMode);

typedef struct Queue Queue;

extern s32 osJamMesg(void *, void *, s32);


void Cartridge_StartReadWorker(s32 workerAddress, s32 count) {
    s32 s0;
    s32 s1;

    osCreateMesgQueue(workerAddress + 0x230, workerAddress + 0x248, 0x200);
    s0 = workerAddress + 0xA48;
    osCreateMesgQueue(s0, workerAddress + 0xA60, 1);
    osSetEventMesg(8, s0, 0x7D1);
    List_InitializeIntrusive(workerAddress + 0x5068, 0x18, 0x1C);
    List_InitializeIntrusive(workerAddress + 0x507C, 0x18, 0x1C);
    s1 = 0;
    s0 = 0xE68;
    do {
        ((struct LinkedWorldFlagsView *) (workerAddress + s0))->flags = 0;
        List_AppendIntrusive(workerAddress + 0x5068, workerAddress + s0);
        s1 += 1;
        s0 += 0x20;
    } while (s1 < 0x210);
    XPlus_FillMemory(workerAddress + 0xA68, count, 0x400);
    osCreateThread(workerAddress, count, &g_packedCodeAddress24_0025657C, workerAddress, workerAddress + 0xE68, g_cartridgeReadWorkerPriority);
    osStartThread((void *)workerAddress);
}

void Cartridge_ReadChunksAndWait(struct CartridgeReadWorker *cartridgeReadWorker, u32 sourceAddress, s32 byteCount, void *extra) {
    char queue[0x18];
    s32 queue_init;
    s32 completed;
    s32 remaining;
    s32 length;
    Chunk *chunk;

    osCreateMesgQueue(queue, (s32) &queue_init, 1);
    remaining = byteCount;
    do {
        chunk = Cartridge_AcquireReadRequest(cartridgeReadWorker);
        length = 0x2000;
        if (chunk == 0) {
            break;
        }
        chunk->source = sourceAddress + (byteCount - remaining);
        chunk->destination = (char *) extra + (byteCount - remaining);
        if ((u32) remaining < 0x2001U) {
            length = remaining;
        }
        chunk->length = length;
        chunk->queue = queue;
        osJamMesg(&cartridgeReadWorker->requestQueueStorage, chunk, 1);
        osRecvMesg(queue, &completed, 1);
        remaining -= length;
    } while (remaining != 0);
}

void Cartridge_SubmitReadChunks(struct CartridgeReadWorker *worker, u32 source, s32 length, void *destination,
                   Queue *queue, s32 value, s32 direct) {
    s32 remaining;
    s32 chunk_length;
    Chunk *chunk;

    if (direct != 0) {
        chunk = Cartridge_AcquireReadRequest(worker);
        if (chunk != 0) {
            chunk->source = source;
            chunk->destination = destination;
            chunk->length = length;
            chunk->queue = queue;
            chunk->value = value;
            osJamMesg(&worker->requestQueueStorage, chunk, 1);
        }
    } else {
        remaining = length;
        do {
            chunk = Cartridge_AcquireReadRequest(worker);
            chunk_length = 0x2000;
            if (chunk == 0) {
                break;
            }
            chunk->source = source + (length - remaining);
            chunk->destination = (char *)destination + (length - remaining);
            if ((u32)remaining < 0x2001U) {
                chunk_length = remaining;
            }
            remaining -= chunk_length;
            chunk->length = chunk_length;
            if (remaining != 0) {
                chunk->queue = 0;
                chunk->value = 0;
            } else {
                chunk->queue = queue;
                chunk->value = value;
            }
            osSendMesg(&worker->requestQueueStorage, (s32)chunk, 1);
        } while ((chunk != 0) && (remaining != 0));
    }
}

#if defined(VERSION_US_REV1)
/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "TYPES.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "sdk/os.h"
/* Cartridge read thread loop: waits on the manager's request queue; a 0xBEEFDEAD message arms a
 * periodic timer that posts 0xDEADBEEF, a 0xDEADBEEF tick runs Libultra_RunDebugLinkCommands when TextLoad_IsArtsendTexturePreviewEnabled
 * reports work, and any other message is a read request whose buffer is invalidated, read from the
 * device through Gamecore_StartRawPeripheralDma, awaited on the completion queue, flushed, acknowledged to its reply
 * queue when one is given and finally retired through Cartridge_ReleaseReadRequest. */





extern void osSetTimer(void *, u64, u64, void *, void *);
extern int TextLoad_IsArtsendTexturePreviewEnabled(void);
extern void Libultra_RunDebugLinkCommands(void);
extern void osWritebackDCache(void *, s32);
extern s32 Gamecore_StartRawPeripheralDma(s32, u32, void *, u32);
extern void osInvalDCache(void *, s32);
extern void Cartridge_ReleaseReadRequest(s32, CartridgeReadRequest *);



void Cartridge_RunReadWorkerRev1(s32 cartridgeReadWorker) {
    struct OSTimer_s timer;
    struct CartridgeReadRequest *request;
    void *done;

    for (;;) {
        osRecvMesg(&((struct CartridgeReadWorker *)(cartridgeReadWorker))->requestQueueStorage, &request, 1);
        if (request == (struct CartridgeReadRequest *)0xBEEFDEAD) {
            osSetTimer(&timer, 0, 0x393870, &((struct CartridgeReadWorker *)(cartridgeReadWorker))->requestQueueStorage, (void *)0xDEADBEEF);
        } else if (request == (struct CartridgeReadRequest *)0xDEADBEEF) {
            if (TextLoad_IsArtsendTexturePreviewEnabled() != 0) {
                Libultra_RunDebugLinkCommands();
            }
        } else {
            osWritebackDCache(request->buffer, request->size);
            Gamecore_StartRawPeripheralDma(0, request->devAddr, request->buffer, request->size);
            osRecvMesg(&((struct CartridgeReadWorker *)(cartridgeReadWorker))->completionQueueStorage, &done, 1);
            osInvalDCache(request->buffer, request->size);
            if (request->replyQueue != 0) {
                osSendMesg(request->replyQueue, request->replyMsg, 1);
            }
            Cartridge_ReleaseReadRequest(cartridgeReadWorker, request);
        }
    }
}
#endif

#if !(defined(VERSION_US_REV1))
/* Receives read requests, transfers and acknowledges each one. The timer-message
 * handling belongs to the separate US-rev1 routine, which this item does not contain. */

extern void osWritebackDCache(void *, s32);
extern s32 Gamecore_StartRawPeripheralDma(s32, u32, void *, u32);
extern void osInvalDCache(void *, s32);
extern void Cartridge_ReleaseReadRequest(s32, CartridgeReadRequest *);

void Cartridge_RunReadWorker(CartridgeReadWorker *worker) {
    CartridgeReadRequest *request;
    void *done;

    for (;;) {
        osRecvMesg(&worker->requestQueueStorage, &request, 1);
        osWritebackDCache(request->buffer, request->size);
        Gamecore_StartRawPeripheralDma(0, request->devAddr, request->buffer, request->size);
        osRecvMesg(&worker->completionQueueStorage, &done, 1);
        osInvalDCache(request->buffer, request->size);
        if (request->replyQueue != 0) {
            osSendMesg(request->replyQueue, request->replyMsg, 1);
        }
        Cartridge_ReleaseReadRequest(worker, request);
    }
}
#endif

void *Cartridge_AcquireReadRequest(CartridgeReadWorker *cartridgeReadWorker) {
    u32 mask;
    void *head;

    mask = __osDisableInt();
    head = cartridgeReadWorker->available.head;
    if (head != 0) {
        List_RemoveIntrusive(&cartridgeReadWorker->available, head);
        ((CartridgeReadRequest *)head)->active = 1;
        List_PrependIntrusive(&cartridgeReadWorker->pending, head);
    }
    __osRestoreInt(mask);
    return head;
}







void Cartridge_ReleaseReadRequest(s32 worker, CartridgeReadRequest *request) {
    u32 mask;

    mask = __osDisableInt();
    List_RemoveIntrusive(&((CartridgeReadWorker *)worker)->pending, request);
    request->active = 0;
    List_PrependIntrusive(&((CartridgeReadWorker *)worker)->available, request);
    __osRestoreInt(mask);
}

#if defined(VERSION_US)
unsigned int func_80256688_de_padding_57288[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_802566E8_de_padding_572D8[2] = {
    0x24050001, 0x8E442B48,
};
#endif

#if defined(VERSION_EU)
unsigned int func_802566E8_de_padding_572A8[2] = {
    0x12A00005, 0x00000000,
};
#endif

#if defined(VERSION_US)
unsigned int g_LoaderWords1[46] = {
    0x0278320C, 0x27BDFFE8, 0xAFB00010, 0x00808021, 0xAFBF0014, 0x8E02001C, 0x10400023, 0x00000000,
    0x0C0AF398, 0x00000000, 0x00402021, 0x8E03001C, 0x24020001, 0x24630001, 0x10620009, 0xAE03001C,
    0x0C0AF3A0, 0x00000000, 0x02002021, 0x00002821, 0x0C0AEC74, 0x24060001, 0x080959BD, 0x00000000,
    0x0C0AF3A0, 0x00000000, 0x0C0AF398, 0x00000000, 0x8E03001C, 0x2463FFFF, 0x10600009, 0xAE03001C,
    0x0C0AF3A0, 0x00402021, 0x02002021, 0x00002821, 0x0C0AECD4, 0x24060001, 0x080959CD, 0x00000000,
    0x0C0AF3A0, 0x00402021, 0x8FBF0014, 0x8FB00010, 0x03E00008, 0x27BD0018,
};
#endif
