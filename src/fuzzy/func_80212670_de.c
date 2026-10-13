#include "span_1000/code_80208000.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8020AF9C.h"
#include "span_1000/code_802106E0.h"
#include "types.h"

extern char D_8013B364[];
extern f32 D_800C20C0_de[];
extern s32 func_8020CCE8_de(EntryList8020CCE8 *, s32, s32 *, s32 *);
extern void *func_8020C9B0_de(void *, s32);
extern void *func_8020C994_de(void *, s32);
#include "shared/route_relation_grid.h"
extern f32 func_802726BC_de(f32 *, f32 *);

/* Choose the farthest reachable neighbor linked by kinds 1, 2 or 7
 * from the actor that this state is following. */
void func_80212670_de(void *object)
{
    s32 neighbors[64];
    s32 links[64];
    s32 *linkCursor;
    Vec3 position;
    Player *actor;
    f32 *point;
    f32 distance;
    f32 farthest;
    s32 actor_node;
    register s32 best;
    s32 count;
    s32 i;
    Link *link;

    actor = ((AiController *)object)->target->player;
    actor_node = actor->controller->current;
    position = actor->pos;
    for (i = 0; i < 64; i++) {
        neighbors[i] = -1;
        links[i] = -1;
    }
    linkCursor = links;
    best = -1;
    farthest = D_800C20C0_de[0];
    count = func_8020CCE8_de((void *)D_8013B364, ((AiController *)object)->current, neighbors, linkCursor);
    for (i = 0; i < count; i++) {
        link = func_8020C9B0_de(D_8013B364, links[i]);
        if ((link->type >= 1 && link->type <= 2) || link->type == 7) {
            point = func_8020C994_de(D_8013B364, neighbors[i]);
            if (func_8020D1CC_de(D_8013B364, actor_node, neighbors[i])) {
                distance = func_802726BC_de(&position.x, point);
                if (farthest < distance) {
                    farthest = distance;
                    best = i;
                }
            }
        }
    }
    ((AiController *)object)->mode = best;
}
