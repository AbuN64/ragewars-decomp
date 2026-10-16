#ifndef UNBAKE_SPAN_1000_CODE_802A25C4_H
#define UNBAKE_SPAN_1000_CODE_802A25C4_H
#include "TYPES.H"
/* Reset and accumulate the scale, weight and displacement of an effect. */
typedef struct EffectContribution {
    s32 id;
    s32 state;
    u8 reserved8[4];
    s32 stateC;
    s32 state10;
    f32 scale;
    u8 reserved18[0xC];
    f32 weight;
    u8 reserved28[0xC];
    f32 x, y, z;
} EffectContribution;

#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
struct func_802A6A44_S1;
typedef struct func_802A6A44_S1 func_802A6A44_S1;

struct func_802A67D0_S2;
typedef struct func_802A67D0_S2 func_802A67D0_S2;

struct Node438C;
typedef struct Node438C Node438C;

struct Node438C;
struct AnimationFrameDefinition;
typedef struct AnimationFrameDefinition AnimationFrameDefinition;
typedef struct AnimationFrameState AnimationFrameState;

struct AnimationFrameState;

struct AnimationFrameDefinition {
    u8 definition_prefix[0x1E];
    u8 mode;
};
struct AnimationFrameState {
    u8 node_prefix[0x2C];
    f32 endpoint;
    f32 frame;
    u8 state_between_frame_and_cache[4];
    s32 cached_frame;
};
struct Node438C {
    u8 pad0[4];
    struct Node438C *next;
    u8 pad8[8];
    Vec3 position;
    f32 a;
    f32 b;
    f32 c;
    f32 matrices[2][16]; /* 0x28: double-buffered transforms */
};

struct Node438C;
struct func_802A438C_S1;
struct func_802A438C_S1 {
    char pad0[0x40];
    struct Node438C * unk40;
    char pad40[0x48 - 0x40 - sizeof(Node438C*)];
    s32 unk48;
};

struct ObjectLinks54;
struct ObjectLinks54 {
    char pad0[0x8];
    char * unk_8;
    char pad8[0x28 - 0x8 - sizeof(char*)];
    f32 unk_28;
    char pad28[0x3C - 0x28 - sizeof(f32)];
    s32 unk_3C;
    char pad3C[0x40 - 0x3C - sizeof(s32)];
    char * unk_40;
    char pad40[0x4C - 0x40 - sizeof(char*)];
    f32 unk_4C;
    char pad4C[0x50 - 0x4C - sizeof(f32)];
    s32 unk_50;
};

struct State_func_802A2FA4_de;
typedef struct State_func_802A2FA4_de State_func_802A2FA4_de;

struct func_802A6A14_S1;
struct func_802A6A14_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    f32 unk14;
    char pad14[0x24 - 0x14 - sizeof(f32)];
    s32 unk24;
    char pad24[0x34 - 0x24 - sizeof(s32)];
    s32 unk34;
    char pad34[0x38 - 0x34 - sizeof(s32)];
    s32 unk38;
    char pad38[0x3C - 0x38 - sizeof(s32)];
    s32 unk3C;
};

struct func_802A6A54_S2;
typedef struct func_802A6A54_S2 func_802A6A54_S2;

struct ObjectState68;
struct ObjectState68 {
    unsigned char padding_0[40];
    UnitMtx unk_28;
};

struct Shade;
typedef struct Shade Shade;

struct Node802A697C;
struct State802A697C;
struct State802A697C {
    u8 pad0[4];
    struct State802A697C *next;
    struct Node802A697C *node;
    u8 padC[0x10];
    void *object;
    u8 pad20[4];
    f32 value;
    u8 pad28[0x14];
    u32 flags;
};
struct Owner802A697C;
struct State802A697C;
struct Owner802A697C {
    u8 pad0[0x7528];
    struct State802A697C *head;
};

struct IntegerState6A94;
typedef struct IntegerState6A94 IntegerState6A94;

struct ObjectState68;
typedef struct ObjectState68 ObjectState68;

struct FloatState50;
struct FloatState50 {
    unsigned char padding_0[76];
    f32 unk_4C;
};

struct SceneRecAt95A8;
typedef struct SceneRecAt95A8 SceneRecAt95A8;

