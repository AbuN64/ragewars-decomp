#ifndef RENDER_POOLRECAT28V1_H
#define RENDER_POOLRECAT28V1_H
#include "TYPES.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"

struct RumbleSpatialPoolView;
typedef struct RumbleSpatialPoolView RumbleSpatialPoolView;


struct RumbleSpatialPoolView;
struct RumbleSpatialPoolView {
    char pad0[0x14];
    IntrusiveList activeEffects;
    char pad14[0x28 - 0x14 - sizeof(IntrusiveList)];
    union { s32 unk28; f32 baseLevel; };
};


struct RumbleEffectNode;
struct RumbleNodePoolView;
/* RumbleNodePoolView is shared with ControllerProfile in ITEMRECAT20V1.H. */

extern float g_spatialEffectFalloffUnitGain;



struct RumbleSpatialEffectNode;
struct RumbleSpatialEffectNode {
    char pad0[4];
    struct RumbleSpatialEffectNode *next;
    void * effectClip;
    char pad8[0xC - 0x8 - sizeof(void*)];
    union { Triple unkC; CVector3 position; };
    char padC[0x18 - 0xC - sizeof(Triple)];
    f32 radius;
    char pad18[0x1C - 0x18 - sizeof(f32)];
    f32 strength;
    char pad1C[0x20 - 0x1C - sizeof(f32)];
    union {
        struct { unsigned int unk20; char pad20[8]; };
        SampledEffectCurveState amplitudeCurve;
    };
    union {
        struct { unsigned int unk2C; char pad2C[8]; };
        SampledEffectCurveState lifetimeCurve;
    };
    void ** ownerSlot;
};

struct RumbleSpatialEffectNode;
typedef struct RumbleSpatialEffectNode RumbleSpatialEffectNode;

struct RumbleNodePoolView;
typedef struct RumbleNodePoolView RumbleNodePoolView;

#endif
