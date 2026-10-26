#ifndef MENU_PAK_80409A88_9_H
#define MENU_PAK_80409A88_9_H
#include "COMMON/RECORDRECATCV1.H"
#include "MENU/80409A88.H"
extern void Pak_EnableProfilePreview(void);
extern void Pak_ClearProfilePreview(void);
extern void Pak_DisablePreviewSelection(struct RecordRecAtCV1 *record);
extern s32 Pak_OpenSelectedPrompt(void *unused, struct RecordRecAt24 *record);
#endif
