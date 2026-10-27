#include "COMMON/ACTORREC.H"

/* Advances a committed selection's stage against the node list D_8013B364: finishes through
   Nav_FindSpecialLinkedCandidate when there are no stages at 0x1BC, counts once into 0x1C8 the list's kind-6 nodes whose
   id matches the selection id at 0x1C0, then runs Nav_AppendDirectionalRouteStage while the stage is within that count,
   Nav_InsertPickupRouteNode on the stage right after it and Nav_ComputeScaledPointCentroid on the one after that. */
#include "TYPES.H"
#include "COMMON/UNUSED.H"
/* Navigation selection/list/node canonical ownership remains unresolved. */







extern NodeList D_8013B364;

extern Node_func_8020D364_de *Nav_GetStridedTableEntry(NodeList *list, s32 index);
extern s32 Nav_AppendDirectionalRouteStage(Selection *sel);
extern s32 Nav_InsertPickupRouteNode(Selection *sel);
extern s32 Nav_ComputeScaledPointCentroid(Selection *sel);
extern s32 Nav_FindSpecialLinkedCandidate(Selection *sel);

s32 Nav_AdvancePickupRouteSelection(Selection *sel)
{
    NodeList *list = &D_8013B364;
    Node_func_8020D364_de *node;
    s32 i;

    if (list == 0) {
        return 1;
    }
    if (sel->stage == 0) {
        return Nav_FindSpecialLinkedCandidate(sel);
    }
    if (sel->selection != -1 && sel->matches == 0) {
        for (i = 0; i < list->count; i++) {
            node = Nav_GetStridedTableEntry(list, i);
            if (node->id == sel->selection && node->kind == 6) {
                sel->matches++;
            }
        }
    }
    if (sel->stage > 0 && sel->stage < sel->matches + 1) {
        return Nav_AppendDirectionalRouteStage(sel);
    }
    if (sel->stage == sel->matches + 1) {
        return Nav_InsertPickupRouteNode(sel);
    }
    if (sel->stage == sel->matches + 2) {
        return Nav_ComputeScaledPointCentroid(sel);
    }
    return 1;
}
