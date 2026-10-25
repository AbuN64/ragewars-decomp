#include "include_asm.h"
#include "COMMON/GROUP.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/LEGACY_COLLISION_ACTOR.H"
#include "COMMON/MOTION_STEP.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "CAMERA/80243A80.H"
#include "GAME/CODE_8027302C.H"

void func_8023E45C_de(void *);

void func_8023E6EC_de(void *, void *);

void func_8023E838_de(void *);

void func_8023EBD4_de(void *);

void func_8023EBFC_de(ActorMotion *, MotionContactResult *);

void func_8023EC54_de(ActorMotion *, MotionContactResult *);

void func_8023ECBC_de(void *, u16 *);

f32 func_802417C4_de(f32 *);

f32 Particle_GetActorHeight(void *);

f32 func_8024E420_de(void *);

f32 Sound_GetActorReach(void *);

f32 func_80273F94_de(f32, f32);

extern void Nav_EaseValueToward(f32 *value, f32 target, f32 rate);

f32 func_8027525C_de(void *, f32, f32);

f32 func_80275DD4_de(void *, f32, f32);

void * func_8028C050_de(void *, CVector3 *);

s32 func_8023CFE0_de();

                     /* extern */


                         /* extern */
extern Func80243A80Global *D_80103FCC;

extern s32 D_80103FD0;

extern s32 D_801001D0;

extern s32 D_80100338;

extern float D_800C379C_de;

/* Moves an actor through collision queries and updates its contact flags and resolved position. */
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x2d0, 0x2d4, 0x2d8, 0x2dc, 0x2e0, 0x2e4, 0x2e8, 0x2f8, 0x2fc, 0x300, 0x304], gap at: 0x2ec. */
typedef Shared_Func80243A80Frame Func80243A80Frame;

typedef CVector3 Func80243A80Vec3;

typedef Shared_Func80243A80Bits Func80243A80Bits;

extern void func_8023E6D0_de(void *arg0, f32 arg1);

extern void func_8023EBD4_de(void *arg0);

extern void func_8023E838_de(void *arg0);

extern void func_8023E45C_de(void *arg0);

