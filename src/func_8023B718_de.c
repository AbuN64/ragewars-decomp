#include "span_C76B0/data.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8023A284.h"
#include "types.h"
/* Updates a rotor: while the control mask bit is held its throttle at 0x208 rises by the descriptor rate up
 * to D_800C86E0, otherwise it falls to zero (returning 1 once idle); the value phase advances, the two wrap
 * angles at 0x1C and 0x20 advance and wrap at D_800C86E8, and the speed at 0x210 becomes the descriptor
 * base plus trim, plus the boost when requested and the host is not stalled, or else the host's speed
 * scaled by the descriptor (flag 1) or the fallback speed (flag 2). Returns 0 while active. */










extern f32 D_800D2988;





s32 func_8023B718_de(Rotor *rotor, s32 mask, f32 fallback, s32 boosting, f32 boost, Host *host) {
    DescriptorRecAt29 *descriptor;
    f32 throttle;
    f32 value;
    f32 angle;
    f32 speed;
    f32 lowered;
    f32 zero;
    f32 wrap;

    descriptor = rotor->descriptor;
    if (rotor->mask & mask) {
        throttle = rotor->throttle + descriptor->throttleRate * D_800D2988;
        if (D_800C86E0 < throttle) {
            throttle = D_800C86E0;
        }
        rotor->throttle = throttle;
    } else {
        zero = 0.0f;
        value = rotor->throttle;
        if (value == zero) {
            return 1;
        }
        lowered = value - descriptor->throttleRate * D_800D2988;
        if (lowered < zero) {
            lowered = zero;
        }
        rotor->throttle = lowered;
    }
    rotor->phase += D_800D2988 * descriptor->phaseRate * rotor->phaseScale;
    value = D_800D2988 * D_800CD744_de * descriptor->spinRate;
    angle = rotor->angleA + value * D_800C35F4_de;
    wrap = D_800C86E8;
    rotor->angleA = angle;
    if (wrap < angle) {
        rotor->angleA = angle - wrap;
    }
    angle = rotor->angleB + value * D_800C35FC_de;
    rotor->angleB = angle;
    if (wrap < angle) {
        rotor->angleB = angle - wrap;
    }
    speed = descriptor->baseSpeed + rotor->trim;
    if (boosting != 0 && host->stalled == 0) {
        speed += boost;
    } else if (descriptor->flags & 1) {
        speed += host->speed * descriptor->hostScale;
    } else if (descriptor->flags & 2) {
        speed += fallback;
    }
    rotor->speed = speed;
    return 0;
}
