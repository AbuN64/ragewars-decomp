#ifndef COMMON_MANAGER_H
#define COMMON_MANAGER_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"

struct Manager;

extern int D_801005A0[];

struct CachedResource;
typedef struct CachedResource CachedResource;

struct Manager;

struct Node_func_802524B0_de;
typedef struct Node_func_802524B0_de Node_func_802524B0_de;


struct ObjectState13;
typedef struct ObjectState13 ObjectState13;

struct func_80250A7C_S1;
struct func_80250A7C_S1 {
    char pad0[0xD0];
    s32 unkD0;
    char padD0[0xD8 - 0xD0 - sizeof(s32)];
    u16 unkD8;
    char padD8[0xDA - 0xD8 - sizeof(u16)];
    u8 unkDA;
};


struct ResourceCacheEntry;
struct ResourceCacheEntry {
    s32 resource;
    s32 size;
    s32 references;
    s32 flags;
    s32 lastUsed;
    s32 owner;
    struct ResourceCacheEntry *next;
    s32 key;
    s32 pending;
    s32 callback;
};

struct CachedResource;
struct ResourceLoadRequest;
struct CachedResource {
    void *data;
    s32 unk04;
    s32 count;
    s32 flags;
    s32 stamp;
    struct ResourceLoadRequest *owner;
};

struct ResourceLoadRequest {
    struct CachedResource *node;
    struct CachedResource *extra; /* 0x04: optional companion resource */
    s32 key;
    s32 priority;
    s32 flags;                         /* 0x10 */
    void *tag;                         /* 0x14 */
    s32 owner;                         /* 0x18: bank/variation id */
    s32 mode;                          /* 0x1C */
    void *replyQueue;                  /* 0x20 */
    struct ResourceLoadRequest *next; /* 0x24 */
};

struct ResourceHashEntry;
struct ResourceLoadRequest;
struct ResourceHashEntry {
    s32 key;
    struct ResourceLoadRequest *value;
    s32 unk08;
    struct ResourceHashEntry *next;
};

struct Manager;
typedef struct Manager Manager;

struct func_80250D88_S1;
struct func_80250D88_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0xDC - 0x18 - sizeof(void*)];
    unsigned int unkDC;
};




struct func_802532A0_S1;
typedef struct func_802532A0_S1 func_802532A0_S1;

struct Request_func_802524B0_de;
typedef struct Request_func_802524B0_de Request_func_802524B0_de;

struct ObjectState13;

struct Manager;

struct Node_func_802524B0_de;
struct Node_func_802524B0_de {
    void *data;
    s32 pad4;
    s32 count;
    s32 flags;
};

struct Node_func_802524B0_de;
struct Request_func_802524B0_de;
struct Request_func_802524B0_de {
    struct Node_func_802524B0_de *node;
    s32 pad4[3];
    s32 flags;
};

struct Owner_func_80250C84_de;

struct ResourceCacheEntry;
typedef struct ResourceCacheEntry ResourceCacheEntry;

struct func_80250D88_S2;
typedef struct func_80250D88_S2 func_80250D88_S2;

struct CachedResource;






extern int func_80250BF0_de();

struct func_802532A0_S1;
struct func_802532A0_S1 {
    char pad0[0x8];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    unsigned int unkC;
};




struct LevelActor;


struct func_80250D88_S2;
struct func_80250D88_S2 {
    char pad0[0xE];
    signed char unkE;
    char padE[0xF - 0xE - sizeof(signed char)];
    signed char unkF;
    char padF[0x24 - 0xF - sizeof(signed char)];
    unsigned int unk24;
};

struct func_80250A7C_S1;
typedef struct func_80250A7C_S1 func_80250A7C_S1;

struct ObjectLinksDC;
typedef struct ObjectLinksDC ObjectLinksDC;

struct ObjectLinksDC;

struct ResourceHashEntry;
typedef struct ResourceHashEntry ResourceHashEntry;



struct Owner_func_80250C84_de;
typedef struct Owner_func_80250C84_de Owner_func_80250C84_de;

struct ResourceHashEntry;

struct ResourceLoadRequest;
typedef struct ResourceLoadRequest ResourceLoadRequest;

struct Shape_func_802BC570_de;

struct ResourceLoadRequest;

struct func_80250D88_S1;
typedef struct func_80250D88_S1 func_80250D88_S1;







#endif
