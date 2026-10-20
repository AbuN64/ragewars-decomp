#ifndef COMMON_OSTASK_T_H
#define COMMON_OSTASK_T_H
#include "TYPES.H"

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


struct OSTask_t;
typedef struct OSTask_t OSTask_t;

union OSTask;
union OSTask {
    OSTask_t t;
    long long force_structure_alignment;
};

union OSTask;
typedef union OSTask OSTask;


extern void func_802BA0FC_de(void);
#endif
