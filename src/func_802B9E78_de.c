#include "types.h"
#include "span_1000/code_802B9ED8.h"
#include "hardware_io.h"
/* The yielded task records its ucode pointer in the last word of its 0xC00-byte yield buffer. */



extern OSTask *func_802B9D90_de(OSTask *arg0);
extern void func_802BD280_de(OSTask *, s32);
extern void func_802BA100_de(u32 arg0);
extern s32 func_802BA0D0_de(u32 arg0);
extern s32 func_802B9FB0_de(void);

void func_802B9E78_de(OSTask *arg0) {
    OSTask *block;
    s32 result;

    block = func_802B9D90_de(arg0);
    if (block->t.flags & 1) {
        block->t.ucode_data = block->t.yield_data_ptr;
        block->t.ucode_data_size = block->t.yield_data_size;
        arg0->t.flags &= ~1;
        if (block->t.flags & 4) {
            block->t.ucode = (u64 *)IO_READ_WORD(((u32)arg0->t.yield_data_ptr + 0xBFCU) | 0xA0000000U);
        }
    }
    func_802BD280_de(block, 0x40);
    func_802BA100_de(0x2B00);
    do {
        result = func_802BA0D0_de(0x04001000);
    } while (result == -1);
    do {
        result = func_802B9FD0_de(1, 0x04000FC0, (s32)block, 0x40);
    } while (result == -1);
    while (func_802B9FB0_de() != 0) {
    }
    do {
        result = func_802B9FD0_de(1, 0x04001000, (s32)block->t.ucode_boot, block->t.ucode_boot_size);
    } while (result == -1);
}
