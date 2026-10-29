#include "include_asm.h"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/S2.H"
#include "TYPES.H"
#include "COMMON/NAVIGATION_ACTOR_SEARCH_VIEWS.H"
#include "COMMON/SELF.H"

void Nav_RequestRandomArmedWeapon(void *brain) {
    AiController *controller = brain;
    s32 chosenWeapon;

    if ((Graphu64_NextRandom() % 100) < 0x15) {
        do {
            chosenWeapon = Weapon_PickRandomArmedWeapon(controller->player);
        } while (chosenWeapon >= 0x10);
        ((Shared_ActorView *)controller->player)->nextWeapon = chosenWeapon;
        if (chosenWeapon != ((Shared_ActorView *)controller->player)->selectedAction) {
            controller->actionDelay = 0;
        }
    }
}

#if defined(VERSION_EU_X)
unsigned int func_80210198_eu_padding_10D98[2] = {
    0xAE020318, 0x8E020064,
};
#endif
