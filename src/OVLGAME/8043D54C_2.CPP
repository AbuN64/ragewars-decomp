#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ACTORRECAT260.H"
#include "TYPES.H"
#include "OVLGAME/SHAREDRECAT224.H"

#if defined(VERSION_EU_X) || defined(VERSION_US)
s32 func_8043DADC_de(void *arg0, MenuRules *arg1) {
    func_8044972C_de(arg1->locked);
    return 1;
}
#endif

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
s32 func_8043DADC_de(void *unused, MenuRules *rules) {
    func_8044972C_de(rules->locked);
    return 1;
}
#endif
