#ifndef MENU_PAK_80405DC0_16_H
#define MENU_PAK_80405DC0_16_H
#include "COMMON/MENURECAT24.H"
extern void Pak_ReleaseSaveBlocks(void);
extern void Pak_SetSaveTrailerValue(s32 offset, s32 value);
extern void Pak_AllocateSaveBlock(void ***handle, void **data, s32 units);
extern char *Pak_GetSaveBlockByteCount(s32 block);
extern s32 Pak_GetSaveTrailerValue(s32 *block);
extern void Pak_CapturePlayerProfile(struct OwnerRecAt5D8V1 *owner);
#endif
