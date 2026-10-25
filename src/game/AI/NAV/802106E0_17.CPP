#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/SELF.H"
#include "TYPES.H"
#include "AI/SHARED_PICKUPGOALNODE.H"

void *func_8020C9B0_de(struct EntryList8020CCE8 *object, int index);
extern void *func_8020C994_de(void *, s32);
#include "AI/ROUTE_RELATION_GRID.H"
extern f32 func_802726BC_de(f32 *, f32 *);

/* Choose the farthest reachable neighbor linked by kinds 1, 2 or 7
 * from the actor that this state is following. */
void Nav_SelectFarthestReachableNeighbor(AiController *object)
{
    s32 neighbors[64];
    s32 links[64];
    s32 *linkCursor;
    CVector3 position;
    Player *actor;
    f32 *point;
    f32 distance;
    f32 farthest;
    s32 actor_node;
    register s32 best;
    s32 count;
    s32 i;
    Link *link;
    void *graph = &D_8013B364;

    actor = object->target->player;
    actor_node = actor->controller->current;
    position = actor->pos;
    for (i = 0; i < 64; i++) {
        neighbors[i] = -1;
        links[i] = -1;
    }
    linkCursor = links;
    farthest = D_800C20C0_de[0];
    count = func_8020CCE8_de(graph, object->current, neighbors, linkCursor);
    best = -1;
    for (i = 0; i < count; i++) {
        link = func_8020C9B0_de(graph, links[i]);
        if ((link->type >= 1 && link->type <= 2) || link->type == 7) {
            point = func_8020C994_de(graph, neighbors[i]);
            if (Nav_GetRouteRelation(graph, actor_node, neighbors[i])) {
                distance = func_802726BC_de(&position.x, point);
                if (farthest < distance) {
                    farthest = distance;
                    best = i;
                }
            }
        }
    }
    object->mode = best;
}
