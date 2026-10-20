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

extern void func_802065C0_de(void *a, ActorMotionState *b, unsigned short c);

extern void func_8028B670_de(void *a, unsigned short b, unsigned short c, int d);

extern int func_80245798_de(void);

/** For each of the object's child slots, attach the child to the record and spawn its effect. */
extern int D_800D297C;

extern void *func_8024BFD4_de(void *, int);

extern void func_8024AA18_de(char *obj, s32 unused, char *info);

extern void func_802472F0_de(void *);
extern void func_80402FB4_de(s32, void *);

void func_8020676C_de(void *arg0, void *arg1, Trigger *arg2) {
    extern void func_80285DB0_de(Shared_World *a, void *b, int c);
    func_802065C0_de(arg0, arg1, arg2->unk6);
    ((LevelActor *)arg0)->flags = ((LevelActor *)arg0)->flags | 0x2100;
    func_802472F0_de(arg0);
    func_80285DB0_de(&D_8011FE88, arg0, 0);
}

void func_802067BC_de(Shared_Actor *arg0) {
    extern void func_80285DB0_de(Shared_World *, void *, s32);
    s32 v = arg0->weaponFlags;
    v &= ~0x2000;
    v &= ~0x100;
    arg0->weaponFlags = v;
    func_80285DB0_de(&D_8011FE88, arg0, 1);
}

void func_802067FC_de(Trigger *arg0) {
    func_8028B670_de(&D_8011FE88, arg0->owner, arg0->actor, 1);
}

void func_8020682C_de(Shared_Actor *arg0, s32 *arg1) {
    extern void func_80285DB0_de(Shared_World *, void *, s32);
    arg0->weaponFlags |= 0x2100;
    if (func_80245798_de() != 0) {
        *arg1 |= 0x200;
    }
    func_802472F0_de(arg0);
    func_80285DB0_de(&D_8011FE88, arg0, 0);
}

void func_80206898_de(Trigger *arg0) {
    func_8028B670_de(&D_8011FE88, arg0->owner, arg0->actor, 0);
}

void func_802068C8_de(struct Shared_Actor *arg0, s32 arg1, s32 arg2) {
    extern void func_80285DB0_de(Shared_World *, void *, s32);
    func_80402FB4_de((s32)arg0, (void *)arg2);
    arg0->weaponFlags |= 0x2100;
    func_80285DB0_de(&D_8011FE88, arg0, 0);
}

void func_80206910_de(s32 arg0) {
    func_80402FB4_de(0, (void *)arg0);
}

/** Copy the source byte at offset 7 into two fields under object offset 0x18. */
void func_80206930_de(LevelActor *arg0, int arg1, Trigger *arg2) {
    void *inner = arg0->definition;
    ((ActorDefinitionHeader *)inner)->first = (s8)arg2->unk6;
    inner = arg0->definition;
    ((ActorDefinitionHeader *)inner)->second = (s8)arg2->unk6;
}

void func_8020694C_de(char *arg0, void *arg1, Rec *arg2) {
    int i;
    int n;
    void *child;

    n = (s8)((LevelActor *)arg0)->stateE7;
    for (i = 0; i < n; i++) {
        child = func_8024BFD4_de(arg0, i);
        if (child != 0) {
            arg2->a = child;
            arg2->b = child;
            func_8024AA18_de(arg0, arg1, arg2);
            func_8026DA4C_de(child, ((LevelActor *)arg0)->fieldB4, 1, &((LevelActor *)arg0)->lighting[D_800D297C], 0, ((LevelActor *)arg0)->field3);
        }
    }
}

#ifdef NON_MATCHING
#include "COMMON/REC.H"
#include "COMMON/LIGHTDATA.H"
extern f32 D_800D2988;
extern f32 D_800C1B04_de, D_800C1B08_de, D_800C1B0C_de;

