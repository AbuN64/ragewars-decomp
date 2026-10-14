#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80231F5C.h"
#include "types.h"





void func_80232DF4_de(void *arg0) {
    s32 temp_s0;
    temp_s0 = (((struct ActorRecAt1D8V1 *) ((s8 *) arg0))->link);
    func_8044A07C_de(temp_s0);
    if ((((struct ObjRecAt650 *) ((s8 *) temp_s0))->unk650) == 0x27) {
        func_802227F4_de((void *) temp_s0, (void *) temp_s0, 2);
    }
}
