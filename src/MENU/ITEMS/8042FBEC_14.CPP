#include "include_asm.h"

#if defined(VERSION_EU)
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "OVLGAME/SHAREDRECAT224.H"

s32 func_8043E9D0_eu(void *unused, MenuRules *rules) {
    func_8044972C_de(rules->locked);
    return 1;
}
#endif

#if defined(VERSION_EU)
INCLUDE_ASM("ovl_80400000", func_8043E9F4_eu);
INCLUDE_ASM("ovl_80400000", func_8043EA40);
#endif
