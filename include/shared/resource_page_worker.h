#ifndef RW_RESOURCE_PAGE_WORKER_H
#define RW_RESOURCE_PAGE_WORKER_H
#include "types.h"
typedef struct ResourcePageMapping {
    struct ResourcePageMapping *next, *prev;
    u16 page;
    u8 flags, slot;
    s32 resident;
} ResourcePageMapping;
typedef struct ResourcePageThread {
    u8 reserved0[0x12]; s16 state;
    u8 reserved14[3]; u8 slot;
    u8 reserved18[0x108]; u32 message, address;
} ResourcePageThread;
typedef struct ResourcePageRegion {
    struct ResourcePageRegion *next;
    u16 first, count;
    u8 (*pages)[4096];
    u8 reservedC[4]; u8 *slots;
    u8 reserved14[12];
} ResourcePageRegion;
typedef struct ResourcePageJob {
    u32 reserved0; u8 *source; u32 size;
    u16 page; u8 reservedE[2];
    ResourcePageMapping *mapping;
    ResourcePageThread *thread;
    u8 *slot;
} ResourcePageJob;
typedef struct ResourcePageQueue { u32 words[6]; } ResourcePageQueue;
typedef struct ResourcePagerSystem {
    s32 requests, misses;
    u32 lastAddress;
    u8 reservedC[0x914];
    ResourcePageMapping mappings[24];
    ResourcePageQueue jobs;
    u8 reservedAB8[0x20];
    ResourcePageQueue pending;
    u8 reservedAF0[0x100];
    ResourcePageMapping *head, *tail;
    u8 reservedBF8[0x160];
    ResourcePageRegion regions;
} ResourcePagerSystem;
#endif
