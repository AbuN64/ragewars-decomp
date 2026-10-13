#include "shared/level_actor.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024E130.h"
#include "types.h"






void func_8024E79C_de(void *arg0, Triple t, void *arg4, s32 *arg5, s32 arg6, s32 arg7) {
    char unused[0x150];
    Triple *output = arg4;
    *output = t;
    *arg5 = ((Actor_func_8024A7A0_de *)arg0)->model;
}
