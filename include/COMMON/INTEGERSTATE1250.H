#ifndef COMMON_INTEGERSTATE1250_H
#define COMMON_INTEGERSTATE1250_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
extern f32 D_800C7E00;

struct IntegerState1250;
typedef struct IntegerState1250 IntegerState1250;

struct ObjectState12C4;
typedef struct ObjectState12C4 ObjectState12C4;

struct func_8022B7E8_S1;
struct func_8022B7E8_S1 {
    char pad0[0x5DC];
    void * unk5DC;
    char pad5DC[0x11E4 - 0x5DC - sizeof(void*)];
    f32 unk11E4;
    char pad11E4[0x13E0 - 0x11E4 - sizeof(f32)];
    void * unk13E0;
};

extern int func_8022B460_de(char *object);

struct func_8022B054_S1;
struct func_8022B054_S1 {
    char pad0[0x16C4];
    Triple unk16C4;
};

struct RecordCode8022AE90;
typedef struct RecordCode8022AE90 RecordCode8022AE90;

struct ObjectState16DA;

extern int func_8022BA90_de(void);

struct func_8022B3C0_S1;
typedef struct func_8022B3C0_S1 func_8022B3C0_S1;

struct func_8022B450_S1;
struct func_8022B450_S1 {
    char pad0[0x11FC];
    float unk11FC;
};

struct func_8022B7E8_S2;
struct func_8022B7E8_S2 {
    char pad0[0x100];
    s32 unk100;
    char pad100[0x5D8 - 0x100 - sizeof(s32)];
    char * unk5D8;
};

struct func_8022B450_S1;
typedef struct func_8022B450_S1 func_8022B450_S1;

struct Timer;
typedef struct Timer Timer;

struct ScoreTable;
struct ScoreTable {
    u8 pad00[0x3C];
    short value[8];
};
struct RecordCode8022AE90;
struct ScoreTable;
struct RecordCode8022AE90 {
    u8 pad0000[0x5D8];
    struct ScoreTable *scores;
    u8 pad05DC[0x16E0 - 0x5DC];
    struct RecordCode8022AE90 *next;
    u8 pad16E4[4];
};

struct ObjectState12C4;

struct ObjRecAt120C;
typedef struct ObjRecAt120C ObjRecAt120C;

struct Timer;
struct Timer {
    float step;
    float duration;
    int kind;
    float target;
    float elapsed;
    int tag;
};

struct Obj_func_8022B550_de;

struct func_8022AE90_S1;
struct func_8022AE90_S1 {
    char pad0[0x8];
    char unk8;
    char pad8[0x5DC - 0x8 - sizeof(char)];
    s32 unk5DC;
    char pad5DC[0x11BC - 0x5DC - sizeof(s32)];
    s32 unk11BC;
};

struct IntegerState1218;

struct func_8022B3C0_S1;
struct func_8022B3C0_S1 {
    char pad0[0x1200];
    CVector3 unk1200;
};

struct ObjectState13E4;

struct func_8022B2F4_S2;
typedef struct func_8022B2F4_S2 func_8022B2F4_S2;

struct func_8022B054_S1;
typedef struct func_8022B054_S1 func_8022B054_S1;

struct ObjRecAt120C;

struct func_8022AF64_S1;
typedef struct func_8022AF64_S1 func_8022AF64_S1;

extern void func_8022B484_de(char *arg0);

struct ObjectState16DA;
typedef struct ObjectState16DA ObjectState16DA;

struct Obj_func_8022B550_de;
typedef struct Obj_func_8022B550_de Obj_func_8022B550_de;

struct IntegerState16D4;

struct func_8022AF64_S1;
struct func_8022AF64_S1 {
    char pad0[0x8];
    char unk8;
    char pad8[0x5DC - 0x8 - sizeof(char)];
    s32 unk5DC;
    char pad5DC[0x11C0 - 0x5DC - sizeof(s32)];
    s32 unk11C0;
};


struct func_8022B08C_S2;

struct func_8022B08C_S1;

struct Context;
struct RecordCode8022AE90;
struct Context {
    u8 pad00[4];
    struct RecordCode8022AE90 *base;
    u8 pad08[0x18];
    struct RecordCode8022AE90 *head;
};

struct Game_func_8022B7F8_de;
typedef struct Game_func_8022B7F8_de Game_func_8022B7F8_de;

struct func_8022B08C_S1;
typedef struct func_8022B08C_S1 func_8022B08C_S1;

extern float D_800C7E08;

struct IntegerState11C0;

struct ObjectState13E4;
typedef struct ObjectState13E4 ObjectState13E4;

struct Context;
typedef struct Context Context;

extern void *func_8022BA0C_de(Context *context);

struct func_8022B74C_S1;
struct func_8022B74C_S1 {
    char pad0[0x5DC];
    s32 unk5DC;
    char pad5DC[0x13B0 - 0x5DC - sizeof(s32)];
    s32 unk13B0;
};

struct IntegerState16D4;
typedef struct IntegerState16D4 IntegerState16D4;

struct func_8022B2F4_S2;
struct func_8022B2F4_S2 {
    char pad0[0x5D0];
    s32 unk5D0;
    char pad5D0[0x11FC - 0x5D0 - sizeof(s32)];
    f32 unk11FC;
    char pad11FC[0x16E0 - 0x11FC - sizeof(f32)];
    void * unk16E0;
};

struct func_8022B08C_S2;
typedef struct func_8022B08C_S2 func_8022B08C_S2;

struct func_8022B74C_S1;
typedef struct func_8022B74C_S1 func_8022B74C_S1;

struct func_8022B7E8_S2;
typedef struct func_8022B7E8_S2 func_8022B7E8_S2;

struct func_8022AE90_S1;
typedef struct func_8022AE90_S1 func_8022AE90_S1;

struct IntegerState1250;

struct func_8022B720_S1;
typedef struct func_8022B720_S1 func_8022B720_S1;

struct IntegerState1218;
typedef struct IntegerState1218 IntegerState1218;

struct Game_func_8022B7F8_de;
struct Game_func_8022B7F8_de {
    char pad0[0x1240];
    MenuSettings settings;
};

struct func_8022B720_S1;
struct func_8022B720_S1 {
    char pad0[0x11DC];
    f32 unk11DC;
    char pad11DC[0x122C - 0x11DC - sizeof(f32)];
    s32 unk122C;
};

struct IntegerState11C0;
typedef struct IntegerState11C0 IntegerState11C0;

struct func_8022B7E8_S1;
typedef struct func_8022B7E8_S1 func_8022B7E8_S1;
#endif
