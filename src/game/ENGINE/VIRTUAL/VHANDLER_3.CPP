#include "include_asm.h"
#include "COMMON/DESCRIPTORRECAT29.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "SCHED/8023A284.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_8.H"
#include "ENGINE/VIRTUAL/VHANDLER_3.H"
#include "ENGINE/VIRTUAL/VHANDLER_2.H"
#include "sdk/os.h"
#include "RESMGR/802A0888.H"

extern Region D_80103F88;

extern func_80205628_S3 *D_800FFE20;


extern void func_802AD370_de(int a0, int a1, int a2, int a3, int a4, int a5);




void **func_8025343C_de(s32 arg0, s32 arg1, s32 arg2, void *arg3);





extern PagerState D_800FF230;

void func_8023C6BC_de(void) {
    u32 var_a2;
    u32 var_a3;
    s32 var_a1;
    u32 *var_a0;
    u32 temp_v1;
    Region *var_v1;
    s32 var_a0_2;
    u16 temp_v0;
    s32 *out;
    s32 *ordered;

    var_a2 = 0;
    var_a3 = 0x80000000;
    var_a1 = 0;
    var_a0 = &D_800FFB5C;
    do {
        temp_v1 = *var_a0;
        if (var_a2 < temp_v1) {
            var_a2 = temp_v1;
        }
        if (temp_v1 < var_a3) {
            var_a3 = temp_v1;
        }
        *var_a0 = temp_v1 + 1;
        var_a1 += 1;
        var_a0 += 4;
    } while (var_a1 < 0x18);

    var_v1 = &D_80103F88;
    var_a0_2 = 0;
    if (&D_80103F88 != 0) {
        do {
            temp_v0 = var_v1->pages;
            var_v1 = var_v1->next;
            var_a0_2 += temp_v0 << 0xC;
        } while (var_v1 != 0);
    }

    out = D_800FF24C;
    ordered = out;
    *ordered = var_a0_2;
    ordered[-3] = var_a2;
    ordered[-2] = var_a3;
    __builtin_memcpy(&out[-1], &D_800FFE20->unkC, sizeof(s32));
}

void func_8023C750_de(void) {
    func_802AD370_de(0x1F, 0x1FE000, 0x200000, 0, 0x100000, 7);
}

void *func_8023C78C_de(s32 arg0, s32 arg1_unused, s32 arg2)
{
  char sp10[0x18];
  int new_var2;
  Block10 blk;
  s32 sp38;
  u32 temp_s1;
  void *sp3C;
  u32 rounded;
  void **temp_v0;
  Draw *temp_v1;
  int new_var;
  temp_s1 = ((u32) (arg0 + 0xFFF)) >> 0xC;
  new_var = (temp_s1 + 1) & (~1);
  if (1)
  {
    osCreateMesgQueue(sp10, (s32) (&sp38), 1);
    blk.f28 = 3;
    blk.f2C = arg0;
    blk.f34 = (void **) sp10;
    new_var2 = temp_s1 * 4;
    rounded = new_var + 0x18;
    temp_v0 = func_8025343C_de(0, new_var2 + rounded, 3, &D_800C3600_de);
    temp_v1 = *temp_v0;
    blk.f30 = temp_v1;
    temp_v1->model = temp_v0;
  }
  ((Draw *)blk.f30)->allocationMode = arg2;
  func_802BB420_de(&D_800FF254, &blk.f28, 1);
  func_802BB2A0_de(sp10, &sp3C, 1);
  return sp3C;
}

void func_8023C85C_de(s32 arg0) {
    char sp10[0x18];
    Block_func_8023C85C_de block;
    s32 sp38;
    void *sp3C;

    osCreateMesgQueue(sp10, (s32)&sp38, 1);
    block.type = 2;
    block.value = arg0;
    block.data = sp10;
    func_802BB420_de(&D_800FF254, &block, 1);
    func_802BB2A0_de(sp10, &sp3C, 1);
    func_80253838_de(0, ((Draw *)(sp3C))->model);
}

void func_8023C8D4_de(struct PagerCounters *arg0) {
    *arg0 = D_800FF230.counters;
}

/* Resource manager thread setup and loop: fills a 0x200-byte stack with a marker, creates and starts the
 * thread object at D_80103720 (entry D_0023CA24, stack top D_800FFB50), then forever receives request
 * messages and dispatches on the request type to func_8023C1F0_de, Sched_FinishPageJob, func_8023CCD4_de or
 * func_8023CDD4_de. */
extern char D_800FF950[];
extern char D_0023CA24[];
extern void func_802BAC90_de(void *, s32, void *, void *, void *, s32);
extern void func_802BB750_de(void *);
extern void Sched_FinishPageJob(struct ResourcePageJob *job);

void func_8023C924_de(void) {
    OSMesg request;

    func_802A001C_de(D_800FF950, 0x62, 0x200);
    func_802BAC90_de(D_800FF950 - 0x230, 0x62, D_0023CA24, 0, D_800FF950 + 0x200, 0x94);
    func_802BB750_de(D_800FF950 - 0x230);
    for (;;) {
        func_802BB2A0_de(&D_800FF254, &request, 1);
        switch (((Request *)request)->type) {
        case 0:
            func_8023C1F0_de();
            break;
        case 1:
            Sched_FinishPageJob(request);
            break;
        case 3:
            func_8023CDD4_de(request);
            break;
        case 2:
            func_8023CCD4_de(request);
            break;
        }
    }
}

#include "SCHED/RESOURCE_PAGE_WORKER.H"
extern char D_801011B8;
extern char D_8014E000;
extern void func_8025637C_de(void *worker, u8 *source, s32 size, void *buffer);
extern void func_802BCF70_de(void *addr, s32 size);
extern void func_802BD010_de(void *addr, s32 size);

/* Resource page reader thread: takes page jobs from the pending queue, reads the page from the cartridge
 * into its slot of the page array, writes the data cache back and invalidates the instruction cache, then
 * returns the job to the manager. */
void func_8023CA14_de(void *unused) {
    OSMesgQueue queue;
    OSMesg queueMessage;
    OSMesg message;

    osCreateMesgQueue(&queue, &queueMessage, 1);
    for (;;) {
        func_802BB2A0_de(&D_800FF230.pending, &message, 1);
        if (*((ResourcePageJob *)message)->slot == 0xFF) {
            func_8025637C_de(&D_801011B8, ((ResourcePageJob *)message)->source, (((ResourcePageJob *)message)->size + 1) & ~1,
                             &D_8014E000 + (((ResourcePageJob *)message)->mapping->index << 12));
            func_802BCF70_de(&D_8014E000 + (((ResourcePageJob *)message)->mapping->index << 12), 0x1000);
            func_802BD010_de(&D_8014E000 + (((ResourcePageJob *)message)->mapping->index << 12), 0x1000);
        }
        ((Request *)message)->type = 1;
        func_802BB420_de(&D_800FF230.completion, message, 1);
    }
}

typedef struct PageChain {
    ResourcePageMapping *head;
    ResourcePageMapping *tail;
} PageChain;

/* Unlinks a mapping from a doubly linked chain. */
void func_8023CB0C_de(PageChain *list, ResourcePageMapping *node) {
    if (node->prev != 0) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
        node->next->prev = 0;
    }
    if (node->next != 0) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
        node->prev->next = 0;
    }
}
