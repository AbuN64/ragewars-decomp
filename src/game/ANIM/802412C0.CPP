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

f32 func_802417C4_de(f32 *contactRecord) {
    f32 magnitude;
    f32 result;
    f32 zero;

    magnitude = Math_Sqrtf((contactRecord[18] * contactRecord[18]) + (contactRecord[20] * contactRecord[20]));
    zero = 0.0f;
    if (magnitude == zero) {
        return zero;
    }
    result = GraphU64_ArcCos(contactRecord[20] / magnitude);
    if (!(zero < contactRecord[18])) {
        result = -result;
    }
    return result;
}
