#include "span_1000/code_802B8DD0.h"
#include "hardware_io.h"
#include "span_1000/code_802B9ED8.h"
#include "types.h"

/* _VirtualToPhysicalTask, drafted from ultralib src/io/sptask.c; this library's bcopy is the
   destination-first copy func_802BD3A0_de. */
extern OSTask D_80148800;

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

extern u32 func_802BBBC0_de(void *addr);

/* The yielded task records its ucode pointer in the last word of its 0xC00-byte yield buffer. */



extern OSTask *func_802B9D90_de(OSTask *arg0);

extern void func_802BD280_de(OSTask *, s32);

extern void func_802BA100_de(u32 arg0);

extern s32 func_802BA0D0_de(u32 arg0);

extern s32 __osSpDeviceBusy(void);

OSTask *func_802B9D90_de(OSTask *intp)
{
    OSTask *tp;
    OSTask *task = &D_80148800;
    tp = task;
    func_802BD3A0_de(task, intp, sizeof(OSTask));
    if (task->t.ucode != 0) { task->t.ucode = (void *)func_802BBBC0_de(task->t.ucode); } (void)0;
    if (task->t.ucode_data != 0) { task->t.ucode_data = (void *)func_802BBBC0_de(task->t.ucode_data); } (void)0;
    if (task->t.dram_stack != 0) { task->t.dram_stack = (void *)func_802BBBC0_de(task->t.dram_stack); } (void)0;
    if (task->t.output_buff != 0) { task->t.output_buff = (void *)func_802BBBC0_de(task->t.output_buff); } (void)0;
    if (task->t.output_buff_size != 0) { task->t.output_buff_size = (void *)func_802BBBC0_de(task->t.output_buff_size); } (void)0;
    if (task->t.data_ptr != 0) { task->t.data_ptr = (void *)func_802BBBC0_de(task->t.data_ptr); } (void)0;
    if (task->t.yield_data_ptr != 0) { task->t.yield_data_ptr = (void *)func_802BBBC0_de(task->t.yield_data_ptr); } (void)0;
    return tp;
}

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
    while (__osSpDeviceBusy() != 0) {
    }
    do {
        result = func_802B9FD0_de(1, 0x04001000, (s32)block->t.ucode_boot, block->t.ucode_boot_size);
    } while (result == -1);
}

void osSpTaskStartGo(void) {
    do {
    } while (__osSpDeviceBusy() != 0);
    func_802BA100_de(0x125U);
}
