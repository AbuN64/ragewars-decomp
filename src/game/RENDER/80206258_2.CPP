#include "COMMON/MODEL_RENDER.H"
#include "include_asm.h"
#include "COMMON/REC.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/LISTHEADER.H"
#include "TYPES.H"
#include "RENDER/80206258_2.H"
#include "RENDER/80206258.H"

extern void func_8028B670_de(void *a, unsigned short b, unsigned short c, int d);

extern int func_80245798_de(void);

/** For each of the object's child slots, attach the child to the record and spawn its effect. */
extern int D_800D297C;

extern void *func_8024BFD4_de(void *, int);

extern void func_8024AA18_de(char *obj, s32 unused, char *info);

extern void func_802472F0_de(void *);
extern void func_80402FB4_de(s32, void *);

void func_8020676C_de(void *arg0, void *arg1, Trigger *trigger) {
    extern void func_80285DB0_de(Shared_World *a, void *b, int c);
    func_802065C0_de(arg0, arg1, trigger->unk6);
    ((LevelActor *)arg0)->flags = ((LevelActor *)arg0)->flags | 0x2100;
    func_802472F0_de(arg0);
    func_80285DB0_de(&D_8011FE88, arg0, 0);
}

void func_802067BC_de(Shared_Actor *actor) {
    extern void func_80285DB0_de(Shared_World *, void *, s32);
    s32 v = actor->weaponFlags;
    v &= ~0x2000;
    v &= ~0x100;
    actor->weaponFlags = v;
    func_80285DB0_de(&D_8011FE88, actor, 1);
}

void func_802067FC_de(Trigger *trigger) {
    func_8028B670_de(&D_8011FE88, trigger->owner, trigger->actor, 1);
}

void func_8020682C_de(Shared_Actor *actor, s32 *arg1) {
    extern void func_80285DB0_de(Shared_World *, void *, s32);
    actor->weaponFlags |= 0x2100;
    if (func_80245798_de() != 0) {
        *arg1 |= 0x200;
    }
    func_802472F0_de(actor);
    func_80285DB0_de(&D_8011FE88, actor, 0);
}

void func_80206898_de(Trigger *trigger) {
    func_8028B670_de(&D_8011FE88, trigger->owner, trigger->actor, 0);
}

void func_802068C8_de(struct Shared_Actor *actor, s32 arg1, s32 arg2) {
    extern void func_80285DB0_de(Shared_World *, void *, s32);
    func_80402FB4_de((s32)actor, (void *)arg2);
    actor->weaponFlags |= 0x2100;
    func_80285DB0_de(&D_8011FE88, actor, 0);
}

void func_80206910_de(s32 arg0) {
    func_80402FB4_de(0, (void *)arg0);
}

/** Copy the source byte at offset 7 into two fields under object offset 0x18. */
void func_80206930_de(LevelActor *actor, int arg1, Trigger *arg2) {
    void *inner = actor->definition;
    ((ActorDefinitionHeader *)inner)->first = (s8)arg2->unk6;
    inner = actor->definition;
    ((ActorDefinitionHeader *)inner)->second = (s8)arg2->unk6;
}

void func_8020694C_de(char *arg0, void *arg1, Rec *info) {
    int i;
    int n;
    void *child;

    n = (s8)((LevelActor *)arg0)->stateE7;
    for (i = 0; i < n; i++) {
        child = func_8024BFD4_de(arg0, i);
        if (child != 0) {
            info->a = child;
            info->b = child;
            func_8024AA18_de(arg0, arg1, info);
            func_8026DA4C_de(child, ((LevelActor *)arg0)->fieldB4, 1, &((LevelActor *)arg0)->lighting[D_800D297C], 0, ((LevelActor *)arg0)->field3);
        }
    }
}

#ifdef NON_MATCHING
#include "COMMON/REC.H"
#include "COMMON/LIGHTDATA.H"
extern f32 D_800D2988;
extern f32 D_800C1B04_de, D_800C1B08_de, D_800C1B0C_de;

/* 223/237 aligned words; remaining: release flag loads and register allocation. */
/* Advance triggered shaking and vertical motion, invalidating animation on a state change. */
void Render_UpdateTriggeredMotion(Actor_func_80206DD4_de *actor, RiderCode80206258 *motion) {
    SegmentRecAt5C *segment;
    s32 oldState;
    s32 release;
    f32 shakeMin;
    f32 shakeMax;

    oldState = motion->state;
    segment = &actor->motionTrack->segment;
    switch (oldState) {
    case 0:
        if (segment->flags & 0xC00000) {
            if (segment->flags & 0x04000000) {
                if (actor->inputFlags & 0x40) {
                    motion->triggerTime = motion->triggerTime + D_800D2988;
                } else {
                    motion->triggerTime = 0.0f;
                    break;
                }
            } else if (motion->triggerTime > 0.0f || (actor->inputFlags & 0x20)) {
                motion->triggerTime += D_800D2988;
            }
            if (motion->triggerTime >= segment->triggerDelay) {
                motion->timer = 0.0f;
                if (segment->flags & 0x01000000) {
                    motion->state = 3;
                } else if (segment->flags & 0x400000) {
                    motion->state = 1;
                } else if (segment->flags & 0x800000) {
                    motion->state = 4;
                }
            }
        }
        break;
    case 3:
        shakeMin = D_800C1B04_de;
        shakeMax = D_800C1B08_de;
        motion->shake.x = func_80274A90_de(shakeMin, shakeMax);
        motion->shake.y = func_80274A90_de(shakeMin, shakeMax);
        motion->shake.z = func_80274A90_de(shakeMin, shakeMax);
        motion->timer += D_800D2988;
        if (D_800C1B0C_de < motion->timer) {
            motion->timer = 0.0f;
            if (segment->flags & 0x400000) {
                motion->state = 1;
            } else if (segment->flags & 0x800000) {
                motion->state = 4;
            }
        }
        break;
    case 1:
        if (motion->timer < segment->duration) {
            motion->timer += D_800D2988;
        } else if (segment->flags & 0x02000000) {
            actor->flags &= ~0x2000;
        } else {
            motion->timer = segment->duration;
            release = 0;
            if (!(segment->flags & 0x08000000) || (actor->inputFlags & 0x40)) {
                release = 1;
                if (segment->flags & 0x10000000) {
                    release = (u32)(actor->inputFlags & 0x40) < 1U;
                }
            }
            if (release) {
                motion->state = 2;
            }
        }
        if (segment->duration > 0.0f) {
            motion->shake.y = -segment->displacement * func_80265714_de(motion->timer / segment->duration);
        } else {
            motion->shake.y = -segment->displacement;
        }
        break;
    case 2:
        if (motion->timer > 0.0f) {
            motion->timer -= D_800D2988;
        } else {
            motion->state = 0;
            motion->triggerTime = 0.0f;
        }
        if (segment->duration > 0.0f) {
            motion->shake.y = -segment->displacement * func_80265714_de(motion->timer / segment->duration);
        } else {
            motion->shake.y = -segment->displacement;
        }
        break;
    case 4:
        if (motion->timer < segment->duration) {
            motion->timer += D_800D2988;
        }
        if (segment->duration > 0.0f) {
            motion->shake.y = -segment->displacement * func_80265714_de(motion->timer / segment->duration);
        } else {
            motion->shake.y = -segment->displacement;
        }
        if (segment->flags & 0x02000000) {
            actor->flags &= ~0x2000;
        }
        break;
    }
    if (oldState != motion->state) {
        motion->animation = -1;
    }
}
#else
INCLUDE_ASM("span_1000", Render_UpdateTriggeredMotion);
#endif
