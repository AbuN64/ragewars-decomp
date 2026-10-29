#ifndef FX_PARTICLE_ATTACHMENT_H
#define FX_PARTICLE_ATTACHMENT_H
#include "TYPES.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
/* Attachment view of the existing collision state: ROM pointer at0,
 * draw-frame selector at0x14; the scene vector begins at0x08. */
typedef struct ParticleAttachmentState {
    Shared_ParticleTarget *current;
    s32 reserved4;
    CVector3 origin;
    union { s32 frame; u8 frameBytes[4]; };
    char reserved18[0x66];
    u8 mode;
    char reserved7F[0x88 - 0x7F];
    s32 pointHit;
    char reserved8C[0x4];
    CVector3 pointHitPosition;
    s32 materialHit;
    CVector3 materialHitPosition;
    char reservedAC[0x4];
    s32 surfaceHitKind;
    s32 spaceHit;
    CVector3 spaceHitPosition;
    s32 typedHit;
    CVector3 typedHitPosition;
    char reservedD4[0x4];
    CVector3 direction;
    char reservedE4[0xC];
    CVector3 point;
} ParticleAttachmentState;
#endif