s32 func_80243A90_de(Func80243A80Actor *actor, Func80243A80Vec3 pos, u32 *arg4) {
    s32 func_8023D380_de();
    Func80243A80Frame frame;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 high;
    f32 count;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 var_f2;
    s32 temp_v0;
    s32 flags;
    s32 var_a1; 
    s32 var_a1_3;
    s32 var_s0;
    s32 var_s3;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    u16 *surface;
    u32 temp_a0;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 var_v0_2;
    u32 loopMask; 
    f32 dropDistance; 
    Func80243A80Actor *attachedActor; 
    s32 collisionOne; 
    f32 hitY; 
    f32 actorY; 
    f32 savedY; 

    func_8023EBD4_de(&frame.sp18);
    __builtin_memcpy(&D_80103FCC->x, &actor->room, 12);
    actor->flags = (u32) (actor->flags & ~0x18);
    frame.sp18 = actor;
    var_a1 = 0;
    if (actor->type == 1) {
        var_a1 = (u32) var_a1 < (actor->status & 0x300000);
    }
    frame.sp1C = var_a1;
    temp_f22 = Sound_GetActorReach(actor);
    count = func_8024D398_de(actor);
    high = Particle_GetActorHeight(actor);
    func_8023E690_de(&frame.sp18, temp_f22, count, high, func_8024E420_de(actor));
    *(Func80243A80Vec3 *)&frame.sp5C = *(Func80243A80Vec3 *)&actor->x;
    __builtin_memcpy(&frame.sp68, &pos, 12);
    __builtin_memcpy(&frame.sp8C, &actor->room, 12);
    frame.spC4 = actor->collision;
    var_v1 = 0;
    if ((*arg4 & 0x200) && (actor->velY <= 0.0f)) {
        var_v1 = 1;
    }
    frame.sp3C = var_v1;
    frame.sp38 = ((u32) *arg4 >> 1) & 1;
    frame.sp40 = (((u32) actor->flags >> 2) ^ 1) & 1;
    frame.sp44 = 1;
    frame.sp54 = actor->flags;
    frame.sp34 = frame.sp28 * D_800C3790_de;
    frame.sp50 = ((u32) *arg4 >> 0x13) & 1;
    frame.sp58 = arg4;
    func_8023CFE0_de(&frame.sp18);
    if ((frame.sp3C != 0) && (frame.sp54 & 7) && !(frame.sp54 & 0x2000)) {
        __builtin_memcpy(&frame.sp210, &actor->contactX, 12);
        frame.sp1E0 = actor->x;
        frame.sp1E4 = actor->groundY;
        frame.sp1E8 = actor->z;
        func_8023E6EC_de(&frame.sp18, &frame.sp1C8);
    }
    if ((frame.sp1C != 0) || (frame.sp5C != frame.sp68) || (frame.sp60 != frame.sp6C) || (var_v0 = 0, (frame.sp64 != frame.sp70))) {
        var_v1_2 = ++D_800CB410_de;
        if (var_v1_2 < D_800CB414_de) {
            var_v1_2 = D_800CB414_de;
        }
        D_800CB414_de = var_v1_2;
        if ((arg4 != &D_80100338) && (arg4 != &D_801001D0) && (arg4 != &D_80103FD0) && (arg4 != &D_80100170)) {
            actor->attached = 0;
            frame.sp54 &= ~0x7B;
        }
        frame.sp54 &= ~0x80;
        if (actor->type == 1) {
            frame.sp2C8 = actor->angle;
        } else {
            frame.sp2C8 = 0.0f;
        }
        temp_f22_2 = func_802B7130_de(frame.sp2C8);
        temp_f0 = func_802B6560_de(frame.sp2C8);
        frame.sp54 &= ~0x2000;
        temp_v1 = *arg4;
        if (temp_v1 & 4) {
            var_s0 = 1;
        } else if (temp_v1 & 0x800) {
            var_s0 = 3;
        } else {
            if (actor->type == 1) var_s0 = 4;
            else var_s0 = 1;
        }
        var_v1_3 = var_s0;
        if (var_s0 >= 3) {
            var_v1_3 = 2;
        }
        frame.sp48 = var_v1_3;
        var_v1_4 = var_s0 + 1;
        if (var_v1_4 >= 4) {
            var_v1_4 = 3;
        }
        frame.sp4C = var_v1_4;
        func_8023E838_de(&frame.sp18);
        var_s3 = 0;
        loopMask = 0x80000;
        collisionOne = 1;
loop_34:
        if (*arg4 & loopMask) {
            frame.spC4 = func_8028C050_de(frame.spC4, &frame.sp68);
        }
        temp_v0 = func_8023D158_de((s8 *) &frame.sp18);
        var_a1 = 0;
        if (temp_v0 != 0) {
            if (frame.spC8 != collisionOne) {
                if (frame.spC8 == 4) {
                    if (((frame.sp110 * -temp_f22_2) + (frame.sp118 * -temp_f0)) < D_800C3794_de) {
                        frame.sp54 |= 0x80;
                        func_8023EBFC_de(&frame.sp18, &frame.spC8);
                    }
                } else {
                    goto block_42;
                }
            } else {
                frame.sp38 = 0;
block_42:
                frame.sp54 &= ~0x80;
            }
            func_8023E45C_de(&frame.sp18);
            var_s3 += 1;
            var_a1 = func_8023D380_de(&frame.sp18);
            __builtin_memcpy(&frame.sp5C, &frame.sp198, 12);
            __builtin_memcpy(&frame.sp68, &frame.sp1B0, 12);
            __builtin_memcpy(&frame.sp8C, &frame.sp1BC, 12);
        } else {
            __builtin_memcpy(&frame.sp5C, &frame.sp68, 12);
        }
        var_s0 -= 1;
        if (var_a1 == 0) {
        } else if (var_s0 != 0) {
            goto loop_34;
        }
        __builtin_memcpy(&actor->x, &frame.sp5C, 12);
        __builtin_memcpy(&actor->room, &frame.sp8C, 12);
        frame.sp54 &= ~4;
        if (*arg4 & 0x40000) {
            __builtin_memcpy(&frame.sp68, &frame.sp5C, 12);
            frame.sp44 = 0;
            frame.sp48 = 0;
            frame.sp4C = 0;
            savedY = frame.sp6C;
            dropDistance = D_800C3798_de;
            frame.sp6C = savedY - dropDistance;
            __builtin_memcpy(&frame.sp2A8, &D_801000F0, sizeof(D_801000F0));
            frame.sp58 = &frame.sp2A8;
            temp_v1_2 = frame.sp2A8 & 0xFFE7FFF7;
            frame.sp2A8 = temp_v1_2;
            frame.sp2A8 = temp_v1_2 | (*arg4 & 0x180008);
            frame.sp50 = 0;
            func_8023E838_de(&frame.sp18);
            actor->contactX = 0.0f;
            actor->contactZ = 0.0f;
            actor->contactBits = D_800C379C_de;
            actor->groundY = (f32) (actor->y - dropDistance);
loop_49:
            if (func_8023D158_de((s8 *) &frame.sp18) != 0) {
                if (frame.spD0 == 7) {
                    frame.sp3C = 0;
                }
                func_8023D380_de(&frame.sp18);
                var_a1_3 = 0;
                actor->groundY = frame.sp19C;
                __builtin_memcpy(&actor->contactX, &frame.sp110, 12);
                actorY = actor->y;
                hitY = frame.sp19C;
                var_f2 = actorY - hitY;
                if ((frame.sp3C != 0) && (var_f2 < D_800C37A0_de)) {
                    frame.sp3C = 0;
                    actor->velY = 0.0f;
                    var_f2 = actor->velY;
                    actor->y = hitY;
                }
                if ((actor->velY <= 0.0f) && (var_f2 < D_800C37A4_de)) {
                    if (frame.spC8 == 5) {
                        frame.sp54 |= 0x2004;
                        func_8023EC54_de(&frame.sp18, &frame.spC8);
                        var_a1_3 = 1;
                        *frame.sp58 &= ~8;
                    } else {
                        if (frame.spC8 < 5) goto no_attach;
                        if (frame.spC8 >= 0xA) goto no_attach;
                        if (frame.spC8 < 7) goto no_attach;
                        if (frame.sp11C->type != 1) goto no_attach;
                        attachedActor = frame.sp11C;
                        actor->attached = attachedActor;
                        flags = attachedActor->flags;
                        attachedActor->flags = (s32) (flags | 0x20);
                        if (frame.sp1C != 0) {
                            attachedActor->flags = (s32) (flags | 0x60);
                        }
                        var_v0_2 = (frame.sp54 & ~3) | 2;
                        goto attach_done;
no_attach:
                        var_v0_2 = frame.sp54 | 4;
attach_done:
                        frame.sp54 = var_v0_2;
                    }
                }
                if (var_a1_3 != 0) {
                    __builtin_memcpy(&frame.sp5C, &frame.sp198, 12);
                    goto block_71;
                }
            } else {
                var_a1_3 = 0;
block_71:
                if (var_a1_3 == 0) {

                } else {
                    goto loop_49;
                }
            }
        }
        temp_a0 = frame.sp54;
        frame.sp54 = temp_a0 & ~0x100;
        if ((frame.sp38 != 0) || (temp_a0 & 0x80)) {
            __builtin_memcpy(&frame.sp5C, &actor->x, 12);
            __builtin_memcpy(&frame.sp68, &actor->x, 12);
            frame.sp44 = 0;
            frame.sp48 = 0;
            frame.sp4C = 0;
            frame.sp58 = &D_801000F0.flags;
            frame.sp68 -= temp_f22_2 * D_800C37A8_de;
            frame.sp70 -= temp_f0 * D_800C37A8_de;
            func_8023E838_de(&frame.sp18);
            if ((func_8023D158_de((s8 *) &frame.sp18) != 0) && (frame.spC8 == 4)) {
                if (frame.sp38 != 0) {
                    func_8023D380_de(&frame.sp18);
                    actor->x = frame.sp198;
                    actor->z = frame.sp1A0;
                    frame.sp54 |= 0x100;
                    func_8023EBFC_de(&frame.sp18, &frame.spC8);
                    if (actor->type == 1) {
                        Nav_EaseValueToward(&frame.sp2C8, frame.sp2C8 - func_80273F94_de(frame.sp2C8, func_802417C4_de((f32 *) &frame.spC8)), 0.9f);
                        actor->angle = frame.sp2C8;
                    }
                }
            } else {
                frame.sp54 &= ~0x80;
            }
        }
        if (*arg4 & 0x80000) {
            surface = func_8028C050_de(frame.spC4, &actor->x);
            frame.sp54 &= ~0x5000;
            if ((surface != 0) && ((((Func80243A80Collision *)surface)->flags & 0x41) == 0x41) && (func_80275DD4_de(surface, actor->x, actor->z) <= actor->y)) {
                temp_f0_2 = func_8027525C_de(surface, actor->x, actor->z);
                if (actor->y <= temp_f0_2) {
                    frame.sp54 |= 0x4000;
                }
                temp_f0_2 += frame.sp34;
                if (actor->y <= temp_f0_2) {
                    frame.sp54 |= 0x1000;
                }
                func_8023ECBC_de(&frame.sp18, surface);
            }
            actor->collision = surface;
        }
        actor->flags = frame.sp54;
        return var_s3;
    }
    return 0;
}

