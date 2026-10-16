#ifndef UNBAKE_SPAN_16E000_CODE_8041BEA8_H
#define UNBAKE_SPAN_16E000_CODE_8041BEA8_H
#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "resident_event_handler.h"
#include "span_16E000/code_8043962C.h"
struct Label;
typedef struct Label Label;

struct State_func_8041C40C_de;
struct State_func_8041C40C_de {
    char pad[0x14];
    int ticks;
    int paused;
};

struct State_func_8041DE5C_de;
struct State_func_8041DE5C_de {
    char pad[0xD8];
    s32 first;
    s32 second;
};

extern s32 func_8041C574_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Game_func_8041D960_de;
struct Game_func_8041D960_de {
    char pad0[0x17C1];
    u8 language;
};

struct Menu_func_8041D960_de;
typedef struct Menu_func_8041D960_de Menu_func_8041D960_de;

struct ObjRecAt480;
struct ObjRecAt480 {
    char pad[0x480];
    Vec3 unk480;
};

struct ProfileStatisticsScreen;
typedef struct ProfileStatisticsScreen ProfileStatisticsScreen;

extern void func_8041D960_de();

extern void func_8041D6A8_de();

struct Object49C;
struct Object49C {
    char pad[0x49C];
    s32 value;
};

struct ObjRecAt48C;
struct ObjRecAt48C {
    char pad[0x48C];
    Vec3 unk48C;
};

struct ObjRecAt48C;
typedef struct ObjRecAt48C ObjRecAt48C;

extern void func_8041CDDC_de(ObjRecAt48C *arg0, Vec3 v);

struct MenuRecAt10C;
typedef struct MenuRecAt10C MenuRecAt10C;

struct MenuRecAt108;
typedef struct MenuRecAt108 MenuRecAt108;

struct ObjRecAt480;
typedef struct ObjRecAt480 ObjRecAt480;

struct NodeRecAt10;
struct NodeRecAt10 {
    char pad0[0x10];
    s8 style;
};

struct Unk8041CE88;
typedef struct Unk8041CE88 Unk8041CE88;

struct Unk8041CE88;
struct Unk8041CE88 {
    char pad0[0x274];
    u16 unk274;
};

extern void func_8041CE18_de(Unk8041CE88 *arg0);

struct ObjRecAt498;
struct ObjRecAt498 {
    char pad[0x498];
    s32 unk498;
};

extern s32 func_8041C164_de();

struct MenuRecAt10C;
struct MenuRecAt10C {
    void *root;
    char pad4[0x108];
    s32 player;
};

struct Unk8041CE88;
extern void func_8041C610_de(struct Unk8041CE88 * arg0);

struct ObjRecAt498;
typedef struct ObjRecAt498 ObjRecAt498;

extern void func_8041CE08_de(ObjRecAt498 *arg0, s32 arg1);

struct Game_func_8041D960_de;
typedef struct Game_func_8041D960_de Game_func_8041D960_de;

struct Node_func_8041D134_de;
typedef struct Node_func_8041D134_de Node_func_8041D134_de;

struct MenuRecAt8;
struct MenuRecAt8 {
    char pad0[8];
    char model[1];
};

struct ProfileStatisticsScreen;
struct ProfileStatisticsScreen {
    void *handle;
    char pad4[0x10C - 4];
    s32 index;
    char kills[0x32];
    char wins[0x32];
    char deaths[0x32];
    char score[0x32];
    char count[0x32];
};

extern void func_8041C19C_de();

struct State_func_8041C40C_de;
typedef struct State_func_8041C40C_de State_func_8041C40C_de;

struct Node_func_8041D134_de;
struct Node_func_8041D134_de {
    char pad0[0x10];
    u8 style;
    char pad11[0x14 - 0x11];
    u16 x;
    u16 y;
};

struct Label;
struct Menu_func_8041D960_de;
struct Menu_func_8041D960_de {
    char pad0[0xEC];
    ObjRecAtCV1 *focus;
    struct Label *label;
    char padF4[0x18];
    s32 player;
};

struct ListRecAt4C;
typedef struct ListRecAt4C ListRecAt4C;

struct MenuRecAt8;
typedef struct MenuRecAt8 MenuRecAt8;

struct Screen_func_8041C2AC_de;
struct Screen_func_8041C2AC_de {
    void *parent;
    void *windows[4];
    s32 selection;
    s32 scroll;
    s32 state;
};

struct ListRecAt4C;
struct ListRecAt4C {
    char pad[0x48];
    int count;
    void *items[1];
};

struct NodeRecAt10;
typedef struct NodeRecAt10 NodeRecAt10;

struct State_func_8041DDF4_de;
struct State_func_8041DDF4_de {
    char pad0[0xEC];
    s32 value;
};

extern void func_8041CDB0_de(ObjRecAt480 *arg0, Vec3 v);

struct MenuRecAt108;
struct Node_func_8041D134_de;
struct MenuRecAt108 {
    char pad0[4];
    void *handle;
    char pad8[0xC8 - 8];
    struct Node_func_8041D134_de *left;
    char padCC[2];
    u16 leftStep;
    struct Node_func_8041D134_de *right;
    char padD4[2];
    u16 rightStep;
    s32 state;
    s32 timer;
    s32 fade;
    struct Node_func_8041D134_de *groupA;
    struct Node_func_8041D134_de *cursor;
    struct Node_func_8041D134_de *focus;
    char padF0[4];
    struct Node_func_8041D134_de *groupB;
    s32 styleStep;
    s32 styleValue;
    struct Node_func_8041D134_de *groupC;
    char pad104[3];
    u8 alphaStep;
    s32 clock;
};

extern void func_8041D4E0_de();

extern void func_8041B968_de(struct Object6C *object, s32 value);
extern void func_8041DA5C_de(s32 style);

extern void func_80439CD4_de(struct ObjectB8 *, s32);

#endif
