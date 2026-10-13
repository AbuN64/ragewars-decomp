#include "shared/gameplay_camera.h"
#include "span_1000/code_80233920.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8044ACCC.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"
/* Initializes camera transforms, viewport state, clipping records, and resource lists. */

 
void func_80238EB8_de(void *);                               /* extern */
void func_802390F4_de(void *, s32);                         /* extern */
void func_802393D8_de(void *);                            /* extern */
void func_80239C20_de(void *);                            /* extern */
void func_802727D8_de(void *);                            /* extern */
void func_80442544_de(void *);                    /* extern */


extern s32 D_800E28D0, D_800E28D4;
extern struct Shape_func_802764D4_de_2 D_80103220;






/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x10, 0x14, 0x20, 0x24], gap at: 0x18. */
void func_8044A170_de(State_func_8044A170_de *arg0) {
    f32 temp_f21;
    f32 zero;
    s16 temp_a0;
    s32 var_a1;
    Floats *temp_v0;
    Floats *temp_v0_2;
    Floats *temp_v0_3;
    Floats *temp_v0_4;
    Floats *temp_v0_5;

    func_80238EB8_de(((void *)&((Shared_func_80234FDC_S2 *)arg0)->unk24));
    func_802727D8_de(((void *)&((Shared_func_80234FDC_S2 *)arg0)->unk160));
    func_802727D8_de(((void *)&((Shared_func_80234FDC_S2 *)arg0)->unk1E0));
    zero = 0.0f;
    temp_f21 = 1.0f;
    temp_v0 = ((void *)&((Shared_func_80234FDC_S2 *)arg0)->orientation);
    temp_v0->unk8 = zero;
    temp_v0->unk4 = zero;
    arg0->unk140 = zero;
    arg0->unk14C = temp_f21;
    func_802727D8_de(((void *)&((Shared_func_80234FDC_S2 *)arg0)->unk1A0));
    arg0->unk29C = (f32) D_800E28D0;
    arg0->unk2A0 = (f32) D_800E28D4;
    arg0->unk518 = -1;
    arg0->unk2A4 = zero;
    arg0->unk2A8 = zero;
    arg0->unk520 = 0;
    arg0->unk524 = 0;
    arg0->unk521 = 0;
    arg0->unk525 = 0;
    arg0->unk522 = 0;
    arg0->unk526 = 0;
    arg0->unk523 = 0;
    arg0->unk527 = 0;
    arg0->unk51C = temp_f21;
    arg0->unk53C = 0x3E3;
    arg0->unk540 = 0x3E3;
    arg0->unk548 = 0;
    arg0->unk7C = 0;
    arg0->unkC = temp_f21;
    arg0->unk10 = temp_f21;
    arg0->unk528 = (f32) 1024.0f;
    arg0->unk52C = (f32) 1024.0f;
    arg0->unk530 = (f32) 47.5f;
    arg0->unk534 = (f32) 47.5f;
    func_802393D8_de(arg0);
    temp_v0_2 = ((void *)&((Shared_func_80234FDC_S2 *)arg0)->padA0);
    arg0->unkF4 = zero;
    arg0->unkF8 = zero;
    temp_v0_2->unk8 = zero;
    temp_v0_2->unkC = zero;
    temp_v0_2->unk10 = zero;
    temp_v0_2->unk14 = temp_f21;
    temp_v0_3 = ((void *)&((Shared_func_80234FDC_S2 *)arg0)->unkB8);
    temp_v0_3->unk4 = zero;
    temp_v0_3->unk8 = zero;
    temp_v0_3->unkC = zero;
    temp_v0_3->unk10 = zero;
    temp_v0_4 = ((void *)&((Shared_func_80234FDC_S2 *)arg0)->unkCC);
    temp_v0_4->unk4 = zero;
    temp_v0_4->unk8 = zero;
    temp_v0_4->unkC = zero;
    temp_v0_4->unk10 = zero;
    temp_v0_5 = ((void *)&((Shared_func_80234FDC_S2 *)arg0)->unkE0);
    temp_v0_5->unk4 = zero;
    temp_v0_5->unk8 = zero;
    temp_v0_5->unkC = zero;
    temp_v0_5->unk10 = zero;
    func_802390F4_de(arg0, 0);
    temp_a0 = D_800E28D0 * 2;
    for (var_a1 = 0; var_a1 < 2; var_a1++) {
        ((Racer *)arg0)->viewports[var_a1].vscale[0] = temp_a0;
        ((Racer *)arg0)->viewports[var_a1].vscale[1] = temp_a0;
        ((Racer *)arg0)->viewports[var_a1].vscale[2] = 0x3FF;
        ((Racer *)arg0)->viewports[var_a1].vscale[3] = 0;
        ((Racer *)arg0)->viewports[var_a1].vtrans[0] = temp_a0;
        ((Racer *)arg0)->viewports[var_a1].vtrans[1] = temp_a0;
        ((Racer *)arg0)->viewports[var_a1].vtrans[2] = 0;
        ((Racer *)arg0)->viewports[var_a1].vtrans[3] = 0;
    }
    func_80442544_de(((void *)&((Shared_func_80234FDC_S2 *)arg0)->messageList));
    func_802727D8_de(((void *)&((Shared_func_80234FDC_S2 *)arg0)->unkE54));
    func_802727D8_de(((void *)&((Shared_func_80234FDC_S2 *)arg0)->unkE94));
    arg0->unk544 = 0;
    arg0->unk120 = 0;
    arg0->unk124 = 0x32;
    arg0->unk126 = 0;
    D_80103220.field_4 = 0;
    func_80255CA0_de(&((Shared_func_80234FDC_S2 *)arg0)->objects, 0, 4);
    func_80239C20_de(arg0);
}
