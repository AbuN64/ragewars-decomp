#include "include_asm.h"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/S2.H"
#include "TYPES.H"
#include "COMMON/OBJECTLINKS1458.H"
#include "COMMON/SELF.H"

void func_802100E0_de(void *arg0) {
    AiController *controller = arg0;
    s32 temp_v0;

    if ((func_802744D4_de() % 100) < 0x15) {
        do {
            temp_v0 = func_80232ABC_de(controller->player);
        } while (temp_v0 >= 0x10);
        ((Shared_ActorView *)controller->player)->nextWeapon = temp_v0;
        if (temp_v0 != ((Shared_ActorView *)controller->player)->selectedAction) {
            controller->unk2E4 = 0;
        }
    }
}

#if defined(VERSION_EU_X)
INCLUDE_DATA("span_1000", func_80210198_eu_padding_10D98);
#endif
