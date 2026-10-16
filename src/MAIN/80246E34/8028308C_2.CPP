#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028308C.h"
#include "TYPES.H"
#include "shared/particle_sound.h"

extern s32 D_80140FF8[];
extern s32 D_800D297C;

extern void func_80272898_de(void *, void *, Vec3 *);
extern void func_8027DD48_de(void *, s32, s32, f32);






void func_80284178_de(void *arg0) {
    Vec3 delta;
    void *arg1;
    f32 amount;
    s32 *state;

    state = D_80140FF8;
    if (state[0] == 1) {
        arg1 = (void *)state[-4];
        func_80272898_de(&((struct Shared_ParticleView *)arg1)->viewMtx, &((Shared_Particle *)arg0)->inst.pos, &delta);
        amount = delta.z;
        if (amount < 0.0f) {
            amount = -amount;
        }
        func_8027DD48_de(arg0,
                      (s32)((char *)arg0 + ((D_800D297C << 6) + 0x60)),
                      (s32)arg1, amount);
    } else {
        func_8027DD48_de(arg0,
                      (s32)((char *)arg0 + ((D_800D297C << 6) + 0x60)),
                      0, 0.0f);
    }
    ((Shared_Particle *)arg0)->flags |= 0x100000;
}

/* Spawns a sequence of effects along an object's motion segment. */








extern char D_8011D8D0;

extern void func_80271818_de(struct Shape_typemap_165 *, Triple *);
extern void func_80271F68_de(Triple *, Triple *, Triple *);
extern void func_80271F9C_de(Triple *, Triple *, f32);
extern void func_80271F34_de(Triple *, Triple *, Triple *);
extern s32 func_802800C0_de(void *, void *, void *, s32, s32, s32,
                         Triple, struct Shape_typemap_165, Triple, s32, s32, s32);
void func_8028422C_de(TrailActor *actor) {
        struct Shape_typemap_165 rotation;
        int temp;
        Triple delta;
        Triple step;
        unsigned int actor_2;
        Triple position;
        f32 divisor;
        s32 i;
        s8 count;
        void *system;
        count = actor->node->state->count;
        if (count > 0) {
                position = actor->position;
                func_80271818_de(&rotation, &position);
                func_80271F68_de(&delta, &actor->origin, &actor->end);
                system = &D_8011D8D0;
                i = 1;
                temp = i <= count;
                if (temp) {
                        divisor = (f32) count + (&D_800C4E88_de)[1];
                        do {
    do { func_80271F9C_de(&step, &delta, (f32) i / divisor); func_80271F34_de(&step, &step, &actor->end); actor_2 = actor->model; func_802800C0_de(system, actor, actor->owner, actor->property, actor->type, actor_2, position, rotation, step, 0, -1, 0x20E001); i++; } while (0);
                        } while (count >= i);
                }
        }
}


extern void *func_8025CC6C_de(void);
extern void *func_8025C95C_de(void *, s32, Vec3 *, void *, s32);






void func_802843B8_de(void *arg0, s32 arg1) {
    void *node;

    node = ((SoundParticle *)arg0)->sound;
    if (node != 0) {
        if (((Node80253610 *)node)->flags == arg1 && ((Node80253610 *)node)->references != -1) {
            return;
        }
        func_80284434_de(arg0);
    }
    ((SoundParticle *)arg0)->sound =
        func_8025C95C_de(func_8025CC6C_de(), arg1, &((SoundParticle *)arg0)->particle.inst.pos, &((SoundParticle *)arg0)->particle.inst.pos, -1);
}

s32 func_80284434_de(void *a) {
    if (((SoundParticle *)a)->sound != 0) {
        func_8025CA24_de(func_8025CC6C_de(), ((SoundParticle *)a)->sound);
        ((SoundParticle *)a)->sound = 0;
    }
}
