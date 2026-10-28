#include "COMMON/SESSIONHANDLERROW.H"
#include "TYPES.H"
#include "RENDER/80291054_6.H"

s32 SetN64_StartBootstrapThread(s32 *);
#include "COMMON/GAME_SESSION.H"
void SetN64_StartSessionThreads(void) {
    SetN64_StartBootstrapThread(&D_8011FAC0);
}
