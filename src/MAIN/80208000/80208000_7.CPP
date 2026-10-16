#include "span_1000/code_80208000.h"
#include "common/types_1dc8418c21db.h"
#include "shared/navigation_graph.h"
#include "span_1000/code_8020AF9C.h"
#include "stddef.h"
#include "TYPES.H"

f32 func_802726BC_de(f32 *a, f32 *b);

extern void func_8020D1FC_de(s32);


extern void func_8020D220_de(void *, s32);

extern s32 func_8020C5A0_de(Obj8020BC50 *, Node8020BC50 *);

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
    obj->selected = obj->result;
}
