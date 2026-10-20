#include "include_asm.h"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/NAVIGATION_GRAPH.H"
#include "COMMON/OBJECTLINKS14.H"
#include "stddef.h"
#include "TYPES.H"
#include "AI/NAV/8020EAE0.H"

f32 func_802726BC_de(void *a, void *b);

extern void func_8020D1FC_de(void *);


extern void func_8020D220_de(void *, s32);

extern void func_8020C5A0_de(NavigationGraph *, NavigationSearchNode *);

s32 func_8020B95C_de(NavigationGraph *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 arg4) {
    NavigationPoint *var_s7;
    NavigationBuffer *temp_v1;
    NavigationBuffer *temp_v1_2;
    s32 *var_a3;
    s32 var_s2;
    s32 var_s4;
    s32 var_s5;
    s32 var_t0;
    s32 var_v0;
    s32 var_v0_2;
    s32 temp_a0;
    s32 temp_a0_2;
    NavigationPortal *temp_v1_3;

    if (arg2 != -1) {
        temp_v1 = arg0->points;
        var_s7 = navigationRecord(temp_v1, arg2);
    } else {
        var_s7 = NULL;
    }
    var_t0 = 0;
    var_s4 = 0;
    if (arg0->portalCount > 0) {
        s32 reversibleKind4 = 4;
        s32 reversibleKind1 = 1;
        s32 reversibleKind7 = 7;
        s32 noRoom = -1;
        s32 forwardExcludedKind = 6;
        var_a3 = arg3;
        do {
            temp_v1_2 = arg0->portals;
            temp_v1_3 = navigationRecord(temp_v1_2, var_t0);
            if (arg4 != 0) {
                if (temp_v1_3->second == arg1) {
                    var_s4 += 1;
                    *var_a3 = (s32) temp_v1_3->first;
                    var_a3 += 1;
                }
                if (temp_v1_3->first == arg1) {
                    temp_a0 = temp_v1_3->kind;
                    if (temp_a0 != reversibleKind4) {
                        if ((s32) temp_a0 < 5) {
                            var_v0 = 0;
                            if (temp_a0 != reversibleKind1) {

                            } else {
                                goto block_14;
                            }
                        } else {
                            var_v0 = 0;
                            if (temp_a0 == reversibleKind7) {
                                goto block_14;
                            }
                        }
                    } else {
block_14:
                        var_v0 = 1;
                    }
                    if (var_v0 != 0) {
                        var_s4 += 1;
                        *var_a3 = (s32) temp_v1_3->second;
                        var_a3 += 1;
                    }
                }
                if ((arg2 != noRoom) && (temp_v1_3->first == arg1) && (temp_v1_3->second == arg2) && (var_s7 != NULL) && (var_s7->flags & 2)) {
                    *var_a3 = arg2;
                    var_a3 += 1;
                    var_s4 += 1;
                }
            } else {
                if ((temp_v1_3->first == arg1) && (temp_v1_3->kind != forwardExcludedKind)) {
                    var_s4 += 1;
                    *var_a3 = (s32) temp_v1_3->second;
                    var_a3 += 1;
                }
                if (temp_v1_3->second == arg1) {
                    temp_a0_2 = temp_v1_3->kind;
                    if (temp_a0_2 != reversibleKind4) {
                        if ((s32) temp_a0_2 < 5) {
                            var_v0_2 = 0;
                            if (temp_a0_2 != reversibleKind1) {

                            } else {
                                goto block_32;
                            }
                        } else {
                            var_v0_2 = 0;
                            if (temp_a0_2 == reversibleKind7) {
                                goto block_32;
                            }
                        }
                    } else {
block_32:
                        var_v0_2 = 1;
                    }
                    if (var_v0_2 != 0) {
                        var_s4 += 1;
                        *var_a3 = (s32) temp_v1_3->first;
                        var_a3 += 1;
                    }
                }
            }
            var_t0 += 1;
        } while (var_t0 < arg0->portalCount);
    }
    if (arg2 == -1) return var_s4;
    if (var_s7 != 0) {
            for (var_s5 = 0; var_s5 < var_s4 - 1; var_s5++) {
                for (var_s2 = var_s5 + 1; var_s2 < var_s4; var_s2++) {
                    NavigationBuffer *table = arg0->points;
                    s32 firstIndex = arg3[var_s5] * table->stride;
                    s32 secondIndex = arg3[var_s2] * table->stride;
                    void *first = table->data + firstIndex;
                    void *other = table->data + secondIndex;
                    f32 distance = func_802726BC_de(&var_s7->position.x, first);
                    if (func_802726BC_de(&var_s7->position.x, other) < distance) {
                        s32 saved = arg3[var_s5];
                        arg3[var_s5] = arg3[var_s2];
                        arg3[var_s2] = saved;
                    }
                }
            }
    }
    return var_s4;
}

