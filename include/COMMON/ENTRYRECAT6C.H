#ifndef COMMON_ENTRYRECAT6C_H
#define COMMON_ENTRYRECAT6C_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"




struct EntryRecAt6C;
struct EntryRecAt6C {
    char pad0[0x58];
    s32 first;
    char pad5C[0x6C - 0x5C];
    s32 second;
    char pad70[2920 - 0x70];
};


struct ObjectState71;
struct ObjectState71 {
    char pad0[0x70];
    char unk_70;
};



struct Triple;



struct IntegerState346C;
typedef struct IntegerState346C IntegerState346C;



struct RecordRecAtD;
struct RecordRecAtD {
    s32 id;
    signed char kind;
    char pad5[7];
    s8 slot; /* 0xC */
    s8 place; /* 0xD */
    char padE[400 - 14];
};



struct Entry_func_80434FC4_de;
struct Entry_func_80434FC4_de {
    char pad0[0x2C];
    s32 phases[1];
    char pad30[0x68 - 0x30];
    void *window;
    char pad6C[2920 - 0x6C];
};

struct PlayerRecAtBA4;
struct PlayerRecAtBA4 {
    char pad[0x58];
    int state;
    char pad5C[0xBA0 - 0x5C];
    int phase;
    int timer;
};

struct Triple;


struct IntegerStateBC0;
typedef struct IntegerStateBC0 IntegerStateBC0;






struct func_80435898_S1;
struct func_80435898_S1 {
    char pad0[0xC];
    s8 unkC;
    char padC[0xD - 0xC - sizeof(s8)];
    s8 unkD;
};

extern int D_800E54A0;











struct IntegerState346C;
struct IntegerState346C {
    char pad0[0x3468];
    s32 unk_3468;
};



struct IntegerStateBC0;
struct IntegerStateBC0 {
    unsigned char padding_0[3004];
    s32 unk_BBC;
};

extern float D_800DDED0;

struct Triple;



struct State_func_80434D70_de;
struct State_func_80434D70_de {
    char pad0[4];
    s32 window;
    char pad8[0x50];
    s32 state;
    s32 step;
    s32 next;
    char pad64[8];
    s32 display;
    char pad70[0xB18];
    s32 reset;
    char padb8c[0x226C];
    s32 selected;
};

struct IntegerState3470;
struct IntegerState3470 {
    char pad0[0x3468];
    s32 unk_3468;
    char pad3468[0x346C - 0x3468 - sizeof(s32)];
    s32 unk_346C;
};

struct func_80435898_S1;
typedef struct func_80435898_S1 func_80435898_S1;

extern float D_800E1EF8;

struct PlayerRecAtBA4;
typedef struct PlayerRecAtBA4 PlayerRecAtBA4;

struct State_func_80434D70_de;
typedef struct State_func_80434D70_de State_func_80434D70_de;




struct ObjectState71;
typedef struct ObjectState71 ObjectState71;




struct IntegerState3470;
typedef struct IntegerState3470 IntegerState3470;


extern void func_804355E8_de(void);
#endif
