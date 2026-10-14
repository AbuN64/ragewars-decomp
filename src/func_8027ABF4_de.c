/* Steers toward a distant target; otherwise accelerates, clamps speed, and updates the actor. */
#include "types.h"
#include "packed_float.h"
#include "shared/func_80214624_de_closed.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "span_1000/code_8027A0F4.h"

void func_8027ABF4_de(AccelSteeringObj *arg0) {
    AccelSteeringVec delta, direction;
    AccelSteeringVec *velocity;
    f32 accel, length, limit;

    if (arg0->target != 0 && arg0->distance > 1.0f) {
        func_8027A948_de(arg0, &arg0->target->point);
        return;
    }
    accel = func_802B2350(arg0->link->params->accel);
    if (accel != 0.0f) {
        do {
            direction = arg0->direction;
            func_80271F9C_de(&delta, &direction, accel);
            velocity = &arg0->velocity;
            func_80271F34_de(velocity, velocity, &delta);
        } while (0);
        length = func_802B72B0_de(arg0->velocity.x * arg0->velocity.x + arg0->velocity.y * arg0->velocity.y + arg0->velocity.z * arg0->velocity.z);
        limit = func_802B2350(arg0->link->params->limit);
        if (accel > 0.0f) {
            if (!(limit < length)) goto done;
        } else {
            if (!(length < limit)) goto done;
        }
        func_80271F9C_de(velocity, &direction, limit);
done:;
    }
    func_80279DD0_de(arg0, 1.0f);
}
