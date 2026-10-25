#ifndef RENDER_3_RANGENODE_H
#define RENDER_3_RANGENODE_H
struct SceneEffectPool;
#ifndef SPAN_1000_CODE_80268160_H
#define SPAN_1000_CODE_80268160_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/OBJRECAT5F14.H"
struct SceneEffect;
struct RangeNode;
typedef struct RangeNode RangeNode;

struct Blast;
typedef struct Blast Blast;

extern float D_800C4468_de;

struct OwnerRecAt16D4;
struct OwnerRecAt16D4 {
    char pad0[8];
    CVector3 pos;
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

struct OwnerRecAt16D4;
typedef struct OwnerRecAt16D4 OwnerRecAt16D4;

extern float D_800C9564;

extern float D_800C9560;

extern float D_800C446C_de;

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

struct Filter;
struct Filter {
    u8 type;
    u8 pad[0x17B];
    s32 mask;
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

extern void func_802689BC_de(LevelActor *arg0, int arg1, int arg2, Blast blast);

typedef CVector3 Vec3f;
extern struct SceneEffect *func_802627A0_de(struct SceneEffectPool *scene, s32 variant, s32 owner, CVector3 position, f32 scale, CVector3 direction,
                      CVector3 color, s32 *ref);

#endif
#endif
