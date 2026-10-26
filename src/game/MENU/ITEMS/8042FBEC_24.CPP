#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
extern s32 Pak_AdjustValue(void *, s32, s32, s32, s32, s32);

s32 Items_AdjustLanguage(void *first, void *second) {
    Shared_Game *game = &D_801462C8;
    game->language = Pak_AdjustValue(second, game->language, 1, 0, 3, 1);
    return 0;
}
#endif