s32 func_8020BC50_de(Obj8020BC50 *obj, s32 key, s32 requested, void *owner) {
    Node8020BC50 *node;
    s32 found;

    {
        Node8020BC50 *reset;

        reset = obj->nodes;
        while (reset != 0) {
            reset->value = D_800C1D68_de;
            reset->state = -1;
            reset->field18 = 0;
            reset->field1C = 0;
            reset->field20 = 0;
            reset->field24 = 0;
            reset->field28 = 0;
            reset->field2C = 0;
            reset->field30 = 0;
            reset = reset->next;
        }
    }

    obj->selected = -1;
    obj->value = D_800C1D6C_de;
    func_8020D1FC_de(obj);
    found = 0;
    func_8020EC14_de(owner);
    func_8020D220_de(obj, requested);

    {
        s32 i;
        s32 count;
        u32 mask;

        i = found;
        count = obj->count;
        if (count > 0) {
            mask = 0x04300000;
            do {
            char *record;
            s32 product;

            product = i * count;
            if (i != requested) {
                if (((struct ObjRecAt4V1 *) (obj->links->data + ((product + requested) * obj->links->stride)))->unk4 != 0) {
                    record = (char *)obj->records +
                             (i * obj->records->stride + 8);
                    if (record != 0 && (((ObjectState10 *)(record))->unk_C.v0 & mask) == 0) {
                        func_8020D220_de(obj, i);
                        found++;
                    }
                }
            }
                i++;
                count = obj->count;
            } while (i < count);
        }

        if (found == 0) {
            for (i = 0; i < obj->count; i++) {
                char *record;
                s32 product;

                product = i * obj->count;
                if (i != requested) {
                    if (((struct ObjRecAt4V1 *) (obj->links->data + ((product + requested) * obj->links->stride)))->unk4 != 0) {
                        record = (char *)obj->records +
                                 (i * obj->records->stride + 8);
                        if (record != 0 && (((ObjectState10 *)(record))->unk_C.v1 & 0x400) == 0) {
                            func_8020D220_de(obj, i);
                        }
                    }
                }
            }
        }
    }

    node = obj->nodes;
    if (node == 0) {
        goto not_found;
    }
    do {
        if (node->key == key) {
            goto search_done;
        }
        node = node->next;
    } while (node != 0);
not_found:
    node = 0;
search_done:
    func_8020C5A0_de(obj, node);
    return obj->selected = obj->result;
}

#ifdef NON_MATCHING
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
extern f32 D_800C1D70_de;
#include "TYPES.H"
f32 func_802726BC_de(void *a, void *b);
s32 func_8020C078_de(NavigationGraph *, s32, s32, u8, s32, f32 *, f32);

static __inline__ s32 navigationNeighbors(NavigationGraph *graph, s32 key, s32 *out, s32 *edges) {
    s32 i = 0;
    s32 count = 0;
    if (graph->portalCount > 0) {
        do {
            NavigationPortal *portal = navigationRecord(graph->portals, i);
            if (portal->first == key) {
                count++;
                *out = portal->second;
                *edges = i;
                edges++;
                out++;
            }
            if (portal->second == key) {
                count++;
                *out = portal->first;
                *edges = i;
                edges++;
                out++;
            }
            i++;
        } while (i < graph->portalCount);
    }
    return count;
}

