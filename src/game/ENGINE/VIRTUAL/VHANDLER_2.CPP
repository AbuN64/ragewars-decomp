#include "include_asm.h"
#include "COMMON/DESCRIPTORRECAT29.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "SCHED/8023A284.H"
#include "TYPES.H"
#include "ENGINE/VIRTUAL/VHANDLER_2.H"
#include "sdk/os.h"
#include "AUDIO_4/802BFE60.H"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "COMMON/OWNERRECAT8V2.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "sdk/libgultra/libasm_802BD1A8.h"
#include "sdk/os.h"
#include "RESMGR/802A0888.H"
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
#else
INCLUDE_ASM("span_1000", func_8023B9C0_eu);
#endif
#endif

#if defined(VERSION_DE)
#ifdef NON_MATCHING
/* Fuzzy draft: inline-asm carrier of the original instructions (no C written yet). */
void func_8023B9B0_de(void) {
    __asm__ volatile (
        ".set noreorder\n"
        ".set noat\n"
        "addiu      $sp, $sp, -0x30\n"
        "sw         $ra, 0x2C($sp)\n"
        "sw         $s4, 0x28($sp)\n"
        "sw         $s3, 0x24($sp)\n"
        "sw         $s2, 0x20($sp)\n"
        "sw         $s1, 0x1C($sp)\n"
        "jal        func_80265350_de\n"
        "sw        $s0, 0x18($sp)\n"
        "lui        $v1, (0x80000000 >> 16)\n"
        "addu       $s4, $v0, $v1\n"
        "lui        $v0, (0x80400000 >> 16)\n"
        "sltu       $v0, $v0, $s4\n"
        "beql       $v0, $zero, .Lauto_8023B9E8\n"
        "addu      $s4, $zero, $zero\n"
        ".Lauto_8023B9E8:\n"
        "lui        $a0, %hi(D_800FF230)\n"
        "addiu      $a0, $a0, %lo(D_800FF230)\n"
        "addiu      $v1, $zero, 0xD77\n"
        ".Lauto_8023B9F4:\n"
        "sb         $zero, 0x0($a0)\n"
        "addiu      $a0, $a0, 0x1\n"
        "addu       $v0, $v1, $zero\n"
        "bnez       $v0, .Lauto_8023B9F4\n"
        "addiu     $v1, $v1, -0x1\n"
        "addiu      $a1, $zero, 0xFF\n"
        "lui        $a0, %hi(D_8010FE28)\n"
        "addiu      $a0, $a0, %lo(D_8010FE28)\n"
        "addiu      $v1, $zero, 0xFF\n"
        ".Lauto_8023BA18:\n"
        "sb         $a1, 0x0($a0)\n"
        "addiu      $a0, $a0, 0x1\n"
        "addu       $v0, $v1, $zero\n"
        "bnez       $v0, .Lauto_8023BA18\n"
        "addiu     $v1, $v1, -0x1\n"
        "addiu      $a1, $zero, 0xFF\n"
        "lui        $a0, %hi(D_800FFB50)\n"
        "addiu      $a0, $a0, %lo(D_800FFB50)\n"
        "addiu      $v1, $zero, 0x17F\n"
        ".Lauto_8023BA3C:\n"
        "sb         $a1, 0x0($a0)\n"
        "addiu      $a0, $a0, 0x1\n"
        "addu       $v0, $v1, $zero\n"
        "bnez       $v0, .Lauto_8023BA3C\n"
        "addiu     $v1, $v1, -0x1\n"
        "jal        osUnmapTLBAll\n"
        "addu      $s1, $zero, $zero\n"
        "ori        $a0, $zero, 0xFFFF\n"
        "addiu      $v1, $zero, 0xFF\n"
        "sll        $v0, $s1, 2\n"
        ".Lauto_8023BA64:\n"
        "addiu      $s1, $s1, 0x1\n"
        "lui        $at, %hi(D_80103F28)\n"
        "addu       $at, $at, $v0\n"
        "sh         $a0, %lo(D_80103F28)($at)\n"
        "lui        $at, %hi(D_800FFF2A)\n"
        "addu       $at, $at, $v0\n"
        "sb         $v1, %lo(D_800FFF2A)($at)\n"
        "lui        $at, %hi(D_800FFF2B)\n"
        "addu       $at, $at, $v0\n"
        "sb         $v1, %lo(D_800FFF2B)($at)\n"
        "sltiu      $v0, $s1, 0x18\n"
        "bnez       $v0, .Lauto_8023BA64\n"
        "sll       $v0, $s1, 2\n"
        "addu       $s1, $zero, $zero\n"
        "lui        $v0, %hi(D_800FFE24)\n"
        "addiu      $v0, $v0, %lo(D_800FFE24)\n"
        "addiu      $s3, $v0, -0x4\n"
        "addiu      $s2, $v0, -0x2D4\n"
        "sw         $zero, 0x0($v0)\n"
        "sw         $zero, -0x4($v0)\n"
        ".Lauto_8023BAB4:\n"
        "addu       $a0, $s3, $zero\n"
        "sll        $s0, $s1, 4\n"
        "lui        $at, %hi(D_800FFB50)\n"
        "addu       $at, $at, $s0\n"
        "sw         $zero, %lo(D_800FFB50)($at)\n"
        "lui        $at, %hi(D_8010FB54)\n"
        "addu       $at, $at, $s0\n"
        "sw         $zero, %lo(D_8010FB54)($at)\n"
        "jal        func_8023CB60_de\n"
        "addu      $a1, $s2, $zero\n"
        "lui        $at, %hi(D_8010FB5A)\n"
        "addu       $at, $at, $s0\n"
        "sb         $s1, %lo(D_8010FB5A)($at)\n"
        "addiu      $s1, $s1, 0x1\n"
        "sltiu      $v0, $s1, 0x18\n"
        "bnez       $v0, .Lauto_8023BAB4\n"
        "addiu     $s2, $s2, 0x10\n"
        "addiu      $s1, $s3, -0xBCC\n"
        "addu       $a0, $s1, $zero\n"
        "addiu      $a1, $s3, -0xBB4\n"
        "jal        osCreateMesgQueue\n"
        "addiu     $a2, $zero, 0x21\n"
        "addiu      $s0, $s3, -0x150\n"
        "addu       $a0, $s0, $zero\n"
        "addiu      $a1, $s3, -0x138\n"
        "jal        osCreateMesgQueue\n"
        "addiu     $a2, $zero, 0x8\n"
        "addiu      $a0, $s3, -0x118\n"
        "addiu      $a1, $s3, -0x100\n"
        "jal        osCreateMesgQueue\n"
        "addiu     $a2, $zero, 0x8\n"
        "addiu      $v0, $zero, 0x400\n"
        "sh         $v0, 0xD38($s1)\n"
        "addiu      $v0, $zero, 0x100\n"
        "sh         $v0, 0xD3A($s1)\n"
        "addiu      $v0, $s3, 0x8\n"
        "lui        $s2, %hi(D_176000)\n"
        "addiu      $s2, $s2, %lo(D_176000)\n"
        "sw         $v0, 0xD44($s1)\n"
        "lui        $v0, (0xB0000000 >> 16)\n"
        "or         $v0, $s2, $v0\n"
        "sw         $zero, 0xD34($s1)\n"
        "sw         $v0, 0xD3C($s1)\n"
        "jal        func_80265350_de\n"
        "sh        $zero, 0xD4E($s1)\n"
        "lui        $v1, (0x4FFFFF >> 16)\n"
        "ori        $v1, $v1, (0x4FFFFF & 0xFFFF)\n"
        "sltu       $v1, $v1, $v0\n"
        "beqz       $v1, .Lauto_8023BB94\n"
        "addu      $a1, $s2, $zero\n"
        "lui        $a0, %hi(D_801011B8)\n"
        "addiu      $a0, $a0, %lo(D_801011B8)\n"
        "lui        $a2, %hi(D_52BF0)\n"
        "addiu      $a2, $a2, %lo(D_52BF0)\n"
        "jal        func_8025637C_de\n"
        "addu      $a3, $s4, $zero\n"
        ".Lauto_8023BB94:\n"
        "beqz       $s4, .Lauto_8023BBD0\n"
        "addu      $a0, $zero, $zero\n"
        "lui        $a1, (0x1FE000 >> 16)\n"
        "ori        $a1, $a1, (0x1FE000 & 0xFFFF)\n"
        "lui        $a2, (0x400000 >> 16)\n"
        "lui        $a3, (0x80000000 >> 16)\n"
        "addu       $a3, $s4, $a3\n"
        "addiu      $v0, $zero, -0x1\n"
        "sw         $v0, 0x10($sp)\n"
        "addiu      $v0, $zero, 0x7\n"
        "jal        func_802AD370_de\n"
        "sw        $v0, 0x14($sp)\n"
        "addiu      $v0, $zero, 0x1\n"
        "sh         $v0, 0xD4C($s1)\n"
        "sh         $v0, 0xD4E($s1)\n"
        ".Lauto_8023BBD0:\n"
        "addu       $s1, $zero, $zero\n"
        "addu       $s2, $s0, $zero\n"
        "addiu      $s0, $s3, -0xE0\n"
        ".Lauto_8023BBDC:\n"
        "addu       $a0, $s2, $zero\n"
        "addu       $a1, $s0, $zero\n"
        "jal        func_802BB420_de\n"
        "addiu     $a2, $zero, 0x1\n"
        "addiu      $s1, $s1, 0x1\n"
        "sltiu      $v0, $s1, 0x8\n"
        "bnez       $v0, .Lauto_8023BBDC\n"
        "addiu     $s0, $s0, 0x1C\n"
        "addiu      $a0, $zero, 0xC\n"
        "addiu      $a1, $s2, -0xA7C\n"
        "addiu      $a2, $s2, -0xA80\n"
        "jal        func_802BB550_de\n"
        "sh        $zero, -0xA80($s2)\n"
        "addiu      $a0, $s2, -0x7B0\n"
        "addiu      $a1, $zero, 0x63\n"
        "jal        func_802A001C_de\n"
        "addiu     $a2, $zero, 0x200\n"
        "addiu      $s0, $s2, -0x9E0\n"
        "addu       $a0, $s0, $zero\n"
        "addiu      $a1, $zero, 0x63\n"
        "lui        $a2, %hi(D_0023C934)\n"
        "addiu      $a2, $a2, %lo(D_0023C934)\n"
        "addu       $a3, $zero, $zero\n"
        "addiu      $v0, $s2, -0x5B0\n"
        "sw         $v0, 0x10($sp)\n"
        "addiu      $v0, $zero, 0x93\n"
        "jal        func_802BAC90_de\n"
        "sw        $v0, 0x14($sp)\n"
        "jal        func_802BB750_de\n"
        "addu      $a0, $s0, $zero\n"
        "lw         $ra, 0x2C($sp)\n"
        "lw         $s4, 0x28($sp)\n"
        "lw         $s3, 0x24($sp)\n"
        "lw         $s2, 0x20($sp)\n"
        "lw         $s1, 0x1C($sp)\n"
        "lw         $s0, 0x18($sp)\n"
        "jr         $ra\n"
        "addiu     $sp, $sp, 0x30\n"
    );
}
#else
INCLUDE_ASM("span_1000", func_8023B9B0_de);
#endif
#endif

