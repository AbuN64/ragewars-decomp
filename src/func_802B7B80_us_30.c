#include "common/unused.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B8CCC.h"
#include "types.h"



typedef struct Queue Queue;

extern s32 D_800D4360;
extern Queue *func_802B8DA0_de(void);
extern s32 func_802BB160_de(Queue *, void *, s32);
extern s32 func_802BB420_de(Queue *, s32, s32);




s32 func_802B8CF0_de(OSIoMesg *entry, s32 subtype, s32 arg2, s32 arg3,
                   s32 arg4, s32 arg5, Opaque_OSMesgQueue *arg6) {
    s16 type;

    if (D_800D4360 == 0) {
        return -1;
    }
    type = 12;
    if (arg2 == 0) {
        type = 11;
    }
    entry->hdr.type = type;
    entry->hdr.pri = subtype;
    entry->hdr.retQueue = arg6;
    entry->dramAddr = (void *)arg4;
    entry->devAddr = arg3;
    entry->size = arg5;
    entry->piHandle = 0;
    if (subtype != 1) {
        return func_802BB420_de(func_802B8DA0_de(), (s32)entry, 0);
    }
    return func_802BB160_de(func_802B8DA0_de(), entry, 0);
}
