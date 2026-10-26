#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ACTORRECAT260.H"
#include "TYPES.H"
#include "OVLGAME/SHAREDRECAT224.H"

#if defined(VERSION_EU_X) || defined(VERSION_US)
s32 Menu_ForwardRulesLock(void *arg0, MenuRules *menuRules) {
    Ovlgame_PlacePlayerForRound(menuRules->locked);
    return 1;
}
#endif

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
s32 Menu_ForwardRulesLock(void *unused, MenuRules *rules) {
    Ovlgame_PlacePlayerForRound(rules->locked);
    return 1;
}
#endif
