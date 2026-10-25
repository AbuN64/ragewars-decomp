#ifndef COMMON_DESCRIPTORRECAT29_H
#define COMMON_DESCRIPTORRECAT29_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"

struct DescriptorRecAt29;
typedef struct DescriptorRecAt29 DescriptorRecAt29;

extern float D_800C86E8;

struct ClipView;
typedef struct ClipView ClipView;


struct IntegerState8A4;
typedef struct IntegerState8A4 IntegerState8A4;

struct Host;
struct Host {
    char pad0[0x24];
    s32 stalled;
    char pad28[0x104];
    f32 speed;
};


struct DescriptorRecAt29;
struct DescriptorRecAt29 {
    s16 texture; /* +0: Sched_UpdateSceneEffects passes it to func_80295E84_de */
    u8 red, green, blue;
    u8 envRed, envGreen, envBlue;
    f32 spinRate;
    f32 textureScale;
    f32 phaseRate;
    f32 baseSpeed;
    f32 fadeDepth;
    f32 hostScale;
    f32 throttleRate;
    char pad24[4];
    u8 alpha;
    u8 flags;
};

struct ObjRecAt210;
typedef struct ObjRecAt210 ObjRecAt210;

struct Effect;
struct Effect {
    char pad00[0xC];
    s16 *definition;
    s16 mask;
    char pad12[2];
    s32 resource; /* 0x14: initialized from the effect definition */
    char pad18[4];
    s32 angle0;
    s32 angle1;
    char pad24[0x1E4];
    s32 timer;
    s32 velocity;
    char pad210[4];
    f32 scale;
    f32 offset0;
    f32 offset1;
    f32 offset2;
};

struct Host;
typedef struct Host Host;

struct ObjectRecAt220;
struct ObjectRecAt220 {
    char gap0[4];
    struct ObjectRecAt220 *next;
    char gap8[4];
    DescriptorRecAt29 *descriptor;
    u16 mask;
    char gap12[2];
    s32 texture[2];
    f32 offsetS;
    f32 offsetT;
    char gap24[4];
    UnitVtx vertices[2][15];
    f32 throttle;
    f32 phase;
    f32 depth;
    f32 phaseScale;
    f32 textureScale;
    f32 trim;
    f32 opacity;
};


extern float D_800CD744_de;


struct ClipView;
struct ClipView {
    char gap0[0x8];
    s32 index;
    char gapC[0x120 - 0xC];
    s32 hidden;
    char gap124[8];
    f32 depth;
    char gap130[0x1E0 - 0x130];
    f32 viewProjection[16];
    char gap220[0x260 - 0x220];
    CVector3 fan[5];
    char gap29C[0x74];
    f32 clipPlane[4];
};

struct ObjectRecAt220;
typedef struct ObjectRecAt220 ObjectRecAt220;

struct Scene;
typedef struct Scene Scene;

extern float D_800C86E0;

struct Effect;
typedef struct Effect Effect;

struct Rotor;
typedef struct Rotor Rotor;

extern float D_800C35F4_de;

struct DescriptorRecAt29;
struct Rotor;

struct ObjRecAt210;

struct ObjectRecAt220;
struct Scene;

struct IntegerState8A4;

extern void func_80295F78_de(s32 **, void *);


extern void D_0023B938();
extern void D_0023B94C();
extern void D_0023B978_de();


extern void func_80239CE0_de(void *arg0);
#endif
