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

s32 func_8020B95C_de(CNavData *graph, s32 arg1, s32 arg2, s32 *arg3, s32 arg4) {
    NavigationPoint *point;
    NavigationBuffer *points;
    NavigationBuffer *temp_v1_2;
    s32 *var_a3;
    s32 i;
    s32 var_s4;
    s32 j;
    s32 k;
    s32 var_v0;
    s32 var_v0_2;
    s32 kind;
    s32 temp_a0_2;
    NavigationPortal *temp_v1_3;

    if (arg2 != -1) {
        points = graph->points;
        point = navigationRecord(points, arg2);
    } else {
        point = NULL;
    }
    k = 0;
    var_s4 = 0;
    if (graph->m_nNavLinks > 0) {
        s32 reversibleKind4 = 4;
        s32 reversibleKind1 = 1;
        s32 reversibleKind7 = 7;
        s32 noRoom = -1;
        s32 forwardExcludedKind = 6;
        var_a3 = arg3;
        do {
            temp_v1_2 = graph->m_pusNavLinks;
            temp_v1_3 = navigationRecord(temp_v1_2, k);
            if (arg4 != 0) {
                if (temp_v1_3->second == arg1) {
                    var_s4 += 1;
                    *var_a3 = (s32) temp_v1_3->first;
                    var_a3 += 1;
                }
                if (temp_v1_3->first == arg1) {
                    kind = temp_v1_3->kind;
                    if (kind != reversibleKind4) {
                        if ((s32) kind < 5) {
                            var_v0 = 0;
                            if (kind != reversibleKind1) {

                            } else {
                                goto block_14;
                            }
                        } else {
                            var_v0 = 0;
                            if (kind == reversibleKind7) {
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
                if ((arg2 != noRoom) && (temp_v1_3->first == arg1) && (temp_v1_3->second == arg2) && (point != NULL) && (navigation_point_flags(point) & 2)) {
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
            k += 1;
        } while (k < graph->m_nNavLinks);
    }
    if (arg2 == -1) return var_s4;
    if (point != 0) {
            for (j = 0; j < var_s4 - 1; j++) {
                for (i = j + 1; i < var_s4; i++) {
                    NavigationBuffer *table = graph->points;
                    s32 firstIndex = arg3[j] * table->stride;
                    s32 secondIndex = arg3[i] * table->stride;
                    void *first = table->data + firstIndex;
                    void *other = table->data + secondIndex;
                    f32 distance = func_802726BC_de(&point->position.x, first);
                    if (func_802726BC_de(&point->position.x, other) < distance) {
                        s32 saved = arg3[j];
                        arg3[j] = arg3[i];
                        arg3[i] = saved;
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
    Nav_SetPickupGoalWeights(owner);
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

extern f32 D_800C1D70_de;
s32 Nav_SearchPortalRoute(CNavData *, s32, s32, u8, s32, f32 *, f32);
/* Collects the nodes linked to key, with the link index of each, into out/edges; returns how many. */
static __inline__ s32 navigationNeighbors(CNavData *graph, s32 key, s32 *out, s32 *edges) {
    s32 i;
    s32 count = 0;
    for (i = 0; i < graph->m_nNavLinks; i++) {
        NavigationPortal *portal = navigationRecord(graph->m_pusNavLinks, i);
        if (portal->first == key) {
            out[count] = portal->second;
            edges[count] = i;
            count++;
        }
        if (portal->second == key) {
            out[count] = portal->first;
            edges[count] = i;
            count++;
        }
    }
    return count;
}
/* Returns startNode when one of its own links has portalKind, else the portal node the nearest
 * neighbor route reaches within maxDepth links (-1 when none). */
s32 Nav_FindPortalRoute(CNavData *graph, s32 startNode, u8 portalKind, s32 maxDepth) {
    s32 neighborNodes[64];
    s32 neighborLinks[64];
    f32 distance;
    f32 *origin;
    f32 bestDistance;
    s32 foundNode;
    s32 result;
    s32 index;
    s32 neighborCount;
    NavigationPortal *portal;

    result = -1;
    bestDistance = D_800C1D70_de;
    for (index = 0; index < graph->m_nNavLinks; index++) {
        portal = navigationRecord(graph->m_pusNavLinks, index);
        if (portal->first == startNode && portal->kind == portalKind) return startNode;
    }
    origin = navigationRecord(graph->points, startNode);
    neighborCount = navigationNeighbors(graph, startNode, neighborNodes, neighborLinks);
    for (index = 0; index < neighborCount; index++) {
        distance = func_802726BC_de(origin, navigationRecord(graph->points, neighborNodes[index]));
        foundNode = Nav_SearchPortalRoute(graph, startNode, neighborNodes[index], portalKind, maxDepth - 1, &distance, bestDistance);
        if (foundNode != -1) {
            bestDistance = distance;
            result = foundNode;
        }
    }
    return result;
}

extern f32 D_800C1D74_de;
/* Depth-limited search from currentNode (entered from previousNode): returns currentNode when one of its links
 * has portalKind, else the portal node of the shortest route under distanceLimit (-1 when none); stores that
 * route's length in *routeDistance. */
s32 Nav_SearchPortalRoute(CNavData *graph, s32 previousNode, s32 currentNode, u8 portalKind, s32 remainingDepth, f32 *routeDistance, f32 distanceLimit) {
    s32 neighborNodes[64];
    s32 neighborLinks[64];
    f32 candidateDistance;
    f32 *previousPosition;
    f32 bestDistance;
    s32 result;
    s32 index;
    s32 neighborCount;
    s32 portalNode;
    NavigationPortal *portal;

    bestDistance = D_800C1D74_de;
    result = -1;
    for (index = 0; index < graph->m_nNavLinks; index++) {
        portal = navigationRecord(graph->m_pusNavLinks, index);
        if (portal->first == currentNode && portal->kind == portalKind) return currentNode;
    }
    if (remainingDepth == 0) return -1;
    previousPosition = navigationRecord(graph->points, previousNode);
    neighborCount = navigationNeighbors(graph, previousNode, neighborNodes, neighborLinks);
    for (index = 0; index < neighborCount; index++) {
        f32 *point = navigationRecord(graph->points, neighborNodes[index]);
        if (point != previousPosition) {
            candidateDistance = *routeDistance + func_802726BC_de(previousPosition, point);
            if (candidateDistance < distanceLimit) {
                portalNode = Nav_SearchPortalRoute(graph, currentNode, neighborNodes[index], portalKind, remainingDepth - 1, &candidateDistance, distanceLimit);
            } else {
                portalNode = -1;
            }
            if (portalNode != -1 && candidateDistance < bestDistance) {
                bestDistance = candidateDistance;
                result = portalNode;
            }
        }
    }
    if (bestDistance < distanceLimit) {
        *routeDistance = bestDistance;
    }
    return result;
}

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
/* 29/253 aligned edits; remaining: floating zero lifetime, invalid-index fill and neighbor-collection setup. */
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
        for (index = 0, byteOffset = 0; index < count; index++, byteOffset += 4) {
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
            if (reversible == 0 && portal->first != current->key) continue;
            edgeKind = portal->kind;
            if (edgeKind == 0xA) continue;
            if (edgeKind == 0xB) continue;
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
        current->open = 2;
    }
}
#else
INCLUDE_ASM("span_1000", Nav_SearchPath);
#endif
