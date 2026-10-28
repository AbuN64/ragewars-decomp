#include "COMMON/UNUSED.H"
#include "COMMON/MOTION_STEP.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "ANIM/RAY180.H"
#include "TYPES.H"
#include "COMMON/OBJ.H"
#include "COMMON/LONE/D_80103FCC.H"
#include "COMMON/ITEMRECAT20V1.H"

extern f32 Gobjinst_GetActorRadius(void *);
extern f32 Gobjinst_GetActorHeight(void *);
extern f32 InstHdr_GetActorBaseOffset(void *);
extern f32 InstHdr_GetActorReach(void *);
extern s32 Unicol_SweepActorMotion(void *, CVector3, CVector3, struct CCollisionInfo2_t *, f32, f32, f32, f32);

/* 80241940.CPP */
/* Builds the eight world-space corners of an object's collision box: the extents come from the shape at
 * 0x18 + 0x14 (half width and depth, or the radius for a cylinder of kind 1), grown by the optional
 * attachment's sizes from Gobjinst_GetActorRadius, Gobjinst_GetActorHeight and func_8024E420_de; the box is turned by the object's
 * rest matrix from 0x2A4 and its heading 0x6C composed with its orientation at 0x5C, moved to its position
 * and, for shapes flagged 1, its bottom corners are dropped to the ground height of the given floor. */


extern void BuildPitchMatrix(f32 *, f32);
extern void MultiplyQuaternions(CQuatern *, CQuatern *, CQuatern *);
extern void MatrixFromQuaternion(CQuatern *, f32 *);
extern void Graphu64_MultiplyAffineMatrices(f32 *, f32 *, f32 *);
extern void TranslateMatrix(f32 *, f32, f32, f32);
extern void Graphu64_TransformPoints(f32 *, CVector3 *, CVector3 *, s32);

void CPlatformCollision_BuildWorldBounds(char *obj, CVector3 *corners, char *floor, s32 attachment) {
    f32 matrix[16];
    f32 rest[16];
    f32 turn[16];
    CQuatern yaw;
    CQuatern orient;
    ShapeRecAt18V1 *shape;
    char *anim;
    f32 grow;
    f32 lift;
    f32 extra;
    f32 extentX;
    f32 extentZ;
    f32 height;
    f32 minX;
    f32 maxX;
    f32 minZ;
    f32 maxZ;
    f32 top;
    f32 bottom;
    f32 diff;
    f32 sine;
    f32 angle;

    anim = obj + 0x170;
    shape = (ShapeRecAt18V1 *)((u8 *)((LevelActor *)obj)->definition + 0x14);
    if (attachment != 0) {
        grow = Gobjinst_GetActorRadius(attachment);
        lift = Gobjinst_GetActorHeight(attachment);
        extra = InstHdr_GetActorBaseOffset(attachment);
    } else {
        lift = 0.0f;
        grow = 0.0f;
        extra = 0.0f;
    }
    diff = extra - lift;
    if (shape->kind != 1) {
        extentX = shape->halfWidth * 0.5f + grow * 0.5f;
        extentZ = shape->halfDepth * 0.5f + grow * 0.5f;
        height = shape->height + extra;
    } else {
        extentZ = shape->radius + grow;
        height = shape->height + extra;
        extentX = extentZ;
    }
    bottom = shape->center.y + diff;
    minX = shape->center.x - extentX;
    top = shape->center.y + height;
    maxZ = shape->center.z + extentZ;
    maxX = shape->center.x + extentX;
    minZ = shape->center.z - extentZ;
    corners[0].x = minX;
    corners[0].y = top;
    corners[0].z = maxZ;
    corners[1].x = maxX;
    corners[1].y = top;
    corners[1].z = maxZ;
    corners[2].x = maxX;
    corners[2].y = top;
    corners[2].z = minZ;
    corners[3].x = minX;
    corners[3].y = top;
    corners[3].z = minZ;
    corners[4].x = minX;
    corners[4].y = bottom;
    corners[4].z = maxZ;
    corners[5].x = maxX;
    corners[5].y = bottom;
    corners[5].z = maxZ;
    corners[6].x = maxX;
    corners[6].y = bottom;
    corners[6].z = minZ;
    corners[7].x = minX;
    corners[7].y = bottom;
    corners[7].z = minZ;
    BuildPitchMatrix(rest, ((Dest *)anim)->restPitch);
    sine = Gu_Sinf(((LevelActor *)obj)->yaw * 0.5f);
    yaw.x = 0.0f;
    yaw.y = sine;
    yaw.z = 0.0f;
    angle = ((LevelActor *)obj)->yaw * 0.5f;
    D_80115DEC = sine;
    yaw.w = Math_Cosf(angle);
    MultiplyQuaternions(&orient, &yaw, &((LevelActor *)obj)->rotation);
    MatrixFromQuaternion(&orient, turn);
    Graphu64_MultiplyAffineMatrices(matrix, rest, turn);
    TranslateMatrix(matrix, ((LevelActor *)obj)->position0.x, ((LevelActor *)obj)->position0.y, ((LevelActor *)obj)->position0.z);
    Graphu64_TransformPoints(matrix, corners, corners, 8);
    if (shape->flags & 1) {
        bottom = ((ActorMotion *)floor)->end.y - ((ActorMotion *)floor)->height;
        lift = bottom;
        corners[4].y = bottom;
        corners[5].y = bottom;
        corners[6].y = bottom;
        corners[7].y = bottom;
    }
}

