#include "COMMON/PROBE.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"
#include "particle/80271B18_3.H"

/* Returns the rotation that turns an actor's aim toward a target point: a player's forward axis is its
 * aiming orientation from func_8024796C_de applied to +z, anyone else looks along +z; the target is the
 * player's lock-on at 0x1F0 or else whatever Weapons_FindNearestPlayer finds at the point, and with no target the
 * identity is returned. Otherwise the forward axis turns about its cross product with the direction from
 * the point up to three quarters of the target's height, by half the angle between them, composed with the
 * player's aiming orientation; the sine is kept in D_80115DEC. */





extern char D_80145040;

extern f32 D_80115DEC;

extern CQuatern func_8024796C_de(char *);

extern void MatrixFromQuaternion(CQuatern *, f32 *);


extern char *Weapons_FindNearestPlayer(void *, CVector3);

extern f32 Particle_GetActorHeight(char *);

extern void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);


extern void Particle_CrossVectors(CVector3 *, CVector3 *, CVector3 *);

extern void MultiplyQuaternions(CQuatern *, CQuatern *, CQuatern *);

extern void Particle_CrossVectors(CVector3 *out, CVector3 *a, CVector3 *b);


CQuatern func_8024D4AC_de(char *actor, CVector3 point) {
    CVector3 origin;
    CVector3 dir;
    CVector3 forward;
    CVector3 local;
    CVector3 axis;
    CQuatern turn;
    CQuatern aim;
    CQuatern result;
    f32 matrix[16];
    char *target;
    char *found;
    f32 angle;
    f32 scale;

    target = 0;
    if (actor != 0 && *(u8 *)actor == 1) {
        target = ((LevelActor *)(actor))->lockOn;
        aim = func_8024796C_de(actor);
        MatrixFromQuaternion(&aim, matrix);
        local.x = 0.0f;
        local.y = 0.0f;
        local.z = 1.0f;
        Particle_TransformPoint(matrix, &local, &forward);
    } else {
        forward.x = 0.0f;
        forward.y = 0.0f;
        forward.z = 1.0f;
    }
    if (target == 0) {
        found = Weapons_FindNearestPlayer(&D_80145040, point);
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
    origin.y += Particle_GetActorHeight(target) * 0.75f;
    Particle_SubtractVectors(&dir, &origin, &point);
    func_8027207C_de(&dir);
    Particle_CrossVectors(&axis, &forward, &dir);
    func_8027207C_de(&axis);
    angle = Nav_ArcCos(forward.x * dir.x + forward.y * dir.y + forward.z * dir.z) * 0.5f;
    scale = func_802B7130_de(angle);
    turn.x = axis.x * scale;
    turn.y = axis.y * scale;
    turn.z = axis.z * scale;
    D_80115DEC = scale;
    turn.w = func_802B6560_de(angle);
    if (actor != 0 && *(u8 *)actor == 1) {
        MultiplyQuaternions(&result, &aim, &turn);
    } else {
        result = turn;
    }
    return result;
}

CQuatern func_8024D728_de(InputRecAt44 *input) {
    CVector3 source;
    CVector3 up;
    CVector3 axis;
    CQuatern result;
    f32 angle;
    f32 scale;
    int state;

    state = input->state;
    if (state == 0) {
        goto default_source;
    }
    if (state < 0) {
        goto default_source;
    }
    if (state < 4) {
        goto input_source;
    }
default_source:
    source.x = 0.0f;
    source.y = D_800C3C98_de;
    source.z = 0.0f;
    goto source_ready;
input_source:
    source = input->direction;
source_ready:

    up.x = 0.0f;
    up.y = D_800C3C9C_de;
    up.z = 0.0f;
    Particle_CrossVectors(&axis, &up, &source);
    func_8027207C_de(&axis);

    angle = Nav_ArcCos((up.x * source.x) +
                          (up.y * source.y) +
                          (up.z * source.z));
    angle *= D_800C3CA0_de;
    scale = func_802B7130_de(angle);
    result.x = axis.x * scale;
    result.y = axis.y * scale;
    result.z = axis.z * scale;
    D_80115DEC = scale;
    result.w = func_802B6560_de(angle);

    return result;
}
