#include "span_1000/code_802B243C.h"
#include "types.h"

extern s32 func_802B235C_de(void *arg0);




s32 func_802B22F4_de(ALSeq_s *arg0, s32 *arg1) {
    u8 *field8;

    field8 = arg0->curPtr;
    if (!(field8 < (arg0->base + arg0->len))) {
        return 0;
    }
    *arg1 = func_802B235C_de(arg0);
    arg0->curPtr = field8;
    return 1;
}
