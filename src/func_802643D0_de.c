#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802636D0.h"



int func_802643D0_de(void *arg0) {
    ControllerProfile *profile = arg0;
    int flag = profile->buttonState & 0x80404;
    return flag != 0;
}