struct Transform;
struct Transform {
    union {
        PackedMatrixWords matrix;
        struct {
            char pad0[0x18];
            s16 position[3];
        };
    };
};

extern void func_802A57D8_de(void);

extern void func_802A5A24_de(EffectContribution *arg0, s32 arg1);

struct func_802A6A14_S1;
typedef struct func_802A6A14_S1 func_802A6A14_S1;

struct Entity1DC;
struct Entity1DC {
    char pad[0x118];
    func_80204468_S3 *unk_118;
    char p11c[0x1f];
    u8 unk_13B;
    char p13c[0x9d];
    u8 unk_1D9;
};

struct Entity1DC;
typedef struct Entity1DC Entity1DC;

struct Particle;
typedef struct Particle Particle;

struct DefC;
typedef struct DefC DefC;

struct ChildB4;
typedef struct ChildB4 ChildB4;

struct DefC;
struct DefC {
    int unk_0;
    f32 unk_4;
    f32 unk_8;
};

struct ChildB4;
struct ChildB4 {
    int unk_0;
    struct ChildB4 *unk_4;
    f32 unk_8;
    int pc;
    f32 pos[3];
    f32 rot[3];
    Matrix mat[2];
    f32 fraction; /* 0xA8 */
    f32 length; /* 0xAC */
    Entity1DC *unk_B0;
};

struct Node44;
struct Node44 {
    int unk_0;
    struct Node44 *unk_4;
    DefC *unk_8;
    char pc[0x10];
    Entity1DC *unk_1C;
    int p20;
    f32 unk_24;
    char p28[0x14];
    int unk_3C;
    ChildB4 *unk_40;
};

struct Node44;
typedef struct Node44 Node44;

struct Root752C;
struct Root752C {
    char pad[0x7528];
    Node44 *unk_7528;
};

extern float D_800C5DC0_de;

struct func_802A41D8_S1;
typedef struct func_802A41D8_S1 func_802A41D8_S1;

struct Actor_func_802A274C_de;
typedef struct Actor_func_802A274C_de Actor_func_802A274C_de;

struct FloatStateB0;
struct FloatStateB0 {
    unsigned char padding_0[172];
    f32 unk_AC;
};

struct Root752C;
typedef struct Root752C Root752C;

extern void func_802A5A64_de(EffectContribution *arg0);

struct ObjectLinks54;
typedef struct ObjectLinks54 ObjectLinks54;

struct func_802A68A0_S2;
struct func_802A68A0_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x1C - 0x4 - sizeof(void*)];
    void * unk1C;
    char pad1C[0x24 - 0x1C - sizeof(void*)];
    f32 unk24;
};

extern float D_800C5E98_de;

struct Morph;
typedef struct Morph Morph;

struct func_802A438C_S1;
typedef struct func_802A438C_S1 func_802A438C_S1;

struct Shade;
struct Shade {
    u8 a;
    u8 b;
    u8 g;
    u8 r;
};

struct Blend;
struct Blend {
    Shade from;
    Shade to;
    u16 first;
    u16 second;
};

struct func_802A41D8_S3;
struct func_802A41D8_S3 {
    char pad0[0x1A0];
    char unk1A0;
};

struct ObjectStateB0;
struct ObjectStateB0 {
    char pad0[0x10];
    Vec3 unk_10;
    char pad10[0xAC - 0x10 - sizeof(Vec3)];
    f32 unk_AC;
};

struct func_802A697C_S3;
struct func_802A697C_S3 {
    char pad0[0x1D9];
    char unk1D9;
};

struct func_802A6A54_S3;
struct func_802A6A54_S3 {
    f32 unk0;
    char pad0[0x4 - 0x0 - sizeof(f32)];
    f32 unk4;
};

struct func_802A41D8_S1;
struct func_802A41D8_S1 {
    char pad0[0x10];
    func_80234DD0_S1_U260 unk10;
    char pad10[0x1C - 0x10 - sizeof(func_80234DD0_S1_U260)];
    f32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(f32)];
    f32 unk20;
    char pad20[0x24 - 0x20 - sizeof(f32)];
    f32 unk24;
};

