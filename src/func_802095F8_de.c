#include "types.h"
#include "span_1000/code_80208000.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "span_C76B0/data.h"

extern void func_8022B144_de(void *, f32 *);

void func_802095F8_de(Brain *object) {
    void *memory = object;
    PitchBrain *brain = memory;
    Vec3 origin, delta;
    f32 ownHeight, targetHeight, correction, vertical, horizontal, zero;
    PitchPlayer *target;
    if (brain->target) {
        origin = brain->player->position;
        func_8022B144_de(brain->player, &delta.x);
        ownHeight = delta.y - brain->player->position.y;
        target = brain->target->player;
        if (target->transformed) {
            func_8022B144_de(target, &delta.x);
            targetHeight = delta.y - target->position.y;
        } else targetHeight = target->model->height - target->position.y;
        targetHeight *= D_800C1C74_de;
        if (D_801468F4 && target->profile->scaled) targetHeight *= D_800C1C78_de;
        delta = brain->targetPosition;
        delta.x -= origin.x;
        delta.y -= origin.y;
        delta.z -= origin.z;
        correction = targetHeight - ownHeight;
        brain->distance = func_802B72B0_de(delta.x*delta.x + delta.y*delta.y + delta.z*delta.z);
        vertical = delta.y;
        delta.y = 0.0f;
        vertical += correction;
        zero = delta.y;
        horizontal = func_802B72B0_de(delta.x*delta.x + delta.z*delta.z);
        if (horizontal == zero) {
            if (vertical < zero) brain->angle = D_800C1C7C_de;
            else brain->angle = D_800C1C80_de;
        } else brain->angle = func_8029C044_de(vertical, horizontal) * D_800C1C84_de;
    } else brain->angle = 0.0f;
    brain->previousAngle = brain->angle;
}
