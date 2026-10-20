#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"

extern void func_802B00D4_de(ALEventQueue *, void *, s32);




void alSndpStop(ObjRecAt40V2 *arg0) {
    s32 new_var;
    Buf16 sp10;

    new_var = arg0->field40;
    sp10.count = 1;
    sp10.value = new_var + (arg0->field3C * 0x30);
    func_802B00D4_de(&arg0->events, &sp10, 0);
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802B2ED8);
#endif
