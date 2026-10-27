#include "RENDER/80293A04_2.H"
#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJRECAT26DD8.H"
#include "COMMON/SHARED_WORLDFUNC.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLD.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "TYPES.H"
#include "RENDER/802944E8_3.H"
extern s32 D_800E28D0;








extern int Player_GetFirstPlayer(void *arg0);


extern void SetN64_HandleSessionTransitionInput(s32 arg0, s32 arg1, s32 arg2);


s32 SetN64_DrawCreditsLines(s32);

s32 func_80291074_de(s32);


void SetN64_SelectSpawnAfterCredits(void *arg0, s32 arg1) {
    GameSession *object = arg0;
    Shared_Placed spawn;
    s32 selectionValues;

    selectionValues = arg1;
    if (OvlScene_FindPlacedObjectsByKey(&g_world, -1, selectionValues, &spawn, 1) == 0) {
        selectionValues = 0;
    }
    object->phase = 2;
    object->selector = selectionValues;
    object->target = 0xE;
}

/* Initializes the game state for a new game phase with arg0 as the phase identifier. */
void SetN64_InitializeMode16Credits(s32 arg0) {
    D_800CD780 = 0;
    D_8011B9F0 = 0;
    D_80146CB8 = (f32)(&D_800E28D0)[1];
    D_80142898 = 0;
    Player_GetFirstPlayer(&D_80145040);
    D_800CD784_de = 0;
    Scene_ResetTransitionViewport();
    SetN64_ResetPlayerItems(arg0, 0x82);
}

void SetN64_HandleMode16CreditsInput(s32 session) {
    s32 *p;

    if (D_800CD780 != 0) {
        SetN64_HandleSessionTransitionInput(session, 1, 1);
        return;
    }
    p = (s32 *)&D_8010B0E0.pressedButtons;
    if ((*p & 0x1000) && (D_80142898 == 0)) {
        D_80142898 = 1;
        *p = 0;
        D_80142CB4 = D_800C54DC_de;
    }
}

void SetN64_DrawMode16Credits(s32 session) {
    SetN64_DrawSessionWithAttractTimeout((void *)session);
    SetN64_DrawCreditsLines(session);
    func_80291074_de(session);
}

/* Initializes the game state for a new game phase with arg0 and updates the game state flag. */
void SetN64_InitializeMode17Credits(s32 arg0) {
    Shared_Game *game = &D_80145040.game;

    game->local = 0;
    D_800CD780 = 0;
    D_8011B9F0 = 0;
    D_80146CB8 = (f32)(&D_800E28D0)[1];
    D_80142898 = 0;
    Player_GetFirstPlayer(&D_80145040);
    D_800CD784_de = 0;
    Scene_ResetTransitionViewport();
    SetN64_ResetPlayerItems(arg0, 0x82);
    D_800CD780 = 1;
    D_800CD784_de = 0;
}

void SetN64_HandleMode17CreditsInput(s32 session) {
    if (D_800CD780 != 0) {
        SetN64_HandleSessionTransitionInput(session, 1, 1);
        return;
    }
    if ((D_8010B194_de & 0x1000) && (D_80142898 == 0)) {
        D_80142898 = 1;
        D_8010B194_de = 0;
        D_80142CB4 = (15.0f);
    }
}

void SetN64_DrawMode17Credits(s32 session) {
    SetN64_DrawSessionWithAttractTimeout((void *)session);
    SetN64_DrawCreditsLines(session);
    func_80291074_de(session);
}

#if defined(VERSION_US)
const unsigned int rodata_func_8029499C_us_800C5410[1] = {
    0x3F800000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C54E4[3] = {
    0x75726500, 0x0029523C, 0x002954A0,
};
#endif
