#include "TYPES.H"
typedef struct Vec3f { f32 x, y, z; } Vec3f;
typedef struct SharedDirectionState { char pad0[0x14]; Vec3f direction; s32 ready; } SharedDirectionState;


extern const f32 D_800C53B0_de[2];

extern const f32 D_800C53B8_de;

void func_8027207C_de(f32 *direction);

void func_8044DC60_de(SharedDirectionState *state) {
    state->direction.x = D_800C53B0_de[0];
    state->direction.y = D_800C53B0_de[1];
    state->direction.z = D_800C53B8_de;
    func_8027207C_de(&state->direction.x);
    state->ready = 1;
}
