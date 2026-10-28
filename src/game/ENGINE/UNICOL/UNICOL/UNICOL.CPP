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

/* 80243A80.CPP */
void CCollision_StoreContactResult(void *);

void CCollision_ProjectSegmentOntoSurface(void *, void *);

void CCollision_ResetContactNormal(void *);

void CCollision_ClearResultFlags(void *);

void CCollision_UpdateSurfaceResponseFlags(ActorMotion *, MotionContactResult *);

void CCollision_UpdateMaterialFlags(ActorMotion *, MotionContactResult *);

void CCollision_UpdateModelSurfaceFlags(void *, u16 *);

f32 CCollision_GetContactYaw(f32 *);

f32 InstHdr_GetActorReach(void *);

extern void GraphU64_EaseValueToward(f32 *value, f32 target, f32 rate);

f32 GraphU64_GetTrianglePlaneHeight(void *, f32, f32);

f32 Region_GetPolygonHeight(void *, f32, f32);

void * Scene_ResolveFloorPolygon(void *, CVector3 *);

s32 CCollision_IntegrateGravityAndDrag();

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

extern void CCollision_SetUniformSweepExtent(void *arg0, f32 arg1);

s32 Unicol_MoveActorWithCollision(Func80243A80Actor *actor, Func80243A80Vec3 pos, u32 *motionSettings) {
    s32 func_8023D380_de();
    Func80243A80Frame frame;
    f32 headingCosine;
    f32 surfaceCeilingHeight;
    f32 high;
    f32 count;
    f32 actorReach;
    f32 headingSine;
    f32 groundSeparation;
    s32 collisionFound;
    s32 flags;
    s32 motionContinuation;
    s32 repeatFloorProbe;
    s32 remainingIterations;
    s32 collisionCount;
    s32 var_v0;
    s32 groundFollowEnabled;
    s32 peakMoveCount;
    s32 horizontalResponseTicks;
    s32 verticalResponseTicks;
    u16 *surface;
    u32 preProbeFlags;
    u32 settingsFlags;
    u32 floorProbeBaseFlags;
    u32 attachmentFlags;
    u32 loopMask;
    f32 dropDistance;
    Func80243A80Actor *attachedActor;
    s32 collisionOne;
    f32 hitY;
    f32 actorY;
    f32 savedY;

    CCollision_ClearResultFlags(&frame.sp18);
    __builtin_memcpy(&D_80103FCC->x, &actor->room, 12);
    actor->flags = (u32) (actor->flags & ~0x18);
    frame.sp18 = actor;
    motionContinuation = 0;
    if (actor->type == 1) {
        motionContinuation = (u32) motionContinuation < (actor->status & 0x300000);
    }
    frame.sp1C = motionContinuation;
    actorReach = InstHdr_GetActorReach(actor);
    count = GameObject_GetActorRadius(actor);
    high = GameObject_GetActorHeight(actor);
    CCollision_SetSweepRange(&frame.sp18, actorReach, count, high, InstHdr_GetActorBaseOffset(actor));
    *(Func80243A80Vec3 *)&frame.sp5C = *(Func80243A80Vec3 *)&actor->x;
    __builtin_memcpy(&frame.sp68, &pos, 12);
    __builtin_memcpy(&frame.sp8C, &actor->room, 12);
    frame.spC4 = actor->collision;
    groundFollowEnabled = 0;
    if ((*motionSettings & 0x200) && (actor->velY <= 0.0f)) {
        groundFollowEnabled = 1;
    }
    frame.sp3C = groundFollowEnabled;
    frame.sp38 = ((u32) *motionSettings >> 1) & 1;
    frame.sp40 = (((u32) actor->flags >> 2) ^ 1) & 1;
    frame.sp44 = 1;
    frame.sp54 = actor->flags;
    frame.sp34 = frame.sp28 * D_800C3790_de;
    frame.sp50 = ((u32) *motionSettings >> 0x13) & 1;
    frame.sp58 = motionSettings;
    CCollision_IntegrateGravityAndDrag(&frame.sp18);
    if ((frame.sp3C != 0) && (frame.sp54 & 7) && !(frame.sp54 & 0x2000)) {
        __builtin_memcpy(&frame.sp210, &actor->contactX, 12);
        frame.sp1E0 = actor->x;
        frame.sp1E4 = actor->groundY;
        frame.sp1E8 = actor->z;
        CCollision_ProjectSegmentOntoSurface(&frame.sp18, &frame.sp1C8);
    }
    if ((frame.sp1C != 0) || (frame.sp5C != frame.sp68) || (frame.sp60 != frame.sp6C) || (var_v0 = 0, (frame.sp64 != frame.sp70))) {
        peakMoveCount = ++D_800CB410_de;
        if (peakMoveCount < D_800CB414_de) {
            peakMoveCount = D_800CB414_de;
        }
        D_800CB414_de = peakMoveCount;
        if ((motionSettings != &D_80100338) && (motionSettings != &D_801001D0) && (motionSettings != &D_80103FD0) && (motionSettings != &D_80100170)) {
            actor->attached = 0;
            frame.sp54 &= ~0x7B;
        }
        frame.sp54 &= ~0x80;
        if (actor->type == 1) {
            frame.sp2C8 = actor->angle;
        } else {
            frame.sp2C8 = 0.0f;
        }
        headingSine = Math_Sinf(frame.sp2C8);
        headingCosine = Math_Cosf(frame.sp2C8);
        frame.sp54 &= ~0x2000;
        settingsFlags = *motionSettings;
        if (settingsFlags & 4) {
            remainingIterations = 1;
        } else if (settingsFlags & 0x800) {
            remainingIterations = 3;
        } else {
            if (actor->type == 1) remainingIterations = 4;
            else remainingIterations = 1;
        }
        horizontalResponseTicks = remainingIterations;
        if (remainingIterations >= 3) {
            horizontalResponseTicks = 2;
        }
        frame.sp48 = horizontalResponseTicks;
        verticalResponseTicks = remainingIterations + 1;
        if (verticalResponseTicks >= 4) {
            verticalResponseTicks = 3;
        }
        frame.sp4C = verticalResponseTicks;
        CCollision_ResetContactNormal(&frame.sp18);
        collisionCount = 0;
        loopMask = 0x80000;
        collisionOne = 1;
loop_34:
        if (*motionSettings & loopMask) {
            frame.spC4 = Scene_ResolveFloorPolygon(frame.spC4, &frame.sp68);
        }
        collisionFound = CCollision_TraceActorMotion((s8 *) &frame.sp18);
        motionContinuation = 0;
        if (collisionFound != 0) {
            if (frame.spC8 != collisionOne) {
                if (frame.spC8 == 4) {
                    if (((frame.sp110 * -headingSine) + (frame.sp118 * -headingCosine)) < D_800C3794_de) {
                        frame.sp54 |= 0x80;
                        CCollision_UpdateSurfaceResponseFlags(&frame.sp18, &frame.spC8);
                    }
                } else {
                    goto block_42;
                }
            } else {
                frame.sp38 = 0;
block_42:
                frame.sp54 &= ~0x80;
            }
            CCollision_StoreContactResult(&frame.sp18);
            collisionCount += 1;
            motionContinuation = func_8023D380_de(&frame.sp18);
            __builtin_memcpy(&frame.sp5C, &frame.sp198, 12);
            __builtin_memcpy(&frame.sp68, &frame.sp1B0, 12);
            __builtin_memcpy(&frame.sp8C, &frame.sp1BC, 12);
        } else {
            __builtin_memcpy(&frame.sp5C, &frame.sp68, 12);
        }
        remainingIterations -= 1;
        if (motionContinuation == 0) {
        } else if (remainingIterations != 0) {
            goto loop_34;
        }
        __builtin_memcpy(&actor->x, &frame.sp5C, 12);
        __builtin_memcpy(&actor->room, &frame.sp8C, 12);
        frame.sp54 &= ~4;
        if (*motionSettings & 0x40000) {
            __builtin_memcpy(&frame.sp68, &frame.sp5C, 12);
            frame.sp44 = 0;
            frame.sp48 = 0;
            frame.sp4C = 0;
            savedY = frame.sp6C;
            dropDistance = D_800C3798_de;
            frame.sp6C = savedY - dropDistance;
            __builtin_memcpy(&frame.sp2A8, &D_801000F0, sizeof(D_801000F0));
            frame.sp58 = &frame.sp2A8;
            floorProbeBaseFlags = frame.sp2A8 & 0xFFE7FFF7;
            frame.sp2A8 = floorProbeBaseFlags;
            frame.sp2A8 = floorProbeBaseFlags | (*motionSettings & 0x180008);
            frame.sp50 = 0;
            CCollision_ResetContactNormal(&frame.sp18);
            actor->contactX = 0.0f;
            actor->contactZ = 0.0f;
            actor->contactBits = D_800C379C_de;
            actor->groundY = (f32) (actor->y - dropDistance);
loop_49:
            if (CCollision_TraceActorMotion((s8 *) &frame.sp18) != 0) {
                if (frame.spD0 == 7) {
                    frame.sp3C = 0;
                }
                func_8023D380_de(&frame.sp18);
                repeatFloorProbe = 0;
                actor->groundY = frame.sp19C;
                __builtin_memcpy(&actor->contactX, &frame.sp110, 12);
                actorY = actor->y;
                hitY = frame.sp19C;
                groundSeparation = actorY - hitY;
                if ((frame.sp3C != 0) && (groundSeparation < D_800C37A0_de)) {
                    frame.sp3C = 0;
                    actor->velY = 0.0f;
                    groundSeparation = actor->velY;
                    actor->y = hitY;
                }
                if ((actor->velY <= 0.0f) && (groundSeparation < D_800C37A4_de)) {
                    if (frame.spC8 == 5) {
                        frame.sp54 |= 0x2004;
                        CCollision_UpdateMaterialFlags(&frame.sp18, &frame.spC8);
                        repeatFloorProbe = 1;
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
                        attachmentFlags = (frame.sp54 & ~3) | 2;
                        goto attach_done;
no_attach:
                        attachmentFlags = frame.sp54 | 4;
attach_done:
                        frame.sp54 = attachmentFlags;
                    }
                }
                if (repeatFloorProbe != 0) {
                    __builtin_memcpy(&frame.sp5C, &frame.sp198, 12);
                    goto block_71;
                }
            } else {
                repeatFloorProbe = 0;
block_71:
                if (repeatFloorProbe == 0) {

                } else {
                    goto loop_49;
                }
            }
        }
        preProbeFlags = frame.sp54;
        frame.sp54 = preProbeFlags & ~0x100;
        if ((frame.sp38 != 0) || (preProbeFlags & 0x80)) {
            __builtin_memcpy(&frame.sp5C, &actor->x, 12);
            __builtin_memcpy(&frame.sp68, &actor->x, 12);
            frame.sp44 = 0;
            frame.sp48 = 0;
            frame.sp4C = 0;
            frame.sp58 = &D_801000F0.flags;
            frame.sp68 -= headingSine * D_800C37A8_de;
            frame.sp70 -= headingCosine * D_800C37A8_de;
            CCollision_ResetContactNormal(&frame.sp18);
            if ((CCollision_TraceActorMotion((s8 *) &frame.sp18) != 0) && (frame.spC8 == 4)) {
                if (frame.sp38 != 0) {
                    func_8023D380_de(&frame.sp18);
                    actor->x = frame.sp198;
                    actor->z = frame.sp1A0;
                    frame.sp54 |= 0x100;
                    CCollision_UpdateSurfaceResponseFlags(&frame.sp18, &frame.spC8);
                    if (actor->type == 1) {
                        GraphU64_EaseValueToward(&frame.sp2C8, frame.sp2C8 - Graphu64_GetWrappedDifference(frame.sp2C8, CCollision_GetContactYaw((f32 *) &frame.spC8)), 0.9f);
                        actor->angle = frame.sp2C8;
                    }
                }
            } else {
                frame.sp54 &= ~0x80;
            }
        }
        if (*motionSettings & 0x80000) {
            surface = Scene_ResolveFloorPolygon(frame.spC4, &actor->x);
            frame.sp54 &= ~0x5000;
            if ((surface != 0) && ((((Func80243A80Collision *)surface)->flags & 0x41) == 0x41) && (Region_GetPolygonHeight(surface, actor->x, actor->z) <= actor->y)) {
                surfaceCeilingHeight = GraphU64_GetTrianglePlaneHeight(surface, actor->x, actor->z);
                if (actor->y <= surfaceCeilingHeight) {
                    frame.sp54 |= 0x4000;
                }
                surfaceCeilingHeight += frame.sp34;
                if (actor->y <= surfaceCeilingHeight) {
                    frame.sp54 |= 0x1000;
                }
                CCollision_UpdateModelSurfaceFlags(&frame.sp18, surface);
            }
            actor->collision = surface;
        }
        actor->flags = frame.sp54;
        return collisionCount;
    }
    return 0;
}

