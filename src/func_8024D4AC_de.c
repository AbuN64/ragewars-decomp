#include "common/unused.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024D018.h"
#include "types.h"
/* Returns the rotation that turns an actor's aim toward a target point: a player's forward axis is its
 * aiming orientation from func_8024796C_de applied to +z, anyone else looks along +z; the target is the
 * player's lock-on at 0x1F0 or else whatever func_8022A480_de finds at the point, and with no target the
 * identity is returned. Otherwise the forward axis turns about its cross product with the direction from
 * the point up to three quarters of the target's height, by half the angle between them, composed with the
 * player's aiming orientation; the sine is kept in D_80115DEC. */





extern char D_80145040;
extern f32 D_80115DEC;
extern Vector4f func_8024796C_de(char *);
extern void func_80274244_de(Vector4f *, f32 *);
extern void func_80272898_de(f32 *, Vec3 *, Vec3 *);
extern char *func_8022A480_de(void *, Vec3);
extern f32 func_8024D284_de(char *);
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_8027207C_de(Vec3 *);
extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);



extern void func_80274098_de(Vector4f *, Vector4f *, Vector4f *);






Vector4f func_8024D4AC_de(char *actor, Vec3 point) {
    Vec3 origin;
    Vec3 dir;
    Vec3 forward;
    Vec3 local;
    Vec3 axis;
    Vector4f turn;
    Vector4f aim;
    Vector4f result;
    f32 matrix[16];
    char *target;
    char *found;
    f32 angle;
    f32 scale;

    target = 0;
    if (actor != 0 && *(u8 *)actor == 1) {
        target = ((Actor_func_8024A7A0_de *)(actor))->lockOn;
        aim = func_8024796C_de(actor);
        func_80274244_de(&aim, matrix);
        local.x = 0.0f;
        local.y = 0.0f;
        local.z = 1.0f;
        func_80272898_de(matrix, &local, &forward);
    } else {
        forward.x = 0.0f;
        forward.y = 0.0f;
        forward.z = 1.0f;
    }
    if (target == 0) {
        found = func_8022A480_de(&D_80145040, point);
        if (found != 0) {
            target = found;
        }
        if (target == 0) {
            result.x = result.y = result.z = 0.0f;
            result.w = 1.0f;
            return result;
        }
    }
    origin = ((Actor_func_80214310_de *)(target))->position;
    origin.y += ((Actor_func_80214310_de *)(target))->eye;
    origin.y += func_8024D284_de(target) * 0.75f;
    func_80271F68_de(&dir, &origin, &point);
    func_8027207C_de(&dir);
    func_80272018_de(&axis, &forward, &dir);
    func_8027207C_de(&axis);
    angle = func_802745D0_de(forward.x * dir.x + forward.y * dir.y + forward.z * dir.z) * 0.5f;
    scale = func_802B7130_de(angle);
    turn.x = axis.x * scale;
    turn.y = axis.y * scale;
    turn.z = axis.z * scale;
    D_80115DEC = scale;
    turn.w = func_802B6560_de(angle);
    if (actor != 0 && *(u8 *)actor == 1) {
        func_80274098_de(&result, &aim, &turn);
    } else {
        result = turn;
    }
    return result;
}
