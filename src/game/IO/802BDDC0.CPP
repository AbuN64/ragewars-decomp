#include "COMMON/UNUSED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/S1_4.H"
#include "TYPES.H"
#include "sdk/os.h"
#include "IO/802BDE70.H"

typedef struct Queue Queue;

extern s32 func_802BB160_de(Queue *, void *, s32);




s32 func_802B8CF0_de(OSIoMesg *entry, s32 subtype, s32 direction, s32 deviceAddress,
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
        return osSendMesg(func_802B8DA0_de(), (s32)entry, 0);
    }
    return func_802BB160_de(func_802B8DA0_de(), entry, 0);
}