/* 80241940_2.CPP */




extern f32 CCollision_GetSurfaceHeight(SurfaceHit *, f32, f32);

struct CCollisionInfo2_t;

extern void Graphu64_AddVec3(CVector3 *, CVector3 *, CVector3 *);

extern char D_80100338;

extern void Plane_BuildBoxFace5(void *, RayCornerBounds *);
extern void Plane_BuildBoxFace4(void *, RayCornerBounds *);
extern void Plane_BuildBoxFace3(void *, RayCornerBounds *);
extern void Plane_BuildBoxFace2(void *, RayCornerBounds *);
extern void Plane_BuildBoxFace1(void *, RayCornerBounds *);
extern void Plane_BuildBoxFace0(void *, RayCornerBounds *);
extern s32 CCollision_TestSegmentDisk(void *, void *, void *, f32, s32);
extern s32 CCollision_TestSegmentPolygon(void *, void *, s32);
extern s32 CCollision_TestRayCylinder(void *, void *, f32, f32, f32, s32, void *, s32);
void CPlatformCollision_PushActorFromBox(ActorCPlatformCollisionPushActorFromBox *actor, OwnerRecAt18 *owner, RayCornerBounds *bounds, SurfaceHit *query, CollisionProbe *input) {
    u8 collision[0x108];
    CVector3 next;
    f32 hit_y;
    f32 extent0;
    f32 extent1;
    f32 extent2;
    f32 extent3;
    void *saved_collision;
    s32 hit;

    if (actor->movement.y > 0.0f) {
        query->word0 = 3;
        Plane_BuildBoxFace0(query, bounds);
        if (CCollision_TestSegmentPolygon(actor, query, 0)) {
            saved_collision = D_80103FCC;
            D_80103FCC = collision;
            hit_y = CCollision_GetSurfaceHeight(query, input->x, input->z);
            input->owner = owner;
            extent0 = InstHdr_GetActorReach(input);
            extent1 = Gobjinst_GetActorRadius(input);
            extent2 = Gobjinst_GetActorHeight(input);
            extent3 = InstHdr_GetActorBaseOffset(input);
            next.x = input->x;
            next.y = hit_y + D_800C3758_de[0];
            next.z = input->z;
            if (Unicol_SweepActorMotion(input, *(CVector3 *)&input->x, next, &D_801000F0,
                              extent0, extent1, extent2, extent3)) {
                actor->saved_query = *query;
                actor->flags |= 8;
                input->flags38 |= 0x10;
            } else {
                input->y = next.y;
                if (input->floor < 0.0f) input->floor = 0.0f;
                {
                    s32 flags = actor->flags;
                    actor->flags = flags | 0x20;
                    if (input->kind == 1 && (input->flags100 & 0x300000))
                        actor->flags = flags | 0x60;
                }
                input->flags38 = (input->flags38 & ~3) | 2;
            }
            D_80103FCC = saved_collision;
        }
    }
    if (actor->movement.y < 0.0f) {
        query->word0 = 2;
        Plane_BuildBoxFace1(query, bounds);
        if (CCollision_TestSegmentPolygon(actor, query, 1)) {
            actor->flags |= 8;
            input->flags38 |= 0x10;
        }
    }
    if (actor->movement.x != 0.0f || actor->movement.z != 0.0f) {
        query->word0 = 3;
        Plane_BuildBoxFace2(query, bounds);
        hit = CCollision_TestSegmentPolygon(actor, query, 1);
        Plane_BuildBoxFace3(query, bounds);
        hit |= CCollision_TestSegmentPolygon(actor, query, 1);
        Plane_BuildBoxFace4(query, bounds);
        hit |= CCollision_TestSegmentPolygon(actor, query, 1);
        Plane_BuildBoxFace5(query, bounds);
        hit |= CCollision_TestSegmentPolygon(actor, query, 1);
        if (hit) {
            actor->flags |= 8;
            Graphu64_AddVec3(&((LevelActor *)input)->position1,
                          &((LevelActor *)input)->position1,
                          &actor->movement);
        }
    }
}