/* Array views share measured storage: FF F2A - FF B5B = 0x3CF;
 * the two four-byte-stride index streams occupy adjacent bytes. */

extern PagerState D_800FF230;

extern ResourcePageMapping *D_800FFE20;

static __inline__ ResourcePageMapping *readLink(ResourcePageMapping **value) { return *value; }

static __inline__ void writeLink(ResourcePageMapping **where, ResourcePageMapping *value) { *where = value; }

/* Releases one page of a resource's TLB slot: clears the odd (flag 1) or even page of the slot's entry in
 * D_80103F28 and, when the other page is still in use, remaps the slot with only that page through
 * func_802AD370_de; otherwise it unmaps the slot through osUnmapTLB and frees its virtual page. The
 * resource then has no slot. */







int func_8023BC74_de(void) {
    u16 previous;
    s16 index;
    previous = D_800FFFA0[0];
    D_800FFFA0[0] = previous + 1;
    if ((s16)(previous + 1) >= 24) {
        D_800FFFA0[0] = D_800FFFA0[1];
    }
    index = (s16)previous;
    if (D_800FFB5B.first.indices[index * 4] != 0xFF) {
        D_800FFB5B.marks[D_800FFB5B.first.indices[index * 4] << 4] = 0xFF;
        D_800FFB5B.first.indices[index * 4] = 0xFF;
    }
    if (D_800FFB5B.second.indices[index * 4] != 0xFF) {
        D_800FFB5B.marks[D_800FFB5B.second.indices[index * 4] << 4] = 0xFF;
        D_800FFB5B.second.indices[index * 4] = 0xFF;
    }
    return index;
}

