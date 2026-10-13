#include "shared/level_actor.h"
#include "shared/func_80214624_de_closed.h"
#include "span_1000/code_802609CC.h"
#include "span_1000/code_8027302C.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"





extern void func_8025E5B0_de(s32 *, s32, f32, f32 *);
extern void func_80272898_de(void *arg0, void *arg1, void *arg2);






void func_8024C34C_de(void *arg0, s32 *arg1) {
    Scratch scratch;
    f32 zero;

    zero = 0.0f;
    func_8025E5B0_de(arg1, 0, zero, scratch.first);
    func_8025E5B0_de(arg1, 0, ((AnimTrack_func_8026193C_de *)arg1)->time, scratch.second);
    scratch.in[0] = scratch.second[0] - scratch.first[0];
    scratch.in[1] = zero;
    scratch.in[2] = scratch.second[1] - scratch.first[1];
    func_802736D4_de(scratch.matrix, ((Actor_func_8024A7A0_de *)arg0)->yaw);
    func_80272898_de(scratch.matrix, scratch.in, scratch.out);
    scratch.position.x = ((Actor_func_8024A7A0_de *)arg0)->position0.x +
                          (scratch.out[0] * ((Actor_func_8024A7A0_de *)arg0)->scale.x);
    scratch.position.y = ((Actor_func_8024A7A0_de *)arg0)->position0.y;
    scratch.position.z = ((Actor_func_8024A7A0_de *)arg0)->position0.z +
                          (scratch.out[2] * ((Actor_func_8024A7A0_de *)arg0)->scale.z);
    func_8024E79C_de(arg0, scratch.position, &((Actor_func_8024A7A0_de *)arg0)->position0,
                  &((Actor_func_8024A7A0_de *)arg0)->model, 0, 0);
}
