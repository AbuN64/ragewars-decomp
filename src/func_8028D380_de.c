#include "span_1000/code_802508E0.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028CCB8.h"
#include "types.h"

extern s32 func_8028FE28_de(s32 *arg0, s32 arg1, s32 arg2);
extern s32 func_80254284_de(s32 arg0, s32 *arg1, s32 arg2, void *arg3);
extern void **func_80254408_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);
extern void func_80253838_de(void *arg0, void *arg1);

extern s32 D_800C5110_de;
extern char D_800C5280_de;






void func_8028D380_de(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    s32 sp20;
    s32 tempv0;
    s32 temps2;
    CachedResource *node;
    s32 count;

    tempv0 = func_8028FE28_de(((Shared_World *)arg0)->resourceDirectory, ((Shared_World *)arg0)->resourceBank, arg1);
    temps2 = func_80254284_de(0, &sp20, tempv0, &D_800C5110_de);
    node = func_80254408_de(0, sp20, 8, tempv0, (s32)arg0, 0, &D_800C5280_de + 4);
    count = node->unk04;
    if (arg3 < count) {
        count = arg3;
    }
    func_802BD3A0_de(arg2, node->data, count);
    func_80253838_de(0, (s32)node);
    if (((Shared_World *)arg0)->level != arg1) {
        func_80253838_de(0, temps2);
    }
}
