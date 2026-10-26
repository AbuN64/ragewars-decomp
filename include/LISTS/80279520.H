#ifndef LISTS_80279520_H
#define LISTS_80279520_H
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LISTHEADER.H"
#include "TYPES.H"
struct List802795C0;
struct ListLink;
struct Lists18;
extern void Lists_MoveNodeToActiveList(struct Lists18 *arg0, struct ListLink *arg1);
extern int Lists_Remove(struct List802795C0 *arg0, struct ListLink *arg1);
extern s32 Lists_Append(void *arg0, void *arg1);
extern ListLink *Lists_MoveHeadToInactiveList(Lists18 *arg0);
extern s32 Lists_AppendWeightedEntry(WeightedTable *arg0, s16 arg1, s16 arg2);
extern s16 Lists_ChooseWeightedTableEntry(WeightedTable *arg0);
#endif
