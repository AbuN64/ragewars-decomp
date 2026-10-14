#ifndef UNBAKE_SPAN_1000_CODE_80254CE4_H
#define UNBAKE_SPAN_1000_CODE_80254CE4_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
struct func_80255428_S3;
struct func_80255428_S3 {
    char pad0[0xC];
    s32 * unkC;
};

struct EntryRecAt18V3;
struct EntryRecAt18V3 {
    char pad0[0xC];
    s32 flags;
    s32 stamp;
    s32 pad14;
    struct EntryRecAt18V3 *next;
};

struct EntryList;
struct EntryRecAt18V3;
struct EntryList {
    s32 pad0;
    struct EntryRecAt18V3 *first;
};

struct Pool80255720;
typedef struct Pool80255720 Pool80255720;

struct EntryList;
typedef struct EntryList EntryList;

union func_80255428_S1_UC;
typedef union func_80255428_S1_UC func_80255428_S1_UC;

struct EntryRecAtCV1;
typedef struct EntryRecAtCV1 EntryRecAtCV1;

struct Block80255720;
struct Block80255720 {
    struct Block80255720 *prev;
    struct Block80255720 *next;
    struct Block80255720 *prev_phys;
    struct Block80255720 *next_phys;
    s32 offset;
    s32 size;
};

struct Block80255720;
typedef struct Block80255720 Block80255720;

struct Pool80255ACC;
struct Pool80255ACC {
    s32 unk0;
    s32 unk4;
    Block80255720 *head;
    Block80255720 *tail;
};

struct EntryRecAtCV1;
struct EntryRecAtCV1 {
    u32 key;
    s32 value;
    s32 index;
    struct EntryRecAtCV1 *next;
};

struct func_80255428_S3;
typedef struct func_80255428_S3 func_80255428_S3;

struct Slot_func_802552E0_de;
struct Slot_func_802552E0_de {
    s32 key;
    s32 value;
    u32 index;
    struct Slot_func_802552E0_de *next;
};

union func_80255428_S1_UC;
union func_80255428_S1_UC {
    s32 * v0;
    s32 v1;
};

struct HeapRecAtC;
typedef struct HeapRecAtC HeapRecAtC;

struct func_802551C8_S1;
typedef struct func_802551C8_S1 func_802551C8_S1;

struct BlockRecAt20;
struct BlockRecAt20 {
    struct BlockRecAt20 *prevFree;
    struct BlockRecAt20 *nextFree;
    struct BlockRecAt20 *prev;
    struct BlockRecAt20 *next;
    u32 size;
    u32 free;
    u8 reserved18[8];
    u8 data[1]; /* +0x20: allocation payload */
};

struct EntryRecAt18V3;
typedef struct EntryRecAt18V3 EntryRecAt18V3;

extern void func_80255488_de(s32 arg0);

struct Block80255720;
struct Pool80255720;
struct Pool80255720 {
    s32 unk0;
    s32 unk4;
    struct Block80255720 *head;
    struct Block80255720 *tail;
    struct Block80255720 *anchor;
};

extern void func_80255780_de(Pool80255720 *arg0);

extern s32 func_80255540_de(s32 arg0);

struct func_80255428_S2;
typedef struct func_80255428_S2 func_80255428_S2;

struct BlockRecAt14;
struct BlockRecAt14 {
    struct BlockRecAt14 *next;
    struct BlockRecAt14 *previous;
    s32 a;
    s32 b;
    s32 header;
    s32 size;
};

struct BlockRecAt14;
struct Heap;
struct Heap {
    char *start;
    char *end;
    struct BlockRecAt14 *free;
    struct BlockRecAt14 *last;
    struct BlockRecAt14 *first;
};

struct Slot_func_802552E0_de;
typedef struct Slot_func_802552E0_de Slot_func_802552E0_de;

struct BlockRecAt20;
struct HeapRecAtC;
struct HeapRecAtC {
    char pad0[8];
    struct BlockRecAt20 *head;
    struct BlockRecAt20 *tail;
};

struct func_80255110_S2;
struct func_80255110_S2 {
    char pad0[0x230];
    s32 unk230;
};

struct Pool80255ACC;
typedef struct Pool80255ACC Pool80255ACC;

struct func_80255110_S2;
typedef struct func_80255110_S2 func_80255110_S2;

struct func_80255428_S1;
struct func_80255428_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    func_80255428_S1_UC unkC;
};

struct BlockRecAt20;
typedef struct BlockRecAt20 BlockRecAt20;

extern void func_802552E0_de(s32 capacity);

struct func_80255428_S1;
typedef struct func_80255428_S1 func_80255428_S1;

struct func_80255428_S2;
struct func_80255428_S2 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 * unkC;
};

struct func_802551C8_S1;
struct func_802551C8_S1 {
    char pad0[0x238];
    s32 unk238;
};

extern s32 D_80100560;


/* Resource-loader thread, its request queue, message slots and stack. */
typedef struct ResourceLoadWorker {
    u8 thread[0x230];
    struct RingQueue requests;
    s32 messages[128];
    u8 stack[0x1000];
} ResourceLoadWorker;

#endif
