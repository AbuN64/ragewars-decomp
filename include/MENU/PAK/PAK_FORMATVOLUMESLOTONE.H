#ifndef MENU_PAK_PAK_FORMATVOLUMESLOTONE_H
#define MENU_PAK_PAK_FORMATVOLUMESLOTONE_H
#include "COMMON/MENURECAT20V1.H"
extern s32 Pak_FormatVolumeSlotOne(struct Field *field);
#include "COMMON/SHARED_GAMESLOT.H"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char *D_800D7DD4[];
#else
extern char *D_800D7DD4;
#endif
#endif
