#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80268160.h"
#include "types.h"











extern s32 D_8010EC90;


extern f32 D_800C4460_de;
extern void func_8028CE94_de(void *, void *, s32, Triple, f32, f32);

void func_802681A8_de(func_8024E8F0_S1 *arg0, Context_func_802681A8_de *arg1, s32 arg2, Triple arg3, Params_func_802681A8_de arg6) {
    void *resource;

    if ((arg0->unk0 == 1) && (arg0->unk100 & 0x300000)) {
        resource = arg1->inner->resource + 0x140;
        arg3.x = 0;
        arg3.y = 0;
        arg3.z = 0;
    } else {
        resource = &D_8010EC90;
    }

    func_8028CE94_de(&D_8011FE88, resource, arg6.value, arg3,
                  arg6.angle * *(&D_800C4458_de + 1), arg6.scale * D_800C4460_de);
}