s32 func_8020BE7C_de(NavigationGraph *arg0, s32 arg1, u8 arg2, s32 arg3) {
    s32 sp20[64];
    s32 sp120[64];
    f32 sp220;
    f32 *sp224;
    f32 var_fs0;
    NavigationBuffer *temp_a1;
    NavigationBuffer *temp_a2;
    NavigationBuffer *temp_v1_2;
    NavigationBuffer *temp_v1_3;
    s32 *var_a0_2;
    s32 *var_a1;
    s32 *var_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a0;
    s32 var_fp;
    s32 var_s0;
    s32 var_t0;
    s32 var_t1;
    s32 var_v0;
    NavigationPortal *temp_v1;
    NavigationPortal *temp_v1_4;

    var_fp = -1;
    var_s0 = 0;
    temp_v0 = arg0->portalCount;
    var_fs0 = D_800C1D70_de;
    if (temp_v0 > 0) {
        s32 stride;
        temp_a1 = arg0->portals;
        stride = temp_a1->stride;
        var_a0 = 8;
        do {
            temp_v1 = (void *)(temp_a1->data + (var_a0 - 8));
            var_s0++;
            if (temp_v1->first == arg1 && temp_v1->kind == (u8)arg2) return arg1;
            var_a0 += stride;
        } while (var_s0 < temp_v0);
    }
block_7:
    temp_v1_2 = arg0->points;
    sp224 = navigationRecord(temp_v1_2, arg1);
    var_t1 = navigationNeighbors(arg0, arg1, sp20, sp120);
    for (var_s0 = 0; var_s0 < var_t1; var_s0++) {
        NavigationBuffer *table = arg0->points;
        sp220 = func_802726BC_de(sp224, navigationRecord(table, sp20[var_s0]));
        temp_v0_2 = func_8020C078_de(arg0, arg1, sp20[var_s0], (u8)arg2, arg3 - 1, &sp220, var_fs0);
        if (temp_v0_2 != -1) {
            var_fs0 = sp220;
            var_fp = temp_v0_2;
        }
    }
    return var_fp;
}
#else
INCLUDE_ASM("span_1000", func_8020BE80_de);
#endif

#ifdef NON_MATCHING
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
extern f32 D_800C1D74_de;
#include "TYPES.H"
f32 func_802726BC_de(void *a, void *b);
s32 func_8020C078_de(NavigationGraph *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4, f32 *arg5, f32 arg6) {
    s32 sp20[64];
    s32 sp120[64];
    f32 sp220;
    f32 *temp_a1;
    f32 *temp_s4;
    f32 temp_fv0f;
    f32 var_fs0;
    NavigationBuffer *temp_a0;
    NavigationBuffer *temp_a2;
    NavigationBuffer *temp_v1_2;
    NavigationBuffer *temp_v1_3;
    s32 *var_a0_2;
    s32 *var_a2;
    s32 *var_s1;
    s32 temp_v0;
    s32 var_a0;
    s32 var_fp;
    s32 var_s0;
    s32 var_t0;
    s32 var_t1;
    s32 var_v0;
    NavigationPortal *temp_v1;
    NavigationPortal *temp_v1_4;

    var_fs0 = D_800C1D74_de;
    var_fp = -1;
    var_s0 = 0;
    temp_v0 = arg0->portalCount;
    if (temp_v0 > 0) {
        s32 stride;
        temp_a2 = arg0->portals;
        stride = temp_a2->stride;
        var_a0 = 8;
        do {
            temp_v1 = (void *)(temp_a2->data + (var_a0 - 8));
            var_s0++;
            if (temp_v1->first == arg2 && temp_v1->kind == (u8)arg3) return arg2;
            var_a0 += stride;
        } while (var_s0 < temp_v0);
    }
block_5:
    var_t0 = 0;
    if (arg4 == 0) {
        return -1;
    }
    temp_v1_2 = arg0->points;
    var_t1 = 0;
    var_a0_2 = sp20;
    temp_s4 = navigationRecord(temp_v1_2, arg1);
    if (arg0->portalCount > 0) {
        var_a2 = sp120;
        do {
            temp_v1_3 = arg0->portals;
            temp_v1_4 = navigationRecord(temp_v1_3, var_t0);
            if (temp_v1_4->first == arg1) {
                var_t1 += 1;
                *var_a0_2 = (s32) temp_v1_4->second;
                *var_a2 = var_t0;
                var_a2 += 1;
                var_a0_2 += 1;
            }
            if (temp_v1_4->second == arg1) {
                var_t1 += 1;
                *var_a0_2 = (s32) temp_v1_4->first;
                *var_a2 = var_t0;
                var_a2 += 1;
                var_a0_2 += 1;
            }
            var_t0 += 1;
        } while (var_t0 < arg0->portalCount);
    }
    for (var_s0 = 0; var_s0 < var_t1; var_s0++) {
        NavigationBuffer *table = arg0->points;
        void *point = navigationRecord(table, sp20[var_s0]);
        if (point != temp_s4) {
            sp220 = *arg5 + func_802726BC_de(temp_s4, point);
            if (sp220 < arg6) {
                var_v0 = func_8020C078_de(arg0, arg2, sp20[var_s0], (u8)arg3, arg4 - 1, &sp220, arg6);
            } else var_v0 = -1;
            if (var_v0 != -1 && sp220 < var_fs0) {
                var_fs0 = sp220;
                var_fp = var_v0;
            }
        }
    }
    if (var_fs0 < arg6) {
        *arg5 = var_fs0;
    }
    return var_fp;
}
#else
INCLUDE_ASM("span_1000", func_8020C078_de);
#endif

