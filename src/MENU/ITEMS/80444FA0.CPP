#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
extern u8 *D_800E3B74[];

void func_80444FA0_eu(Shared_PlayerSettingsRecord *record, s32 i) {
    Shared_Game *game = &D_801462C8;
    do {
        record->name[i] = D_800E3B74[game->language][i];
        i++;
    } while (i < 8);
}
#endif
