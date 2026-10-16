#ifndef UNBAKE_SPAN_1000_CODE_80277444_H
#define UNBAKE_SPAN_1000_CODE_80277444_H
#include "types.h"
#include "common/types_06e4f7ef1f9e.h"
#include "resident_event_handler.h"
extern void func_80279158_de(void *arg0);

struct ObjectLinks150C;
typedef struct ObjectLinks150C ObjectLinks150C;

struct IntegerState1504;
struct IntegerState1504 {
    char pad0[0x1500];
    s32 unk_1500;
};

struct IntegerState1504;
typedef struct IntegerState1504 IntegerState1504;

struct ObjectRecAtBC;
struct ObjectRecAtBC {
    f32 falloff;
    f32 value;
    Vec3 direction; /* 0x08 */
    Vec3 axis; /* 0x14 */
    char pad20[0xB8-0x20];
    u8 flagB8;
    u8 flagB9;
    char padBA;
    u8 shape; /* 0xBB */
    u8 animationSeed; /* 0xBC */
};

struct ObjectRecAt8;
struct ObjectRecAt8 {
    u8 pad00[4];
    s32 count;
    u8 records[1];
};

struct ObjRecAt6V2;
struct ObjRecAt6V2 {
    char pad0[0x6];
    short unk6;
};

extern void func_80279048_de(void *arg0, void *arg1);

struct ObjectLinks150C;
struct ObjectLinks150C {
    unsigned char padding_0[5384];
    s32 *unk_1508;
};

extern float D_800C4AD8_de;

struct FloatState64;
typedef struct FloatState64 FloatState64;

struct Record14;
typedef struct Record14 Record14;

struct Record14;
struct Record14 {
    u32 coordinates[3];
    u16 lifetime;
    u8 flags;
    u8 kind;
    u8 state;
    u8 active;
    u8 mode;
    u8 reserved13;
};

struct ObjectState104;
struct ObjectState104 {
    unsigned char padding_0[8];
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    unsigned char padding_14[88];
    f32 unk_6C;
    unsigned char padding_70[144];
    s32 unk_100;
};

struct func_80278EEC_S1;
typedef struct func_80278EEC_S1 func_80278EEC_S1;

struct ObjectState104;
typedef struct ObjectState104 ObjectState104;

struct ObjRecAt6V2;
typedef struct ObjRecAt6V2 ObjRecAt6V2;

extern void func_80279178_de(void *arg0);

struct FloatState64;
struct FloatState64 {
    unsigned char padding_0[72];
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    unsigned char padding_54[12];
    f32 unk_60;
};

struct func_80278EEC_S1;
struct func_80278EEC_S1 {
    char pad0[0xE];
    char unkE;
};

struct Trigger;
extern void func_8027907C_de(s32 arg0, s32 arg1, struct Trigger *arg2);

struct ObjectRecAt8;
typedef struct ObjectRecAt8 ObjectRecAt8;

struct func_80278900_S1;
typedef struct func_80278900_S1 func_80278900_S1;

struct LevelActor;
extern void func_80278F68_de(struct LevelActor *object);

struct func_80278900_S1;
struct func_80278900_S1 {
    char pad0[0xBC];
    u8 unkBC;
};

extern void func_80279138_de(int arg0, int arg1, void *arg2);

extern s32 func_80278ABC_de(void);

struct ObjectRecAtBC;
typedef struct ObjectRecAtBC ObjectRecAtBC;

typedef struct Vertex38 { u8 pad0[6]; u16 flags; u8 pad8[4]; s8 x,y,z; u8 padF; } Vertex38;
typedef struct Vertices38 { s32 stride, count; Vertex38 vertices[1]; } Vertices38;
typedef struct Light38 { u8 pad0[0x11]; s8 x,y,z; } Light38;

struct WorldRecAt1B40C;
extern s32 func_8028C568_de(struct WorldRecAt1B40C *arg0, Record14 *arg1);

#endif
