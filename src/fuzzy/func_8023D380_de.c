#include "shared/motion_step.h"
void func_8027207C_de(Vec3 *);
void func_80271FC8_de(void *, f32, void *, void *);
void func_80271F34_de(void *, void *, void *);
void func_80271F9C_de(Vec3 *, Vec3 *, f32);
void *func_80272180_de(void *, void *, void *, f32);
void *func_80272214_de(void *, void *, void *);
Vec3 func_802723FC_de(Vec3 *, Vec3 *);
void func_8023EC54_de(void *, void *);
extern f32 D_800CB404_de, D_800C3634_de, D_800C3638_de, D_800C363C_de;
extern f32 D_800C3640_de, D_800C3644_de, D_800C3648_de;
extern f32 D_800C3670_de, D_800C3674_de, D_800C3678_de, D_800C367C_de;
extern f32 D_800C3680_de, D_800C3684_de, D_800C3688_de, D_800C368C_de;
extern f32 D_800D0640;

s32 func_8023D380_de(void *object) {
    ActorMotion *motion = object;
    Vec3 scaled, projected, response, plane, tangent, drift, orientation;
    MotionSurface *surface;
    f32 step, height, value, factor;
    s32 i, moving;
    surface = motion->surface;
    if (motion->collisionState == 0) return 0;
    func_8027207C_de(&motion->normal);
    step = D_800CB404_de * D_800C3634_de;
    motion->position = motion->end;
    motion->projectedOrientation = motion->orientation;
    if (step <= motion->distance && motion->mode != 7) {
        motion->blend -= step / motion->distance;
        func_80271FC8_de(&motion->interpolated, motion->blend, &motion->start, &motion->end);
    }
    if (motion->grounded && motion->collisionState == 3) {
        height = motion->contacts[0].y;
        for (i = 1; i < motion->contactCount; i++) {
            value = motion->contacts[i].y;
            if (!(height <= value)) value = height;
            height = value;
        }
        height -= motion->start.y;
        if (height > 0.0f && height <= D_800C3638_de) {
            motion->interpolated = motion->start;
            motion->position = motion->end;
            motion->projectedOrientation = motion->orientation;
            motion->blend = 0.0f;
            height += D_800C363C_de;
            motion->interpolated.y += height;
            motion->position.y += height;
            return 1;
        }
    }
    if (motion->mode == 6) motion->mode = motion->grounded ? 2 : 3;
    if (motion->mode == 3 && surface->response < D_800C3640_de && motion->distance < D_800C3644_de) {
        motion->mode = 1;
        if (D_800C3648_de <= motion->velocity.x * motion->velocity.x + motion->velocity.z * motion->velocity.z)
            motion->mode = 2;
    }
    if (motion->collisionState < 3 && motion->collisionState > 0) {
        if (motion->verticalTicks != 0) motion->verticalTicks--;
    } else {
        if (motion->horizontalTicks != 0) motion->horizontalTicks--;
    }
    if (motion->verticalTicks == 0) motion->velocity.y = 0.0f;
    moving = 0;
    if (motion->horizontalTicks == 0) {
        motion->velocity.z = 0.0f;
        motion->velocity.x = 0.0f;
    }
    if (motion->horizontalTicks != 0 || motion->verticalTicks != 0) moving = 1;
    switch (motion->mode) {
    case 1:
    case 8:
        if (motion->orientationActive) {
            motion->projectedOrientation.x = 0.0f;
            motion->projectedOrientation.y = 0.0f;
            motion->projectedOrientation.z = 0.0f;
        }
        if (moving) motion->position = motion->interpolated;
        return 0;
    case 2:
        if (motion->orientationActive) {
            func_80272214_de(&orientation, &motion->orientation, &motion->normal);
            motion->projectedOrientation = orientation;
            func_80271F9C_de(&motion->projectedOrientation, &motion->projectedOrientation, D_800C3678_de - motion->damping);
        }
        if (!moving) return 1;
        factor = D_800C367C_de;
        func_80271F9C_de(&scaled, &motion->velocity, factor - motion->blend);
        func_80272214_de(&response, &scaled, &motion->normal);
        break;
    case 3:
        if (motion->orientationActive) {
            func_80272180_de(&orientation, &motion->orientation, &motion->normal, surface->response);
            motion->projectedOrientation = orientation;
            func_80271F9C_de(&motion->projectedOrientation, &motion->projectedOrientation, D_800C3670_de - motion->damping);
        }
        if (!moving) return 1;
        factor = D_800C3674_de;
        func_80271F9C_de(&scaled, &motion->velocity, factor - motion->blend);
        func_80272180_de(&projected, &scaled, &motion->normal, surface->response);
        func_80271F9C_de(&projected, &projected, factor - motion->damping);
        func_80271F34_de(&motion->position, &motion->interpolated, &projected);
        return 1;
    case 4:
        if (motion->orientationActive) {
            orientation = func_802723FC_de(&motion->orientation, &motion->normal);
            motion->projectedOrientation = orientation;
        }
        if (!moving) return 1;
        func_80271F9C_de(&scaled, &motion->velocity, D_800C3680_de - motion->blend);
        response = func_802723FC_de(&scaled, &motion->normal);
        goto add_response;
    case 5:
        if (motion->orientationActive) {
            func_80272214_de(&plane, &motion->orientation, &motion->normal);
            tangent = func_802723FC_de(&motion->orientation, &motion->normal);
            func_80271FC8_de(&motion->projectedOrientation, 0.25f, &plane, &tangent);
            func_80271F9C_de(&motion->projectedOrientation, &motion->projectedOrientation, D_800C3684_de - motion->damping);
        }
        if (!moving) return 1;
        factor = D_800C3688_de;
        func_80271F9C_de(&scaled, &motion->velocity, factor - motion->blend);
        func_80272214_de(&plane, &scaled, &motion->normal);
        tangent = func_802723FC_de(&scaled, &motion->normal);
        func_80271FC8_de(&response, 0.25f, &plane, &tangent);
        break;
    case 6:
        return 0;
    case 7:
        if (motion->orientationActive) motion->projectedOrientation = motion->orientation;
        if (moving) motion->position = motion->end;
        if (motion->transitionActive) {
            if (motion->collisionState == 5) {
                motion->flags ^= 0x1000;
                func_8023EC54_de(motion, &motion->collisionState);
            }
            if (motion->collisionState == 6) {
                motion->flags ^= 0x4000;
                func_8023EC54_de(motion, &motion->collisionState);
            }
        }
        return 1;
    default:
        return 0;
    }
    func_80271F9C_de(&response, &response, factor - motion->damping);
add_response:
    func_80271F34_de(&motion->position, &motion->interpolated, &response);
    func_80271F9C_de(&drift, &motion->normal, D_800D0640 * D_800C368C_de);
    func_80271F34_de(&motion->position, &motion->position, &drift);
    return 1;
}