s32 func_802444A4_de(char *arg0, CVector3 arg1, CVector3 desired, s32 arg3) {
    extern s32 func_8023D380_de(void *arg0);
    Work80244494 work;
    VectorPair vectors;
    char *object = arg0;
    char *out;
    s32 count;
    s32 active;
    s32 result;
    s32 next;
    s32 maximum;
    s32 flags;

    func_8023E6D0_de(work.data, 0.0f);
    out = work.data;
    vectors.first = arg1;
    vectors.second = desired;
    func_8023EBD4_de(out);
    if (vectors.first.x == vectors.second.x &&
        vectors.first.y == vectors.second.y &&
        vectors.first.z == vectors.second.z) {
        return 0;
    }

    D_800CB418_de += 1;
    maximum = D_800CB41C_de;
    next = D_800CB418_de;
    if (next < maximum) {
        next = maximum;
    }
    D_800CB41C_de = next;

    ((struct ActorMotion *)(out))->actor = object;
    if (object != 0) {
        s32 value = 0;
        if (*(u8 *)object == 1) {
            flags = ((struct LevelActor *)(object))->flags;
            flags &= 0x300000;
            value = flags != 0;
        }
        ((struct ActorMotion *)(out))->actorFlags = value;
    } else {
        ((struct ActorMotion *)(out))->actorFlags = 0;
    }

    ((struct ActorMotion *)(out))->start = vectors.first;
    ((struct ActorMotion *)(out))->end = vectors.second;
    ((struct ActorMotion *)(out))->grounded = 0;
    ((struct ActorMotion *)(out))->candidate = 0;
    ((struct ActorMotion *)(out))->candidateIndex = 0;
    ((struct ActorMotion *)(out))->orientationActive = 0;
    ((struct ActorMotion *)(out))->iteration = 0;
    ((struct ActorMotion *)(out))->surface = (MotionSurface *)arg3;
    ((struct ActorMotion *)(out))->queryFlags = 0;
    ((struct ActorMotion *)(out))->horizontalTicks = 0;
    ((struct ActorMotion *)(out))->verticalTicks = 0;
    func_8023E838_de(out);

    active = 1;
    count = 0;
    do {
        if (func_8023D158_de(out) != 0) {
            func_8023E45C_de(out);
            count += 1;
            result = func_8023D380_de(out);
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->interpolated;
            ((struct ActorMotion *)(out))->end = ((struct ActorMotion *)(out))->position;
            ((struct ActorMotion *)(out))->orientation = ((struct ActorMotion *)(out))->projectedOrientation;
            active -= 1;
        } else {
            result = 0;
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->end;
            active -= 1;
        }
    } while (result != 0 && active != 0);
    return count;
}

