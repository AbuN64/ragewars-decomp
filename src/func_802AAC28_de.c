#include "shared/world.h"
#include "span_1000/code_802A8A94.h"
#include "types.h"



extern s32 D_800CD764_de;
extern GfxRec *D_80110634;



extern func_802ABC18_S1 *D_8011BDC0;


extern s32 func_8028BEAC_de(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_802AA1AC_de(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6);
extern void func_80253754_de(s32 arg0, s32 arg1);

s32 func_802AAC28_de(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6) {
    s32 temp_v0;

    if ((u32)(D_800E28A4 - ((u32)((s32)D_80110634 - D_8011BDC0->unk114) >> 3)) < 0x3E8
        || D_800CD764_de == 0
        || (temp_v0 = func_8028BEAC_de(&D_8011FE88, arg0, 0, 1), temp_v0 == 0)) {
        return 0;
    }
    func_802AA1AC_de(temp_v0, arg1, arg2, arg3, arg4, arg5, arg6);
    func_80253754_de(0, temp_v0);
    return 1;
}
