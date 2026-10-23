#ifndef COMMON_RESULTS_H
#define COMMON_RESULTS_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
struct Node_func_8029076C_de;
struct Node_func_8029076C_de {
    char pad0[0x17C];
    f32 x0;
    f32 x1;
    f32 x2;
    f32 y0;
    f32 y1;
    f32 y2;
    char pad194[8];
    s32 flags;
    char pad1A0[0x3C];
    struct Node_func_8029076C_de *next;
};

struct Results;
typedef struct Results Results;


struct Node_func_8029076C_de;
typedef struct Node_func_8029076C_de Node_func_8029076C_de;

struct Results;
struct Results {
    char pad0[0x144];
    Node_func_8029076C_de *nodes[0x200];
    s32 count;
};


struct func_80290930_S1;
typedef struct func_80290930_S1 func_80290930_S1;

struct func_802905D4_S2;
typedef struct func_802905D4_S2 func_802905D4_S2;

extern float D_800C53A8_de;

struct ObjectLinks3C0C;

struct func_8028FFB0_S2;
struct func_8028FFB0_S2 {
    char pad0[0x4];
    s16 unk4;
    char pad4[0x8 - 0x4 - sizeof(s16)];
    func_80234DD0_S1_U260 unk8;
    char pad8[0x14 - 0x8 - sizeof(func_80234DD0_S1_U260)];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    char * unk18;
    char pad18[0x1C - 0x18 - sizeof(char*)];
    CVector3 unk1C;
    char pad1C[0x50 - 0x1C - sizeof(CVector3)];
    s32 unk50;
    char pad50[0x54 - 0x50 - sizeof(s32)];
    s32 unk54;
    char pad54[0x58 - 0x54 - sizeof(s32)];
    s32 unk58;
    char pad58[0x5C - 0x58 - sizeof(s32)];
    s32 unk5C;
    char pad5C[0x168 - 0x5C - sizeof(s32)];
    s32 unk168;
    char pad168[0x16C - 0x168 - sizeof(s32)];
    f32 unk16C;
    char pad16C[0x170 - 0x16C - sizeof(f32)];
    s32 unk170;
    char pad170[0x174 - 0x170 - sizeof(s32)];
    s32 unk174;
    char pad174[0x178 - 0x174 - sizeof(s32)];
    s32 unk178;
    char pad178[0x17C - 0x178 - sizeof(s32)];
    f32 unk17C;
    char pad17C[0x180 - 0x17C - sizeof(f32)];
    f32 unk180;
    char pad180[0x184 - 0x180 - sizeof(f32)];
    f32 unk184;
    char pad184[0x188 - 0x184 - sizeof(f32)];
    f32 unk188;
    char pad188[0x18C - 0x188 - sizeof(f32)];
    f32 unk18C;
    char pad18C[0x190 - 0x18C - sizeof(f32)];
    f32 unk190;
    char pad190[0x194 - 0x190 - sizeof(f32)];
    s32 unk194;
    char pad194[0x19C - 0x194 - sizeof(s32)];
    s16 unk19C;
    char pad19C[0x1C4 - 0x19C - sizeof(s16)];
    s32 unk1C4;
    char pad1C4[0x1C8 - 0x1C4 - sizeof(s32)];
    f32 unk1C8;
    char pad1C8[0x1CC - 0x1C8 - sizeof(f32)];
    s32 unk1CC;
    char pad1CC[0x1D0 - 0x1CC - sizeof(s32)];
    s32 unk1D0;
    char pad1D0[0x1D4 - 0x1D0 - sizeof(s32)];
    s32 * unk1D4;
    char pad1D4[0x1D8 - 0x1D4 - sizeof(s32*)];
    char * unk1D8;
    char pad1D8[0x1DC - 0x1D8 - sizeof(char*)];
    char * unk1DC;
};

struct SceneEffect;
typedef struct SceneEffect SceneEffect;

struct func_802905D4_S1;
struct func_802905D4_S1 {
    char pad0[0x3C04];
    char * unk3C04;
};

struct ObjectLinks1E0;
typedef struct ObjectLinks1E0 ObjectLinks1E0;

struct ObjectLinks1E0;



struct ContainerRecAt3C04;
struct Node_func_8029076C_de;

struct func_8028FFB0_S4;
struct func_8028FFB0_S4 {
    char pad0[0xC];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
};

struct SceneEffect;
struct ActorDefinitionHeader;
struct SceneEffect {
    s8 active;
    char pad1[3];
    s16 model;
    char pad6[2];
    CVector3 position;
    s32 owner;
    struct ActorDefinitionHeader *definition;
    CVector3 rotation;
    char pad28[0x28];
    s32 resource;
    s32 animation;
    s32 frame;
    s32 frameState;
    char pad60[0x108];
    s32 collisionState;
    f32 collisionScale;
    s32 collisionFlags;
    s32 angle;
    s32 angleState;
    f32 minX;
    f32 minY;
    f32 minZ;
    f32 maxX;
    f32 maxY;
    f32 maxZ;
    s32 boundsState;
    char pad198[4];
    u16 flags;
    char pad19E[0x26];
    s32 effectState;
    f32 lifetime;
    f32 lifetimeState;
    s32 state;
    s32 *counter;
    struct SceneEffect *prev;
    struct SceneEffect *next;
    char pad1E0[0x110];
    signed int * ref;
    unsigned char padding2F4[4];
};

