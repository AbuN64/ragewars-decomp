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
s32 func_802B9730_de(OSPiHandle_s *handle, u32 arg1, u32 arg2) {
    OSPiHandle_s *previous;
    s32 index;

    while (*(volatile u32 *)0xA4600010 & 3) {
    }
    index = handle->domain;
    previous = D_800D4380[index];
    if (previous != handle) {
        if (index == 0) {
            if (previous->latency != handle->latency) {
                *(volatile u32 *)0xA4600014 = handle->latency;
            }
            if (previous->pageSize != handle->pageSize) {
                *(volatile u32 *)0xA460001C = handle->pageSize;
            }
            if (previous->relDuration != handle->relDuration) {
                *(volatile u32 *)0xA4600020 = handle->relDuration;
            }
            if (previous->pulse != handle->pulse) {
                *(volatile u32 *)0xA4600018 = handle->pulse;
            }
        } else {
            if (previous->latency != handle->latency) {
                *(volatile u32 *)0xA4600024 = handle->latency;
            }
            if (previous->pageSize != handle->pageSize) {
                *(volatile u32 *)0xA460002C = handle->pageSize;
            }
            if (previous->relDuration != handle->relDuration) {
                *(volatile u32 *)0xA4600030 = handle->relDuration;
            }
            if (previous->pulse != handle->pulse) {
                *(volatile u32 *)0xA4600028 = handle->pulse;
            }
        }
        D_800D4380[index] = handle;
    }
    *(volatile u32 *)(handle->baseAddress | arg1 | 0xA0000000) = arg2;
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
    Resmgr_FillMemory(handle->transferInfo, 0, 0x60);
    lock = __osDisableInt();
    slot = &D_800D437C;
    previous = *slot;
    *slot = state;
    D_801487B4 = state;
    state->next = previous;
    __osRestoreInt(lock);
    return state;
}

#if defined(VERSION_US)
char rodata_unresolved_802B9874[12] =
    "ponT\000\000P\000\000\000\010\000";
#endif
