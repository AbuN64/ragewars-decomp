#include "span_1000/code_80208000.h"
#include "shared/navigation_graph.h"
#include "shared/route_chase_records.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8020EAE0.h"
#include "types.h"

extern s32 D_8013B364;

extern void func_8020D014_de(void *arg0);
extern void func_8020D1FC_de(s32);
extern s32 func_8020F150_de(void *arg0);
extern void func_8020D0CC_de(void *arg0, s32 arg1);
extern void func_8020D114_de(void *arg0, void *arg1, s32 arg2);






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
