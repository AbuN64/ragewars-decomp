#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80208000.h"
#include "types.h"

/* Steers a computer player toward a point: measures the heading error to the point through func_80216F44_de plus an offset, wrapped to -pi..pi, and when it exceeds the turn rate in degrees sets the player's steering at 0x69C to full lock beyond 60 degrees or to a half, quarter, eighth or tenth of lock beyond 30, 10 and 4 degrees, in the error's direction; then passes the brain's speed sum (by the player's gear at 0x594) in radians and the turn rate to func_80209910_de and returns the heading error. */






extern f32 func_80216F44_de(Player_func_80209308_de *, Vec3);
extern void func_80209910_de(Brain_func_80209308_de *, f32, s32);

f32 func_80209308_de(Brain_func_80209308_de *brain, Vec3 *target, f32 rate, f32 offset) {
    f32 angle;
    f32 direction;
    f32 limit;
    f32 scale;

    angle = func_80216F44_de(brain->player, *target) + offset;
    if (angle > 3.141593f) {
        angle -= 6.283186f;
    } else if (angle < -3.141593f) {
        angle += 6.283186f;
    }
    direction = -1.0f;
    if (angle > 0.0f) {
        direction = 1.0f;
    }
    limit = rate * 0.017453294f;
    if (angle < 0.0f ? limit < -angle : limit < angle) {
        if (angle < 0.0f ? 1.0471977f < -angle : 1.0471977f < angle) {
            brain->player->steer = direction;
        } else {
            if (angle < 0.0f ? 0.52359885f < -angle : 0.52359885f < angle) {
                scale = 0.5f;
            } else if (angle < 0.0f ? 0.17453295f < -angle : 0.17453295f < angle) {
                scale = 0.25f;
            } else if (angle < 0.0f ? 0.06981318f < -angle : 0.06981318f < angle) {
                scale = 0.125f;
            } else {
                scale = 0.1f;
            }
            brain->player->steer = direction * scale;
        }
    }
    func_80209910_de(brain, (brain->player->gear == 2 ? brain->speed[1] + brain->speed[3] : brain->speed[0] + brain->speed[2]) * 0.017453294f, rate);
    return angle;
}
