#ifndef LISTS_LISTS_H
#define LISTS_LISTS_H
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LISTHEADER.H"
#include "TYPES.H"
struct List802795C0;
struct ListLink;
struct Lists18;
extern void Lists_MoveNodeToActiveList(struct Lists18 *list, struct ListLink *node);
extern int Lists_Remove(struct List802795C0 *listHeader, struct ListLink *listLink);
extern s32 Lists_Append(void *listHeader, void *newNode);
extern ListLink *Lists_MoveHeadToInactiveList(Lists18 *lists);
extern s32 Lists_AppendWeightedEntry(WeightedTable *table, s16 value, s16 weight);
extern s16 Lists_ChooseWeightedTableEntry(WeightedTable *weightedTable);
#endif
