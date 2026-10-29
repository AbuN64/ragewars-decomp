#ifndef COMMON_ENTRYRECAT18V3_H
#define COMMON_ENTRYRECAT18V3_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"

struct CacheEvictionEntry;
struct CacheEvictionEntry {
    char pad0[0xC];
    s32 flags;
    s32 stamp;
    s32 pad14;
    struct CacheEvictionEntry *next;
};

struct EntryList;
struct CacheEvictionEntry;

struct Pool80255720;
typedef struct Pool80255720 Pool80255720;

struct EntryList;
typedef struct EntryList EntryList;


struct CacheHashEntry;
typedef struct CacheHashEntry CacheHashEntry;

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

struct CacheHashEntry;
struct CacheHashEntry {
    u32 key;
    struct ResourceLoadRequest *value;
    s32 index;
    struct CacheHashEntry *next;
};




struct HeapFreeBlockList;
typedef struct HeapFreeBlockList HeapFreeBlockList;


struct HeapAllocationBlock;
struct HeapAllocationBlock {
    struct HeapAllocationBlock *prevFree;
    struct HeapAllocationBlock *nextFree;
    struct HeapAllocationBlock *prev;
    struct HeapAllocationBlock *next;
    u32 size;
    u32 free;
    u8 reserved18[8];
    u8 data[1]; /* +0x20: allocation payload */
};

struct CacheEvictionEntry;
typedef struct CacheEvictionEntry CacheEvictionEntry;


struct Block80255720;
struct Pool80255720;





struct Heap;


struct HeapAllocationBlock;
struct HeapFreeBlockList;


struct Pool80255ACC;
typedef struct Pool80255ACC Pool80255ACC;



struct HeapAllocationBlock;
typedef struct HeapAllocationBlock HeapAllocationBlock;








extern s32 g_resourceLoadIdlePriority;
extern s32 g_resourceLoadPriorityBoost;
extern s32 g_resourceLoadIdlePriority;

extern s32 g_resourceHashIndexMask;
extern CacheHashEntry *g_resourceHashBuckets;
extern s32 g_resourceHashInitialized;
#endif
