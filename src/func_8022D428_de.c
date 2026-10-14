#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8022C894.h"
#include "types.h"



extern void func_80274870_de(f32 *value, f32 target, f32 rate);
extern void func_80449870_de(void *);




void func_8022D428_de(void *arg0) {
    Actor_func_8022D290_de *actor = arg0;
    if (actor->unk_0x0850 == 0) {
        if ((actor->unk_0x0664 & 0x8000) == 0) {
            func_80274870_de(&actor->unk_0x072C, 1.308997f, 0.25f);
        }
        if (actor->unk_0x0658 > D_800C2DB8_de) {
            func_80449870_de(arg0);
        }
    }
}
