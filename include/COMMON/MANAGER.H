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

struct OwnerStaticInstanceDrawGeometryVariant;

struct ResourceCacheEntry;
typedef struct ResourceCacheEntry ResourceCacheEntry;


struct CachedResource;






extern int StaticInstance_AdvanceResourceKey();





struct LevelActor;




struct ObjectLinksDC;
typedef struct ObjectLinksDC ObjectLinksDC;

struct ObjectLinksDC;

struct ResourceHashEntry;
typedef struct ResourceHashEntry ResourceHashEntry;



struct OwnerStaticInstanceDrawGeometryVariant;
typedef struct OwnerStaticInstanceDrawGeometryVariant OwnerStaticInstanceDrawGeometryVariant;

struct ResourceHashEntry;

struct ResourceLoadRequest;
typedef struct ResourceLoadRequest ResourceLoadRequest;

struct Shape_func_802BC570_de;

struct ResourceLoadRequest;








#endif
