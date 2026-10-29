#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
extern u8 *g_playerNamePrefixByLanguage[];

void Items_CopyLocalizedNameBytesEu(Shared_PlayerSettingsRecord *record, s32 i) {
    Shared_Game *game = &g_gameSettings;
    do {
        record->name[i] = g_playerNamePrefixByLanguage[game->language][i];
        i++;
    } while (i < 8);
}
#endif
