#ifndef FX_2_PARTICLE_ATTACHMENT_H
#define FX_2_PARTICLE_ATTACHMENT_H
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
    s32 unk88;
    char reserved8C[0x4];
    CVector3 unk90;
    s32 unk9C;
    CVector3 unkA0;
    char reservedAC[0x4];
    s32 unkB0;
    s32 unkB4;
    CVector3 unkB8;
    s32 unkC4;
    CVector3 unkC8;
    char reservedD4[0x4];
    CVector3 direction;
    char reservedE4[0xC];
    CVector3 point;
} ParticleAttachmentState;
#endif