void func_8023BD34_de(s16 flags, ResourcePageMapping *item, s32 unused, u8 *out) {
    extern void func_802AD370_de(s32, s32, s32, u32, s32, s32);
    u8 *pair;
    s32 mapped;
    s32 slot;
    ResourcePageMapping *entry;
    u32 first;
    s32 second;
    pair = out;
    if (flags & 1) pair = out - 1;
    if (pair[0] != 0xFF && D_800FFB5B.marks[pair[0] * 16] != 0xFF) {
        slot = D_800FFB5B.marks[pair[0] * 16];
        D_80103F28[(s16)slot].slot = item->index;
    } else if (pair[1] != 0xFF && D_800FFB5B.marks[pair[1] * 16] != 0xFF) {
        slot = D_800FFB5B.marks[pair[1] * 16];
        D_80103F28[(s16)slot].team = item->index;
    } else {
        slot = func_8023BC74_de();
        if (flags & 1) {
            D_80103F28[(s16)slot].slot = item->index;
            if (pair[0] != 0xFF) {
                entry = &D_800FF230.slots[pair[0]].chain;
                D_80103F28[(s16)slot].team = entry->index;
                entry->slot = slot;
                if (readLink(&entry->prev) != 0) readLink(&entry->prev)->next = readLink(&entry->next);
                else { D_800FFE20 = readLink(&entry->next); readLink(&entry->next)->prev = 0; }
                if (readLink(&entry->next) != 0) readLink(&entry->next)->prev = readLink(&entry->prev);
                else { D_800FFE24 = readLink(&entry->prev); readLink(&entry->prev)->next = 0; }
                writeLink(&entry->next, 0);
                writeLink(&entry->prev, D_800FF230.tail);
                if (D_800FF230.tail != 0) D_800FF230.tail->next = entry;
                D_800FFE24 = entry;
                if (D_800FFE20 == 0) D_800FFE20 = entry;
            }
        } else {
            D_80103F28[(s16)slot].team = item->index;
            if (pair[1] != 0xFF) {
                entry = &D_800FF230.slots[pair[1]].chain;
                D_80103F28[(s16)slot].slot = entry->index;
                entry->slot = slot;
                if (readLink(&entry->prev) != 0) readLink(&entry->prev)->next = readLink(&entry->next);
                else { D_800FFE20 = readLink(&entry->next); readLink(&entry->next)->prev = 0; }
                if (readLink(&entry->next) != 0) readLink(&entry->next)->prev = readLink(&entry->prev);
                else { D_800FFE24 = readLink(&entry->prev); readLink(&entry->prev)->next = 0; }
                writeLink(&entry->next, 0);
                writeLink(&entry->prev, D_800FF230.tail);
                if (D_800FF230.tail != 0) D_800FF230.tail->next = entry;
                D_800FFE24 = entry;
                if (D_800FFE20 == 0) D_800FFE20 = entry;
            }
        }
        D_80103F28[(s16)slot].id = flags & 0xFFFE;
    }
    item->id = flags;
    item->slot = slot;
    *out = item->index;
    mapped = (s16)slot;
    unused = D_80103F28[mapped].id << 12;
    if (D_80103F28[mapped].team != 0xFF)
        first = ((u32)&D_8014E000 & 0x3FFFFFF) + (D_80103F28[mapped].team << 12);
    else first = -1;
    func_802AD370_de(mapped, 0, unused, first,
        D_80103F28[(s16)slot].slot != 0xFF ? ((u32)&D_8014E000 & 0x3FFFFFF) + (D_80103F28[(s16)slot].slot << 12) : -1, 7);
}

