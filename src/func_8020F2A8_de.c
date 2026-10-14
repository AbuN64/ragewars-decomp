#include "span_1000/code_802106E0.h"
#include "shared/navigation_graph.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8020EAE0.h"
#include "types.h"

extern s32 D_8013B364;

extern void func_8020D014_de(void *arg0);
extern void func_8020D1FC_de(s32);
extern s32 func_8020F150_de(void *arg0);
extern void func_8020D0CC_de(void *arg0, s32 arg1);
extern void *func_8020CFE0_de(char *, s32);
extern void func_8020D114_de(void *arg0, void *arg1, s32 arg2);








s32 func_8020F2A8_de(void *arg0) {
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
        ((CloseAttackBrain *)arg0)->routeObject = 0;
        ((CloseAttackBrain *)arg0)->routeState = -1;
        return 1;
    }
    value = -1;
    global->result = value;
    func_8020D0CC_de(global, ((CloseAttackBrain *)arg0)->route);
    current = global->result;
    if (current != value) {
        entry = func_8020CFE0_de(global, current);
        ((CloseAttackBrain *)arg0)->destination = global->result;
        ((CloseAttackBrain *)arg0)->routeObject = entry->object;
        func_8020D114_de(global, &((CloseAttackBrain *)arg0)->routeNodes[0], 4);
    } else {
        ((CloseAttackBrain *)arg0)->routeObject = 0;
        ((CloseAttackBrain *)arg0)->routeState = current;
    }
    return 1;
}
