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

extern void Nav_SearchPath(CNavData *, NavigationSearchNode *);

s32 func_8020B95C_de(CNavData *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 arg4) {
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
    if (arg0->m_nNavLinks > 0) {
        s32 reversibleKind4 = 4;
        s32 reversibleKind1 = 1;
        s32 reversibleKind7 = 7;
        s32 noRoom = -1;
        s32 forwardExcludedKind = 6;
        var_a3 = arg3;
        do {
            temp_v1_2 = arg0->m_pusNavLinks;
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
                if ((arg2 != noRoom) && (temp_v1_3->first == arg1) && (temp_v1_3->second == arg2) && (var_s7 != NULL) && (navigation_point_flags(var_s7) & 2)) {
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
        } while (var_t0 < arg0->m_nNavLinks);
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
    Nav_SearchPath(obj, node);
    return obj->selected = obj->result;
}

#ifdef NON_MATCHING
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
extern f32 D_800C1D70_de;
#include "TYPES.H"
f32 func_802726BC_de(void *a, void *b);
s32 func_8020C078_de(CNavData *, s32, s32, u8, s32, f32 *, f32);

static __inline__ s32 navigationNeighbors(CNavData *graph, s32 key, s32 *out, s32 *edges) {
    s32 i = 0;
    s32 count = 0;
    if (graph->m_nNavLinks > 0) {
        do {
            NavigationPortal *portal = navigationRecord(graph->m_pusNavLinks, i);
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
        } while (i < graph->m_nNavLinks);
    }
    return count;
}

s32 func_8020BE80_de(CNavData *arg0, s32 arg1, u8 arg2, s32 arg3) {
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
    temp_v0 = arg0->m_nNavLinks;
    var_fs0 = D_800C1D70_de;
    if (temp_v0 > 0) {
        s32 stride;
        temp_a1 = arg0->m_pusNavLinks;
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
s32 func_8020C078_de(CNavData *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4, f32 *arg5, f32 arg6) {
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
    temp_v0 = arg0->m_nNavLinks;
    if (temp_v0 > 0) {
        s32 stride;
        temp_a2 = arg0->m_pusNavLinks;
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
    if (arg0->m_nNavLinks > 0) {
        var_a2 = sp120;
        do {
            temp_v1_3 = arg0->m_pusNavLinks;
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
        } while (var_t0 < arg0->m_nNavLinks);
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

f32 func_8020C2E8_de(CNavData *graph, NavigationSearchNode *node)
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
        goal = graph->m_nGoalList[goalIndex];
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
        if (graph->m_nNavLinks > portalIndex)
        {
            portalOut = portalBase;
            neighborOut = neighborBase;
            do
            {
                links = graph->m_pusNavLinks;
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
            while (portalIndex < graph->m_nNavLinks);
        }
        neighborCount = count;
    }
    {
        for (neighborIndex = 0; neighborIndex < neighborCount; neighborIndex++)
        {
            portalTable = graph->m_pusNavLinks;
            portal = navigationRecord(portalTable, portalIds[neighborIndex]);
            if ((portal->kind == 9) && (portal->first == node->key))
            {
                exitPoints = graph->points;
                exitPoint = navigationRecord(exitPoints, portal->second);
                for (goalIndex = 0; goalIndex < 64; goalIndex++)
                {
                    exitGoal = graph->m_nGoalList[goalIndex];
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
extern f32 func_8020C2E8_de(CNavData *, NavigationSearchNode *);
extern f32 func_802726F8_de(f32 *,f32 *);

static inline s32 navHasOpenNode(CNavData *graph, s32 status) {
    NavigationSearchNode *node = graph->nodes;
    while (node) {
        if (node->open == status) return 1;
        node = node->next;
    }
    return 0;
}
static inline NavigationSearchNode *navFindNode(CNavData *graph, s32 key) {
    NavigationSearchNode *node = graph->nodes;
    while (node) {
        if (node->key == key) return node;
        node = node->next;
    }
    return 0;
}
static inline s32 navCollectNeighbors(CNavData *graph, NavigationSearchNode *node,s32 *out,s32 *ids) {
    s32 key = node->key, index = 0, count = 0;
    s32 *portalOut = ids, *neighborOut = out;
    NavigationBuffer *links;
    NavigationPortal *portal;
        if (graph->m_nNavLinks > 0) {

            do {
                links = graph->m_pusNavLinks;
                portal=navigationRecord(links,index);
                if (portal->first == key) {
                    count += 1;
                    *neighborOut = portal->second;
                    *portalOut = index;
                    portalOut++;
                    neighborOut++;
                }
                if (portal->second == key) {
                    count += 1;
                    *neighborOut = portal->first;
                    *portalOut = index;
                    portalOut++;
                    neighborOut++;
                }
                index += 1;
            } while (index < graph->m_nNavLinks);
        }
    return count;
}
/* 250/253 words (32 aligned edits); remaining: loop.c hoists 0.0f out of the outer loop (f20/f21 swap), the -1 fill constant and the neighbor-collect setup order; the 10/11 skips fill no likely slots. */
void Nav_SearchPath(CNavData *graph, NavigationSearchNode *start) {
    s32 neighbors[64];
    s32 portals[64];
    s32 *neighborBase;
    NavigationPoint *origin;
    NavigationPoint *destination;
    f32 sentinel;
    f32 initialEstimate;
    f32 estimate;
    f32 cost;
    f32 distance;
    f32 edgeCost;
    NavigationBuffer *pointTable;
    NavigationBuffer *linkTable;
    NavigationBuffer *neighborTable;
    s32 *portalOut;
    s32 *neighborOut;
    s32 neighborKey;
    s32 currentKey;
    s32 state;
    s32 index;
    s32 byteOffset;
    s32 count;
    const s32 open = 1;
    s32 reversible;
    u8 edgeKind;
    s32 kind;
    NavigationPortal *portal;
    NavigationSearchNode *current;
    NavigationSearchNode *node;
    NavigationSearchNode *best;
    f32 minimum;
    NavigationSearchNode *nodeList;
    NavigationSearchNode *next;

    start->cost = 0.0f;
    initialEstimate = func_8020C2E8_de(graph,start);
    sentinel = D_800C1D80_de;
    neighborBase=neighbors;
    start->estimate = initialEstimate;
    start->parent = 0;
    start->open=open;
    start->total = (start->cost + initialEstimate);
    while (navHasOpenNode(graph, open)) {
        node = graph->nodes;
        best = 0;
        minimum = D_800C1D84_de;
        while (node) {
            if (node->open == open) {
                if (node->total < minimum) {
                    best = node;
                    minimum = node->total;
                } else if (minimum == sentinel) {
                    best = node;
                    minimum = node->total;
                }
            }
            node = node->next;
        }
        if (best) best->open = 0;
        current = best;
        pointTable = graph->points;
        currentKey = current->key;
        origin=navigationRecord(pointTable,currentKey);
        if (current->goal != 0) {
            graph->result = currentKey;
            return;
        }
        index = 0;
        portalOut=portals;
        neighborOut=neighborBase;
        do {
            *neighborOut = -1;
            *portalOut = -1;
            portalOut++;
            index += 1;
            neighborOut++;
        } while (index < 0x40);
count=navCollectNeighbors(graph,current,neighbors,portals);
        index = 0;
        if (count > 0) {
            byteOffset = 0;
            do {
                neighborTable = graph->points;
                neighborKey = *(s32 *)((u8 *)neighborBase + byteOffset);
                nodeList = graph->nodes;
                destination=navigationRecord(neighborTable,neighborKey);
                next=navFindNode(graph,neighborKey);
                linkTable = graph->m_pusNavLinks;
                portal=navigationRecord(linkTable,*(s32 *)((u8 *)portals + byteOffset));
                kind = portal->kind;
                switch (kind) {
                    case 1:
                    case 4:
                    case 7:
                        reversible = 1;
                        break;
                    default:
                        reversible = 0;
                        break;
                }
                if ((reversible != 0) || (portal->first == current->key)) {
                    edgeKind = portal->kind;
                    if (edgeKind != 0xA) if (edgeKind != 0xB) {
                        if (edgeKind == 9) {
                            distance = 0.0f;
                        } else {
                            distance = func_802726F8_de(&destination->position.x,&origin->position.x);
                        }
                        edgeCost = distance + next->extra;
                        if (navigation_point_flags(destination) & 0x400) {
                            edgeCost += D_800C1D88_de;
                        }
                        if (edgeCost < 0.0f) {
                            edgeCost = 0.0f;
                        }
                        state = next->open;
                        cost = current->cost + edgeCost;
                        if (((state ^ 2) == 0) || ((state ^ 1) == 0)) {
                            if (!(next->cost <= cost)) {
                                goto update_neighbor;
                            }
                        } else {
update_neighbor:
                            next->parent = current;
                            next->cost = cost;
                            estimate = func_8020C2E8_de(graph, next);
                            next->estimate = estimate;
                            next->total = (next->cost + estimate);
                            if ((next->open ^ 2) == 0) {
                                next->open = 0;
                            }
                            if ((next->open ^ open) != 0) {
                                next->open=open;
                            }
                        }
                    }
                }
                index += 1;
                byteOffset += 4;
            } while (index < count);
        }
        current->open = 2;
    }
}
#else
INCLUDE_ASM("span_1000", Nav_SearchPath);
#endif
