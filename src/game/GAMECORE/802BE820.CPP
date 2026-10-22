#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_11.H"
#include "COMMON/EXTERNS_12.H"
#include "sdk/os.h"
#include "RESMGR/802A0888.H"

extern OSPiHandle_s *D_800D4380[];

/** Update changed PI timing registers, then write through the uncached transfer address. */
s32 func_802B9730_de(OSPiHandle_s *arg0, u32 arg1, u32 arg2) {
    OSPiHandle_s *previous;
    s32 index;

    while (*(volatile u32 *)0xA4600010 & 3) {
    }
    index = arg0->domain;
    previous = D_800D4380[index];
    if (previous != arg0) {
        if (index == 0) {
            if (previous->latency != arg0->latency) {
                *(volatile u32 *)0xA4600014 = arg0->latency;
            }
            if (previous->pageSize != arg0->pageSize) {
                *(volatile u32 *)0xA460001C = arg0->pageSize;
            }
            if (previous->relDuration != arg0->relDuration) {
                *(volatile u32 *)0xA4600020 = arg0->relDuration;
            }
            if (previous->pulse != arg0->pulse) {
                *(volatile u32 *)0xA4600018 = arg0->pulse;
            }
        } else {
            if (previous->latency != arg0->latency) {
                *(volatile u32 *)0xA4600024 = arg0->latency;
            }
            if (previous->pageSize != arg0->pageSize) {
                *(volatile u32 *)0xA460002C = arg0->pageSize;
            }
            if (previous->relDuration != arg0->relDuration) {
                *(volatile u32 *)0xA4600030 = arg0->relDuration;
            }
            if (previous->pulse != arg0->pulse) {
                *(volatile u32 *)0xA4600028 = arg0->pulse;
            }
        }
        D_800D4380[index] = arg0;
    }
    *(volatile u32 *)(arg0->baseAddress | arg1 | 0xA0000000) = arg2;
    return 0;
}






OSPiHandle_s *func_802B9870_de(void) {
    OSPiHandle_s *state;
    struct OSPiHandle_s *handle;
    u32 lock;
    OSPiHandle_s *previous;
    OSPiHandle_s **slot;

    state = &D_80148740;
    state->type = 2;
    state->baseAddress = 0xA5000000;
    state->latency = 3;
    state->pulse = 6;
    state->pageSize = 6;
    state->relDuration = 2;
    state->domain = 1;
    *(volatile u32 *)0xA4600024 = 3;
    *(volatile u32 *)0xA4600028 = 6;
    *(volatile u32 *)0xA460002C = 6;
    *(volatile u32 *)0xA4600030 = 2;
    state->speed = 0;
    handle = (void *)state;
    func_802A001C_de(handle->transferInfo, 0, 0x60);
    lock = func_802BCF30_de();
    slot = &D_800D437C;
    previous = *slot;
    *slot = state;
    D_801487B4 = state;
    state->next = previous;
    __osRestoreInt(lock);
    return state;
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802B9874);
#endif
