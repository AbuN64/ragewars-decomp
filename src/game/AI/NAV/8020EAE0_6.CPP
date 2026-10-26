#include "COMMON/NAVIGATION_GRAPH.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS1458.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJECTLINKS14.H"

/* Selects the nodes of D_8013B364's list whose flagged record matches one of thirty ids: every match
   whose owner at 0x34 is active at 0x294 is selected through Nav_AddGoalNode, and when none was, every
   matching node is selected regardless of owner. Returns the number of selections. Written from its
   own assembly in the style of func_8020EEA4_de. */



extern s32 D_8013B364;
extern void *Nav_GetGraphPoint(s32 *, s32);
extern void Nav_AddGoalNode(s32 *, s32);







s32 func_8020F150_de(s32 *ids) {
    s32 *base;
    Node8020BC50 *node;
    void *record;
    s32 count;
    s32 i;

    base = &D_8013B364;
    count = 0;
    for (node = (Node8020BC50 *)((Obj8020BC50 *)base)->nodes; node != 0; node = node->next) {
        record = Nav_GetGraphPoint(base, node->key);
        if (navigation_point_flags((NavigationPoint *)record) & 1) {
            for (i = 0; i < 30; i++) {
                if (navigation_point_object_id((NavigationPoint *)record) == ids[i] && node->owner != 0
                    && ((Owner8020F150 *)node->owner)->active != 0) {
                    Nav_AddGoalNode(base, node->key);
                    count++;
                }
            }
        }
    }
    if (count == 0) {
        for (node = (Node8020BC50 *)((Obj8020BC50 *)base)->nodes; node != 0; node = node->next) {
            record = Nav_GetGraphPoint(base, node->key);
            if (navigation_point_flags((NavigationPoint *)record) & 1) {
                for (i = 0; i < 30; i++) {
                    if (navigation_point_object_id((NavigationPoint *)record) == ids[i]) {
                        Nav_AddGoalNode(base, node->key);
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
