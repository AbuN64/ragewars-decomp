#ifndef MENU_PAK_80409A88_5_H
#define MENU_PAK_80409A88_5_H
#include "COMMON/RECORDRECATCV1.H"
#include "MENU/80409A88.H"
extern s32 Pak_FindNextAvailableChannel(s32 arg0);
extern char *func_8040A038_de(int unused, int kind);
extern void Pak_ProbeMenuChannel(struct Shared_PakMenu *record);
extern s32 Pak_GetChannelAndResult(struct RecordRecAt20V2 *record, s32 *out);
extern char *Pak_GetPromptText(struct Shared_PakMenu *menu);
#endif
