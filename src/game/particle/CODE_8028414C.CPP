#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS1E8.H"
#include "TYPES.H"
#include "FX_2/PARTICLE_SOUND.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"
#include "particle/80271B18_3.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "particle/8027A0F4_4.H"
extern s32 func_8025CA24_de(void *arg0, void *arg1);

extern s32 D_80140FF8[];
extern s32 D_800D297C;







void Particle_UpdateMatrix(Shared_Particle *particle) {
    CVector3 delta;
    GameplayCamera *camera;
    f32 amount;
    s32 *state;

    state = D_80140FF8;
    if (state[0] == 1) {
        camera = (GameplayCamera *)state[-4];
        Particle_TransformPoint(camera->worldToView, &particle->inst.pos, &delta);
        amount = delta.z;
        if (amount < 0.0f) {
            amount = -amount;
        }
        Particle_BuildMatrix(particle, &particle->mtx[D_800D297C], camera, amount);
    } else {
        Particle_BuildMatrix(particle, &particle->mtx[D_800D297C], 0, 0.0f);
    }
    particle->flags |= 0x100000;
}

/* Spawns a sequence of effects along an object's motion segment. */








extern char D_8011D8D0;

extern struct Shape_typemap_165 func_80271818_de(Triple *);
extern void Particle_SubtractVectors(Triple *, Triple *, Triple *);
extern void Particle_ScaleVector(Triple *, Triple *, f32);
extern void Particle_AddVec3(Triple *, Triple *, Triple *);
#include "particle/8027A0F4_8.H"
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
                rotation = func_80271818_de(&position);
                Particle_SubtractVectors(&delta, &actor->origin, &actor->end);
                system = &D_8011D8D0;
                i = 1;
                temp = i <= count;
                if (temp) {
                        divisor = (f32) count + (&D_800C4E88_de)[1];
                        do {
    do { Particle_ScaleVector(&step, &delta, (f32) i / divisor); Particle_AddVec3(&step, &step, &actor->end); actor_2 = actor->model; func_802800C0_de((struct EffectSystem *)system, (struct EffectActor *)actor, (struct EffectActor *)actor->owner, (s32 *)actor->property, actor->type, actor_2, *(CVector3 *)&position, *(CQuatern *)&rotation, *(CVector3 *)&step, 0, -1, 0x20E001); i++; } while (0);
                        } while (count >= i);
                }
        }
}


extern void *func_8025CC6C_de(void);
extern void *func_8025C95C_de(void *, s32, CVector3 *, void *, s32);






void func_802843B8_de(void *soundParticle, s32 arg1) {
    void *node;

    node = ((SoundParticle *)soundParticle)->sound;
    if (node != 0) {
        if (((Node80253610 *)node)->flags == arg1 && ((Node80253610 *)node)->references != -1) {
            return;
        }
        Particle_StopSound(soundParticle);
    }
    ((SoundParticle *)soundParticle)->sound =
        func_8025C95C_de(func_8025CC6C_de(), arg1, &((SoundParticle *)soundParticle)->particle.inst.pos, &((SoundParticle *)soundParticle)->particle.inst.pos, -1);
}

void Particle_StopSound(void *a) {
    if (((SoundParticle *)a)->sound != 0) {
        func_8025CA24_de(func_8025CC6C_de(), ((SoundParticle *)a)->sound);
        ((SoundParticle *)a)->sound = 0;
    }
}

#include "TYPES.H"

struct PoolNode84478;
typedef struct PoolBucket84478 {
    struct PoolNode84478 *head;
    struct PoolNode84478 *tail;
    s32 data[3];
} PoolBucket84478;
typedef struct PoolOwner84478 {
    char pad0[0xFC00];
    PoolBucket84478 free;
    char padFC14[0x14];
    PoolBucket84478 slots[256];
} PoolOwner84478;
typedef struct PoolNode84478 {
    char pad0[0x5C];
    s32 state;
    char pad60[0x184];
    PoolBucket84478 *owner;
    char pad1E8[8];
    s32 counter;
    s32 flags;
} PoolNode84478;
extern void Particle_Release(PoolOwner84478 *, PoolNode84478 *);

PoolNode84478 *Particle_AllocPoolNode(PoolOwner84478 *owner, s32 index) {
    PoolNode84478 *node;
    PoolBucket84478 *slot;
    s32 i;
    PoolNode84478 *tail;
    if (owner->free.head == 0) {
        for (i = 0; i <= (index & 0xFF); i++) {
            tail = (&owner->slots[i])->tail;
            if (tail != 0) {
                Particle_Release(owner, tail);
                break;
            }
        }
    }
    node = owner->free.head;
    if (node == 0) {
        return 0;
    }
    func_80255ED8_de(&owner->free, node);
    slot = &owner->slots[index & 0xFF];
    func_80255CB8_de(slot, node);
    node->owner = slot;
    node->flags = 0;
    node->counter = 0;
    node->state = 0x100;
    return node;
}
