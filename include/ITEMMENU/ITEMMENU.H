#ifndef ITEMMENU_ITEMMENU_H
#define ITEMMENU_ITEMMENU_H
#include "COMMON/OBJRECAT18V6.H"
#include "SYSTEM_3/802A6AC0.H"
extern void ItemMenu_ResetEntries(CItemMenu *rec);
extern s32 ItemMenu_SetEntry(char *, s32, s32, s32, s32, f32, s32, s32, s32);
extern s32 ItemMenu_IsSelectedEntryActive(void *);
extern s32 ItemMenu_AdvanceSelection(MenuCode802A6AC0 *menu, s32 backward);
extern void ItemMenu_ClearEntry(CItem *);
extern void ItemMenu_ToggleEntry(void *, void *);
extern s32 ItemMenu_RestoreBootMemory(void);
extern void func_802A754C_de(void);
extern s32 ItemMenu_IsRestorableAddress(u32 address);
extern void func_802A7654_de(void);
#endif