s32 func_802446E0_de(char *arg0, CVector3 arg1, CVector3 arg2, MotionSurface *arg3,
                   f32 arg4) {
    extern s32 func_8023D380_de(void *arg0);
    Work80244494 work;
    VectorPair vectors;
    char *object = arg0;
    char *out;
    s32 count;
    s32 active;
    s32 result;
    s32 next;
    s32 maximum;
    s32 flags;

    func_8023E6D0_de(work.data, arg4);
    out = work.data;
    vectors.first = arg1;
    vectors.second = arg2;
    func_8023EBD4_de(out);
    if (vectors.first.x == vectors.second.x &&
        vectors.first.y == vectors.second.y &&
        vectors.first.z == vectors.second.z) {
        return 0;
    }

    D_800CB418_de += 1;
    maximum = D_800CB41C_de;
    next = D_800CB418_de;
    if (next < maximum) {
        next = maximum;
    }
    D_800CB41C_de = next;

    ((struct ActorMotion *)(out))->actor = object;
    if (object != 0) {
        s32 value = 0;
        if (*(u8 *)object == 1) {
            flags = ((struct LevelActor *)(object))->flags;
            flags &= 0x300000;
            value = flags != 0;
        }
        ((struct ActorMotion *)(out))->actorFlags = value;
    } else {
        ((struct ActorMotion *)(out))->actorFlags = 0;
    }

    ((struct ActorMotion *)(out))->start = vectors.first;
    ((struct ActorMotion *)(out))->end = vectors.second;
    ((struct ActorMotion *)(out))->grounded = 0;
    ((struct ActorMotion *)(out))->candidate = 0;
    ((struct ActorMotion *)(out))->candidateIndex = 0;
    ((struct ActorMotion *)(out))->orientationActive = 0;
    ((struct ActorMotion *)(out))->iteration = 0;
    ((struct ActorMotion *)(out))->surface = arg3;
    ((struct ActorMotion *)(out))->queryFlags = 0;
    ((struct ActorMotion *)(out))->horizontalTicks = 0;
    ((struct ActorMotion *)(out))->verticalTicks = 0;
    func_8023E838_de(out);

    active = 1;
    count = 0;
    do {
        if (func_8023D158_de(out) != 0) {
            func_8023E45C_de(out);
            count += 1;
            result = func_8023D380_de(out);
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->interpolated;
            ((struct ActorMotion *)(out))->end = ((struct ActorMotion *)(out))->position;
            ((struct ActorMotion *)(out))->orientation = ((struct ActorMotion *)(out))->projectedOrientation;
            active -= 1;
        } else {
            result = 0;
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->end;
            active -= 1;
        }
    } while (result != 0 && active != 0);
    return count;
}

