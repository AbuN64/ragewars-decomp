struct Shared_Actor;
#ifndef UNBAKE_SPAN_1000_CODE_80279208_H
#define UNBAKE_SPAN_1000_CODE_80279208_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
extern int D_8011BF00;

struct List802795C0;
struct List802795C0 {
    Link_func_802596B4_de *head;
    Link_func_802596B4_de *tail;
    int count;
};

struct ListHeader;
typedef struct ListHeader ListHeader;

struct ListHeader;
struct ListHeader {
    void *head;
    void *tail;
    s32 count;
};

extern s16 func_80279798_de(s16 *arg0);

struct Lists18;
typedef struct Lists18 Lists18;

struct IntegerState5AC;
typedef struct IntegerState5AC IntegerState5AC;

struct func_80279490_S1;
struct func_80279490_S1 {
    char pad0[0x4];
    u16 unk4;
    char pad4[0xA - 0x4 - sizeof(u16)];
    u16 unkA;
    char padA[0x11 - 0xA - sizeof(u16)];
    u8 unk11;
    char pad11[0x12 - 0x11 - sizeof(u8)];
    u8 unk12;
};

extern void func_802791F0_de(void *object);

struct Trigger;
typedef struct Trigger Trigger;

extern void func_802794B0_de(ListHeader *list);

struct List802795C0;
typedef struct List802795C0 List802795C0;

struct Lists18;
struct Lists18 {
    List802795C0 active;
    List802795C0 inactive;
};

extern void func_80279198_de(int arg0, int arg1, void *arg2);

extern void func_802791D8_de(struct Shared_Actor *arg0);

struct WeightedTable;
struct WeightedTable {
    s16 count;
    s16 entries[25][2]; /* 24 choices and the terminating entry */
    s16 reserved; /* Complete 0x68-byte caller storage. */
};

struct ObjectLinks1BC;
typedef struct ObjectLinks1BC ObjectLinks1BC;

struct ObjectLinks1BC;
struct ObjectLinks1BC {
    char pad0[0x4];
    u16 unk_4;
    char pad4[0x118 - 0x4 - sizeof(u16)];
    char * unk_118;
    char pad118[0x12C - 0x118 - sizeof(char*)];
    char * unk_12C;
    char pad12C[0x1B8 - 0x12C - sizeof(char*)];
    s8 unk_1B8;
    char pad1B8[0x1B9 - 0x1B8 - sizeof(s8)];
    s8 unk_1B9;
    char pad1B9[0x1BA - 0x1B9 - sizeof(s8)];
    s8 unk_1BA;
};

struct ObjectStateC4;
typedef struct ObjectStateC4 ObjectStateC4;

struct Actor_func_80279B40_de;
struct Actor_func_80279B40_de {
    char pad0[8];
    Vec3 position;
    char pad14[8];
    Vec3 facing;
    char pad28[0x34];
    s32 flags;
    char pad60[0xB8];
    ObjRecAt14V3 *def;
    char pad11C[0x10];
    void *owner;
    s32 unk130;
    s32 unk134;
    char pad138[0x48];
    f32 offsetX;
    f32 offsetY;
    s32 angle;
};

extern void func_802795B0_de(ListHeader *lists, void *pool, s32 stride, s32 count);

struct ObjectStateC4;
struct ObjectStateC4 {
    unsigned char padding_0[190];
    u16 unk_BE;
    unsigned char padding_C0[2];
    u16 unk_C2;
};



extern void func_802791B8_de(void *arg0);

struct func_80279490_S1;
typedef struct func_80279490_S1 func_80279490_S1;

struct Actor_func_80279B40_de;
typedef struct Actor_func_80279B40_de Actor_func_80279B40_de;

struct Trigger;
struct Trigger {
    s32 mask;
    s32 unk4;
    s32 unk8;
    union {
        s32 word;
        struct {
            u16 unkC;
            u8 state;
            u8 id;
        } bytes;
    } flags;
    s32 unk10;
};

struct WeightedTable;
typedef struct WeightedTable WeightedTable;

struct IntegerState5AC;
struct IntegerState5AC {
    char pad0[0x59C];
    s32 unk_59C;
    char pad59C[0x5A4 - 0x59C - sizeof(s32)];
    s32 unk_5A4;
    char pad5A4[0x5A8 - 0x5A4 - sizeof(s32)];
    s32 unk_5A8;
};

extern void func_802794A4_de(void * arg0);
#endif
