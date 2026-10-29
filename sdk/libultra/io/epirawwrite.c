#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "TYPES.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "COMMON/CACHE_ALLOCATERESOURCE.H"
#include "../../include/os.h"
#include "RESMGR/X_PLUS.H"

extern OSPiHandle_s *g_peripheralDomainHandles[];

/** Update changed PI timing registers, then write through the uncached transfer address. */
s32 osEPiRawWriteIo(OSPiHandle_s *handle, u32 deviceOffset, u32 wordValue) {
    OSPiHandle_s *previous;
    s32 index;

    while (*(volatile u32 *)0xA4600010 & 3) {
    }
    index = handle->domain;
    previous = g_peripheralDomainHandles[index];
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
        g_peripheralDomainHandles[index] = handle;
    }
    *(volatile u32 *)(handle->baseAddress | deviceOffset | 0xA0000000) = wordValue;
    return 0;
}






OSPiHandle_s *osLeoDiskInit(void) {
    OSPiHandle_s *state;
    struct OSPiHandle_s *handle;
    u32 lock;
    OSPiHandle_s *previous;
    OSPiHandle_s **slot;

    state = &g_diskPeripheralHandle;
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
    XPlus_FillMemory(handle->transferInfo.bytes, 0, 0x60);
    lock = __osDisableInt();
    slot = &g_peripheralHandleList;
    previous = *slot;
    *slot = state;
    g_currentDiskPeripheralHandle = state;
    state->next = previous;
    __osRestoreInt(lock);
    return state;
}

#if defined(VERSION_US)
char k_EpirawioEncodedBytes[12] =
    "ponT\000\000P\000\000\000\010\000";
#endif
