#ifndef COMMON_ENTRYRECAT8V4_H
#define COMMON_ENTRYRECAT8V4_H
#include "TYPES.H"
#include "COMMON/KEYRECAT1C.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/LOCALDECODERANGE.H"

extern CVector3 func_8040385C_de(void);



struct EntryRecAt8V4;
struct EntryRecAt8V4 {
    f32 time;
    s32 side;
    s32 index;
};

struct Record_func_80403458_de;
typedef struct Record_func_80403458_de Record_func_80403458_de;


struct EntryRecAt4V2;
typedef struct EntryRecAt4V2 EntryRecAt4V2;

struct State_func_8040385C_de;
typedef struct State_func_8040385C_de State_func_8040385C_de;

extern void func_80402BA0_de();

struct ItemRecAt12;
typedef struct ItemRecAt12 ItemRecAt12;

struct ItemRecAt12;
struct ItemRecAt12 {
    char pad0[0xE];
    u8 flags;
    char padF[2];
    u8 kind;
    u8 subkind;
    u8 bitIndex; /* 0x13: persistent trigger bit */
};

struct Tables;
struct Tables {
    char pad0[0x11D0];
    ItemRecAt12 *items[2];
};


struct State_func_8040385C_de;
struct State_func_8040385C_de {
    char a[4];
    void *unk4;
    char b[0x30];
    s32 unk38;
};



struct EntryRecAt18V5;
struct EntryRecAt18V5 {
    s32 id0;
    s32 id4;
    s32 id8;
    s32 flags;
    char pad10[8];
    char name[0x34];
};

extern void func_80403B2C_de(u8 *bits, s32 n, s32 set);

extern float D_800DCC7C_de;

struct Tables;
typedef struct Tables Tables;

extern u32 func_80403B0C_de(u8 *bits, s32 index);

struct Record_func_80402FB4_de;
struct Record_func_80402FB4_de {
    char pad0[0x18];
    s32 owner;
    char pad1C[0x58 - 0x1C];
    s32 pending;
    char pad5C[0xD8 - 0x5C];
    s32 id;
    s32 index;
};

struct Spline;
typedef struct Spline Spline;

struct EntryRecAt18V5;
typedef struct EntryRecAt18V5 EntryRecAt18V5;

extern CVector3 func_8040390C_de(void);

struct SplineNode;
struct SplineNode {
    CVector3 p;
    CVector3 d2p;
    f32 s;
    f32 w;
    f32 d2s;
};

struct SplineNode;
typedef struct SplineNode SplineNode;

struct Spline;
struct Spline {
    s32 nodeSize;
    s32 count;
    SplineNode nodes[1];
};

extern f32 func_804039C4_de(void);

struct EntryRecAt8V4;
typedef struct EntryRecAt8V4 EntryRecAt8V4;

struct EntryRecAt4V2;
struct EntryRecAt4V2 {
    s32 id0;
    s32 id4;
    char pad8[0x44];
};



extern void *func_80403B04_de(void *value);


struct State_func_804039C4_de;
typedef struct State_func_804039C4_de State_func_804039C4_de;



struct Record_func_804030E0_de;
typedef struct Record_func_804030E0_de Record_func_804030E0_de;


extern void *func_80403ADC_de(void);

struct Record_func_80403458_de;
struct Record_func_80403458_de {
    char pad0[4];
    s32 resource;
    char pad8[0x14];
    f32 time;
    char pad20[0x14];
    f32 endTime;
    char pad38[0x18];
    s32 active;
    char pad54[4];
    s32 pending;
};

extern s32 func_80403A64_de();

struct Record_func_804030E0_de;
struct Record_func_804030E0_de {
    char pad0[0x18];
    s32 owner;
    char pad1C[0x58 - 0x1C];
    s32 pending;
    char pad5C[0xD8 - 0x5C];
    s32 id;
    s32 index;
    s32 key;
};


struct State_func_804039C4_de;
struct State_func_804039C4_de {
    s32 a;
    s32 *unk4;
};

extern f32 D_800E0B60[];

struct Record_func_80402FB4_de;
typedef struct Record_func_80402FB4_de Record_func_80402FB4_de;

typedef struct ScreenRectangle { char pad0[0x29c]; f32 x,y,width,height; } ScreenRectangle;

typedef struct SplineSource { s32 stride,count; union { char data[0]; CVector3 points[0]; f32 weights[0]; }; } SplineSource;
typedef struct SplineTable { s32 count; } SplineTable;
extern int func_8028FEB8_de(int *);
extern void func_802610A8_de(void *,s32);
extern char *func_802610F0_de(Pack *,s32,s32);
typedef union SplineSourceCursor { SplineSource *header; CVector3 *points; f32 *weights; } SplineSourceCursor;

extern char D_0040067C[];
extern char D_800DCB10[];
extern void *func_80403A90_de(s32);
#endif
