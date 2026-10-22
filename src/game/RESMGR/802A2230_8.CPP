#include "COMMON/STATEPAIR.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/RECORD.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"
#include "RESMGR/802A2230_8.H"

/** Return the global word at D_800D2C98. */



extern float D_800CDA30_de;

/** Store a scalar and clear its associated global state word. */
void func_802A2400_de(float value) {
    D_800CDA30_de = value;
    D_801427B0 = 0;
}
