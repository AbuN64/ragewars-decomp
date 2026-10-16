#include "sdk/libgultra.h"
#include "span_1000/code_802B0388.h"
#include "span_1000/code_802B243C.h"
#include "TYPES.H"

void func_802B1E50_de(ALSeqPlayer *arg0, f32 arg1) {
    ALSeq_s *temp_v0;

    temp_v0 = arg0->target;
    if (temp_v0 != 0) {
        arg0->uspt = (s32)(arg1 * temp_v0->qnpt);
        return;
    }
    arg0->uspt = 0x1E8;
}
