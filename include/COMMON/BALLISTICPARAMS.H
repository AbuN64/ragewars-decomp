#ifndef COMMON_BALLISTICPARAMS_H
#define COMMON_BALLISTICPARAMS_H
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/APPROACHLOCATION.H"

/* Complete records from origin/legacy shared headers and source; historical gaps retained. */
typedef struct ParticleAttractionActorView ParticleAttractionActorView;
struct ParticleAttractionActorView {
    char pad0[0x8];
    CVector3 pos; /* +0x8: src/Particle_UpdateTypedMotion_Ballisticparams.c */
    char pad14[0x5C];
    f32 unk70; /* +0x70: src/Particle_UpdateTypedMotion_Ballisticparams.c */
    char pad74[0x166C];
    void * next; /* +0x16E0: src/Particle_UpdateTypedMotion_Ballisticparams.c */
};

typedef struct ParticleAttractionPositionView ParticleAttractionPositionView;
struct ParticleAttractionPositionView {
    char pad0[0x8];
    CVector3 pos; /* +0x8: src/Particle_UpdateTypedMotion_Ballisticparams.c */
};

typedef struct BallisticParams BallisticParams;
struct BallisticParams { u16 gravityHi; u16 gravityLo; u16 speedHi; u16 speedLo; char pad8[8]; u16 unk10; u16 unk12; };

typedef struct BallisticParamsHolder BallisticParamsHolder;
struct BallisticParamsHolder { u32 flags; char pad4[0xA]; s16 unkE; char pad10[0x20]; BallisticParams *parameters; char pad34[8]; };

/* Phase-1 candidate; target/descriptor layouts and helper ABI remain unresolved. */
typedef struct ParticleAttractionActorView ParticleNearbyActorView;
typedef struct ParticleAttractionPositionView ParticleAttractionTargetView;
extern f32 g_particleNeighborScale;








extern f32 g_particleTrackingMinimum;











void Playerai_ApplyPlayerForces(void *, void *);
f32 Gobjinst_GetActorHeight(void *);
f32 InstHdr_GetActorBaseOffset(void *);
void Graphu64_InterpolateQuaternionWithLinearFallback(void *, f32, void *, void *);
void Graphu64_ClampMotionLength(void *, f32);
void MatrixFromQuaternion(f32 *, f32 *);


void Particle_UpdateSineMotion(void *, f32);
f32 Gu_Sqrtf(f32);
CQuatern Graphu64_BuildDirectionQuaternion(f32 *);            /* extern */
extern Shared_MenuData g_playerViewRenderContext;
extern Shared_GlobalRuntimeState g_transientPlayerList;
#endif
