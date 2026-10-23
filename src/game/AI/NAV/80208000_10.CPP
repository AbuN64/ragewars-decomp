#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/NAVIGATION_GRAPH.H"
#include "COMMON/OBJECTLINKS14.H"
#include "TYPES.H"
#include "AI/NAV/80208000_10.H"

/* Stores an id in the first free (-1) of the object's 64 id slots at 0x38 and flags the node with that
   id in the object's list at 0x24 as active. */




static inline Node *find_node(Obj_func_8020D220_de *obj, int id) {
    Node *node;

    for (node = obj->list; node != 0; node = node->next) {
        if (node->id == id) {
            return node;
        }
    }
    return 0;
}

void func_8020D220_de(Obj_func_8020D220_de *obj, int id) {
    int i;

    for (i = 0; i < 64; i++) {
        if (obj->ids[i] == -1) {
            obj->ids[i] = id;
            find_node(obj, id)->active = 1;
            return;
        }
    }
}

int func_8020D280_de(void *arg0) {
    NavigationSearchNode *node = arg0;
    node->open = 1;
    return 1;
}

void *func_8020D28C_de(void *arg0) {
    CNavData *graph = arg0;
    NavigationSearchNode *node;
    NavigationSearchNode *best;
    f32 best_value;

    node = graph->nodes;
    best_value = (-1.0f);
    best = 0;
    if (node != 0) {
        do {
            if (node->open == 1) {
                f32 value = node->total;
                if (value < best_value || best_value == (-1.0f)) {
                    best = node;
                    best_value = value;
                }
            }
            node = node->next;
        } while (node != 0);
    }
    if (best != 0) {
        best->open = 0;
    }
    return best;
}

/** Set the word at byte offset 0x28 to the state value two. */
void func_8020D2FC_de(void *object) {
    NavigationSearchNode *node = object;
    node->open = 2;
}

int func_8020D308_de(void *arg0) {
    NavigationSearchNode *node = arg0;
    return node->open == 1;
}

/** Report whether the word at object offset 0x28 equals two. */
int func_8020D318_de(void *arg0) {
    NavigationSearchNode *node = arg0;
    return node->open == 2;
}

s32 func_8020D328_de(CNavData *arg0) {
    CNavData *graph = arg0;
    NavigationSearchNode *record = graph->nodes;
    if (record != 0) {
        do {
            if (record->open == 1) {
                return 1;
            }
            record = record->next;
        } while (record != 0);
    }
    return 0;
}

/** Clear the word at offset 0x28. */
void func_8020D35C_de(void *arg0) {
    ObjRecAt28V2 *record = arg0;
    record->unk28 = 0;
}