struct Track_func_802A274C_de;
struct Track_func_802A274C_de {
    char pad0[4];
    f32 span;
    f32 total;
    char padC[0x12 - 0xC];
    u8 closed;
    char pad13[0x21 - 0x13];
    u8 scaleS, scaleT, count;
    struct Blend blends[1];
};
struct Actor_func_802A274C_de;
struct Track_func_802A274C_de;
struct Actor_func_802A274C_de {
    char pad0[8];
    struct Track_func_802A274C_de *track;
    struct Key *first;
    struct Key *second;
    char pad14[0x24 - 0x14];
    f32 time;
    char pad28[0x3C - 0x28];
    u32 flags;
    s32 field40;
    ObjRecAt28V1 *clock;
};

struct Transform;
typedef struct Transform Transform;

struct Particle;
struct Particle {
    char pad0[4];
    struct Particle *next;
    Transform transform;
    u8 padTransform[0x48 - 8 - sizeof(Transform)];
    s32 owner; /* 0x48: actor whose projected effect this is */
};

struct Blend;
typedef struct Blend Blend;

struct Morph_func_802A2B58_de;
struct Morph_func_802A2B58_de {
    s32 count;
    Blend *blends;
    Key *first;
    Key *second;
    void *firstFrame;
    void *secondFrame;
    f32 scaleS;
    f32 scaleT;
    f32 step;
};

struct FloatStateB0;
typedef struct FloatStateB0 FloatStateB0;

struct func_802A66B4_S1;
typedef struct func_802A66B4_S1 func_802A66B4_S1;

struct ParticleList;
typedef struct ParticleList ParticleList;

struct func_802A697C_S1;
struct func_802A697C_S1 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x8 - 0x4 - sizeof(void*)];
    void * unk8;
    char pad8[0x1C - 0x8 - sizeof(void*)];
    void * unk1C;
    char pad1C[0x24 - 0x1C - sizeof(void*)];
    float unk24;
    char pad24[0x3C - 0x24 - sizeof(float)];
    int unk3C;
};

extern void func_802A5A54_de(void *arg0, int arg1);

struct func_802A41D8_S3;
typedef struct func_802A41D8_S3 func_802A41D8_S3;

struct func_802A41D8_S2;
struct func_802A41D8_S2 {
    char pad0[0x10];
    Vec3 unk10;
};

struct Nodes;
struct Nodes {
    s32 unk0;
    struct Nodes *next;
    f32 value;
};

struct func_802A41D8_S5;
struct func_802A41D8_S5 {
    char pad0[0x14];
    f32 unk14;
    char pad14[0x18 - 0x14 - sizeof(f32)];
    f32 unk18;
};

struct func_802A67D0_S2;
struct func_802A67D0_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x8 - 0x4 - sizeof(void*)];
    void * unk8;
    char pad8[0x1C - 0x8 - sizeof(void*)];
    s32 unk1C;
    char pad1C[0x24 - 0x1C - sizeof(s32)];
    f32 unk24;
};

struct Particle;
struct ParticleList;
struct ParticleList {
    struct Particle *active;
    char pad4[0x10];
};

struct Particle;
struct SceneRecAt95A8;
struct SceneRecAt95A8 {
    char pad0[0x94E0];
    IntrusiveList lists[10];
    char pad95A8[0x95A8 - 0x94E0 - 10 * 0x14];
    IntrusiveList free;
};

struct func_802A6A44_S1;
struct func_802A6A44_S1 {
    char pad0[0x4];
    int unk4;
    char pad4[0xC - 0x4 - sizeof(int)];
    int unkC;
    char padC[0x10 - 0xC - sizeof(int)];
    int unk10;
};

struct func_802A68A0_S2;
typedef struct func_802A68A0_S2 func_802A68A0_S2;

struct FloatState50;
typedef struct FloatState50 FloatState50;

struct func_802A697C_S2;
struct func_802A697C_S2 {
    char pad0[0x13B];
    char unk13B;
};

struct func_802A697C_S2;
typedef struct func_802A697C_S2 func_802A697C_S2;

struct func_802A66EC_S1;
typedef struct func_802A66EC_S1 func_802A66EC_S1;

struct Owner802A697C;
typedef struct Owner802A697C Owner802A697C;

