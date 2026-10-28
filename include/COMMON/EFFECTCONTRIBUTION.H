#ifndef COMMON_EFFECTCONTRIBUTION_H
#define COMMON_EFFECTCONTRIBUTION_H
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

#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"


struct Node438C;
typedef struct Node438C Node438C;

struct Node438C;
struct AnimationFrameDefinition;
typedef struct AnimationFrameDefinition AnimationFrameDefinition;
typedef struct AnimationFrameState AnimationFrameState;

struct AnimationFrameState;

struct Node438C {
    u8 pad0[4];
    struct Node438C *next;
    u8 pad8[8];
    CVector3 position;
    f32 a;
    f32 b;
    f32 c;
    f32 matrices[2][16]; /* 0x28: double-buffered transforms */
};

struct Node438C;

struct ObjectLinks54;

struct StateSmpUpdateRibbonLifetime;
typedef struct StateSmpUpdateRibbonLifetime StateSmpUpdateRibbonLifetime;


struct ObjectState68;

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

struct IntegerState6A94;
typedef struct IntegerState6A94 IntegerState6A94;

struct ObjectState68;
typedef struct ObjectState68 ObjectState68;

struct FloatState50;

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

extern void Fx_RibbonNoop(void);

extern void Fx_ResetEffectContribution(EffectContribution *arg0, s32 arg1);


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

extern float D_800C5DC0_de;


struct RibbonActor;
typedef struct RibbonActor RibbonActor;

struct FloatStateB0;

struct Root752C;
typedef struct Root752C Root752C;


struct ObjectLinks54;
typedef struct ObjectLinks54 ObjectLinks54;

struct func_802A68A0_S2;

extern float D_800C5E98_de;

struct Morph;
typedef struct Morph Morph;


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


struct ObjectStateB0;



struct CROMSwoosh_t;
struct CROMSwoosh_t {
    char pad0[4];
    f32 span;
    f32 total;
    char padC[0x12 - 0xC];
    u8 closed;
    char pad13[0x16 - 0x13];
    u8 prim[3];
    u8 env[3];
    u8 kind;
    u8 textureScale;
    char pad1E[0x21 - 0x1E];
    u8 scaleS, scaleT, count;
    struct Blend blends[1];
};
struct RibbonActor;
struct CROMSwoosh_t;

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


struct FloatStateB0;
typedef struct FloatStateB0 FloatStateB0;

struct VertexArena;
typedef struct VertexArena VertexArena;






struct Nodes;
struct Nodes {
    s32 unk0;
    struct Nodes *next;
    f32 value;
};



struct Particle;

struct Particle;
struct SceneRecAt95A8;
struct SceneRecAt95A8 {
    char pad0[0x94E0];
    IntrusiveList lists[10];
    char pad95A8[0x95A8 - 0x94E0 - 10 * 0x14];
    IntrusiveList free;
};


struct func_802A68A0_S2;
typedef struct func_802A68A0_S2 func_802A68A0_S2;

struct FloatState50;
typedef struct FloatState50 FloatState50;




struct Owner802A697C;
typedef struct Owner802A697C Owner802A697C;

struct ObjectLinksB4;

struct Nodes;
struct StateSmpUpdateRibbonLifetime;
struct StateSmpUpdateRibbonLifetime {
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


struct ObjectStateB0;
typedef struct ObjectStateB0 ObjectStateB0;

struct Blend;
struct Key;
struct Morph;

extern float D_800C5E90_de;

extern float D_800C5E9C_de;

extern float D_800C5E94_de;

struct Vtx;
typedef struct Vtx Vtx;

struct ObjectState20;

extern void Fx_DetachEffectOwner(Owner802A697C *owner, int object);


struct ObjectLinksB4;
typedef struct ObjectLinksB4 ObjectLinksB4;



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

/* Shared four-vertex particle quad initialized by Ovlgame_InitParticleQuad. */
extern Vtx g_particleQuadVertices[4];


struct Nodes;
typedef struct Nodes Nodes;


extern float D_800C5E88_de;

/* The ribbon vertex arena Fx_AllocateRibbonVertices allocates from; only passed through here. */
struct VertexArena;

struct IntegerState6A94;

struct ObjectState20;
typedef struct ObjectState20 ObjectState20;

extern CQuatern *Fx_BuildUpAxisQuaternion(CQuatern *out, u32 bx, u32 by, u32 bz);


extern f32 D_800C5E28_de;
extern f32 D_800C5E2C_de;
extern f32 D_800C5E30_de;
extern f32 D_800C5E34_de;
#endif
