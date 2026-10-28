#include "COMMON/UNUSED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/S1_4.H"
#include "TYPES.H"
#include "sdk/os.h"
#include "IO/PIGETCMDQ.H"

typedef struct Queue Queue;

extern s32 osJamMesg(Queue *, void *, s32);




s32 Io_StartPeripheralDma(OSIoMesg *entry, s32 subtype, s32 direction, s32 deviceAddress,
                   s32 dramAddress, s32 transferSize, Opaque_OSMesgQueue *completionQueue) {
    s16 type;

    if (D_800D4360 == 0) {
        return -1;
    }
    type = 12;
    if (direction == 0) {
        type = 11;
    }
    entry->hdr.type = type;
    entry->hdr.pri = subtype;
    entry->hdr.retQueue = completionQueue;
    entry->dramAddr = (void *)dramAddress;
    entry->devAddr = deviceAddress;
    entry->size = transferSize;
    entry->piHandle = 0;
    if (subtype != 1) {
        return osSendMesg(Io_GetPeripheralCommandQueue(), (s32)entry, 0);
    }
    return osJamMesg(Io_GetPeripheralCommandQueue(), entry, 0);
}
