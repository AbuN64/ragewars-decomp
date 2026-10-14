#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802636D0.h"



/** Report whether any selected status bit is set. */
int func_802643A0_de(struct ControllerProfile *object) {
    return (object->buttonState & 0x40101) != 0;
}
