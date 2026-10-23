#include "COMMON/OWNERRECAT8V2.H"
#include "SCHED/8023A284.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "sdk/libgultra/libasm_802BD1A8.h"
#include "sdk/os.h"
#include "RESMGR/802A0888.H"

#if !(defined(VERSION_DE) || defined(VERSION_EU_X))
/* Initializes the game state: clears the whole state block and fills its slot and lookup tables
   with 0xFF, resets the 24 player entries and queue slots, sets up the three lists and the stream
   descriptor for the ROM data at D_16E000, loads the expansion-pak data when more memory is present,
   and builds the eight channels, the message pool and the sprite queue. */









extern PagerState D_800FF230;
extern char D_801011B8[];

extern void func_8023CB60_de(Field_void_4 *base, Slot_func_8023B9C0_eu *slot);
extern void func_8025637C_de(void *dst, void *rom, void *size, u32 extra);
extern u32 func_80265350_de(void);
extern void func_802AD370_de(s32 arg0, s32 arg1, s32 arg2, u32 addr, s32 arg4, s32 arg5);
extern void func_802BAC90_de(void *queue, s32 count, void *arg2, s32 arg3, void *data, s32 arg5);
extern void func_802BB550_de(s32 count, void *list, s16 *arg2);
extern void func_802BB750_de(void *queue);


static inline void fill(void *dst, u8 value, s32 n) {
    u8 *p = dst;

    while (n--) {
        *p++ = value;
    }
}

void func_8023B9C0_eu(void) {
    u32 extra;
    u32 i;

    extra = func_80265350_de() + 0x80000000;
    if (extra <= 0x80400000) {
        extra = 0;
    }
    fill(&D_800FF230, 0, sizeof(PagerState));
    fill(D_800FF230.lookup, 0xFF, sizeof(D_800FF230.lookup));
    fill(D_800FF230.slots, 0xFF, sizeof(D_800FF230.slots));
    osUnmapTLBAll();
    for (i = 0; i < 24; i++) {
        D_800FF230.entries[i].id = 0xFFFF;
        D_800FF230.entries[i].team = 0xFF;
        D_800FF230.entries[i].slot = 0xFF;
    }
    D_800FF230.fBF4 = 0;
    D_800FF230.head = 0;
    for (i = 0; i < 24; i++) {
        D_800FF230.slots[i].a = 0;
        D_800FF230.slots[i].b = 0;
        func_8023CB60_de((Field_void_4 *)&D_800FF230.head, &D_800FF230.slots[i]);
        D_800FF230.slots[i].index = i;
    }
    osCreateMesgQueue(&D_800FF230.completion, D_800FF230.list0Data, 0x21);
    osCreateMesgQueue(&D_800FF230.jobs, D_800FF230.list1Data, 8);
    osCreateMesgQueue(&D_800FF230.pending, D_800FF230.list2Data, 8);
    D_800FF230.regions.start = 0x400;
    D_800FF230.regions.pages = 0x100;
    D_800FF230.regions.map = D_800FF230.lookup;
    D_800FF230.regions.next = 0;
    D_800FF230.regions.source = (u8 (*)[4096])((u32) D_176000 | 0xB0000000);
    D_800FF230.fD72 = 0;
    if (func_80265350_de() > 0x4FFFFF) {
        func_8025637C_de(D_801011B8, D_176000, D_52BF0, extra);
    }
    if (extra != 0) {
        func_802AD370_de(0, 0x1FE000, 0x400000, extra + 0x80000000, -1, 7);
        D_800FF230.fD70 = 1;
        D_800FF230.fD72 = 1;
    }
    for (i = 0; i < 8; i++) {
        func_802BB420_de(&D_800FF230.jobs, &D_800FF230.channels[i], 1);
    }
    D_800FF230.f20 = 0;
    func_802BB550_de(0xC, &D_800FF230.completion, &D_800FF230.f20);
    func_802A001C_de(D_800FF230.pool, 0x63, 0x200);
    func_802BAC90_de(D_800FF230.queue, 0x63, D_0023C934, 0, D_800FF230.queueData, 0x93);
    func_802BB750_de(D_800FF230.queue);
}
#endif
