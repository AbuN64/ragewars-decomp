#include "span_1000/code_802B9ED8.h"
#include "types.h"
/* _VirtualToPhysicalTask, drafted from ultralib src/io/sptask.c; this library's bcopy is the
   destination-first copy func_802BD3A0_de. */
extern OSTask D_80148800;
extern void *func_802BD3A0_de(void *destination, const void *source, int count);
extern u32 func_802BBBC0_de(void *addr);
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
