#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80233920.h"
/* Clears effect state and initializes its scalar, vector and resource defaults. */
#include "types.h"


extern s32 D_800CD8D0[];
extern f32 D_800C3518_de[];
void func_80238EB8_de(State44 *arg0) {
    f32 temp_f0;
    Vec3 *temp_v0;

    arg0->unk_20.i = 0;
    temp_f0 = arg0->unk_20.f;
    arg0->unk_0 = 1;
    temp_v0 = &arg0->v;
    arg0->unk_4 = 0;
    arg0->unk_8 = 0;
    arg0->unk_C = 0;
    arg0->unk_10 = 0;
    arg0->unk_14 = 0;
    arg0->unk_18 = 0;
    arg0->unk_1C = 0;
    temp_v0->z = temp_f0;
    temp_v0->y = temp_f0;
    arg0->v.x = temp_f0;
    arg0->unk_30 = 1.0f;
    arg0->unk_34 = 0;
    arg0->unk_38 = temp_f0;
    arg0->unk_3C = 0.174532949924469f;
    arg0->unk_40 = (s32) *D_800CD8D0;
}
