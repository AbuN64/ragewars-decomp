#ifndef COMMON_SHAPE_TYPEMAP_14_H
#define COMMON_SHAPE_TYPEMAP_14_H
struct SharedPlayer;
#ifndef SPAN_1000_CODE_8022D944_H
#define SPAN_1000_CODE_8022D944_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"

extern f32 Player_EvaluateCubicComplement(f32 arg0);

struct Shared_ActorView;
extern s32 Player_IsSpeedAboveThreshold(struct Shared_ActorView *arg0);


struct Shape_typemap_14;
struct Shape_typemap_14 {
    unsigned char padding_0[8];
    short field_8;
};

struct Marker;
typedef struct Marker Marker;


extern void Player_ApplyRangedPitchToMatrix(void *arg0, void *arg1);

struct EntryPlayerHasLinkedWorldFlagSix;
struct EntryPlayerHasLinkedWorldFlagSix {
    char pad[0x52];
    u16 flags;
};



struct Object126;
typedef struct Object126 Object126;



extern int Player_IsStateFifteen(struct SharedPlayer *arg0);

extern float Player_SumActivePlayerDistances(void * arg0, float * arg1);

struct ObjRecAt724;
typedef struct ObjRecAt724 ObjRecAt724;

extern float D_800C2E0C_de;

extern void func_8022DC14_de(void);


extern float D_800C7EF8;

extern u8 Player_GetImpactSoundEnabled(s32 arg0, s32 arg1);

struct Actor126;
typedef struct Actor126 Actor126;

extern float D_800C7EC0;



extern void Player_UpdateSequence74RunEndPose(void *);

extern float D_801370C4;

struct ObjRecAt1AV1;
typedef struct ObjRecAt1AV1 ObjRecAt1AV1;

extern void Player_ResetPlayerWeaponLock(void *arg0);

extern float D_800C7F10;

struct ObjRecAt724;
struct ObjRecAt724 {
    char pad0[0x650];
    s16 unk650;
    char pad650[0x724 - 0x650 - sizeof(s16)];
    f32 unk724;
};



struct Player;
extern void Player_InitializeStateBlendToZero(struct Player *arg0);


struct ObjRecAt1AV1;
struct ObjRecAt1AV1 {
    char pad0[0x18];
    s8 unk18;
    char pad18[0x19 - 0x18 - sizeof(s8)];
    s8 unk19;
    char pad19[0x1A - 0x19 - sizeof(s8)];
    s8 unk1A;
};

struct ObjRecAt1CV2;
struct ObjRecAt1CV2 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    void * unk8;
    char pad8[0x1C - 0x8 - sizeof(void*)];
    void * unk1C;
};

extern float D_800C2DCC_de;








extern void func_8022E940_de(void);

extern float D_800C7EE0;

extern void Player_ClearPlayerWeaponLock(void *arg0);

extern void Player_InitializeStateBlendTarget(struct Player *arg0);


struct Marker;
struct Marker {
    char pad0[0xC];
    f32 scale;
    s16 x;
    s16 y;
    s16 z;
    s16 active;
};

struct Actor126;
struct Actor126 {
    u8 pad0[0x100];
    s32 flags;
    u8 pad104[0xD0];
    f32 value1D4;
    u8 pad1D8[0x47A];
    s16 state652;
    u8 pad654[0xD4];
    f32 offset728;
};


struct ObjectLinks87C;
typedef struct ObjectLinks87C ObjectLinks87C;


extern float D_800C2E00_de;

struct ObjectLinks87C;
struct ObjectLinks87C {
    char pad0[0x5D8];
    char * unk_5D8;
    char pad5D8[0x5E4 - 0x5D8 - sizeof(char*)];
    s32 unk_5E4;
    char pad5E4[0x62E - 0x5E4 - sizeof(s32)];
    s16 unk_62E;
    char pad62E[0x7E8 - 0x62E - sizeof(s16)];
    s32 unk_7E8;
    char pad7E8[0x7EC - 0x7E8 - sizeof(s32)];
    f32 unk_7EC;
    char pad7EC[0x7F0 - 0x7EC - sizeof(f32)];
    f32 unk_7F0;
    char pad7F0[0x878 - 0x7F0 - sizeof(f32)];
    char unk_878;
};




extern float D_800C2DC8_de;

extern s32 Player_IsStateThreeLowerAnimationGroup(struct SharedPlayer *arg0);

extern void Player_ApplyLinkedProjectileStatus(void * arg0, int arg1, int arg2);

struct Object126;
struct Object126 {
    u8 pad0[0x1C];
    f32 x;
    u8 pad20[4];
    f32 y;
    u8 pad28[0x44];
    f32 angle;
};

extern void Player_OffsetActorForState15(Actor126 *actor, Object126 *arg1);




struct func_80204468_S3;
extern s32 Player_HasLinkedWorldFlagSix(struct func_80204468_S3 *object);

extern float D_800C7EC8;



extern void Player_ReleaseMarkerSlot(void *unused0, s32 *arg1);



extern s32 Player_IsStateThreeUpperAnimationGroup(struct SharedPlayer *arg0);

struct ObjRecAt1CV2;
typedef struct ObjRecAt1CV2 ObjRecAt1CV2;

extern void Player_UpdateActionTransitionBlend(struct Shared_ActorView *arg0);

extern float D_800C7EF4;


extern void Player_UpdateWeaponEffectBlend(void *arg0);

#endif
#endif
