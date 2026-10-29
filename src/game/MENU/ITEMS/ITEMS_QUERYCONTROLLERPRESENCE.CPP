#include "include_asm.h"
#include "COMMON/CONTROLLER_MOTOR_STATE.H"
#include "COMMON/PLAYER_POOL_AND_INODE_CACHE_VIEWS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"

#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CONTROLLER_MOTOR_STATE.H"
#include "TYPES.H"
#include "COMMON/PLAYER_POOL_AND_INODE_CACHE_VIEWS.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"
void __osPfsRequestData(u8 cmd);

s32 Items_QueryControllerPresence(OSMesgQueue *queue, s8 *presentMask) {
    ControllerInitStatusBytes sp10;
    void *sp20;
    u8 sp24;
    ControllerInitStatusBytes *retryStatus;
    ControllerInitStatusBytes *presenceStatus;
    s32 dmaResult;
    s32 retryChannel;
    s32 presenceChannel;
    s32 retriesRemaining;
    s8 connectedMask;

    connectedMask = 0;
    retriesRemaining = 3;
    __osSiGetAccess();
    do {
        __osPfsRequestData(0U);
        __osSiRawStartDma(1, (u8 *)&g_controllerStatusPifBuffer);
        osRecvMesg(queue, &sp20, 1);
        dmaResult = __osSiRawStartDma(0, (u8 *)&g_controllerStatusPifBuffer);
        osRecvMesg(queue, &sp20, 1);
        Items_DecodeControllerStatusReplies(&sp24, &sp10);
        retryChannel = 0;
        if (g_controllerChannelCount[0] != 0) {
            retryStatus = &sp10;
loop_3:
            if (retryStatus->team & 4) {
                retryChannel += 1;
                retryStatus += 4;
                if (retryChannel < (s32) g_controllerChannelCount[0]) {
                    goto loop_3;
                }
            } else {
                retriesRemaining -= 1;
            }
        }
        if (retryChannel == g_controllerChannelCount[0]) {
            retriesRemaining = 0;
        }
    } while (retriesRemaining > 0);
    presenceChannel = 0;
    if (g_controllerChannelCount[0] != 0) {
        presenceStatus = &sp10;
        do {
            if ((presenceStatus->slot == 0) && (presenceStatus->team & 1)) {
                connectedMask |= 1 << presenceChannel;
            }
            presenceChannel += 1;
            presenceStatus += 4;
        } while (presenceChannel < (s32) g_controllerChannelCount[0]);
    }
    __osSiRelAccess();
    *presentMask = connectedMask;
    return dmaResult;
}
#else
INCLUDE_ASM("ovl_frontendMenu", Items_QueryControllerPresence);
#endif
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
extern void __osPfsRequestData(u8);

s32 Items_DetectConnectedPaks(OSMesgQueue *queue, u8 *pattern) {
    ControllerInitStatusBytes data[4];
    void *dummy;
    u8 bitpattern;
    s32 i;
    u8 *count;
    s32 ret;
    s32 patternmask = 0;
    s32 retry = 3;
    __osSiGetAccess();
    do {
        __osPfsRequestData(0);
        __osSiRawStartDma(1, &g_controllerStatusPifBuffer);
        osRecvMesg(queue, &dummy, 1);
        ret = __osSiRawStartDma(0, &g_controllerStatusPifBuffer);
        osRecvMesg(queue, &dummy, 1);
        Items_DecodeControllerStatusReplies(&bitpattern, data);
        for (i = 0; i < g_controllerChannelCount[0]; i++) {
            if (!(data[i].team & 4)) {
                retry--;
                break;
            }
        }
        if (i == g_controllerChannelCount[0]) retry = 0;
    } while (retry > 0);
    count = g_controllerChannelCount;
    for (i = 0; i < *count; i++) {
        if (data[i].slot == 0 && (data[i].team & 1)) patternmask |= 1 << i;
    }
    __osSiRelAccess();
    *pattern = patternmask;
    return ret;
}
#endif

/* Sets the last controller command to the given byte, marks the pak PIF RAM block for execution and packs one request-status command per controller followed by the end marker (libultra __osPfsRequestData). Adapted from __osPackRequestData with the RAM clearing loop dropped, the command byte also stored to g_controllerLastCommand, and the pak PIF RAM block g_controllerStatusPifBuffer used in place of g_controllerQueryPifBuffer, with the pointer taken before the status word is written. */








/* Decodes the controller status replies in g_controllerStatusPifBuffer for each of g_controllerChannelCount channels, recording the error bits from each reply's receive size and, for a channel without error, its type and status, and stores the mask of answering channels through arg0. Adapted from __osContGetInitData. */







void __osPfsRequestData(u8 cmd) {
    u8 *ptr;
    __OSContRequesFormat requestformat;
    s32 i;
    u8 *count;

    g_controllerLastCommand = cmd;
    ptr = (u8 *)&g_controllerStatusPifBuffer;
    g_controllerStatusPifBuffer.pifstatus = 1;
    requestformat.dummy = 0xFF;
    requestformat.txsize = 1;
    requestformat.rxsize = 3;
    requestformat.cmd = cmd;
    requestformat.typeh = 0xFF;
    requestformat.typel = 0xFF;
    requestformat.status = 0xFF;
    requestformat.dummy1 = 0xFF;

    count = g_controllerChannelCount;
    for (i = 0; i < *count; i++) {
        *(__OSContRequesFormat *)ptr = requestformat;
        ptr += sizeof(requestformat);
    }
    *ptr = 0xFE;
}

void Items_DecodeControllerStatusReplies(u8 *valid, ControllerInitStatusBytes *data) {
    u8 *ptr;
    __OSContRequesFormat readformat;
    s32 i;
    u8 mask = 0;

    ptr = (u8 *)&g_controllerStatusPifBuffer;
    for (i = 0; i < g_controllerChannelCount[0]; i++, ptr += sizeof(readformat), data++) {
        readformat = *(__OSContRequesFormat *)ptr;
        data->slot = (readformat.rxsize & 0xC0) >> 4;
        if (data->slot != 0) {
            continue;
        }
        data->id = (readformat.typel << 8) | readformat.typeh;
        data->team = readformat.status;
        mask |= 1 << i;
    }
    *valid = mask;
}

#if defined(VERSION_EU)
unsigned int func_80447A38_de_padding_1BED4C[1] = {
    0x00000000,
};
#endif
