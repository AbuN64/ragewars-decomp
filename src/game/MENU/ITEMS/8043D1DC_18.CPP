#include "include_asm.h"
#include "COMMON/ARG.H"
#include "COMMON/OBJECTSTATE96.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"

#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ARG.H"
#include "TYPES.H"
#include "COMMON/OBJECTSTATE96.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"
void __osPfsRequestData(u8 cmd);

s32 Items_QueryControllerPresence(OSMesgQueue *arg0, s8 *arg1) {
    EntryRecAt3 sp10;
    void *sp20;
    u8 sp24;
    EntryRecAt3 *var_v1;
    EntryRecAt3 *var_v1_2;
    s32 temp_s6;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s0;
    s8 var_s2;

    var_s2 = 0;
    var_s0 = 3;
    func_802B9C14_de();
    do {
        __osPfsRequestData(0U);
        __osSiRawStartDma(1, (u8 *)&D_80154110);
        osRecvMesg(arg0, &sp20, 1);
        temp_s6 = __osSiRawStartDma(0, (u8 *)&D_80154110);
        osRecvMesg(arg0, &sp20, 1);
        Pfs_DecodeControllerStatusReplies(&sp24, &sp10);
        var_a0 = 0;
        if (D_8014D46C[0] != 0) {
            var_v1 = &sp10;
loop_3:
            if (var_v1->team & 4) {
                var_a0 += 1;
                var_v1 += 4;
                if (var_a0 < (s32) D_8014D46C[0]) {
                    goto loop_3;
                }
            } else {
                var_s0 -= 1;
            }
        }
        if (var_a0 == D_8014D46C[0]) {
            var_s0 = 0;
        }
    } while (var_s0 > 0);
    var_a0_2 = 0;
    if (D_8014D46C[0] != 0) {
        var_v1_2 = &sp10;
        do {
            if ((var_v1_2->slot == 0) && (var_v1_2->team & 1)) {
                var_s2 |= 1 << var_a0_2;
            }
            var_a0_2 += 1;
            var_v1_2 += 4;
        } while (var_a0_2 < (s32) D_8014D46C[0]);
    }
    func_802B9C80_de();
    *arg1 = var_s2;
    return temp_s6;
}
#else
INCLUDE_ASM("ovl_80400000", Items_QueryControllerPresence);
#endif
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
extern void __osPfsRequestData(u8);

s32 Pfs_DetectConnectedPaks(OSMesgQueue *queue, u8 *pattern) {
    EntryRecAt3 data[4];
    void *dummy;
    u8 bitpattern;
    s32 i;
    u8 *count;
    s32 ret;
    s32 patternmask = 0;
    s32 retry = 3;
    func_802B9C14_de();
    do {
        __osPfsRequestData(0);
        __osSiRawStartDma(1, &D_80154110);
        osRecvMesg(queue, &dummy, 1);
        ret = __osSiRawStartDma(0, &D_80154110);
        osRecvMesg(queue, &dummy, 1);
        Pfs_DecodeControllerStatusReplies(&bitpattern, data);
        for (i = 0; i < D_8014D46C[0]; i++) {
            if (!(data[i].team & 4)) {
                retry--;
                break;
            }
        }
        if (i == D_8014D46C[0]) retry = 0;
    } while (retry > 0);
    count = D_8014D46C;
    for (i = 0; i < *count; i++) {
        if (data[i].slot == 0 && (data[i].team & 1)) patternmask |= 1 << i;
    }
    func_802B9C80_de();
    *pattern = patternmask;
    return ret;
}
#endif

/* Sets the last controller command to the given byte, marks the pak PIF RAM block for execution and packs one request-status command per controller followed by the end marker (libultra __osPfsRequestData). Adapted from __osPackRequestData with the RAM clearing loop dropped, the command byte also stored to D_8014D4B0, and the pak PIF RAM block D_80154110 used in place of D_8014D470, with the pointer taken before the status word is written. */








/* Decodes the controller status replies in D_80154110 for each of D_8014D46C channels, recording the error bits from each reply's receive size and, for a channel without error, its type and status, and stores the mask of answering channels through arg0. Adapted from __osContGetInitData. */







void __osPfsRequestData(u8 cmd) {
    u8 *ptr;
    __OSContRequesFormat requestformat;
    s32 i;
    u8 *count;

    D_8014D4B0 = cmd;
    ptr = (u8 *)&D_80154110;
    D_80154110.pifstatus = 1;
    requestformat.dummy = 0xFF;
    requestformat.txsize = 1;
    requestformat.rxsize = 3;
    requestformat.cmd = cmd;
    requestformat.typeh = 0xFF;
    requestformat.typel = 0xFF;
    requestformat.status = 0xFF;
    requestformat.dummy1 = 0xFF;

    count = D_8014D46C;
    for (i = 0; i < *count; i++) {
        *(__OSContRequesFormat *)ptr = requestformat;
        ptr += sizeof(requestformat);
    }
    *ptr = 0xFE;
}

void Pfs_DecodeControllerStatusReplies(u8 *valid, EntryRecAt3 *data) {
    u8 *ptr;
    __OSContRequesFormat readformat;
    s32 i;
    u8 mask = 0;

    ptr = (u8 *)&D_80154110;
    for (i = 0; i < D_8014D46C[0]; i++, ptr += sizeof(readformat), data++) {
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
