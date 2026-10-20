#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
extern u8 *D_800E3B94[];

void func_80445030_eu(Shared_PlayerSettingsRecord *record, s32 index) {
    Shared_Game *settings = &D_801462C8;
    do {
        record->name[index] = D_800E3B94[settings->language][index];
        index++;
    } while (index < 8);
}
#endif
