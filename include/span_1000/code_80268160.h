struct SceneEffectPool;
#ifndef UNBAKE_SPAN_1000_CODE_80268160_H
#define UNBAKE_SPAN_1000_CODE_80268160_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_1000/code_802624A0.h"
#include "types.h"
struct RangeNode;
typedef struct RangeNode RangeNode;

struct Blast;
typedef struct Blast Blast;

extern float D_800C4468_de;

struct OwnerRecAt16D4;
struct OwnerRecAt16D4 {
    char pad0[8];
    Vec3 pos;
    char pad14[0x16D4 - 0x14];
    s32 alive;
};

struct ActorRecAt1D8V3;
struct OwnerRecAt16D4;
struct ActorRecAt1D8V3 {
    u8 kind;
    char pad1[0x100 - 1];
    s32 flags;
    char pad104[0x1D8 - 0x104];
    struct OwnerRecAt16D4 *owner;
};

struct Limit;
typedef struct Limit Limit;

struct func_802689BC_S1;
struct func_802689BC_S1 {
    char pad0[0xF];
    char unkF;
};

extern void func_80268264_de(int arg0, int arg1, int arg2, int arg3, ...);

struct ParamsRecAt4;
typedef struct ParamsRecAt4 ParamsRecAt4;

struct ActorRecAt1D8V3;
typedef struct ActorRecAt1D8V3 ActorRecAt1D8V3;

struct Blast;
struct Blast {
    char pad0[0xC];
    s32 radius;
    s32 damage;
};

extern void func_802688E4_de(ActorRecAt1D8V3 *arg0, Player *arg1, s32 arg2, Blast blast);

struct Params_func_802681A8_de;
struct Params_func_802681A8_de {
    s32 value;
    s16 angle;
    u8 scale;
    u8 pad;
};

struct ObjectRecAt17C;
typedef struct ObjectRecAt17C ObjectRecAt17C;

struct func_802689BC_S2;
typedef struct func_802689BC_S2 func_802689BC_S2;

struct OwnerRecAt16D4;
typedef struct OwnerRecAt16D4 OwnerRecAt16D4;

struct func_80268C1C_S2;
typedef struct func_80268C1C_S2 func_80268C1C_S2;

extern float D_800C9564;

extern float D_800C9560;

extern float D_800C446C_de;

struct func_802689CC_S1;
typedef struct func_802689CC_S1 func_802689CC_S1;

struct RangeNode;
struct RangeNode {
    char pad0[4];
    struct RangeNode *next;
    u16 *radius;
    char padC[4];
    s16 x;
    s16 y;
    s16 z;
    s16 active;
};

struct Context_func_802681A8_de;
typedef struct Context_func_802681A8_de Context_func_802681A8_de;

struct ParamsRecAt4;
struct ParamsRecAt4 {
    s16 unk0;
    s16 value;
    s32 team;
};

extern void func_802684B8_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

struct Kind;
struct Kind {
    s32 value;
    u8 pad4[0xA];
    s8 team;
};
struct Kind;
struct ObjectRecAt17C;
struct ObjectRecAt17C {
    u8 type;
    u8 pad1[0x17];
    struct Kind *kind;
    u8 pad1C[0xB4];
    s32 value;
    u8 padD4[0xA8];
    u32 mask;
};

struct func_802689CC_S1;
struct func_802689CC_S1 {
    char pad0[0x100];
    s32 unk100;
    char pad100[0x170 - 0x100 - sizeof(s32)];
    s32 unk170;
};

struct Filter;
struct Filter {
    u8 type;
    u8 pad[0x17B];
    s32 mask;
};

struct func_802689BC_S1;
typedef struct func_802689BC_S1 func_802689BC_S1;

struct func_80268C1C_S2;
struct func_80268C1C_S2 {
    char pad0[0x8];
    void * unk8;
    char pad8[0x16 - 0x8 - sizeof(void*)];
    s16 unk16;
};

extern float D_800C4490_de;

struct Params_func_802681A8_de;
typedef struct Params_func_802681A8_de Params_func_802681A8_de;

struct Filter;
typedef struct Filter Filter;

struct Inner;
struct Inner {
    char pad[0x698];
    char *resource;
};
struct Context_func_802681A8_de;
struct Inner;
struct Context_func_802681A8_de {
    char pad[0x1D8];
    struct Inner *inner;
};

extern float D_800C4494_de;

extern void func_802684E8_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

extern void func_802689BC_de(void *arg0, int arg1, int arg2, Blast blast);

struct func_802689BC_S2;
struct func_802689BC_S2 {
    char pad0[0x270];
    char unk270;
};

typedef Vec3 Vec3f;
extern Effect_func_80262A9C_de *func_802627A0_de(struct SceneEffectPool *scene, s32 variant, s32 owner, Vec3 position, f32 scale, Vec3 direction,
                      Vec3 color, s32 *ref);

#endif
