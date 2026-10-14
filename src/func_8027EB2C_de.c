#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027A0F4.h"
#include "types.h"


extern s32 D_80140FF8;
extern s32 D_800D297C;
extern char D_8011FFB0;
extern char D_800C4D38_de;
extern char D_800C4D50_de;
extern char D_800C4D68_de;
extern char D_0026D7F4;

extern s32 func_802799C0_de(void *, s32);
extern void func_80272898_de(void *, void *, Vec3 *);
extern void func_8027DD48_de(void *, s32, s32, f32);
extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern s32 func_8028FE28_de(s32 *, s32, s32);
extern void func_80253838_de(s32, void *);
extern s32 func_802540F4_de(s32, void **, s32, void *, s32);
extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);
extern void func_8026DC24_de(void **, s32, s32, void *, s32, s32);
extern void func_80253754_de(s32, void *);








void func_8027EB2C_de(void *arg0, void *arg1) {
    Vec3 delta;
    void *sp38;
    void *lookup;
    void **resource;
    s32 key;
    s32 found;
    s32 index;
    f32 amount;

    index = 0;
    if (D_80140FF8 == 1) {
        lookup = (char *)arg0 + ((D_800D297C << 6) + 0x60);
    } else {
        lookup = (void *)func_802799C0_de(&D_8011FFB0, 1);
        if (lookup == 0) {
            return;
        }
        func_80272898_de(&((struct Shared_ParticleView *)arg1)->viewMtx, &((Shared_Particle *)arg0)->inst.pos, &delta);
        amount = delta.z;
        if (amount < 0.0f) {
            amount = -amount;
        }
        func_8027DD48_de(arg0, (s32)lookup, (s32)arg1, amount);
    }

    if (((Shared_Particle *)arg0)->resource == 0) {
        resource = func_8025193C_de(0, ((Shared_Particle *)arg0)->desc->renderModel,
                                ((Shared_Particle *)arg0)->desc->renderModel, 0x18,
                                0, 0, 0, &D_800C4D38_de, 1);
        if (resource != 0) {
            key = func_8028FE28_de(*resource,
                                ((Shared_Particle *)arg0)->desc->renderModel, 1);
            func_80253838_de(0, resource);
            found = func_802540F4_de(0, &sp38, key, &D_800C4D50_de, 1);
            if (found != 0) {
                ((Shared_Particle *)arg0)->resource = func_8028FE3C_de(
                    (s32)sp38, key, index % *(s32 *)sp38,
                    &((Shared_Particle *)arg0)->resourceSize);
                func_80253838_de(0, (void *)found);
            }
        }
        if (((Shared_Particle *)arg0)->resource == 0) {
            return;
        }
    }

    resource = func_8025193C_de(0, ((Shared_Particle *)arg0)->resource,
                            ((Shared_Particle *)arg0)->resource, ((Shared_Particle *)arg0)->resourceSize,
                            0, 0, &D_0026D7F4, &D_800C4D68_de, 1);
    if (resource != 0) {
        func_8026DC24_de(resource, (s32)lookup, 0,
                      (char *)arg0 + (((D_800D297C * 3) << 3) + 0xE0), 0, -1);
        func_80253754_de(0, resource);
    }
}
