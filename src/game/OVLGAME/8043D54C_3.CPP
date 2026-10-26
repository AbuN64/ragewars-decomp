#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "OVLGAME/SHAREDRECAT224.H"
#include "TYPES.H"
#include "OVLGAME/8043D54C_3.H"

#if !(defined(VERSION_EU))
/* Calls Ovlgame_ResetMatchControllerState on D_8011FAC0 when D_80145070 is one, otherwise clears the word at offset
   0x5D0 of the owner at offset 0x1C of the second argument. Returns one. */





#include "COMMON/GAME_SESSION.H"
extern void Ovlgame_ResetMatchControllerState(void *);

s32 func_8043DB04_de(void *unused, struct Holder *holder) {
    if (D_80145070 == 1) {
        Ovlgame_ResetMatchControllerState(&D_8011FAC0);
    } else {
        holder->owner->value = 0;
    }
    return 1;
}
#endif

#if defined(VERSION_US)
unsigned int func_8043DB04_de_padding_1A1D2C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int func_8043DB4C_de_padding_1A3B4C[1] = {
    0x02202021,
};
#endif

#if defined(VERSION_US_REV1)
unsigned int func_8043DB04_de_padding_1ABD2C[1] = {
    0x0810FB52,
};
#endif