s32 func_8024491C_de(char *arg0, CVector3 arg1, CVector3 arg2, MotionSurface *arg3,
                  CVector3 arg4, f32 arg5) {
    extern s32 func_8023D380_de(void *arg0);
    Work80244494 work;
    VectorPair vectors;
    char *object = arg0;
    char *out;
    s32 count;
    s32 active;
    s32 result;
    s32 next;
    s32 maximum;
    s32 flags;

    func_8023E690_de(work.data, arg4.x, arg4.y, arg4.z, arg5);
    out = work.data;
    vectors.first = arg1;
    vectors.second = arg2;
    func_8023EBD4_de(out);
    if (vectors.first.x == vectors.second.x &&
        vectors.first.y == vectors.second.y &&
        vectors.first.z == vectors.second.z) {
        return 0;
    }

    D_800CB418_de += 1;
    maximum = D_800CB41C_de;
    next = D_800CB418_de;
    if (next < maximum) {
        next = maximum;
    }
    D_800CB41C_de = next;

    ((struct ActorMotion *)(out))->actor = object;
    if (object != 0) {
        s32 value = 0;
        if (*(u8 *)object == 1) {
            flags = ((struct LevelActor *)(object))->flags;
            flags &= 0x300000;
            value = flags != 0;
        }
        ((struct ActorMotion *)(out))->actorFlags = value;
    } else {
        ((struct ActorMotion *)(out))->actorFlags = 0;
    }

    ((struct ActorMotion *)(out))->start = vectors.first;
    ((struct ActorMotion *)(out))->end = vectors.second;
    ((struct ActorMotion *)(out))->grounded = 0;
    ((struct ActorMotion *)(out))->candidate = 0;
    ((struct ActorMotion *)(out))->candidateIndex = 0;
    ((struct ActorMotion *)(out))->orientationActive = 0;
    ((struct ActorMotion *)(out))->iteration = 0;
    ((struct ActorMotion *)(out))->surface = arg3;
    ((struct ActorMotion *)(out))->queryFlags = 0;
    ((struct ActorMotion *)(out))->horizontalTicks = 0;
    ((struct ActorMotion *)(out))->verticalTicks = 0;
    func_8023E838_de(out);

    active = 1;
    count = 0;
    do {
        if (func_8023D158_de(out) != 0) {
            func_8023E45C_de(out);
            count += 1;
            result = func_8023D380_de(out);
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->interpolated;
            ((struct ActorMotion *)(out))->end = ((struct ActorMotion *)(out))->position;
            ((struct ActorMotion *)(out))->orientation = ((struct ActorMotion *)(out))->projectedOrientation;
            active -= 1;
        } else {
            result = 0;
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->end;
            active -= 1;
        }
    } while (result != 0 && active != 0);
    return count;
}

