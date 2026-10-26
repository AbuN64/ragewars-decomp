#ifndef COMMON_RESULTS_H
#define COMMON_RESULTS_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
struct NodeSetN64CollectVisibleEffectNodes;
struct NodeSetN64CollectVisibleEffectNodes {
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
    struct NodeSetN64CollectVisibleEffectNodes *next;
};

struct Results;
typedef struct Results Results;


struct NodeSetN64CollectVisibleEffectNodes;
typedef struct NodeSetN64CollectVisibleEffectNodes NodeSetN64CollectVisibleEffectNodes;

struct Results;
struct Results {
    char pad0[0x144];
    NodeSetN64CollectVisibleEffectNodes *nodes[0x200];
    s32 count;
};




extern float D_800C53A8_de;

struct ObjectLinks3C0C;


struct SceneEffect;
typedef struct SceneEffect SceneEffect;


struct ObjectLinks1E0;
typedef struct ObjectLinks1E0 ObjectLinks1E0;

struct ObjectLinks1E0;



struct ContainerRecAt3C04;
struct NodeSetN64CollectVisibleEffectNodes;


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
struct WorldRecAt3C08 {
    struct EffectSlot slots[EFFECT_SLOTS];
    struct EffectSlot *free;
    struct EffectSlot *head;
    struct EffectSlot *tail;
};

struct ListNode80290528;
typedef struct ListNode80290528 ListNode80290528;



struct ListNode80290528;
struct ListNode80290528 {
    char unknown000[0x1D0];
    unsigned int flags;
    int *reference_count;
    struct ListNode80290528 *previous;
    struct ListNode80290528 *next;
};






struct ObjectLinks3C0C;
typedef struct ObjectLinks3C0C ObjectLinks3C0C;






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
