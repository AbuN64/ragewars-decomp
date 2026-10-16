#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024BA6C.h"
#include "TYPES.H"
/* Applies a blast from a source to a body when an owner is given: the strength comes from the falloff table
 * D_800D06C0 indexed by the source's remaining charges, times 0.5 and 0.3 and the kind (-2 for kind 5);
 * the body's reversed velocity is placed in its offset transform, an impulse at the source position is
 * built by func_80272D00_de and applied through func_8026F620_de, the velocity is restored onto the body, and
 * the source spends a charge when its owner matches. */








extern void func_8027302C(f32 *, Body_func_8024C6E8_de *);
extern void func_80271F9C_de(Vec3 *, Vec3 *, f32);
extern void func_80273448_de(void *, f32, f32, f32);
extern void func_80272D00_de(f32 *, f32, f32, f32, f32);
extern void func_8026F620_de(Body_func_8024C6E8_de *, f32 *, f32 *);

void func_8024C6E8_de(s32 unused, SourceRecAt18 *source, Body_func_8024C6E8_de *body, s32 owner, s32 kind) {
    Vec3 velocity;
    Vec3 position;
    f32 impulse[16];
    f32 transform[16];
    f32 strength;
    f32 reverse;
    f32 multiplier;

    if (owner == 0) {
        return;
    }
    velocity.x = body->velocity.x;
    velocity.y = body->velocity.y;
    velocity.z = body->velocity.z;
    position = source->position;
    strength = D_800D06C0[25 - source->charges] * 0.5f;
    strength *= 0.3f;
    if (kind == 5) {
        strength *= -2.0f;
    } else {
        strength *= kind;
    }
    func_8027302C(transform, body);
    reverse = -1.0f;
    func_80271F9C_de(&velocity, &velocity, reverse);
    func_80273448_de(transform, velocity.x, velocity.y, velocity.z);
    func_80272D00_de(impulse, strength, position.x, position.y, position.z);
    func_8026F620_de(body, transform, impulse);
    func_80271F9C_de(&velocity, &velocity, reverse);
    func_80273448_de(body, velocity.x, velocity.y, velocity.z);
    if (source->owner == owner) {
        source->charges--;
    }
}