struct ObjectLinksB4;
struct ObjectLinksB4 {
    char pad0[0x4];
    char * unk_4;
    char pad4[0x8 - 0x4 - sizeof(char*)];
    f32 unk_8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    func_8020E674_S1_U8 unk_10;
    char pad10[0x1C - 0x10 - sizeof(func_8020E674_S1_U8)];
    f32 unk_1C;
    char pad1C[0x28 - 0x1C - sizeof(f32)];
    f32 unk_28;
    char pad28[0x68 - 0x28 - sizeof(f32)];
    f32 unk_68;
    char pad68[0xA8 - 0x68 - sizeof(f32)];
    f32 unk_A8;
    char padA8[0xAC - 0xA8 - sizeof(f32)];
    func_8022E280_S1_U744 unk_AC;
    char padAC[0xB0 - 0xAC - sizeof(func_8022E280_S1_U744)];
    s32 unk_B0;
};

struct Nodes;
struct State_func_802A2FA4_de;
struct State_func_802A2FA4_de {
    u8 pad0[0x1C];
    void *object;
    u8 pad20[4];
    f32 timer;
    u8 pad28[4];
    f32 count_up;
    f32 total;
    u8 pad34[8];
    u32 flags;
    struct Nodes *nodes;
    u8 pad44[4];
    s32 active;
    f32 amount;
    s32 retries;
};

struct func_802A697C_S3;
typedef struct func_802A697C_S3 func_802A697C_S3;

struct ObjectStateB0;
typedef struct ObjectStateB0 ObjectStateB0;

struct Blend;
struct Key;
struct Morph;
struct Morph {
    s32 count;
    struct Blend *blends;
    struct Key *first;
    struct Key *second;
    union { void *firstFrame; f32 scaleS; };
    union { void *secondFrame; f32 scaleT; };
    f32 textureScaleS;
    f32 textureScaleT;
    f32 step;
};

extern float D_800C5E90_de;

extern float D_800C5E9C_de;

extern float D_800C5E94_de;

struct Vtx;
typedef struct Vtx Vtx;

struct ObjectState20;
struct ObjectState20 {
    unsigned char padding_0[8];
    f32 unk_8;
    unsigned char padding_C[16];
    u8 unk_1C;
};

extern void func_802A598C_de(Owner802A697C *owner, int object);

struct Morph_func_802A2B58_de;
typedef struct Morph_func_802A2B58_de Morph_func_802A2B58_de;

struct func_802A6A54_S2;
struct func_802A6A54_S2 {
    char pad0[0x4];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
};

struct ObjectLinksB4;
typedef struct ObjectLinksB4 ObjectLinksB4;

struct func_802A41D8_S5;
typedef struct func_802A41D8_S5 func_802A41D8_S5;

struct func_802A66EC_S1;
struct func_802A66EC_S1 {
    int unk0;
    char pad0[0x2588 - 0x0 - sizeof(int)];
    int unk2588;
    char pad2588[0x258C - 0x2588 - sizeof(int)];
    void * unk258C;
};

struct Vtx;
struct Vtx {
    s16 x;
    s16 y;
    s16 z;
    s16 flag;
    s16 s;
    s16 t;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

/* Double-buffered vertex storage shared by the ribbon allocator and reset. */
struct RibbonVertexPool {
    s32 state;
    s32 reserved4;
    Vtx vertices[2][300]; /* 0x08, 4800 bytes per buffer */
    s32 remaining; /* 0x2588 */
    Vtx *next; /* 0x258C */
};

struct func_802A6A54_S3;
typedef struct func_802A6A54_S3 func_802A6A54_S3;

struct Nodes;
typedef struct Nodes Nodes;

struct func_802A41D8_S2;
typedef struct func_802A41D8_S2 func_802A41D8_S2;

extern float D_800C5E88_de;

struct func_802A66B4_S1;
struct func_802A66B4_S1 {
    char pad0[0x2588];
    s32 unk2588;
    char pad2588[0x258C - 0x2588 - sizeof(s32)];
    s32 unk258C;
};

struct IntegerState6A94;
struct IntegerState6A94 {
    unsigned char padding_0[27280];
    s32 unk_6A90;
};

struct ObjectState20;
typedef struct ObjectState20 ObjectState20;

extern Vector4f *func_802A5020_de(Vector4f *out, u32 bx, u32 by, u32 bz);

struct func_802A697C_S1;
typedef struct func_802A697C_S1 func_802A697C_S1;

extern f32 D_800C5E28_de;
extern f32 D_800C5E2C_de;
extern f32 D_800C5E30_de;
extern f32 D_800C5E34_de;

#endif
