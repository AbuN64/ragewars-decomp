#include "shared/legacy_collision_actor.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024E914.h"
#include "types.h"
#include "math_helpers.h"
/* Places an actor's ground shadow: the shadow size is the smaller of half the vertical offset from
 * func_8024E2FC_de and that minus a tenth of the actor's height above its ground height at 0x40, vanishing
 * when negative; a transform is built from the actor's orientation, scaled flat by the shadow size,
 * positioned at the ground under the actor, stored as the actor's per-frame matrix and submitted through
 * func_8026992C_de. */
extern s32 D_800D297C;
extern f32 func_8024E2FC_de(void *);
extern void func_8024D870_de(f32 *, void *);
extern void func_8027254C_de(Vec3 *, f32);
extern void func_80274244_de(f32 *, f32 *);
extern void func_8027347C_de(f32 *, f32, f32, f32);
extern void func_80273448_de(f32 *, f32, f32, f32);
extern void func_8027027C_de(f32 *, void *);
extern void func_8026992C_de(void *, s32, s32);
void func_8024EF28_de(void *actor) {
    f32 matrix[16];
    Vec3 position;
    f32 rotation[4];
    f32 ground;
    f32 height;
    f32 size;
    ground = ((Shared_Func80243A80Actor *)actor)->groundY;
    height = ((Shared_Func80243A80Actor *)actor)->y - ground;
    if (!(RW_MIN_LT(func_8024E2FC_de(actor) * 0.5f, func_8024E2FC_de(actor) * 0.5f - height * 0.1f) < 0.0f)) {
        size = RW_MIN_LT(func_8024E2FC_de(actor) * 0.5f, func_8024E2FC_de(actor) * 0.5f - height * 0.1f);
    } else {
        size = 0.0f;
    }
    func_8024D870_de(rotation, actor);
    position.x = ((Shared_Func80243A80Actor *)actor)->x;
    position.z = ((Shared_Func80243A80Actor *)actor)->z;
    position.y = ground;
    func_8027254C_de(&position, 20000.0f);
    func_80274244_de(rotation, matrix);
    func_8027347C_de(matrix, size, 1.0f, size);
    func_80273448_de(matrix, position.x, position.y, position.z);
    func_8027027C_de(matrix, (char *)actor + ((D_800D297C << 6) + 0xE8));
    func_8026992C_de((char *)actor + ((D_800D297C << 6) + 0xE8), 1, 0x96);
}
