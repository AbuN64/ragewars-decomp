#include "span_1000/code_80208000.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "shared/navigation_graph.h"
#include "span_1000/code_8020AF9C.h"
#include "TYPES.H"
#include "span_1000/code_802106E0.h"

extern struct {s32 *unk0;} D_8013B364;


extern void func_80271F68_de(Vec3 *out, void *arg1, void *arg2);

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

extern s32 func_8024DEE0_de(void *);

extern s32 func_8024DF5C_de(void *);

extern s32 func_8024DFA0_de(void *);

extern s32 func_80243A90_de(Instance8020CD74 *, Vec3, CollisionInfo8020CD74 *);

/** Return an indexed record from the table referenced by the input. */
void *func_8020C994_de(void *table, int index) {
    char *base = *(char **)table;
    int stride = *(int *)base;
    return base + (index * stride + 8);
}

/** Return an indexed record from the table at object offset 0x8. */
void *func_8020C9B0_de(struct EntryList8020CCE8 *object, int index) {
    char *base = (char *)object->table;
    int stride = *(int *)base;
    return base + (index * stride + 8);
}

s32 func_8020C9CC_de(Link *arg0) {
    u8 temp_v1;
    s32 val;

    temp_v1 = arg0->type;
    val = temp_v1;
    if (val == 4) {
        goto ret1;
    }
    if (val >= 5) {
        goto ge_5;
    }
    if (val == 1) {
        goto ret1;
    }
    goto ret0;
ge_5:
    if (val != 7) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}

void func_8020CA10_de(void *arg0, s32 arg1)
{
    extern f32 D_800C1D90_de;
  NavigationPoint *entry;
  NavigationSearchNode *node = arg0;
  u16 flags;
  char *new_var;
  s32 *base;
  node->value = D_800C1D8C_de;
  node->key = arg1;
  node->state = -1;
  node->flags = 0;
  node->next = 0;
  base = D_8013B364.unk0;
  new_var = (char *)base + ((arg1 * (*base)) + 8);
  entry = (NavigationPoint *)new_var;
  flags = entry->flags;
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
  flags = entry->flags;
  if (flags & 0x40)
  {
    node->ticks = (func_802744D4_de() % 5) + 5;
  }
  flags = entry->flags;
  if (flags & 0x80)
  {
    node->delay = (func_802744D4_de() % 5) + 5;
  }
}

s32 func_8020CB3C_de(struct Obj8020BC50 *arg0, void *arg1) {
    Vec3 sp10;
    f32 temp_f2;
    f32 var_f20;
    void *items;
    s32 stride;
    s32 var_s0;
    s32 var_s1;

    var_s1 = -1;
    var_f20 = 0.0f;
    var_s0 = 0;
    if (arg0->count > 0) {
        do {
            items = arg0->records;
            stride = *(s32 *)items;
            func_80271F68_de(&sp10, arg1, (char *)items + (var_s0 * stride + 8));
            temp_f2 = (sp10.x * sp10.x) + (sp10.y * sp10.y) + (sp10.z * sp10.z);
            if ((var_s1 < 0) || (temp_f2 < var_f20)) {
                var_s1 = var_s0;
                var_f20 = temp_f2;
            }
            var_s0 += 1;
        } while (var_s0 < arg0->count);
    }
    return var_s1;
}

int func_8020CC0C_de(Graph *graph, int from, int to) {
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

s32 func_8020CCE8_de(EntryList8020CCE8 *list, s32 value, s32 *partners, s32 *indices) {
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

s32 func_8020CD74_de(s32 **arg0, Instance8020CD74 *arg1, s32 arg2) {
    extern f32 D_800C1D90_de[];
    Vec3 position;
    CollisionInfo8020CD74 collision;
    Instance8020CD74 saved;
    s32 first_test;
    s32 result;
    s32 *table;
    void *entry;

    table = *arg0;
    entry = (u8 *)table + ((arg2 * table[0]) + 8);
    position = *(Vec3 *)entry;
    position.y += D_800C1D90_de[1];

    if ((((LevelActor *)arg1)->kind == 1) && (((LevelActor *)arg1)->flags & 0x300000)) {
        collision = D_801040D0;
    } else {
        first_test = func_8024DEE0_de(arg1);
        if (func_8024DF5C_de(arg1) == 0) {
            if (first_test != 0) {
                collision = D_80104050;
            } else {
                collision = D_801040D0;
            }
        } else if (func_8024DFA0_de(arg1) == 0) {
            collision = D_80104070;
        } else {
            collision = D_80103FF0;
        }
    }
    collision.w[0] = 0x4000;
    saved = *arg1;
    result = func_80243A90_de(arg1, position, &collision);
    *arg1 = saved;
    return result == 0;
}

void *func_8020CFE0_de(char *object, s32 arg1) {
    NavigationGraph *graph = (NavigationGraph *)object;
    NavigationSearchNode *record = graph->nodes;
    if (record != 0) {
        do {
            if (record->key == arg1) {
                return record;
            }
            record = record->next;
        } while (record != 0);
    }
    return 0;
}

void func_8020D014_de(struct Obj8020BC50 *arg0) {
    struct Node8020BC50 *var_v0;
    f32 k;

    var_v0 = arg0->nodes;
    if (var_v0 != 0) {
        k = (-1.0f);
        do {
            var_v0->value = k;
            var_v0->state = -1;
            var_v0->field18 = 0;
            var_v0->field1C = 0;
            var_v0->field20 = 0;
            var_v0->field24 = 0;
            var_v0->field28 = 0;
            var_v0->field2C = 0;
            var_v0->field30 = 0;
            var_v0 = var_v0->next;
        } while (var_v0 != 0);
    }
    arg0->value = (-1.0f);
    arg0->selected = -1;
}
