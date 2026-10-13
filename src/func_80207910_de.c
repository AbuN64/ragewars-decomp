#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80206258.h"
#include "types.h"

extern void func_80273760_de(void *arg0, f32 arg1);
extern void func_802738C0_de(void *arg0, f32 arg1);
extern void func_80273A98_de(void *arg0, f32 arg1);
extern void func_8027302C(float *arg0, float *arg1);
extern void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);
extern s32 func_8027254C_de(f32 *arg0, f32 arg1);
extern void func_80273448_de(f32 *, f32, f32, f32);
extern void func_80273D6C_de(void *);

void func_80207910_de(void *object, void *state) {
    Player *arg0 = object;
    ActorMotionState *arg1 = state;
    f32 sp10[16];
    f32 *temp_s1;

    func_80273760_de(sp10, arg1->pitch);
    func_802738C0_de(sp10, arg1->yaw);
    func_80273A98_de(sp10, arg0->heading);
    temp_s1 = arg0->matrix;
    func_8027302C(temp_s1, sp10);
    func_8027347C_de(temp_s1, arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_8027254C_de(&arg0->pos.x, 20000.0f);
    func_80273448_de(temp_s1, arg0->pos.x, arg0->pos.y, arg0->pos.z);
    func_80273D6C_de(temp_s1);
}
