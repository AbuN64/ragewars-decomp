#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802636D0.h"
#include "types.h"




/** Fetch-and-clear: return the old slot value, then zero it. */
s32 func_80264580_de(s32 arg0) {
    s32 old;

    if (func_8026475C_de(arg0) == 0) {
        return 0;
    }
    old = D_8010BBF0[arg0];
    D_8010BBF0[arg0] = 0;
    return old;
}
