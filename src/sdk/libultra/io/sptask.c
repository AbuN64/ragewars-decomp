#include "COMMON/EXTERNS_2.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/HARDWARE_IO.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/OSTASK_T.H"
#include "sdk/libultra/io/sprawdma.H"
#include "AUDIO/802BF1C0.H"
#include "AUDIO/802BF1F0.H"
#include "sdk/libgultra/sp.h"
#include "sdk/OSINT/802C0CB0.H"

/* _VirtualToPhysicalTask, drafted from ultralib src/io/sptask.c; this library's bcopy is the
   destination-first copy func_802BD3A0_de. */

extern void *func_802BD3A0_de(void *destination, const void *source, int count);


/* The yielded task records its ucode pointer in the last word of its 0xC00-byte yield buffer. */



OSTask *_VirtualToPhysicalTask(OSTask *intp);


extern void func_802BD280_de(OSTask *, s32);



OSTask *_VirtualToPhysicalTask(OSTask *intp)
{
    OSTask *tp;
    OSTask *task = &D_80148800;
    tp = task;
    func_802BD3A0_de(task, intp, sizeof(OSTask));
    if (task->t.ucode != 0) { task->t.ucode = (void *)osVirtualToPhysical(task->t.ucode); } (void)0;
    if (task->t.ucode_data != 0) { task->t.ucode_data = (void *)osVirtualToPhysical(task->t.ucode_data); } (void)0;
    if (task->t.dram_stack != 0) { task->t.dram_stack = (void *)osVirtualToPhysical(task->t.dram_stack); } (void)0;
    if (task->t.output_buff != 0) { task->t.output_buff = (void *)osVirtualToPhysical(task->t.output_buff); } (void)0;
    if (task->t.output_buff_size != 0) { task->t.output_buff_size = (void *)osVirtualToPhysical(task->t.output_buff_size); } (void)0;
    if (task->t.data_ptr != 0) { task->t.data_ptr = (void *)osVirtualToPhysical(task->t.data_ptr); } (void)0;
    if (task->t.yield_data_ptr != 0) { task->t.yield_data_ptr = (void *)osVirtualToPhysical(task->t.yield_data_ptr); } (void)0;
    return tp;
}

void osSpTaskLoad(OSTask *intp) {
    OSTask *block;
    s32 result;

    block = _VirtualToPhysicalTask(intp);
    if (block->t.flags & 1) {
        block->t.ucode_data = block->t.yield_data_ptr;
        block->t.ucode_data_size = block->t.yield_data_size;
        intp->t.flags &= ~1;
        if (block->t.flags & 4) {
            block->t.ucode = (u64 *)IO_READ_WORD(((u32)intp->t.yield_data_ptr + 0xBFCU) | 0xA0000000U);
        }
    }
    func_802BD280_de(block, 0x40);
    Audio_WriteSignalProcessorStatus(0x2B00);
    do {
        result = func_802BA0D0_de(0x04001000);
    } while (result == -1);
    do {
        result = __osSpRawStartDma(1, 0x04000FC0, (s32)block, 0x40);
    } while (result == -1);
    while (__osSpDeviceBusy() != 0) {
    }
    do {
        result = __osSpRawStartDma(1, 0x04001000, (s32)block->t.ucode_boot, block->t.ucode_boot_size);
    } while (result == -1);
}


void osSpTaskStartGo(void) {
    do {
    } while (__osSpDeviceBusy() != 0);
    Audio_WriteSignalProcessorStatus(0x125U);
}
