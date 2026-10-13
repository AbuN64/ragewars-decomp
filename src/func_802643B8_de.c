#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802636D0.h"



int func_802643B8_de(void *arg0) {
    ControllerProfile *profile = arg0;
    int flag = profile->buttonState & 0x10808;
    return flag != 0;
}
