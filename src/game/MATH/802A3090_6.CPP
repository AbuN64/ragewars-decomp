#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/RECORD.H"
#include "COMMON/STATEPAIR.H"
#include "RESMGR/802A2230.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"

/** Store the active value and reset its timer to sixty. */
void func_802A2418_de(int arg0) {
    D_800CDA30_de.state = arg0;
    D_800CBC14 = 60;
}
