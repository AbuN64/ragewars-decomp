#include "RSP/8026E1F8_5.H"
#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ACTIVE.H"
#include "COMMON/GAMEPLAY_SETTINGS.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_25.H"
#include "RESMGR/802A0888.H"
#include "RENDER/8025DE50_5.H"

/* Returns 0xBC2 plus ten times either the halfword at offset 2 of what Scene_GetBlLevelData finds for
   D_8015402C in D_8011FE88, when the option byte D_801462D5 is one, or D_8015402C itself. */



extern struct StateFlags *Scene_GetBlLevelData(void *, s32);

s32 Random_GetStageTransitionResource(void) {
    return (D_801462C8.controllerMode == 1 ? Scene_GetBlLevelData(&g_world, D_8015402C)->flags : D_8015402C) * 10 + 0xBC2;
}

extern Shared_PlayerSettingsRecord g_playerSettings[];


/* Characters 0 and 5 may appear only once among the eight enabled players. */
static inline s32 characterAvailable(s32 character, s32 firstUniqueCharacter, s32 secondUniqueCharacter) {
    s32 available;
    s32 i;
    Shared_PlayerSettingsRecord *players = g_playerSettings;
    if (character == firstUniqueCharacter || character == secondUniqueCharacter) {
        for (available = 1, i = 0; i < 8; i++) {
            if (players[i].enabled && players[i].character == character) {
                available = 0;
            }
        }
    } else {
        available = 1;
    }
    return available;
}

s32 Random_ChooseRandomCharacter(void) {
    s32 character;
    do {
        character = GraphU64_NextRandom() % 11;
    } while (!characterAvailable(character, 0, 5));
    return character;
}

