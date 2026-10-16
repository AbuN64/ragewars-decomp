#ifndef RW_PARTICLE_ATTACHMENT_H
#define RW_PARTICLE_ATTACHMENT_H
#include "TYPES.H"
#include "span_1000/code_8027A0F4.h"
/* Attachment view of the existing collision state: ROM pointer at0,
 * draw-frame selector at0x14; the scene vector begins at0x08. */
typedef struct ParticleAttachmentState {
    Shared_ParticleTarget *current;
    s32 reserved4;
    Vec3 origin;
    union { s32 frame; u8 frameBytes[4]; };
    char reserved18[0x66];
    u8 mode;
    char reserved7F[0x59];
    Vec3 direction;
    char reservedE4[0xC];
    Vec3 point;
} ParticleAttachmentState;
#endif
