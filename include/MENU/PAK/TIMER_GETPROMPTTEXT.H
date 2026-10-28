#ifndef MENU_PAK_TIMER_GETPROMPTTEXT_H
#define MENU_PAK_TIMER_GETPROMPTTEXT_H
#include "COMMON/RECORDRECATCV1.H"
#include "MENU/80409A88.H"
extern s32 Timer_FindNextAvailableChannel(s32 arg0);
extern char *Timer_GetPromptByKind(int unused, int kind);
extern void Timer_ProbeMenuChannel(struct Shared_PakMenu *record);
extern s32 Timer_GetChannelAndResult(struct RecordRecAt20V2 *record, s32 *out);
extern char *Timer_GetPromptText(struct Shared_PakMenu *menu);
#endif