extern f32 D_800C1D78_de;
extern const f32 D_800C1D7C_de;
extern f32 func_802726F8_de(f32 *, f32 *);

f32 func_8020C2E8_de(NavigationGraph *graph, NavigationSearchNode *node)
{
    s32 neighbors[64];
    s32 portalIds[64];
    NavigationBuffer *portalTable;
    NavigationBuffer *exitPoints;
    NavigationBuffer *goalPoints;
    NavigationBuffer *exitGoalPoints;
    f32 empty;
    f32 distance;
    f32 exitDistance;
    f32 best;
    s32 goal;
    s32 exitGoal;
    s32 goalIndex;
    s32 neighborIndex;
    s32 neighborCount;
    NavigationPortal *portal;
    NavigationPoint *origin;
    NavigationPoint *exitPoint;
    best = D_800C1D78_de;
    empty = best;
    origin = navigationRecord(graph->points, node->key);
    for (goalIndex = 0; goalIndex < 64; goalIndex++)
    {
        goal = graph->goals[goalIndex];
        if (goal == -1)
        {
            continue;
        }
        goalPoints = graph->points;
        distance = func_802726F8_de(&origin->position.x, navigationRecord(goalPoints, goal));
        if ((distance < best) || (best == empty))
        {
            best = distance;
        }
    }

    for (goalIndex = 0; goalIndex < 64; goalIndex++)
    {
        neighbors[goalIndex] = -1;
        portalIds[goalIndex] = -1;
    }

    {
        s32 key = node->key;
        s32 *neighborBase = neighbors;
        s32 *portalBase = portalIds;
        s32 portalIndex = 0;
        s32 count = 0;
        s32 *neighborOut;
        s32 *portalOut;
        NavigationBuffer *links;
        NavigationPortal *link;
        if (graph->portalCount > portalIndex)
        {
            portalOut = portalBase;
            neighborOut = neighborBase;
            do
            {
                links = graph->portals;
                link = navigationRecord(links, portalIndex);
                if (link->first == key)
                {
                    count += 1;
                    *neighborOut = link->second;
                    *portalOut = portalIndex;
                    portalOut++;
                    neighborOut++;
                }
                if (link->second == key)
                {
                    count += 1;
                    *neighborOut = link->first;
                    *portalOut = portalIndex;
                    portalOut++;
                    neighborOut++;
                }
                portalIndex += 1;
            }
            while (portalIndex < graph->portalCount);
        }
        neighborCount = count;
    }
    {
        for (neighborIndex = 0; neighborIndex < neighborCount; neighborIndex++)
        {
            portalTable = graph->portals;
            portal = navigationRecord(portalTable, portalIds[neighborIndex]);
            if ((portal->kind == 9) && (portal->first == node->key))
            {
                exitPoints = graph->points;
                exitPoint = navigationRecord(exitPoints, portal->second);
                for (goalIndex = 0; goalIndex < 64; goalIndex++)
                {
                    exitGoal = graph->goals[goalIndex];
                    if (exitGoal == -1)
                    {
                        continue;
                    }
                    exitGoalPoints = graph->points;
                    exitDistance = func_802726F8_de(&exitPoint->position.x, navigationRecord(exitGoalPoints, exitGoal));
                    if ((exitDistance < best) || (best == D_800C1D7C_de))
                    {
                        best = exitDistance;
                    }
                }

            }
        }

    }
    return best;
}

