#include "COMMON/RECORD.H"
#include "COMMON/EXTERNS_4.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/TEXTURE.H"
#include "MENU/GFX/80414430_21.H"
#include "RESMGR/802A23A4_9.H"

/** Perform no operation. */
void N64Eng_RenderNoop(void) {
}

void N64Eng_ResetRenderState(void) { Gfx_ResetRenderState(); }
