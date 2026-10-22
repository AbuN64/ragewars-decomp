#include "ANIM/RAY180.H"
#include "TYPES.H"
#include "ANIM/MEASUREDRECAT8V3.H"
#include "ANIM/MEASUREDRECAT8V4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OUTPUT.H"
#include "stddef.h"
#include "COMMON/BALLISTICPARAMS.H"
#include "ANIM/802412C0.H"

f32 func_802417C4_de(f32 *arg0) {
    f32 magnitude;
    f32 result;
    f32 zero;

    magnitude = func_802B72B0_de((arg0[18] * arg0[18]) + (arg0[20] * arg0[20]));
    zero = 0.0f;
    if (magnitude == zero) {
        return zero;
    }
    result = func_802745D0_de(arg0[20] / magnitude);
    if (!(zero < arg0[18])) {
        result = -result;
    }
    return result;
}
