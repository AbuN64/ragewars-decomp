#ifndef UNBAKE_SPAN_1000_CODE_802B9ED8_H
#define UNBAKE_SPAN_1000_CODE_802B9ED8_H
#include "types.h"
extern int __osSpDeviceBusy();

struct OSTask_t;
struct OSTask_t {
    u32 type;
    u32 flags;
    u64 *ucode_boot;
    u32 ucode_boot_size;
    u64 *ucode;
    u32 ucode_size;
    u64 *ucode_data;
    u32 ucode_data_size;
    u64 *dram_stack;
    u32 dram_stack_size;
    u64 *output_buff;
    u64 *output_buff_size;
    u64 *data_ptr;
    u32 data_size;
    u64 *yield_data_ptr;
    u32 yield_data_size;
};

extern void func_802BA120_de();

struct OSTask_t;
typedef struct OSTask_t OSTask_t;

union OSTask;
union OSTask {
    OSTask_t t;
    long long force_structure_alignment;
};

union OSTask;
typedef union OSTask OSTask;

extern void func_802BA100_de(unsigned int arg0);

extern void func_802BA0FC_de(void);
extern s32 func_802B9FD0_de(s32 direction, s32 spAddress, s32 dramAddress, s32 size);
#endif