void func_8023C084_de(ResourcePageMapping *mapping) {
    extern void func_802AD370_de(s32, s32, s32, u32, s32, s32);
    s32 slot;

    if (mapping->slot == 0xFF) {
        return;
    }
    if (mapping->id & 1) {
        D_80103F28[mapping->slot].slot = 0xFF;
        slot = mapping->slot;
        if (D_80103F28[slot].team == 0xFF) {
            goto unmap;
        }
        func_802AD370_de(slot, 0, D_80103F28[slot].id << 12,
                      ((s32)&D_8014E000 & 0x3FFFFFF) + (D_80103F28[slot].team << 12), -1, 7);
    } else {
        D_80103F28[mapping->slot].team = 0xFF;
        slot = mapping->slot;
        if (D_80103F28[slot].slot == 0xFF) {
        unmap:
            osUnmapTLB(slot);
            D_80103F28[mapping->slot].id = 0xFFFF;
        } else {
            func_802AD370_de(slot, 0, D_80103F28[slot].id << 12, -1,
                          ((s32)&D_8014E000 & 0x3FFFFFF) + (D_80103F28[slot].slot << 12), 7);
        }
    }
    mapping->slot = 0xFF;
}

#include "SCHED/RESOURCE_PAGE_WORKER.H"
extern s32 D_800CB3F8_de;
extern f32 D_800C3610_de, D_800C3614_de, D_800C3618_de, D_800C361C_de;
u64 func_802BADC0_de(void);
void *func_8023CBC0_de(u16);
void osWritebackDCacheAll(void);
void func_802BD170_de(s32);
void func_802BB750_de(void *);

