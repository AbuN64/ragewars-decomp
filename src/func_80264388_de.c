#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802636D0.h"



/** Report whether any of the selected object flag bytes are set. */
int func_80264388_de(struct ControllerProfile *object) {
    return (object->buttonState & 0x20202) != 0;
}
