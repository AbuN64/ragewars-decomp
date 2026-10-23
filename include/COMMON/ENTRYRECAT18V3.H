#ifndef COMMON_ENTRYRECAT18V3_H
#define COMMON_ENTRYRECAT18V3_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
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
    struct ResourceLoadRequest *value;
    s32 index;
    struct EntryRecAtCV1 *next;
};

struct func_80255428_S3;
typedef struct func_80255428_S3 func_80255428_S3;

struct HashSlot;
struct HashSlot {
    s32 key;
    s32 value;
    u32 index;
    struct HashSlot *next;
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


struct Block80255720;
struct Pool80255720;



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

struct HashSlot;
typedef struct HashSlot HashSlot;

struct BlockRecAt20;
struct HeapRecAtC;

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



extern s32 D_800CD8AC_de;
extern s32 D_800CD704;
extern s32 D_800CD8AC_de;

extern s32 D_80101198;
extern EntryRecAtCV1 *D_80101194;
extern s32 D_800CB6F8;
#endif