void CPlatformCollision_PushActorFromCylinder(ActorCPlatformCollisionPushActorFromBox *actor, OwnerRecAt18 *owner, RayCornerBounds *bounds, SurfaceHit *query, CollisionProbe *input) {
    u8 collision[0x108];
    CVector3 next;
    f32 hit_y;
    f32 extent0;
    f32 extent1;
    f32 extent2;
    f32 extent3;
    f32 height;
    void *saved_collision;
    void *entry;
    void *owner_data;

    owner_data = &((LevelActor *)owner)->position0;
    entry = owner->entries + 0x14;
    height = ((ShapeRecAt18V1 *)entry)->radius + Gobjinst_GetActorRadius(input);
    if (actor->movement.y > 0.0f) {
        query->word0 = 3;
        Plane_BuildBoxFace0(query, bounds);
        if (CCollision_TestSegmentDisk(actor, query, owner_data, height, 0)) {
            saved_collision = D_80103FCC;
            D_80103FCC = collision;
            hit_y = CCollision_GetSurfaceHeight(query, input->x, input->z);
            input->owner = owner;
            extent0 = InstHdr_GetActorReach(input);
            extent1 = Gobjinst_GetActorRadius(input);
            extent2 = Gobjinst_GetActorHeight(input);
            extent3 = InstHdr_GetActorBaseOffset(input);
            next.x = input->x;
            next.y = hit_y + D_800C3758_de[1];
            next.z = input->z;
            if (Unicol_SweepActorMotion(input, *(CVector3 *)&input->x, next, &D_801000F0,
                              extent0, extent1, extent2, extent3)) {
                actor->saved_query = *query;
                actor->flags |= 8;
                input->flags38 |= 0x10;
            } else {
                input->y = next.y;
                if (input->floor < 0.0f) input->floor = 0.0f;
                {
                    s32 flags = actor->flags;
                    actor->flags = flags | 0x20;
                    if (input->kind == 1 && (input->flags100 & 0x300000))
                        actor->flags = flags | 0x60;
                }
                input->flags38 = (input->flags38 & ~3) | 2;
            }
            D_80103FCC = saved_collision;
        }
    }
    if (actor->movement.y < 0.0f) {
        query->word0 = 2;
        Plane_BuildBoxFace1(query, bounds);
        if (CCollision_TestSegmentDisk(actor, query, owner_data, height, 1)) {
            actor->flags |= 8;
            input->flags38 |= 0x10;
        }
    }
    if (actor->movement.x != 0.0f || actor->movement.z != 0.0f) {
        query->word0 = 3;
        if (CCollision_TestRayCylinder(actor, owner_data, height,
                          bounds->corners[0].y, bounds->corners[4].y,
                          1, query, 1)) {
            actor->flags |= 8;
            Graphu64_AddVec3(&((LevelActor *)input)->position1,
                          &((LevelActor *)input)->position1,
                          &actor->movement);
        }
    }
}