void func_80206A20_de(Actor_func_80206DD4_de *arg0, RiderCode80206258 *arg1) {
    f32 temp_fs0;
    f32 temp_fs0f;
    f32 temp_fv0;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv0f_3;
    f32 temp_fv0f_4;
    f32 temp_fv0f_5;
    f32 temp_fv1;
    f32 var_fv0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0;
    s8 temp_s3;
    SegmentRecAt5C *temp_s0;

    temp_s3 = arg1->state;
    temp_s0 = &arg0->motionTrack->segment;
    if ((u32) temp_s3 < 5U) {
        switch (temp_s3) {
        case 0:
            temp_v1 = temp_s0->flags;
            if (temp_v1 & 0xC00000) {
                if (temp_v1 & 0x04000000) {
                    if (!(arg0->inputFlags & 0x40)) {
                        arg1->triggerTime = 0.0f;
                    } else {
                        var_fv0 = D_800D2988 + arg1->triggerTime;
                        goto block_11;
                    }
                } else {
                    temp_fv0f = arg1->triggerTime;
                    if ((temp_fv0f > 0.0f) || (arg0->inputFlags & 0x20)) {
                        var_fv0 = temp_fv0f + D_800D2988;
block_11:
                        arg1->triggerTime = var_fv0;
                    }
                    if (temp_s0->triggerDelay <= arg1->triggerTime) {
                        arg1->timer = 0.0f;
                        temp_v1_2 = temp_s0->flags;
                        if (temp_v1_2 & 0x01000000) {
                            arg1->state = 3;
                        } else if (!(temp_v1_2 & 0x400000)) {
block_21:
                            if (temp_s0->flags & 0x800000) {
                                arg1->state = 4;
                            }
                        } else {
block_19:
                            arg1->state = 1;
                        }
                    }
                }
            }
            break;
        case 3:
            temp_fs0 = D_800C1B04_de;
            temp_fs0f = D_800C1B08_de;
            arg1->shake.x = func_80274A90_de(temp_fs0, temp_fs0f);
            arg1->shake.y = func_80274A90_de(temp_fs0, temp_fs0f);
            temp_fv1 = arg1->timer + D_800D2988;
            arg1->shake.z = func_80274A90_de(temp_fs0, temp_fs0f);
            arg1->timer = temp_fv1;
            if (D_800C1B0C_de < temp_fv1) {
                arg1->timer = 0.0f;
                if (temp_s0->flags & 0x400000) {
                    goto block_19;
                }
                goto block_21;
            }
            break;
        case 1:
            temp_fv0f_2 = arg1->timer;
            temp_fv0 = temp_s0->duration;
            if (temp_fv0f_2 < temp_fv0) {
                arg1->timer = (f32) (temp_fv0f_2 + D_800D2988);
            } else if (temp_s0->flags & 0x02000000) {
                arg0->flags = (s32) (arg0->flags & ~0x2000);
            } else {
                arg1->timer = temp_fv0;
                if (!(temp_s0->flags & 0x08000000) || (var_a0 = 0, ((arg0->inputFlags & 0x40) != 0))) {
                    var_a0 = 1;
                    if (temp_s0->flags & 0x10000000) {
                        var_a0 = (u32) (arg0->inputFlags & 0x40) < 1U;
                    }
                }
                if (var_a0 != 0) {
                    arg1->state = 2;
                }
            }
            if (temp_s0->duration > 0.0f) {
block_41:
                arg1->shake.y = (f32) (-temp_s0->displacement * func_80265714_de(arg1->timer / temp_s0->duration));
            } else {
block_42:
                arg1->shake.y = (f32) -temp_s0->displacement;
            }
            break;
        case 2:
            temp_fv0f_3 = arg1->timer;
            if (!(temp_fv0f_3 > 0.0f)) {
                arg1->state = 0;
                arg1->triggerTime = 0.0f;
            } else {
                arg1->timer = (f32) (temp_fv0f_3 - D_800D2988);
            }
            if (temp_s0->duration > 0.0f) {
                goto block_41;
            }
            goto block_42;
        case 4:
            temp_fv0f_4 = arg1->timer;
            if (temp_fv0f_4 < temp_s0->duration) {
                arg1->timer = (f32) (temp_fv0f_4 + D_800D2988);
            }
            temp_fv0f_5 = temp_s0->duration;
            if (temp_fv0f_5 > 0.0f) {
                arg1->shake.y = (f32) (-temp_s0->displacement * func_80265714_de(arg1->timer / temp_fv0f_5));
            } else {
                arg1->shake.y = (f32) -temp_s0->displacement;
            }
            if (temp_s0->flags & 0x02000000) {
                arg0->flags = (s32) (arg0->flags & ~0x2000);
            }
            break;
        }
    }
    if (temp_s3 != arg1->state) {
        arg1->animation = -1;
    }
}
#else
INCLUDE_ASM("span_1000", func_80206A20_de);
#endif
