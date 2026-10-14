#ifndef UNBAKE_SPAN_16E000_CODE_80443868_H
#define UNBAKE_SPAN_16E000_CODE_80443868_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043F69C.h"
extern void func_80443BCC_de(void);

struct ActorRecAt260;
typedef struct ActorRecAt260 ActorRecAt260;

struct ActorRecAt260;
struct ActorRecAt260 {
    char pad[0x58];
    int flags58;
    char pad5c[0xC4];
    int flags120;
    char pad124[0x9C];
    int flags1c0;
    char pad1c4[0x4C];
    int flags210;
    char pad214[0x24];
    int flags238;
    char pad23c[0x24];
    int flags260;
};

struct ArgRecAt1C;
struct ArgRecAt1C {
    char pad[12];
    ActorRecAt260 *unkC;
    char pad2[12];
    int unk1C;
};

struct Sync;
struct Sync {
    char pad[0x54];
    int sync;
    char pad58[0x1C];
    int team;
};

struct ArgRecAt1C;
typedef struct ArgRecAt1C ArgRecAt1C;

extern void func_80443CD4_de(ArgRecAt1C *arg0);

struct Actor_func_804438BC_de;
struct Actor_func_804438BC_de {
    char pad0[4928];
    s32 unk1340;
    char pad1344[268];
    s32 unk1450;
};

struct Actor_func_804438BC_de;
struct StateRecAt1C;
struct StateRecAt1C {
    char pad0[28];
    struct Actor_func_804438BC_de * unk1C;
};

struct Entry_func_80443734_de;
typedef struct Entry_func_80443734_de Entry_func_80443734_de;

extern s32 func_80443710_de(void *arg0, MenuRules *arg1);

struct ObjectRecAt1C;
typedef struct ObjectRecAt1C ObjectRecAt1C;

struct Leaf;
struct Leaf {
    char pad[0x8E];
    u8 flag;
};
struct Leaf;
struct Middle;
struct Middle {
    char pad[0x5D8];
    struct Leaf *leaf;
};
struct Middle;
struct RootRecAt1C;
struct RootRecAt1C {
    char pad[0x1C];
    struct Middle *middle;
};

struct Owner_func_8043E1F8_de;
typedef struct Owner_func_8043E1F8_de Owner_func_8043E1F8_de;

struct ActorRecAt260;
struct ObjectRecAt1C;
struct ObjectRecAt1C {
    char pad[0xC];
    struct ActorRecAt260 *actor;
    char pad10[0xC];
    Owner_func_8043E1F8_de *parent;
};

extern void func_80443C14_de(ObjectRecAt1C *object);

struct Actor_func_80443844_de;
struct Actor_func_80443844_de {
    char pad[0x5D0];
    int waiting;
    char pad5D4[4];
    ObjRecAt8F *info;
};
struct Actor_func_80443844_de;
struct PlayerRecAt1C;
struct PlayerRecAt1C {
    char pad[0x1C];
    struct Actor_func_80443844_de *actor;
};

struct PlayerRecAt1C;
typedef struct PlayerRecAt1C PlayerRecAt1C;

extern int func_80443844_de(int unused, PlayerRecAt1C *player);

struct RecordRecAtCV3;
extern void func_80443BD4_de(struct RecordRecAtCV3 *record);

struct Entry_func_80443734_de;
struct Entry_func_80443734_de {
    char pad0[4];
    s32 width;
    char pad8[4];
    f32 scaleX;
    f32 scaleY;
    char pad14[2];
    u16 x;
    char pad18[6];
    u16 y;
};

extern void func_80443734_de(ObjRecAt1CV1 *arg0, Entry_func_80443734_de *arg1, s32 arg2, Style_func_8043C9AC_de *arg3);

struct Actor_func_804438BC_de;
typedef struct Actor_func_804438BC_de Actor_func_804438BC_de;

struct RootRecAt1C;
extern s32 func_804436F8_de(void *unused, struct RootRecAt1C *root);

extern void func_80443DD0_de(ArgRecAt1C *arg0);

struct StateRecAt1C;
typedef struct StateRecAt1C StateRecAt1C;

extern s32 func_804438BC_de(StateRecAt1C *arg0);

struct Sync;
typedef struct Sync Sync;

struct MenuRules;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_80443998_de(struct LayeredText *field, struct MenuRules *holder);
#endif

#endif
