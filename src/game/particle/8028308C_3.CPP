#include "COMMON/OBJECTLINKS1E8.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_3.H"

extern void Particle_FinishActorEffects(void *arg0);
extern void Particle_UpdateMatrix(void *);
extern void Fx_DetachParticleSwooshes(void *arg0, void *arg1);


void Particle_Release(EffectSystem *owner, ParticleEffect *releasedEffect) {
    s32 *releaseReferenceCount;
    s32 releasedLight;
    s32 flags;

    flags = releasedEffect->flags;
    if (flags & 0x100) {
        if (!(flags & 0x800)) {
            Particle_FinishActorEffects(releasedEffect);
            if (releasedEffect->unk1D9 != 0) {
                Particle_UpdateMatrix(releasedEffect);
                Fx_DetachParticleSwooshes(&D_801379C0, releasedEffect);
            }
            releasedLight = releasedEffect->unk138;
            if (releasedLight != 0) {
                DynLight_ReleaseLight(&D_8013B1A8, releasedLight);
                releasedEffect->unk138 = 0;
            }
            releaseReferenceCount = releasedEffect->refCount;
            if (releaseReferenceCount != 0) {
                *releaseReferenceCount -= 1;
            }
            releasedEffect->flags =
                releasedEffect->flags & 0xFDFFFEFF;
            func_80255ED8_de(releasedEffect->list, releasedEffect);
            releasedEffect->list = 0;
            func_80255CB8_de(&owner->free, releasedEffect);
            if (releasedEffect->flags & 0x01000000) {
                func_80255ED8_de(&owner->groups, releasedEffect);
            }
        }
    }
}
