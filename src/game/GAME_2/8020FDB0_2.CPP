#include "include_asm.h"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/S2.H"
#include "TYPES.H"
#include "COMMON/OBJECTLINKS1458.H"
#include "COMMON/SELF.H"

void func_802100E0_de(void *brain) {
    AiController *controller = brain;
    s32 temp_v0;

    if ((Nav_NextRandom() % 100) < 0x15) {
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
unsigned int func_80210198_eu_padding_10D98[2] = {
    0xAE020318, 0x8E020064,
};
#endif
