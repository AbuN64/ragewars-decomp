#ifndef RENDER_8028469C_H
#define RENDER_8028469C_H
#include "COMMON/PACKEDMESHMATERIAL.H"
#include "COMMON/SHAREDPLAYER.H"
struct ObjParticleMarkNearbyObjects {
    char pad[4];
    unsigned short unk4;
    char pad6[2];
    f32 pos[3];
    char pad14[0x138];
    short unk14C;
};
struct ObjRecAt4V2 {
    void * unk0;
    s32 unk4;
};
struct ObjRecAt12 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad8[0x6];
    s8 unk12;
};
struct Arg1 {
    char pad0[0x24];
    s32 field24;
    char pad28[0x100];
    CVector3 position128;
};
extern float Particle_GetConditionalFirstValue(struct ParticleEffect *arg0);
extern s32 Particle_RandomInclusiveCount(s32 arg0);
extern f32 Particle_GetConditionalSecondValue(struct ParticleEffect *arg0);
extern void Particle_AdvanceRandomWhenNonzero(f32 arg0);
#endif