s32 CCollision_SweepPoint(char *actorStorage, CVector3 startPosition, CVector3 desired, s32 motionSettings) {
    extern s32 func_8023D380_de(void *actorStorage);
    Work80244494 work;
    VectorPair vectors;
    char *object = actorStorage;
    char *out;
    s32 count;
    s32 active;
    s32 result;
    s32 next;
    s32 maximum;
    s32 flags;

    CCollision_SetUniformSweepExtent(work.data, 0.0f);
    out = work.data;
    vectors.first = startPosition;
    vectors.second = desired;
    CCollision_ClearResultFlags(out);
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
    ((struct ActorMotion *)(out))->surface = (CCollisionInfo2_t *)motionSettings;
    ((struct ActorMotion *)(out))->queryFlags = 0;
    ((struct ActorMotion *)(out))->horizontalTicks = 0;
    ((struct ActorMotion *)(out))->verticalTicks = 0;
    CCollision_ResetContactNormal(out);

    active = 1;
    count = 0;
    do {
        if (CCollision_TraceActorMotion(out) != 0) {
            CCollision_StoreContactResult(out);
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

s32 CCollision_SweepUniformExtent(char *actorStorage, CVector3 startPosition, CVector3 endPosition, CCollisionInfo2_t *sweepSurfaceSettings,
                   f32 sweepExtent) {
    extern s32 func_8023D380_de(void *actorStorage);
    Work80244494 work;
    VectorPair vectors;
    char *object = actorStorage;
    char *out;
    s32 count;
    s32 active;
    s32 result;
    s32 next;
    s32 maximum;
    s32 flags;

    CCollision_SetUniformSweepExtent(work.data, sweepExtent);
    out = work.data;
    vectors.first = startPosition;
    vectors.second = endPosition;
    CCollision_ClearResultFlags(out);
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
    ((struct ActorMotion *)(out))->surface = sweepSurfaceSettings;
    ((struct ActorMotion *)(out))->queryFlags = 0;
    ((struct ActorMotion *)(out))->horizontalTicks = 0;
    ((struct ActorMotion *)(out))->verticalTicks = 0;
    CCollision_ResetContactNormal(out);

    active = 1;
    count = 0;
    do {
        if (CCollision_TraceActorMotion(out) != 0) {
            CCollision_StoreContactResult(out);
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

s32 Unicol_SweepActorMotion(char *actorStorage, CVector3 startPosition, CVector3 endPosition, CCollisionInfo2_t *motionSettings,
                  CVector3 motionExtents, f32 baseOffset) {
    extern s32 func_8023D380_de(void *actorStorage);
    Work80244494 work;
    VectorPair vectors;
    char *object = actorStorage;
    char *out;
    s32 count;
    s32 active;
    s32 result;
    s32 next;
    s32 maximum;
    s32 flags;

    CCollision_SetSweepRange(work.data, motionExtents.x, motionExtents.y, motionExtents.z, baseOffset);
    out = work.data;
    vectors.first = startPosition;
    vectors.second = endPosition;
    CCollision_ClearResultFlags(out);
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
    ((struct ActorMotion *)(out))->surface = motionSettings;
    ((struct ActorMotion *)(out))->queryFlags = 0;
    ((struct ActorMotion *)(out))->horizontalTicks = 0;
    ((struct ActorMotion *)(out))->verticalTicks = 0;
    CCollision_ResetContactNormal(out);

    active = 1;
    count = 0;
    do {
        if (CCollision_TraceActorMotion(out) != 0) {
            CCollision_StoreContactResult(out);
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

s32 CCollision_SweepWithWorkBuffer(char *actorStorage, char *motionWork, CVector3 first, CVector3 second,
                   s32 motionSurface) {
    extern s32 func_8023D380_de(void *actorStorage);
    char *object = actorStorage;
    char *out = motionWork;
    s32 count;
    s32 active;
    s32 result;
    s32 next;
    s32 maximum;
    s32 flags;

    CCollision_ClearResultFlags(out);
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
    ((struct ActorMotion *)(out))->surface = motionSurface;
    ((struct ActorMotion *)(out))->queryFlags = 0;
    ((struct ActorMotion *)(out))->horizontalTicks = 0;
    ((struct ActorMotion *)(out))->verticalTicks = 0;
    CCollision_ResetContactNormal(out);

    active = 1;
    count = 0;
    do {
        if (CCollision_TraceActorMotion(out) != 0) {
            CCollision_StoreContactResult(out);
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

/* 800C8710_13.CPP */
const unsigned int D_auto_src_rw_pool_80243A90_C9480_us_rev1[7] = {
    0xBEE66666, 0xBF350481, 0x434CCCCC, 0x3F800000, 0x424CCCCC, 0x3F83126F, 0x424CCCCC,
};

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C3A9C[1] = {
    0x4F000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C3A5C[1] = {
    0x26730008,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C37AC[1] = {
    0xBF000000,
};
#endif
