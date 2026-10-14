#include "span_1000/code_8024D018.h"
#include "span_C76B0/data.h"
extern s32 D_801041F0;
extern s32 func_802462E8_de(Actor_u1 *, Vec3, char **);

/* Aim toward a point; when obstructed, try progressively wider left/right
 * directions and choose the first clear probe. */
f32 func_80215868_de(Actor_u1 *actor, Vec3 point, s32 target, f32 distance) {
    Vec3 probe;
    char *hit;
    f32 dx = point.x - actor->position.x;
    f32 dz = point.z - actor->position.z;
    f32 length = func_802B72B0_de(dx * dx + dz * dz);
    f32 heading, cosine, sine, dot, offset, angle, bias;
    s32 step, side;
    if (length == 0.0f) {
        heading = 0.0f;
    } else {
        cosine = func_802B7130_de(actor->yaw);
        sine = -func_802B6560_de(actor->yaw);
        dot = (dx * -cosine + dz * sine) / length;
        if (dot < D_800C2184_de) dot = D_800C2184_de;
        else if (D_800C2180_de < dot) dot = D_800C2180_de;
        heading = func_802745D0_de(dot);
        if (!(dx * sine + dz * cosine > 0.0f)) heading = -heading;
    }
    if ((actor->flags & 0x200) && func_802462E8_de(actor, point, &hit)) {
        if (target != 0 && D_801041F0 == target) return heading;
        probe.y = actor->position.y;
        for (step = 1; step < 6; step++) {
            offset = (f32)step * D_800C2188_de;
            for (side = 0; side < 2; side++) {
                if (side != (((s32)actor % 744) & 1)) {
                    angle = heading + offset;
                    bias = D_800C2190_de;
                } else {
                    angle = heading - offset;
                    bias = D_800C2194;
                }
                cosine = func_802B7130_de(actor->yaw + D_800C218C + angle);
                probe.x = actor->position.x + cosine * (distance * func_8024D398_de(actor));
                sine = func_802B6560_de(actor->yaw + D_800C218C + angle);
                probe.z = actor->position.z + sine * (distance * func_8024D398_de(actor));
                if (!func_802462E8_de(actor, probe, 0)) {
                    angle += bias;
                    func_80274020_de(&angle);
                    return angle;
                }
            }
        }
    }
    return heading;
}
