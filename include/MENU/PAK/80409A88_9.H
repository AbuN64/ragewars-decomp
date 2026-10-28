#ifndef MENU_PAK_80409A88_9_H
#define MENU_PAK_80409A88_9_H
#include "COMMON/RECORDRECATCV1.H"
#include "MENU/80409A88.H"
extern void Timer_EnableProfilePreview(void);
extern void Timer_ClearProfilePreview(void);
extern void Timer_DisablePreviewSelection(struct RecordRecAtCV1 *record);
extern s32 Timer_OpenSelectedPrompt(void *unused, struct RecordRecAt24 *record);
extern s32 Menu_CountLineChars(struct Field *);
#endif
