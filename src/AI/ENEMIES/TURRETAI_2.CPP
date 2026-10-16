#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802022E0.h"
#include "TYPES.H"
typedef struct Owner Owner;

/* Moves a rider along its path segment: limits the throttle change by the segment's length over its radius, then either rocks the throttle back and forth between 0 and 1 (mode 1, flipping direction at the ends) or steers it toward a target's projected distance along the segment (mode 2), eases the change through func_80274808_de, clamps the throttle to 0..1 and places the rider at the segment's circle point for that throttle through func_80271FC8_de. */








extern f32 func_802B72B0_de(f32);


extern f32 func_80274808_de(f32, f32, f32);
extern void func_80271F68_de(Vec3 *, char *, Vec3 *);
extern void func_80272898_de(f32 *, Vec3 *, Vec3 *);
extern void func_80271FC8_de(Vec3 *, f32, Vec3 *, Vec3 *);

void func_80202FDC_de(Owner *owner, Rider *rider, s32 mode, char *target) {
    Segment *segment;
    f32 throttle;
    f32 limit;
    f32 step;
    f32 goal;
    Vec3 position;
    Vec3 offset;
    Vec3 local;
    f32 matrix[16];

    segment = (Segment *)(owner->track + 0x14);
    throttle = rider->throttle;
    if (segment->radius != 0.0f || segment->rise != 0.0f) {
        limit = segment->length / func_802B72B0_de(segment->radius * segment->radius + segment->rise * segment->rise);
    } else {
        limit = 0.0f;
    }
    switch (mode) {
    case 0:
        break;
    case 1:
        step = limit;
        if (rider->direction == mode) {
            step = -step;
        }
        rider->change = func_80274808_de(rider->change, step, 0.25f);
        throttle += rider->change;
        if (rider->direction == 0) {
            if (throttle > 1.0f) {
                rider->change = 0.0f;
                rider->direction = mode;
            }
        } else if (throttle < 0.0f) {
            rider->change = 0.0f;
            rider->direction = 0;
        }
        break;
    case 2:
        if (target != 0) {
            if (segment->angle != 0.0f) {
                func_80271F68_de(&offset, target + 8, &rider->base);
                func_802736D4_de(matrix, -segment->angle);
                func_80272898_de(matrix, &offset, &local);
                goal = local.z / segment->radius;
            } else {
                goal = 0.0f;
            }
            step = goal - throttle;
            if (step > limit) {
                step = limit;
            } else if (step < -limit) {
                step = -limit;
            }
            rider->change = func_80274808_de(rider->change, step, 0.25f);
            throttle += rider->change;
        }
        break;
    }
    if (throttle > 1.0f) {
        throttle = 1.0f;
    } else if (throttle < 0.0f) {
        throttle = 0.0f;
    }
    rider->throttle = throttle;
    position = rider->base;
    position.x += segment->radius * func_802B7130_de(segment->angle);
    position.y += segment->rise;
    position.z += segment->radius * func_802B6560_de(segment->angle);
    func_80271FC8_de(rider->frame, throttle, &rider->base, &position);
}
