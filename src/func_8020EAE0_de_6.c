#include "span_1000/code_8020EAE0.h"
#include "common/draft_fields_func_8020F5A4_de.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"
#include "shared/level_actor.h"
#include "shared/navigation_graph.h"
#include "shared/route_chase_records.h"
#include "span_1000/code_80206258.h"
#include "span_1000/code_80208000.h"
#include "span_1000/code_802106E0.h"
#include "types.h"

extern s32 D_8013B364;

extern void func_8020D014_de(void *arg0);

extern void func_8020D1FC_de(s32);

extern s32 func_8020F150_de(void *arg0);

extern void func_8020D0CC_de(void *arg0, s32 arg1);

extern void *func_8020CFE0_de(char *, s32);

extern void func_8020D114_de(void *arg0, void *arg1, s32 arg2);

extern void *func_8020C994_de(void *, s32);

extern void func_8020D220_de(void *, s32);

extern s32 func_8022AAD4_de(Player *, s32);

s32 func_8020F2A8_de(CloseAttackBrain *arg0) {
    s32 data[30];
    s32 *cursor;
    s32 count;
    NavigationGraph *global;
    s32 value;
    s32 current;
    NavigationSearchNode *entry;

    global = (NavigationGraph *)&D_8013B364;
    func_8020D014_de(global);
    func_8020D1FC_de((s32)global);
    count = 29;
    cursor = &data[29];
    do {
        *cursor = 0;
        count--;
        cursor--;
    } while (count >= 0);
    data[0] = 0xBD7;
    if (func_8020F150_de(data) == 0) {
        arg0->routeObject = 0;
        arg0->routeState = -1;
        return 1;
    }
    value = -1;
    global->result = value;
    func_8020D0CC_de(global, arg0->route);
    current = global->result;
    if (current != value) {
        entry = func_8020CFE0_de(global, current);
        arg0->destination = global->result;
        arg0->routeObject = entry->object;
        func_8020D114_de(global, &arg0->routeNodes[0], 4);
    } else {
        arg0->routeObject = 0;
        arg0->routeState = current;
    }
    return 1;
}

s32 func_8020F388_de(void *arg0) {
    s32 data[30];
    s32 *cursor;
    s32 count;
    char *global;
    s32 value;
    s32 current;

    global = &D_8013B364;
    func_8020D014_de(global);
    func_8020D1FC_de((s32)global);
    count = 29;
    cursor = &data[29];
    do {
        *cursor = 0;
        count--;
        cursor--;
    } while (count >= 0);
    data[0] = 0x653;
    if (func_8020F150_de(data) == 0) {
        ((RouteChaseBot *)arg0)->target = 0;
        ((RouteChaseBot *)arg0)->targetId = -1;
        return 1;
    }
    value = -1;
    ((NavigationGraph *)global)->result = value;
    func_8020D0CC_de(global, ((RouteChaseBot *)arg0)->node);
    current = ((NavigationGraph *)global)->result;
    if (current != value) {
        ((RouteChaseBot *)arg0)->goal = current;
        func_8020D114_de(global, &((AiController *)arg0)->queue[0], 4);
    }
    return 1;
}

s32 func_8020F444_de(AiController *arg0) {
    NavigationGraph *global;
    NavigationGraph *scanbase;
    NavigationSearchNode *node;
    NavigationPoint *result;
    s32 count;
    s32 type;
    s32 value;
    s32 current;

    global = (NavigationGraph *)&D_8013B364;
    func_8020D014_de(global);
    func_8020D1FC_de((s32)global);
    count = 0;
    node = D_801372C8;
    scanbase = global;
    if (node != 0) {
        type = 0x64E;
        do {
            result = func_8020C994_de(scanbase, node->key);
            if ((result->flags & 1) &&
                result->objectId == type &&
                ((ActorMotionState *)node->object->motion)->mode == 0) {
                func_8020D220_de(scanbase, node->key);
                count += 1;
            }
            node = node->next;
        } while (node != 0);
    }
    if (count == 0) {
        arg0->routeObject = 0;
        arg0->routeState = -1;
        return 1;
    }
    value = -1;
    global->result = value;
    func_8020D0CC_de(global, arg0->current);
    current = global->result;
    if (current != value) {
        arg0->mode = current;
        func_8020D114_de(global, &arg0->queue, 4);
    }
    return 1;
}

/** Return whether arg0 is within the range [0x6BA, 0x6BC). */
s32 func_8020F55C_de(s32 arg0) {
    if (arg0 < 0x6BC) {
        if (arg0 >= 0x6BA) {
            return 1;
        }
    }
    return 0;
}

/** Return whether arg0 is within the range [0xBC4, 0xBCA). */
s32 func_8020F57C_de(s32 arg0) {
    if (arg0 < 0xBCA) {
        if (arg0 >= 0xBC4) {
            return 1;
        }
    }
    return 0;
}

/** Return the empty result used by callers at VRAM 0x8020F59C. */
int func_8020F59C_de(void) {
    return 0;
}

s32 func_8020F5A4_de(void **arg0) {
    s32 temp_v0;
    void *temp_a0;

    temp_a0 = *arg0;
    temp_v0 = func_8022AAD4_de(temp_a0, (s32) ((struct MeasuredRecAt62EV1 *)(temp_a0))->value);
    switch (temp_v0) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 7;
        default:
            return 4;
    }
}

s32 func_8020F614_de(void) {
    s32 *base;
    NavigationSearchNode *node;
    void *result;
    s32 count;

    base = &D_8013B364;
    node = ((NavigationGraph *)base)->nodes;
    count = 0;
    if (node != 0) {
        do {
            result = func_8020C994_de(base, node->key);
            if ((((NavigationNode *)result)->flags & 1) &&
                ((NavigationNode *)result)->reservedE == 0x64E &&
                (s8)((LevelActor *)node->object)->pad1A4 == 0) {
                func_8020D220_de(base, node->key);
                count += 1;
            }
            node = node->next;
        } while (node != 0);
    }
    return count;
}
