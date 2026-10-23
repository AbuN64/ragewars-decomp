#include "COMMON/OBJECTLINKS1E8.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"

extern void func_80279A00_de(void *arg0);
extern void func_80284178_de(void *);
extern void func_802A42F4_de(void *arg0, void *arg1);


void func_80284570_de(EffectSystem *owner, ParticleEffect *arg1) {
    s32 *temp_v1;
    s32 temp_a1;
    s32 flags;

    flags = arg1->flags;
    if (flags & 0x100) {
        if (!(flags & 0x800)) {
            func_80279A00_de(arg1);
            if (arg1->unk1D9 != 0) {
                func_80284178_de(arg1);
                func_802A42F4_de(&D_801379C0, arg1);
            }
            temp_a1 = arg1->unk138;
            if (temp_a1 != 0) {
                func_80268C7C_de(&D_8013B1A8, temp_a1);
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
