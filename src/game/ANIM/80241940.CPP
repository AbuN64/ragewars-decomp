#include "COMMON/UNUSED.H"
#include "COMMON/MOTION_STEP.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "ANIM/RAY180.H"
#include "TYPES.H"
#include "COMMON/OBJ.H"

/* Builds the eight world-space corners of an object's collision box: the extents come from the shape at
 * 0x18 + 0x14 (half width and depth, or the radius for a cylinder of kind 1), grown by the optional
 * attachment's sizes from Particle_GetActorRadius, Particle_GetActorHeight and func_8024E420_de; the box is turned by the object's
 * rest matrix from 0x2A4 and its heading 0x6C composed with its orientation at 0x5C, moved to its position
 * and, for shapes flagged 1, its bottom corners are dropped to the ground height of the given floor. */







extern f32 Particle_GetActorRadius(s32);
extern f32 Particle_GetActorHeight(s32);
extern f32 Sound_GetActorBaseOffset(s32);


extern void func_80273648_de(f32 *, f32);
extern void MultiplyQuaternions(CQuatern *, CQuatern *, CQuatern *);
extern void MatrixFromQuaternion(CQuatern *, f32 *);
extern void Rsp_MultiplyAffineMatrices(f32 *, f32 *, f32 *);
extern void TranslateMatrix(f32 *, f32, f32, f32);
extern void func_80272944_de(f32 *, CVector3 *, CVector3 *, s32);








void func_80241950_de(char *obj, CVector3 *corners, char *floor, s32 attachment) {
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
        grow = Particle_GetActorRadius(attachment);
        lift = Particle_GetActorHeight(attachment);
        extra = Sound_GetActorBaseOffset(attachment);
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
    func_80273648_de(rest, ((Dest *)anim)->restPitch);
    sine = func_802B7130_de(((LevelActor *)obj)->yaw * 0.5f);
    yaw.x = 0.0f;
    yaw.y = sine;
    yaw.z = 0.0f;
    angle = ((LevelActor *)obj)->yaw * 0.5f;
    D_80115DEC = sine;
    yaw.w = func_802B6560_de(angle);
    MultiplyQuaternions(&orient, &yaw, &((LevelActor *)obj)->rotation);
    MatrixFromQuaternion(&orient, turn);
    Rsp_MultiplyAffineMatrices(matrix, rest, turn);
    TranslateMatrix(matrix, ((LevelActor *)obj)->position0.x, ((LevelActor *)obj)->position0.y, ((LevelActor *)obj)->position0.z);
    func_80272944_de(matrix, corners, corners, 8);
    if (shape->flags & 1) {
        bottom = ((ActorMotion *)floor)->end.y - ((ActorMotion *)floor)->height;
        lift = bottom;
        corners[4].y = bottom;
        corners[5].y = bottom;
        corners[6].y = bottom;
        corners[7].y = bottom;
    }
}
