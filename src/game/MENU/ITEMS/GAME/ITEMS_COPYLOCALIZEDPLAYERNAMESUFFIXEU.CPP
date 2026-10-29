#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
extern u8 *g_playerNameSuffixByLanguage[];

void Items_CopyLocalizedPlayerNameSuffixEu(Shared_PlayerSettingsRecord *record, s32 index) {
    Shared_Game *settings = &g_gameSettings;
    do {
        record->name[index] = g_playerNameSuffixByLanguage[settings->language][index];
        index++;
    } while (index < 8);
}
#endif
