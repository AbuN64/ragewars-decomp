#include "COMMON/RECORD.H"
#include "COMMON/EXTERNS_4.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/TEXTURE.H"
#include "MATH/80297CD0_3.H"
#include "RESMGR/802A23A4_10.H"

int N64Eng_GetFrameCounter(void) {
    return D_800D2C18;
}

/** Increment the global counter D_800D2C18. */
void N64Eng_AdvanceFrameCounter(void) {
    D_800D2C18 += 1;
}

void N64Eng_RegisterNumericWidgetClass(void) {
    func_802982C4_de(0xB65, D_002A1B50, D_002A1BE0, 3);
}
