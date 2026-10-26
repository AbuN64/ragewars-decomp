#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/CALLBACK.H"

void Smos_SetAxisThreshold(int arg0) {
    D_8014D080->limit = arg0;
}

/** Return the word at offset 0x14 of the current global object. */
unsigned int Smos_GetControlRepeatLimit(void) {
    return D_8014D080->limit;
}
