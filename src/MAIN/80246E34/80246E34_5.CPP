#include "common/unused.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80246E34.h"
#include "TYPES.H"
/* Returns an actor's aim with auto-aim applied: with no assist cone the actor's aiming orientation from
 * func_8024796C_de is returned unchanged; otherwise, of the live entities other than the actor (not flagged 1,
 * with a body at 0x174), the one whose aim point (half its height above its top) lies most nearly along the
 * aim direction from the given point, within the cone (in degrees, halved), pulls the aim toward it by an
 * angle that fades with the fourth root of how far off-axis it is. The applied correction is also written
 * to the optional assist quaternion (identity when nothing is in range). */





extern char *D_8011CA18[];

extern f32 D_80115DEC;
extern Vector4f func_8024796C_de(char *);
extern void func_80274244_de(Vector4f *, f32 *);
extern void func_80272898_de(f32 *, Vec3 *, Vec3 *);
extern f32 func_8024D284_de(char *);
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_8027207C_de(Vec3 *);
extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);

extern f32 func_802B72B0_de(f32);


extern void func_80274098_de(Vector4f *, Vector4f *, Vector4f *);




Vector4f func_80247BB4_de(char *actor, Vec3 point, Vector4f *assist, f32 cone) {
    Vec3 dir;
    Vec3 local;
    Vec3 aim;
    Vec3 axis;
    Vec3 best;
    Vec3 center;
    Vector4f base;
    Vector4f turn;
    Vector4f result;
    f32 matrix[16];
    char *entity;
    char *target;
    s32 count;
    s32 i;
    f32 bestDot;
    f32 dot;
    f32 angle;

    local.x = 0.0f;
    local.y = 0.0f;
    local.z = 1.0f;
    base = func_8024796C_de(actor);
    if (cone == 0.0f) {
        if (assist != 0) {
            assist->x = assist->y = assist->z = 0.0f;
            assist->w = 1.0f;
        }
        return base;
    }
    func_80274244_de(&base, matrix);
    func_80272898_de(matrix, &local, &aim);
    i = 0;
    target = 0;
    bestDot = func_802B6560_de(cone * 0.008726647f);
    count = D_8011CC18;
    for (; i < count; i++) {
        entity = D_8011CA18[i];
        if (entity == actor || (((LevelActor *)(entity))->flags & 1) || ((LevelActor *)(entity))->active == 0) {
            continue;
        }
        center = ((LevelActor *)(entity))->position0;
        center.y += ((LevelActor *)(entity))->eyeHeight;
        center.y += func_8024D284_de(entity) * 0.5f;
        func_80271F68_de(&dir, &center, &point);
        func_8027207C_de(&dir);
        dot = aim.x * dir.x + aim.y * dir.y + aim.z * dir.z;
        if (bestDot < dot) {
            bestDot = dot;
            best = dir;
            target = entity;
        }
    }
    if (target != 0) {
        func_80272018_de(&axis, &aim, &best);
        func_8027207C_de(&axis);
        angle = func_802745D0_de(bestDot);
        angle *= func_802B72B0_de(func_802B72B0_de(1.0f - angle / (cone * 0.008726647f)));
        angle *= 0.5f;
        D_80115DEC = func_802B7130_de(angle);
        turn.x = axis.x * D_80115DEC;
        turn.y = axis.y * D_80115DEC;
        turn.z = axis.z * D_80115DEC;
        turn.w = func_802B6560_de(angle);
        func_80274098_de(&result, &base, &turn);
        if (assist != 0) {
            *assist = turn;
        }
        return result;
    }
    if (assist != 0) {
        assist->x = assist->y = assist->z = 0.0f;
        assist->w = 1.0f;
    }
    return base;
}
