#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B0388.h"



/** Clamp (record - arg1) at a lower bound of 0x3E8 for negative results. */
int func_802B1888_de(void *arg0, int arg1) {
    struct ALVoiceState_s *voice = arg0;
    int v = voice->envEndTime - arg1;
    if (v >= 0) {
        return v;
    }
    return 0x3E8;
}
