#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_802B8DD0.h"
#include "types.h"
#include "common/unused.h"

extern PiTransfer802BE820 *D_800D4380[];

/** Update changed PI timing registers, then write through the uncached transfer address. */
s32 func_802B9730_de(PiTransfer802BE820 *arg0, u32 arg1, u32 arg2) {
    PiTransfer802BE820 *previous;
    s32 index;

    while (*(volatile u32 *)0xA4600010 & 3) {
    }
    index = arg0->index;
    previous = D_800D4380[index];
    if (previous != arg0) {
        if (index == 0) {
            if (previous->field5 != arg0->field5) {
                *(volatile u32 *)0xA4600014 = arg0->field5;
            }
            if (previous->field6 != arg0->field6) {
                *(volatile u32 *)0xA460001C = arg0->field6;
            }
            if (previous->field7 != arg0->field7) {
                *(volatile u32 *)0xA4600020 = arg0->field7;
            }
            if (previous->field8 != arg0->field8) {
                *(volatile u32 *)0xA4600018 = arg0->field8;
            }
        } else {
            if (previous->field5 != arg0->field5) {
                *(volatile u32 *)0xA4600024 = arg0->field5;
            }
            if (previous->field6 != arg0->field6) {
                *(volatile u32 *)0xA460002C = arg0->field6;
            }
            if (previous->field7 != arg0->field7) {
                *(volatile u32 *)0xA4600030 = arg0->field7;
            }
            if (previous->field8 != arg0->field8) {
                *(volatile u32 *)0xA4600028 = arg0->field8;
            }
        }
        D_800D4380[index] = arg0;
    }
    *(volatile u32 *)(arg0->address | arg1 | 0xA0000000) = arg2;
    return 0;
}

extern DeviceState D_80148740;
extern char *D_801487B4;
extern DeviceState *D_800D437C;

extern void *func_802A001C_de(void *, s32, u32);
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);




DeviceState *func_802B9870_de(void) {
    DeviceState *state;
    struct OSPiHandle_s *handle;
    u32 lock;
    DeviceState *previous;
    DeviceState **slot;

    state = &D_80148740;
    state->type = 2;
    state->address = 0xA5000000;
    state->latency = 3;
    state->pulse = 6;
    state->page_size = 6;
    state->release = 2;
    state->domain = 1;
    *(volatile u32 *)0xA4600024 = 3;
    *(volatile u32 *)0xA4600028 = 6;
    *(volatile u32 *)0xA460002C = 6;
    *(volatile u32 *)0xA4600030 = 2;
    state->queue = 0;
    handle = (void *)state;
    func_802A001C_de(handle->transferInfo, 0, 0x60);
    lock = func_802BCF30_de();
    slot = &D_800D437C;
    previous = *slot;
    *slot = state;
    D_801487B4 = state;
    state->previous = previous;
    func_802BCF50_de(lock);
    return state;
}
