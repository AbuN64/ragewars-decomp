#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/CALLBACK.H"

void func_80299B3C_de(int arg0) {
    D_8014D080->limit = arg0;
}

/** Return the word at offset 0x14 of the current global object. */
unsigned int func_80299B4C_de(void) {
    return D_8014D080->limit;
}