void CPlatformCollision_TraceShape(ActorCPlatformCollisionTraceShape *actor, OwnerRecAt18 *owner) {
    QueryRecAt58 query;
    RayCornerBounds bounds;
    EntryRecAt8V5 *entry;

    entry = &((RayEntryBlock *)owner->entries)->entry;
    if ((actor->field40 != &D_80100338) && (((Shape *)actor->field40)->enabled != 0)) {
        f32 value;
        s32 *word;
        void *owner_data;

        CPlatformCollision_BuildWorldBounds(owner, &bounds, actor, actor->owner);
        query.word4 = 0;
        query.word8 = 2;
        query.wordC = 0;
        query.word10 = 0;
        query.owner = owner;
        query.index = -1;
        switch (entry->kind) {
        case 1:
            word = &query.word0;
            owner_data = &((LevelActor *)owner)->position0;
            value = ((RayEntryBlock *)owner->entries)->entry.value + actor->fieldC;
            if ((actor->field5C != *(f32 *)&query.word4) ||
                (actor->field64 != *(f32 *)&query.word4)) {
                *word = 3;
                CCollision_TestRayCylinder(actor, owner_data, value, bounds.corners[0].y,
                              bounds.corners[4].y, 1, word, 1);
            }
            if (actor->field60 > 0.0f) {
                *word = 2;
                Plane_BuildBoxFace1(word, &bounds);
                CCollision_TestSegmentDisk(actor, word, owner_data, value, 1);
            }
            if (actor->field60 < 0.0f) {
                *word = 9;
                Plane_BuildBoxFace0(word, &bounds);
                CCollision_TestSegmentDisk(actor, word, owner_data, value, 1);
                return;
            }
            break;
        case 2:
        {
            f32 movement;
            f32 zero;

            word = &query.word0;
            movement = actor->field60;
            zero = *(f32 *)&query.word4;
            if (zero < movement) {
                *word = 2;
                Plane_BuildBoxFace1(word, &bounds);
                CCollision_TestSegmentPolygon(actor, word, 1);
            }
            if ((actor->field5C != zero) || (actor->field64 != zero)) {
                *word = 3;
                Plane_BuildBoxFace2(word, &bounds);
                CCollision_TestSegmentPolygon(actor, word, 1);
                Plane_BuildBoxFace3(word, &bounds);
                CCollision_TestSegmentPolygon(actor, word, 1);
                Plane_BuildBoxFace4(word, &bounds);
                CCollision_TestSegmentPolygon(actor, word, 1);
                Plane_BuildBoxFace5(word, &bounds);
                CCollision_TestSegmentPolygon(actor, word, 1);
            }
            if (actor->field60 < 0.0f) {
                *word = 9;
                Plane_BuildBoxFace0(word, &bounds);
                CCollision_TestSegmentPolygon(actor, word, 1);
            }
            break;
        }
        }
    }
}

/* 80241940_3.CPP */
extern void Graphu64_SubtractVectors(Triple *, Triple *, Triple *);







void CPlatformCollision_ProcessRiderMotion(ActorCPlatformCollisionProcessRiderMotion *actor, SourceBarrelUpdateActorController *input) {
    Triple saved_previous;
    Triple saved_position;
    SurfaceHit query;
    RayCornerBounds bounds;
    OwnerRecAt18 *owner;
    EntryRecAt4V3 *entry;

    owner = actor->owner;
    entry = (EntryRecAt4V3 *)(owner->entries + 0x14);
    if (*actor->flags & 0x40000) {
        saved_previous = actor->previous;
        saved_position = actor->position;
        actor->previous = input->position;
        Graphu64_SubtractVectors(&actor->position, &input->position, &actor->delta);
        query.word4 = 0;
        query.word8 = 1;
        query.wordC = 0;
        query.word10 = 0;
        query.input = input;
        query.index = -1;
        CPlatformCollision_BuildWorldBounds(owner, &bounds, actor, input);
        switch (entry->kind) {
        case 1:
            CPlatformCollision_PushActorFromCylinder(actor, owner, &bounds, &query, input);
            break;
        case 2:
            CPlatformCollision_PushActorFromBox(actor, owner, &bounds, &query, input);
            break;
        }
        actor->previous = saved_previous;
        actor->position = saved_position;
    }
}

struct CCollisionInfo2_t;

void CPlatformCollision_LiftActorToSurface(ActorRecAtB0 *actor, void *owner, InputCPlatformCollisionLiftActorToSurface *input, SurfaceHit *query) {
    u8 collision[0x108];
    CVector3 next;
    f32 hit_y;
    f32 extent0;
    f32 extent1;
    f32 extent2;
    f32 extent3;
    void *saved_collision;

    saved_collision = D_80103FCC;
    D_80103FCC = collision;
    hit_y = CCollision_GetSurfaceHeight(query, input->x, input->z);
    input->owner = owner;
    extent0 = InstHdr_GetActorReach(input);
    extent1 = Gobjinst_GetActorRadius(input);
    extent2 = Gobjinst_GetActorHeight(input);
    extent3 = InstHdr_GetActorBaseOffset(input);
    next.x = input->x;
    next.y = hit_y + D_800C3760_de;
    next.z = input->z;
    if (Unicol_SweepActorMotion(input, *(CVector3 *)&input->x, next, &D_801000F0,
                      extent0, extent1, extent2, extent3)) {
        actor->saved_query = *query;
        actor->flags |= 8;
        input->flags38 |= 0x10;
    } else {
        input->y = next.y;
        if (input->floor < 0.0f) input->floor = 0.0f;
        {
            s32 flags = actor->flags;
            actor->flags = flags | 0x20;
            if (input->kind == 1 && (input->flags100 & 0x300000))
                actor->flags = flags | 0x60;
        }
        input->flags38 = (input->flags38 & ~3) | 2;
    }
    D_80103FCC = saved_collision;
}
