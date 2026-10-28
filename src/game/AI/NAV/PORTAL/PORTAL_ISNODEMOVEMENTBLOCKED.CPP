#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/NAVIGATION_GRAPH.H"
#include "COMMON/OBJECTLINKS14.H"
#include "TYPES.H"
#include "COMMON/SELF.H"
#include "AI/NAV/PORTAL_INITSEARCHNODE.H"
#include "COMMON/POOLED_FLOATS.H"

extern struct {s32 *unk0;} D_8013B364;


extern void Graphu64_SubtractVectors(CVector3 *out, void *arg1, void *arg2);

/** Return the index of the link joining two nodes, accepting reversed links of two-way types, or -1. */






static inline int isTwoWay(Link *link) {
    switch (link->type) {
    case 1:
    case 4:
    case 7:
        return 1;
    }
    return 0;
}

extern CollisionInfo8020CD74 D_80103FF0;

extern CollisionInfo8020CD74 D_80104050;

extern CollisionInfo8020CD74 D_80104070;

extern CollisionInfo8020CD74 D_801040D0;

extern s32 Insthdr_GetModelCollisionFlag1(void *);

extern s32 Insthdr_IsInactiveOrCollisionOption4(void *);

extern s32 Insthdr_GetModelCollisionFlag8(void *);

extern s32 Unicol_MoveActorWithCollision(Instance8020CD74 *, CVector3, CollisionInfo8020CD74 *);

/** Return an indexed record from the table referenced by the input. */
void *Portal_GetGraphPoint(void *table, int index) {
    char *base = *(char **)table;
    int stride = *(int *)base;
    return base + (index * stride + 8);
}

/** Return an indexed record from the table at object offset 0x8. */
void *Portal_GetStridedTableEntry(struct EntryList8020CCE8 *object, int index) {
    char *base = (char *)object->table;
    int stride = *(int *)base;
    return base + (index * stride + 8);
}

s32 Portal_IsReversibleLink(Link *link) {
    u8 linkTypeByte;
    s32 linkType;

    linkTypeByte = link->type;
    linkType = linkTypeByte;
    if (linkType == 4) {
        goto ret1;
    }
    if (linkType >= 5) {
        goto ge_5;
    }
    if (linkType == 1) {
        goto ret1;
    }
    goto ret0;
ge_5:
    if (linkType != 7) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}

void Portal_InitSearchNode(void *searchNode, s32 nodeKey)
{
  NavigationPoint *entry;
  NavigationSearchNode *node = searchNode;
  u16 flags;
  char *new_var;
  s32 *base;
  node->value = D_800C1D8C_de;
  node->key = nodeKey;
  node->state = -1;
  node->flags = 0;
  node->next = 0;
  base = D_8013B364.unk0;
  new_var = (char *)base + ((nodeKey * (*base)) + 8);
  entry = (NavigationPoint *)new_var;
  flags = navigation_point_flags(entry);
  if (flags & 2)
  {
    node->wait = D_800C1D90_de;
  }
  node->object = 0;
  node->ticks = 0;
  node->delay = 0;
  node->platform = 0;
  node->endpoint.x = 0;
  node->endpoint.y = 0;
  node->endpoint.z = 0;
  flags = navigation_point_flags(entry);
  if (flags & 0x40)
  {
    node->ticks = (Graphu64_NextRandom() % 5) + 5;
  }
  flags = navigation_point_flags(entry);
  if (flags & 0x80)
  {
    node->delay = (Graphu64_NextRandom() % 5) + 5;
  }
}