static __inline__ void detachPage(ResourcePageMapping *mapping) {
    if (readLink(&mapping->prev)) readLink(&mapping->prev)->next = readLink(&mapping->next);
    else {
        D_800FFE20 = readLink(&mapping->next);
        readLink(&mapping->next)->prev = 0;
    }
    if (readLink(&mapping->next)) readLink(&mapping->next)->prev = readLink(&mapping->prev);
    else {
        D_800FFE24 = readLink(&mapping->prev);
        readLink(&mapping->prev)->next = 0;
    }
}
/* The pager uses the same two-pointer list operations as its worker. */
/* The LRU list as the pager helpers see it: head D_800FFE20, tail D_800FFE24, reached through a list pointer. */
typedef struct PageList { ResourcePageMapping *head, *tail; } PageList;
static __inline__ ResourcePageMapping *oldestPage(PageList *list) {
    return list->head;
}
static __inline__ void appendPage(Field_void_4 *list, void *node) {
    void *tail;
    *(void **)node = 0;
    ((Field_void_4 *)node)->value = list->value;
    tail = list->value;
    if (tail) *(void **)tail = node;
    list->value = node;
    if (!*(void **)list) *(void **)list = node;
}
static __inline__ Region *findPageRegion(u32 page) {
    Region *region;
    for (region = &D_800FF230.regions; region != 0; region = region->next) {
        if (page >= region->start && page < region->start + region->pages) break;
    }
    return region;
}
void Virtual_HandleResourcePageRequest(void) {
    ResourcePageThread *thread;
    Region *region;
    ResourcePageMapping *mapping;
    ResourcePageJob *job;
    u8 *slot;
    u32 page, kind;
    u64 start, elapsed;
    f32 duration;
    f32 scale;
    f32 limit;
    thread = func_802BAD70_de();
    kind = thread->message & 0x7C;
    if (kind == 4 || kind == 8) {
        D_800FF230.counters.requests++;
        page = thread->address >> 12;
        region = findPageRegion(page);
        if (region) {
            D_800FF230.counters.lastAddress = thread->address;
            slot = &region->map[page - region->start];
            if (*slot != 0xFF) {
                mapping = &D_800FF230.slots[*slot].chain;
                if (mapping->slot == 0xFF) {
                    detachPage(mapping);
                    func_8023BD34_de(page, mapping, thread->slot, slot);
                    appendPage((Field_void_4 *)&D_800FFE20, mapping);
                }
                thread->state = 2;
                func_802BB750_de(thread);
                return;
            }
            func_802BB2A0_de(&D_800FF230.jobs, (void **)&job, 1);
            D_800FF230.counters.misses++;
            job->source = region->source[page - region->start];
            job->size = 4096;
            mapping = oldestPage((PageList *)&D_800FFE20);
            detachPage(mapping);
            func_8023C084_de(mapping);
            if (mapping->id != 0xFFFF) {
                Region *previousRegion = func_8023CBC0_de(mapping->id);
                previousRegion->map[mapping->id - previousRegion->start] = 0xFF;
                mapping->id = 0xFFFF;
            }
            mapping->fieldC = 0;
            job->mapping = mapping;
            job->page = page;
            job->slot = slot;
            job->thread = thread;
            func_802BB420_de(&D_800FF230.pending, job, 1);
            return;
        }
        start = func_802BADC0_de();
        scale = D_800C3610_de;
        limit = D_800C3614_de;
        do {
            elapsed = ((func_802BADC0_de() - start) << 6) / 3000;
            duration = elapsed;
        } while (duration * scale < limit);
    } else {
        start = func_802BADC0_de();
        scale = D_800C3618_de;
        limit = D_800C361C_de;
        do {
            elapsed = ((func_802BADC0_de() - start) << 6) / 3000;
            duration = elapsed;
        } while (duration * scale < limit);
    }
    osWritebackDCacheAll();
    func_802BD170_de(1);
    ((void (*)(void))0x80000400)();
    D_800CB3F8_de = -1;
    thread->state = 2;
    func_802BB750_de(thread);
}
