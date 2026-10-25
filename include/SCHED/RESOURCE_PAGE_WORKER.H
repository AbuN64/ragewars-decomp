#ifndef SCHED_RESOURCE_PAGE_WORKER_H
#define SCHED_RESOURCE_PAGE_WORKER_H
#include "TYPES.H"
#include "COMMON/OWNERRECAT8V2.H"
typedef struct ResourcePageThread {
    u8 reserved0[0x12]; s16 state;
    u8 reserved14[3]; u8 slot;
    u8 reserved18[0x108]; u32 message, address;
} ResourcePageThread;
typedef struct ResourcePageJob {
    u32 reserved0; u8 *source; u32 size;
    u16 page; u8 reservedE[2];
    ResourcePageMapping *mapping;
    ResourcePageThread *thread;
    u8 *slot;
} ResourcePageJob;
#endif
