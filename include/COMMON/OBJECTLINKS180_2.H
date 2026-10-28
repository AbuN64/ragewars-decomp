#ifndef COMMON_OBJECTLINKS180_2_H
#define COMMON_OBJECTLINKS180_2_H
#include "TYPES.H"
#include "COMMON/LEVEL_INPUT.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/OBJRECAT4V7.H"
#include "COMMON/LOCALDECODERANGE.H"

extern float D_800C8B48;

struct ObjectLinks180_2;
typedef struct ObjectLinks180_2 ObjectLinks180_2;

struct Obj_func_80247004_de;
typedef struct Obj_func_80247004_de Obj_func_80247004_de;



extern float D_800C3A50_de;



struct ObjectState110;
struct ObjectState110 {
    unsigned char padding_0[256];
    s32 unk_100;
    s32 unk_104;
    unsigned char padding_108[6];
    s8 unk_10E;
    s8 unk_10F;
};

extern int D_800D06BC;

struct SineTable;
struct SineTable {
    f32 count;
    f32 value[120];
};



extern float D_800C3948_de;


struct Box70;
struct Box70 {
    CVector3 corners[8];
    char pad60[0xC];
    s32 mask;
};

struct ObjectLinks23C;
struct ObjectLinks23C {
    char pad0[0x8];
    CVector3 unk_8;
    char pad8[0x14 - 0x8 - sizeof(CVector3)];
    u16 * unk_14;
    char pad14[0x18 - 0x14 - sizeof(u16*)];
    s32 * unk_18;
    char pad18[0x100 - 0x18 - sizeof(s32*)];
    s32 unk_100;
    char pad100[0x1A0 - 0x100 - sizeof(s32)];
    void * unk_1A0;
    char pad1A0[0x1F4 - 0x1A0 - sizeof(void*)];
    u16 * unk_1F4;
    char pad1F4[0x238 - 0x1F4 - sizeof(u16*)];
    u16 unk_238;
};

struct IntegerState104;
struct IntegerState104 {
    unsigned char padding_0[180];
    s32 unk_B4;
    s32 unk_B8;
    s32 unk_BC;
    s32 unk_C0;
    unsigned char padding_C4[60];
    s32 unk_100;
};

struct Obj_func_80247004_de;
struct Obj_func_80247004_de {
    char pad[0x14];
    ObjRecAt2V2 *unk14;
    char pad18[0x5C - 0x18];
    f32 rotation[4]; /* 0x5C */
    char pad6C[0x100 - 0x6C];
    u32 unk100;
};

struct Lookup;
struct Lookup {
    s32 unk0;
    s32 unk4;
    u32 pad8;
    void **value;
};



struct ObjectLinks180_2;
struct ObjectLinks180_2 {
    unsigned char padding_0[1];
    s8 unk_1;
    unsigned char padding_2[178];
    char *unk_B4;
    char *unk_B8;
    unsigned char padding_BC[68];
    s32 unk_100;
    unsigned char padding_104[120];
    s32 unk_17C;
};

struct InputRecAt27;



struct Lookup;
typedef struct Lookup Lookup;


struct Box70;
typedef struct Box70 Box70;

struct BlockRecAt0;
struct BlockRecAt0 {
    u32 words[6];
};

struct IntegerState104;
typedef struct IntegerState104 IntegerState104;

struct TypeEntry;
typedef struct TypeEntry TypeEntry;




struct ObjectState110;
typedef struct ObjectState110 ObjectState110;




struct SineTable;
typedef struct SineTable SineTable;

extern float D_800C8B50;


struct TypeEntry;
struct TypeEntry {
    void *unk0;
    void (*callback)(void *, void *);
};

struct InputRecAt27;



struct ObjectRecAt140;
typedef struct ObjectRecAt140 ObjectRecAt140;

struct BlockRecAt0;
typedef struct BlockRecAt0 BlockRecAt0;



