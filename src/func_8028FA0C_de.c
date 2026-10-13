#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028DF6C.h"
#include "types.h"






s32 func_8028FA0C_de(void *arg0, void *arg1) {
    if ((((s32)((struct OSScTask_s *)arg1)->state)) & 3) {
        return 0;
    }
    if ((((struct OSScTask_s *)arg1)->list.type) != 1) {
        return 1;
    }
    if (((((s32)((struct OSScTask_s *)arg1)->flags)) & 0x60) != 0x60) {
        return 1;
    }
    func_802BA8C0_de(((s32)((struct OSScTask_s *)arg1)->framebuffer));
    return 1;
}