#ifdef NON_MATCHING
#include "COMMON/OBJECTLINKS14.H"
extern f32 D_800C1D80_de,D_800C1D84_de,D_800C1D88_de;
extern f32 func_8020C2E8_de(NavigationGraph *, NavigationSearchNode *);
extern f32 func_802726F8_de(f32 *,f32 *);

static inline s32 hasOpen35(NavigationGraph *g,s32 status){NavigationSearchNode *n=g->nodes;while(n){if(n->open==status)return 1;n=n->next;}return 0;}
static __inline__ NavigationSearchNode *choose35(NavigationGraph *g,s32 status,f32 initial,f32 sentinel){NavigationSearchNode *n=g->nodes,*best=0;f32 minimum=initial;while(n){if(n->open==status){if(n->total<minimum){best=n;minimum=n->total;}else if(minimum==sentinel){best=n;minimum=n->total;}}n=n->next;}if(best)best->open=0;return best;}
static inline NavigationSearchNode *find35(NavigationGraph *g,s32 key){NavigationSearchNode *n=g->nodes;while(n){if(n->key==key)return n;n=n->next;}return 0;}
static inline s32 neighbors35(NavigationGraph *arg0, NavigationSearchNode *node,s32 *out,s32 *ids) {
 s32 temp_t1=node->key,var_a3=0,var_t0=0; s32 *var_a0_3=out,*var_a1=ids; NavigationBuffer *temp_v1;NavigationPortal *temp_v1_2;
        if (arg0->portalCount > 0) {

            do {
                temp_v1 = arg0->portals;
                temp_v1_2=navigationRecord(temp_v1,var_a3);
                if (temp_v1_2->first == temp_t1) {
                    var_t0 += 1;
                    *var_a0_3 = temp_v1_2->second;
                    *var_a1 = var_a3;
                    var_a1++;
                    var_a0_3++;
                }
                if (temp_v1_2->second == temp_t1) {
                    var_t0 += 1;
                    *var_a0_3 = temp_v1_2->first;
                    *var_a1 = var_a3;
                    var_a1++;
                    var_a0_3++;
                }
                var_a3 += 1;
            } while (var_a3 < arg0->portalCount);
        }
return var_t0;
}
void func_8020C5A0_de(NavigationGraph *arg0, NavigationSearchNode *arg1) {
    s32 sp10[64];
    s32 sp110[64];
    s32 *sp210;
    NavigationPoint *temp_fp;
    NavigationPoint *temp_s2;
    f32 temp_fs0f;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0f;
    f32 var_fv0f;
    f32 var_fv0f_2;
    f32 var_fv0f_3;
    NavigationBuffer *temp_a0;
    NavigationBuffer *temp_a0_3;
    NavigationBuffer *temp_v1;
    NavigationBuffer *temp_v1_3;
    s32 *var_a0_2;
    s32 *var_a0_3;
    s32 *var_a1;
    s32 *var_v1_3;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_t1;
    s32 temp_v1_5;
    s32 var_a3;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s4;
    s32 var_t0;
    s32 var_v0;
    const s32 one = 1;
    s32 var_v0_2;
    u8 temp_a0_5;
    s32 temp_v1_4;
    NavigationPortal *temp_a0_4;
    NavigationPortal *temp_v1_2;
    NavigationSearchNode *var_a0;
    NavigationSearchNode *var_a1_2;
    NavigationSearchNode *var_s0;
    NavigationSearchNode *var_v1;
    NavigationSearchNode *var_v1_2;

    arg1->cost = 0.0f;
    temp_fv0 = func_8020C2E8_de(arg0,arg1);
    temp_fs0f = D_800C1D80_de;
    sp210=sp10;
    arg1->estimate = temp_fv0;
    arg1->parent = 0;
    arg1->open=one;
    arg1->total = (arg1->cost + temp_fv0);
loop_1:
 if(hasOpen35(arg0,one)){
 var_a0=choose35(arg0,one,D_800C1D84_de,temp_fs0f);
        temp_a0 = arg0->points;
        temp_a1 = var_a0->key;
        temp_fp=navigationRecord(temp_a0,temp_a1);
        if (var_a0->goal != 0) {
            arg0->result = temp_a1;
            return;
        }
        var_s1_2 = 0;
        var_a0_2=sp110;
        var_v1_3=sp10;
        do {
            *var_v1_3 = -1;
            *var_a0_2 = -1;
            var_a0_2++;
            var_s1_2 += 1;
            var_v1_3++;
        } while (var_s1_2 < 0x40);
var_t0=neighbors35(arg0,var_a0,sp10,sp110);
        var_s1_2 = 0;
        if (var_t0 > 0) {
            var_s4 = 0;
            do {
                temp_v1_3 = arg0->points;
                temp_a0_2 = sp210[var_s1_2];
                var_a1_2 = arg0->nodes;
                temp_s2=navigationRecord(temp_v1_3,temp_a0_2);
                var_s0=find35(arg0,temp_a0_2);
                temp_a0_3 = arg0->portals;
                temp_a0_4=navigationRecord(temp_a0_3,sp110[var_s1_2]);
                temp_v1_4 = temp_a0_4->kind;
                if (temp_v1_4 != 4) {
                    if (temp_v1_4 < 5) {
                        var_v0_2 = 0;
                        if (temp_v1_4 != 1) {

                        } else {
                            goto block_35;
                        }
                    } else {
                        var_v0_2 = 0;
                        if (temp_v1_4 == 7) {
                            goto block_35;
                        }
                    }
                } else {
block_35:
                    var_v0_2 = 1;
                }
                if ((var_v0_2 != 0) || (temp_a0_4->first == var_a0->key)) {
                    temp_a0_5 = temp_a0_4->kind;
                    if ((temp_a0_5 != 0xA) && (temp_a0_5 != 0xB)) {
                        if (temp_a0_5 == 9) {
                            var_fv0f_2 = 0.0f;
                        } else {
                            var_fv0f_2 = func_802726F8_de(&temp_s2->position.x,&temp_fp->position.x);
                        }
                        var_fv0f_3 = var_fv0f_2 + var_s0->extra;
                        if (temp_s2->flags & 0x400) {
                            var_fv0f_3 += D_800C1D88_de;
                        }
                        if (var_fv0f_3 < 0.0f) {
                            var_fv0f_3 = 0.0f;
                        }
                        temp_v1_5 = var_s0->open;
                        temp_fv0f = var_a0->cost + var_fv0f_3;
                        if (((temp_v1_5 ^ 2) == 0) || ((temp_v1_5 ^ 1) == 0)) {
                            if (!(var_s0->cost <= temp_fv0f)) {
                                goto block_51;
                            }
                        } else {
block_51:
                            var_s0->parent = var_a0;
                            var_s0->cost = temp_fv0f;
                            temp_fv0_3 = func_8020C2E8_de(arg0, var_s0);
                            var_s0->estimate = temp_fv0_3;
                            var_s0->total = (var_s0->cost + temp_fv0_3);
                            if ((var_s0->open ^ 2) == 0) {
                                var_s0->open = 0;
                            }
                            if ((var_s0->open ^ one) != 0) {
                                var_s0->open=one;
                            }
                        }
                    }
                }
                var_s1_2 += 1;
                var_s4 += 4;
            } while (var_s1_2 < var_t0);
        }
        var_a0->open = 2;
        goto loop_1;
    }
}
#else
INCLUDE_ASM("span_1000", func_8020C5A0_de);
#endif
