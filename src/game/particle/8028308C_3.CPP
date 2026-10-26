#include "COMMON/OBJECTLINKS1E8.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"

extern void func_80279A00_de(void *arg0);
extern void Particle_UpdateMatrix(void *);
extern void Fx_DetachParticleSwooshes(void *arg0, void *arg1);


void Particle_Release(EffectSystem *owner, ParticleEffect *arg1) {
    s32 *temp_v1;
    s32 temp_a1;
    s32 flags;

    flags = arg1->flags;
    if (flags & 0x100) {
        if (!(flags & 0x800)) {
            func_80279A00_de(arg1);
            if (arg1->unk1D9 != 0) {
                Particle_UpdateMatrix(arg1);
                Fx_DetachParticleSwooshes(&D_801379C0, arg1);
            }
            temp_a1 = arg1->unk138;
            if (temp_a1 != 0) {
                DynLight_ReleaseLight(&D_8013B1A8, temp_a1);
                arg1->unk138 = 0;
            }
            temp_v1 = arg1->refCount;
            if (temp_v1 != 0) {
                *temp_v1 -= 1;
            }
            arg1->flags =
                arg1->flags & 0xFDFFFEFF;
            func_80255ED8_de(arg1->list, arg1);
            arg1->list = 0;
            func_80255CB8_de(&owner->free, arg1);
            if (arg1->flags & 0x01000000) {
                func_80255ED8_de(&owner->groups, arg1);
            }
        }
    }
}