s32 Portal_FindNearestPointIndex(struct Obj8020BC50 *pointSet, void *point) {
    CVector3 offset;
    f32 distanceSq;
    f32 bestDistanceSq;
    void *items;
    s32 stride;
    s32 index;
    s32 bestIndex;

    bestIndex = -1;
    bestDistanceSq = 0.0f;
    index = 0;
    if (pointSet->count > 0) {
        do {
            items = pointSet->records;
            stride = *(s32 *)items;
            Graphu64_SubtractVectors(&offset, point, (char *)items + (index * stride + 8));
            distanceSq = (offset.x * offset.x) + (offset.y * offset.y) + (offset.z * offset.z);
            if ((bestIndex < 0) || (distanceSq < bestDistanceSq)) {
                bestIndex = index;
                bestDistanceSq = distanceSq;
            }
            index += 1;
        } while (index < pointSet->count);
    }
    return bestIndex;
}

int Portal_FindLinkIndex(Graph *graph, int from, int to) {
    int i;
    Link *link;

    for (i = 0; i < graph->count; i++) {
        link = (Link *)((char *)&graph->links->first + i * graph->links->stride);
        if (link->from == from && link->to == to) {
            return i;
        }
        if (link->to == from && link->from == to && isTwoWay(link)) {
            return i;
        }
        if (link->to == from && link->from == to && link->type == 6) {
            return i;
        }
    }
    return -1;
}

s32 Portal_CollectIncidentLinks(EntryList8020CCE8 *list, s32 value, s32 *partners, s32 *indices) {
    s32 i;
    s32 found;

    i = 0;
    found = 0;
    if (list->count > 0) {
        do {
            s32 product = i * list->table->field_0;
            s32 offset = product + 8;
            u16 *entry;
            u16 *other_entry;

            entry = (u16 *)((char *)list->table + offset);
            other_entry = entry;

            if (entry[0] == value) {
                found++;
                *partners = entry[1];
                *indices = i;
                indices++;
                partners++;
            }
            if (other_entry[1] == value) {
                found++;
                *partners = other_entry[0];
                *indices = i;
                indices++;
                partners++;
            }
            i++;
        } while (i < list->count);
    }
    return found;
}

s32 Portal_IsNodeMovementBlocked(s32 **arg0, Instance8020CD74 *arg1, s32 arg2) {
    CVector3 position;
    CollisionInfo8020CD74 collision;
    Instance8020CD74 saved;
    s32 first_test;
    s32 result;
    s32 *table;
    void *entry;

    table = *arg0;
    entry = (u8 *)table + ((arg2 * table[0]) + 8);
    position = *(CVector3 *)entry;
    position.y += *(&D_800C1D90_de + 1);

    if ((((LevelActor *)arg1)->kind == 1) && (((LevelActor *)arg1)->flags & 0x300000)) {
        collision = D_801040D0;
    } else {
        first_test = Insthdr_GetModelCollisionFlag1(arg1);
        if (Insthdr_IsInactiveOrCollisionOption4(arg1) == 0) {
            if (first_test != 0) {
                collision = D_80104050;
            } else {
                collision = D_801040D0;
            }
        } else if (Insthdr_GetModelCollisionFlag8(arg1) == 0) {
            collision = D_80104070;
        } else {
            collision = D_80103FF0;
        }
    }
    collision.w[0] = 0x4000;
    saved = *arg1;
    result = Unicol_MoveActorWithCollision(arg1, position, &collision);
    *arg1 = saved;
    return result == 0;
}

void *Portal_FindSearchNode(char *object, s32 current) {
    CNavData *graph = (CNavData *)object;
    NavigationSearchNode *record = graph->nodes;
    if (record != 0) {
        do {
            if (record->key == current) {
                return record;
            }
            record = record->next;
        } while (record != 0);
    }
    return 0;
}

void Portal_ResetSearchState(struct Obj8020BC50 *graph) {
    struct Node8020BC50 *node;
    f32 k;

    node = graph->nodes;
    if (node != 0) {
        k = (-1.0f);
        do {
            node->value = k;
            node->state = -1;
            node->field18 = 0;
            node->field1C = 0;
            node->field20 = 0;
            node->field24 = 0;
            node->field28 = 0;
            node->field2C = 0;
            node->field30 = 0;
            node = node->next;
        } while (node != 0);
    }
    graph->value = (-1.0f);
    graph->selected = -1;
}
