#include "common/types_06e4f7ef1f9e.h"
#include "shared/level_actor.h"
#include "span_1000/code_8023330C.h"
#include "span_1000/code_8027302C.h"

void func_8023378C_de(void *arg0, void *arg1) {
    func_80203DF0_S1 *event = arg1;
    if (event->unk4 == 6) {
        Actor_func_8024A7A0_de *actor = event->unk8;
        func_802733B4_de(arg0, 0.0f, actor->pitch, 0.0f);
    }
}
