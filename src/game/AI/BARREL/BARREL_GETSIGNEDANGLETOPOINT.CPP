#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/MATH_HELPERS.H"

/* 80213ED4_18.CPP */
/* Returns the signed angle between an actor's facing and the direction to a point on the ground plane:
   normalises the offset from the actor at 0x8 to the point, takes its dot product with the facing
   built from the sine and cosine of the yaw at 0x6C, clamps it to -1..1, converts it through the arc
   cosine GraphU64_ArcCos and negates it when the point lies on the other side, or returns zero when the
   point is at the actor. Scheduler lever, disclosed: the sine read sits in a do-while(0) block. */
extern f32 Math_Sqrtf(f32);

f32 Barrel_GetSignedAngleToPoint(void *actor, CVector3 point) {
    f32 dx;
    f32 dz;
    f32 dist;
    f32 s;
    f32 c;
    f32 dot;
    f32 angle;
    dx = point.x - ((struct Actor_func_80214DD4_de *)actor)->pos.x;
    dz = point.z - ((struct Actor_func_80214DD4_de *)actor)->pos.z;
    dist = Math_Sqrtf(dx * dx + dz * dz);
    if (dist == 0.0f) {
        return 0.0f;
    }
    do {
        s = Math_Sinf(((struct Actor_func_80214DD4_de *)actor)->heading);
    } while (0);
    c = -Math_Cosf(((struct Actor_func_80214DD4_de *)actor)->heading);
    dot = (dx * -s + dz * c) / dist;
    dot = ((RW_MIN(dot, 1.0f))<((-1.0f))?((-1.0f)):(RW_MIN(dot, 1.0f)));
    angle = GraphU64_ArcCos(dot);
    if (dx * c + dz * s > 0.0f) {
        return angle;
    }
    return -angle;
}

/* 80213ED4_23.CPP */
#if defined(VERSION_US)
const float D_800C21D8_de[] = {
    450.0f, 600.0f, 450.0f, 600.0f,
};
#endif
