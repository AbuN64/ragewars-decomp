#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
extern u8 *D_800E3B84[];

void Items_CopyLocalizedPlayerNameSuffix(Shared_PlayerSettingsRecord *record, s32 i, Shared_Game *game) {
    do {
        record->name[i] = D_800E3B84[game->language][i];
        i++;
    } while (i < 8);
}
#endif