s32 func_80244B68_de(char *arg0, char *arg1, CVector3 first, CVector3 second,
                   s32 arg4) {
    extern s32 func_8023D380_de(void *arg0);
    char *object = arg0;
    char *out = arg1;
    s32 count;
    s32 active;
    s32 result;
    s32 next;
    s32 maximum;
    s32 flags;

    func_8023EBD4_de(out);
    if (first.x == second.x && first.y == second.y && first.z == second.z) {
        return 0;
    }

    D_800CB418_de += 1;
    maximum = D_800CB41C_de;
    next = D_800CB418_de;
    if (next < maximum) {
        next = maximum;
    }
    D_800CB41C_de = next;

    ((struct ActorMotion *)(out))->actor = object;
    if (object != 0) {
        s32 value = 0;
        if (*(u8 *)object == 1) {
            flags = ((struct LevelActor *)(object))->flags;
            flags &= 0x300000;
            value = flags != 0;
        }
        ((struct ActorMotion *)(out))->actorFlags = value;
    } else {
        ((struct ActorMotion *)(out))->actorFlags = 0;
    }

    ((struct ActorMotion *)(out))->start = first;
    ((struct ActorMotion *)(out))->end = second;
    ((struct ActorMotion *)(out))->grounded = 0;
    ((struct ActorMotion *)(out))->candidate = 0;
    ((struct ActorMotion *)(out))->candidateIndex = 0;
    ((struct ActorMotion *)(out))->orientationActive = 0;
    ((struct ActorMotion *)(out))->iteration = 0;
    ((struct ActorMotion *)(out))->surface = arg4;
    ((struct ActorMotion *)(out))->queryFlags = 0;
    ((struct ActorMotion *)(out))->horizontalTicks = 0;
    ((struct ActorMotion *)(out))->verticalTicks = 0;
    func_8023E838_de(out);

    active = 1;
    count = 0;
    do {
        if (func_8023D158_de(out) != 0) {
            func_8023E45C_de(out);
            count += 1;
            result = func_8023D380_de(out);
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->interpolated;
            ((struct ActorMotion *)(out))->end = ((struct ActorMotion *)(out))->position;
            ((struct ActorMotion *)(out))->orientation = ((struct ActorMotion *)(out))->projectedOrientation;
            active -= 1;
        } else {
            result = 0;
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->end;
            active -= 1;
        }
    } while (result != 0 && active != 0);
    return count;
}

#if defined(VERSION_US)
char rodata_unresolved_80244D44[12] =
    "CTER_JUGGERN";
#endif