struct SceneEffect;
struct WorldRecAt3C08;
/* The world record opens with a pool of 32 effect slots of 0x1E0 bytes each (Ovlgame_InitEffectPool). */
#define EFFECT_SLOTS 32
#define EFFECT_STRIDE 0x1E0
/* One 0x1E0-byte slot of that pool: the leading fields of SceneEffect, with the free/live list links. */
struct EffectSlot {
    s8 active;
    char pad1[3];
    s16 model;
    char pad6[2];
    CVector3 position;
    s32 owner;
    struct ActorDefinitionHeader *definition;
    CVector3 rotation;
    char pad28[0x28];
    s32 resource;
    s32 animation;
    s32 frame;
    s32 frameState;
    char pad60[0x108];
    s32 collisionState;
    f32 collisionScale;
    s32 collisionFlags;
    s32 angle;
    s32 angleState;
    f32 minX;
    f32 minY;
    f32 minZ;
    f32 maxX;
    f32 maxY;
    f32 maxZ;
    s32 boundsState;
    char pad198[4];
    u16 flags;
    char pad19E[0x26];
    s32 effectState;
    f32 lifetime;
    f32 lifetimeState;
    s32 state;
    s32 *counter;
    struct EffectSlot *prev;
    struct EffectSlot *next;
};
typedef char EffectSlot_size_check[(sizeof(struct EffectSlot) == EFFECT_STRIDE) ? 1 : -1];
struct WorldRecAt3C08 {
    struct EffectSlot slots[EFFECT_SLOTS];
    struct EffectSlot *free;
    struct EffectSlot *head;
    struct EffectSlot *tail;
};

struct ListNode80290528;
typedef struct ListNode80290528 ListNode80290528;

struct func_8028FFB0_S1;
struct func_8028FFB0_S1 {
    char pad0[0x3C00];
    char * unk3C00;
    char pad3C00[0x3C04 - 0x3C00 - sizeof(char*)];
    char * unk3C04;
    char pad3C04[0x3C08 - 0x3C04 - sizeof(char*)];
    char * unk3C08;
};

struct func_802905D4_S3;
typedef struct func_802905D4_S3 func_802905D4_S3;

struct ListNode80290528;
struct ListNode80290528 {
    char unknown000[0x1D0];
    unsigned int flags;
    int *reference_count;
    struct ListNode80290528 *previous;
    struct ListNode80290528 *next;
};

struct func_80290930_S1;
struct func_80290930_S1 {
    char pad0[0x3C00];
    ListNode80290528 * unk3C00;
    char pad3C00[0x3C04 - 0x3C00 - sizeof(ListNode80290528*)];
    ListNode80290528 * unk3C04;
    char pad3C04[0x3C08 - 0x3C04 - sizeof(ListNode80290528*)];
    ListNode80290528 * unk3C08;
};

struct func_802905D4_S3;
struct func_802905D4_S3 {
    char pad0[0x17C];
    f32 unk17C;
    char pad17C[0x180 - 0x17C - sizeof(f32)];
    f32 unk180;
    char pad180[0x184 - 0x180 - sizeof(f32)];
    f32 unk184;
    char pad184[0x188 - 0x184 - sizeof(f32)];
    f32 unk188;
    char pad188[0x18C - 0x188 - sizeof(f32)];
    f32 unk18C;
    char pad18C[0x190 - 0x18C - sizeof(f32)];
    f32 unk190;
    char pad190[0x1C8 - 0x190 - sizeof(f32)];
    f32 unk1C8;
    char pad1C8[0x1DC - 0x1C8 - sizeof(f32)];
    char * unk1DC;
};

struct func_802903E8_S1;
typedef struct func_802903E8_S1 func_802903E8_S1;

struct func_802905D4_S2;
struct func_802905D4_S2 {
    char pad0[0x350];
    f32 unk350;
    char pad350[0x354 - 0x350 - sizeof(f32)];
    f32 unk354;
    char pad354[0x358 - 0x354 - sizeof(f32)];
    f32 unk358;
    char pad358[0x35C - 0x358 - sizeof(f32)];
    f32 unk35C;
    char pad35C[0x360 - 0x35C - sizeof(f32)];
    f32 unk360;
    char pad360[0x364 - 0x360 - sizeof(f32)];
    f32 unk364;
};

struct func_802905D4_S1;
typedef struct func_802905D4_S1 func_802905D4_S1;

struct ObjectLinks3C0C;
typedef struct ObjectLinks3C0C ObjectLinks3C0C;


struct func_8028FFB0_S1;
typedef struct func_8028FFB0_S1 func_8028FFB0_S1;

struct func_8028FFB0_S2;
typedef struct func_8028FFB0_S2 func_8028FFB0_S2;

struct func_8028FFB0_S4;
typedef struct func_8028FFB0_S4 func_8028FFB0_S4;

struct func_802903E8_S1;
struct func_802903E8_S1 {
    signed char unk0;
    char pad0[0x18 - 0x0 - sizeof(signed char)];
    void * unk18;
    char pad18[0x1D0 - 0x18 - sizeof(void*)];
    int unk1D0;
};

struct WorldRecAt3C08;
typedef struct WorldRecAt3C08 WorldRecAt3C08;


struct ContainerRecAt3C04;
typedef struct ContainerRecAt3C04 ContainerRecAt3C04;

/* Resident resource chunks have two count/stride words followed by byte payload. */
typedef struct ResidentDataChunk {
    s32 width;
    s32 count;
    u8 data[1];
} ResidentDataChunk;
#endif
