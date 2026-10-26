#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/PACKEDMESHMATERIAL.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "COMMON/SELF.H"
#include "RENDER/8028469C.H"
#include "SYSTEM/80255C40_3.H"

void *func_802846C8_de(EffectSystem *effectSystem, s32 arg1, EffectEntry *effectEntry) {
    void *record;

    record = effectEntry->params->listIndex[effectSystem->lists].head;
    if (effectEntry != 0) {
        if (record != 0) {
            do {
                if (((ParticleEffect *)record)->ownerId == arg1) {
                    if (((ParticleEffect *)record)->entry == effectEntry) {
                        return record;
                    }
                }
                record = ((ParticleEffect *)record)->next;
            } while (record != 0);
        }
    } else if (record != 0) {
        do {
            if (((ParticleEffect *)record)->ownerId == arg1) {
                return record;
            }
            record = ((ParticleEffect *)record)->next;
        } while (record != 0);
    }
    return 0;
}

extern void func_80255D70_de(void *, s32, s32);

void func_80284758_de(EffectSystem *arg0, ParticleEffect *arg1)
{
    void *current;
    s32 key;

    current = arg0->groups.head;
    if (current != 0) {
        key = (s32)arg1->entry;
loop:
        if (((ParticleEffect *)current)->entry != key) {
            current = ((ParticleEffect *)current)->groupNext;
            if (current != 0) {
                goto loop;
            }
        }
    }

    if (current != 0) {
        func_80255D70_de(&arg0->groups, current, arg1);
    } else if (arg1->entry->flags & 0x2000) {
        func_80255CB8_de(&arg0->groups, arg1);
    } else {
        func_80255D14_de(&arg0->groups, arg1);
    }

    arg1->flags |= 0x01000000;
}


s32 func_8028480C_de(s32 arg0) {
    if (arg0 != 0) {
        return GraphU64_NextRandom() % (arg0 + 1);
    }
    return 0;
}


void func_80284870_de(f32 arg0) {
    if (arg0 != 0.0f) {
        ((s32 (*)())GraphU64_RandomFloat)();
    }
}

/** Return offset 0x180 only when the nested state word is zero. */
float func_8028489C_de(ParticleEffect *effect) {
    void *inner = effect->entry;
    if (((EffectEntry *)inner)->unk14 != 0) {
        return 0.0f;
    }
    return effect->unk180[0];
}

f32 func_802848BC_de(ParticleEffect *effect) {
    f32 result;
    result = 0.0f;
    if ((effect->entry->unk14) == 0) {
        result = (effect->unk180[1]);
    }
    return result;
}

s32 func_802848DC_de(ParticleEffect *effect) {
    u16 kind;
    s32 val;

    kind = effect->kind;
    val = kind;
    if (val == 0x56) {
        goto ret1;
    }
    if (val >= 0x57) {
        goto ge_e;
    }
    if (val == 2) {
        goto ret1;
    }
    goto ret0;
ge_e:
    if (val == 0x111) {
        goto ret1;
    }
    if (val != 0x126) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}

s32 func_80284928_de(ParticleEffect *effect) {
    u16 kind;
    s32 val;

    kind = effect->kind;
    val = kind;
    if (val == 0x11) {
        goto ret1;
    }
    if (val >= 0x12) {
        goto ge_12;
    }
    if (val < 5) {
        goto ret0;
    }
    if (val < 8) {
        goto ret1;
    }
    if (val == 9) {
        goto ret1;
    }
    goto ret0;
ge_12:
    if (val == 0x1A) {
        goto ret1;
    }
    if (val >= 0x1B) {
        goto ge_1b;
    }
    if (val == 0x13) {
        goto ret1;
    }
    goto ret0;
ge_1b:
    if (val == 0x101) {
        goto ret1;
    }
    if (val != 0x110) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}

s32 func_802849AC_de(ParticleEffect *effect) {
    u16 kind;
    s32 val;

    kind = effect->kind;
    val = kind;
    if (val == 0xD) {
        goto ret1;
    }
    if (val >= 0xE) {
        goto ge_e;
    }
    if (val == 8) {
        goto ret1;
    }
    goto ret0;
ge_e:
    if (val != 0x12) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}

#include "COMMON/BALLISTICPARAMS.H"

void func_802849F0_de(ParticleEffect *effect)
{
    CVector3 delta;
    CVector3 direction;
    f32 acceleration;
    f32 speed;
    f32 limit;
    f32 x, y, z;
    CVector3 *velocity;

    Player_ApplyPlayerForces(&D_80145040, effect);
    acceleration = func_802B2350(effect->entry->motion->acceleration);
    if (acceleration != 0.0f) {
        direction = effect->direction;
        GraphU64_ScaleVector(&delta, &direction, acceleration);
        GraphU64_AddVec3(&effect->velocity, &effect->velocity, &delta);
        velocity = &effect->velocity;
        x = effect->velocity.x;
        y = effect->velocity.y;
        z = effect->velocity.z;
        speed = Math_Sqrtf(x * x + y * y + z * z);
        limit = func_802B2350(effect->entry->motion->speedLimit);
        if (acceleration > 0.0f) {
            if (!(limit < speed)) goto finished;
        } else {
            if (!(speed < limit)) goto finished;
        }
        GraphU64_ScaleVector(velocity, &direction, limit);
finished:
        ;
    }
    Particle_UpdateSineMotion(effect, 1.0f);
}
