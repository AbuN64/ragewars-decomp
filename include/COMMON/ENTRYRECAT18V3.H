#ifndef COMMON_ENTRYRECAT18V3_H
#define COMMON_ENTRYRECAT18V3_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"

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



union func_80255428_S1_UC;
union func_80255428_S1_UC {
    s32 * v0;
    s32 v1;
};

struct HeapRecAtC;
typedef struct HeapRecAtC HeapRecAtC;


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





struct Heap;


struct BlockRecAt20;
struct HeapRecAtC;


struct Pool80255ACC;
typedef struct Pool80255ACC Pool80255ACC;



struct BlockRecAt20;
typedef struct BlockRecAt20 BlockRecAt20;








extern s32 D_800CD8AC_de;
extern s32 D_800CD704;
extern s32 D_800CD8AC_de;

extern s32 D_80101198;
extern EntryRecAtCV1 *D_80101194;
extern s32 D_800CB6F8;
#endif
