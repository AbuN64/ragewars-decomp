#ifndef UNBAKE_SPAN_1000_CODE_802508E0_H
#define UNBAKE_SPAN_1000_CODE_802508E0_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
extern int func_80250DE0_de(void *object);

struct Manager;
struct Manager {
    char queue[0x92C];
    IntrusiveList pending;
    IntrusiveList active;
    char padActive[0x20 - sizeof(IntrusiveList)];
    char lock[0x18];
    char unk978[0x24];
    s32 mask;
};

extern int D_801005A0[];

struct CachedResource;
typedef struct CachedResource CachedResource;

struct Manager_func_802524B0_de;
struct Manager_func_802524B0_de {
    char queue[0x92C];
    IntrusiveList pending;
    IntrusiveList active;
    char padActive[0x20 - sizeof(IntrusiveList)];
    char lock[0x18];
};

struct Node_func_802524B0_de;
typedef struct Node_func_802524B0_de Node_func_802524B0_de;

extern int func_802532F4_de(void *arg0);

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

extern void func_80253300_de(void *arg0);

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

struct Manager_func_802524B0_de;
typedef struct Manager_func_802524B0_de Manager_func_802524B0_de;

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
struct ObjectState13 {
    unsigned char padding_0[18];
    signed char unk_12;
};

struct Manager;
typedef struct Manager Manager;

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
struct Owner_func_80250C84_de {
    char pad0[0x20];
    s32 field20;
    char pad24[4];
    char transform[0xA8];
    s32 flagsD0;
    char padD4[6];
    u8 colorFrame;
};

struct ResourceCacheEntry;
typedef struct ResourceCacheEntry ResourceCacheEntry;

struct func_80250D88_S2;
typedef struct func_80250D88_S2 func_80250D88_S2;

struct CachedResource;

extern void *func_802517B4_de(s32 arg0, s32 arg1);

extern void func_80250AD4_de(void *arg0);




extern int func_80250BF0_de();

struct func_802532A0_S1;
struct func_802532A0_S1 {
    char pad0[0x8];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    unsigned int unkC;
};




extern s8 func_80250E14_de(void *arg0);

extern void func_80250A9C_de();

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
struct ObjectLinksDC {
    char pad0[0x18];
    char * unk_18;
    char pad18[0xD8 - 0x18 - sizeof(char*)];
    unsigned short unk_D8;
};

struct ResourceHashEntry;
typedef struct ResourceHashEntry ResourceHashEntry;

extern void func_802524B0_de(void *arg);

extern void func_8025331C_de(void *arg0);

struct Owner_func_80250C84_de;
typedef struct Owner_func_80250C84_de Owner_func_80250C84_de;

struct ResourceHashEntry;

struct ResourceLoadRequest;
typedef struct ResourceLoadRequest ResourceLoadRequest;

struct Shape_func_802BC570_de;
struct Shape_func_802BC570_de {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct ResourceLoadRequest;

struct func_80250D88_S1;
typedef struct func_80250D88_S1 func_80250D88_S1;





/* Shared object layout established by resource-binding consumers. */
struct ResourceBinding {
    u8 padding000[1];
    s8 variant; /* 0x01 */
    u8 padding002[0x1E];
    s32 *resource; /* 0x20: loaded resource descriptor */
    u8 padding024[4];
    u8 transform[0x8C]; /* 0x28 */
    void *loadedResource; /* 0xB4 */
    u8 runtimeState[0x18]; /* 0xB8 */
    s32 registrationFlags; /* 0xD0 */
    u8 padding0D4[4];
    u16 status; /* 0xD8 */
    u8 colorFrame; /* 0xDA */
};

typedef struct State802532E4 {
    s32 active;
    s32 count;
} State802532E4;
extern void func_802515F0_de(s32, s32);

/* Actor resource fade selects the near/far value using its frame threshold. */
struct ResourceFadeDefinition {
    u8 reserved0[0xE];
    s8 nearValue; /* 0xE */
    s8 farValue; /* 0xF */
    u8 reserved10[0x14];
    u32 threshold; /* 0x24 */
};

#endif
