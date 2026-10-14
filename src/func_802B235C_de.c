#include "span_1000/code_802B243C.h"
#include "types.h"




s32 func_802B235C_de(struct ALSeq_s *arg0) {
    u8 *p;
    s32 b;
    s32 val;

    p = arg0->curPtr;
    b = *p;
    arg0->curPtr = p + 1;
    val = b;
    if (val & 0x80) {
        val = val & 0x7F;
        do {
            p = arg0->curPtr;
            b = *p;
            arg0->curPtr = p + 1;
            val = (val << 7) + (b & 0x7F);
        } while (b & 0x80);
    }
    return val;
}
