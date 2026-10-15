#include "sdk/libgultra.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B2EF8.h"
#include "types.h"





extern void func_802B00D4_de(ALEventQueue *, void *, s32);




void alSndpStop(ObjRecAt40V2 *arg0) {
    s32 new_var;
    Buf16 sp10;

    new_var = arg0->field40;
    sp10.count = 1;
    sp10.value = new_var + (arg0->field3C * 0x30);
    func_802B00D4_de(&arg0->events, &sp10, 0);
}
