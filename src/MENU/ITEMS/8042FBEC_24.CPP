#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
extern s32 func_804423BC_de(void *, s32, s32, s32, s32, s32);

s32 func_80445F60_eu(void *first, void *second) {
    Shared_Game *game = &D_801462C8;
    game->language = func_804423BC_de(second, game->language, 1, 0, 3, 1);
    return 0;
}
#endif