struct CallbackState288;
struct CollisionInfo;
struct CallbackState288 {
    unsigned char padding_0[644];
    void (*callback)(void *, void *, struct CollisionInfo *);
};



struct ObjectRecAt140;
struct ObjectRecAt140 {
    char pad[0x140];
    Block24 blocks[2];
};

struct ObjectStateC;
typedef struct ObjectStateC ObjectStateC;

extern float D_800C3924_de;

struct ObjectLinks180;
typedef struct ObjectLinks180 ObjectLinks180;

struct ObjectLinks10;
typedef struct ObjectLinks10 ObjectLinks10;




struct ObjectLinks180;
struct ObjectLinks180 {
    unsigned char padding_0[1];
    s8 unk_1;
    unsigned char padding_2[6];
    CVector3 unk_8;
    unsigned char padding_14[164];
    char *unk_B8;
    unsigned char padding_BC[40];
    u16 unk_E4;
    unsigned char padding_E6[26];
    s32 unk_100;
    unsigned char padding_104[120];
    s32 unk_17C;
};

struct CallbackState288;
typedef struct CallbackState288 CallbackState288;


struct CollisionInfo;
struct ObjectLinks10;
struct ObjectLinks10 {
    char pad0[0xC];
    struct CollisionInfo * unk_C;
};


struct ObjectLinks23C;
typedef struct ObjectLinks23C ObjectLinks23C;

struct ObjectStateC;
struct ObjectStateC {
    char pad0[0x8];
    func_80203908_S3_U124 unk_8;
};



struct Actor_func_8024A3B0_de;
struct Actor_func_8024A3B0_de {
    char pad0[3];
    s8 field3;
    u32 pad4;
    CVector3 position0;
    u32 pad14[2];
    CVector3 position1;
    u32 pad28[13];
    CQuatern rotation;
    char pad6C[0xB4 - 0x6C];
    s32 fieldB4;
    char padB8[0x140 - 0xB8];
    BlockRecAt0 blocks[4];
};

struct Actor_func_8024A3B0_de;
typedef struct Actor_func_8024A3B0_de Actor_func_8024A3B0_de;

typedef void (*func_8024B4E4_de_FuncPtr)(void *, void *);
extern void Graphu64_TransformBoundingBox(void *arg0, int box, void *out);

extern void func_802472F0_de(void *);
extern void Scene_UpdateMovementTriggers(struct Shared_World *, struct LevelActor *, CVector3 *, CVector3 *);
extern u8 D_800C38F4_de[];
typedef struct Actor36 {
    u8 pad0[8];
    CVector3 position;
    u8 pad14[4];
    s32 *kind;
    u8 pad1C[0x34];
    f32 scaleX;
    u8 pad54[4];
    f32 scaleZ;
    u8 pad5C[0x10];
    f32 heading;
    u8 pad70[4];
    f32 matrix[4][4];
    u8 padB4[0x10];
    s32 size;
    s32 animationKey;
    u8 padCC[4];
    s32 alignment;
    u8 padD4[0x10];
    u16 ownerId;
    s8 animationCount;
    u8 padE7;
    BoxRecAtC box;
    u32 flags;
    struct Anim currentTrack;
    struct Anim previousTrack;
    s16 blendFrames;
    u8 pad12E[2];
    f32 blend;
    f32 blendTime;
    u8 blendStart;
    u8 blendEnd;
    u8 pad13A[0x36];
    u8 state[0x54];
    CVector3 displacement;
    u8 pad1D0[0xBC];
    void (*update)(void *, void *);
} Actor36;


/* Options passed with an actor render submission. */
typedef struct ActorRenderSettings {
    s32 drawModel;
    s32 drawShadow;
    s32 reserved8;
    s32 view;
    s32 reserved10;
    CVector3 *shadowOffset; /* 0x14: offset of the blob shadow from the actor */
} ActorRenderSettings;
#endif
