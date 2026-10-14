#ifndef UNBAKE_SPAN_1000_CODE_802BBC68_H
#define UNBAKE_SPAN_1000_CODE_802BBC68_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
struct Func802C1F10Node;
struct Func802C1F10Node {
    s32 field0;
    s32 field4;
    void *field8;
    struct Func802C1F10Node *next;
    u16 field10;
};

extern void func_802BCC90_de();

extern unsigned int func_802BD1C0_eu();

extern unsigned int func_802BCE50_us();

extern void func_802BCD64_de();

struct Ctx;
typedef struct Ctx Ctx;

struct Ctx;
struct Ctx {
    Queue_func_802BB420_de *cur;
    s32 f4;
};

extern void func_802BC850_eu_x();

extern unsigned int func_802BD200_eu_x();

struct Func802C1F10Node;
typedef struct Func802C1F10Node Func802C1F10Node;


/* Disk transfer state embedded at offset 0x14 in the PI device handle. */
typedef struct DiskTransferInfo {
    u16 command;
    u16 mode;
    u32 block;
    s32 sector;
    u32 deviceAddress;
    u32 bmControl;
} DiskTransferInfo;

#endif
