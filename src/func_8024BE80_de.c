#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"
#include "shared/level_actor.h"

extern void **func_8024BFD4_de(void *arg0, s32 arg1);
extern char *func_8028FDB4_de(int *arg0, int arg1);
extern void func_80253754_de(void *arg0, void *arg1);






s32 func_8024BE80_de(void *arg0) {
    void **temp_s0;
    char *temp_v0;
    s32 result;

    result = -1;
    temp_s0 = func_8024BFD4_de(arg0, ((Actor_func_8024A7A0_de *)arg0)->team);
    if (temp_s0 != 0) {
        temp_v0 = func_8028FDB4_de((int *)*temp_s0, 5);
        result = ((struct ActorFrameMetadata *)temp_v0)->renderMode;
        func_80253754_de(0, temp_s0);
    }
    return result;
}
