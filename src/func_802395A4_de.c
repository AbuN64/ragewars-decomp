#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802393F4.h"
#include "types.h"
#include "shared/menu_match_globals.h"



extern s32 func_8027254C_de(f32 *arg0, f32 arg1);
extern void func_80271F68_de(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2);







void *func_802395A4_de(void *arg0, Vec3 *arg1) {
    Vec3 position;
    Shared_func_80234FDC_S2 *node;
    void *bestNode;
    f32 bestDist;
    f32 distSq;

    func_8027254C_de(&arg1->x, 20000.0f);
    if (((MenuMatchGlobals *)arg0)->useFallbackCamera != 0) {
        return &((MenuMatchGlobals *)arg0)->fallbackCamera;
    }
    node = ((MenuMatchGlobals *)arg0)->cameras;
    bestDist = D_800C3548_de;
    bestNode = 0;
    if (node != 0) {
        do {
            func_80271F68_de(&position, arg1, &node->position);
            distSq = (position.x * position.x) +
                     (position.y * position.y) +
                     (position.z * position.z);
            if (distSq < bestDist) {
                bestNode = node;
                bestDist = distSq;
            }
            node = node->next;
        } while (node != 0);
    }
    if (bestNode == 0) {
        return &((MenuMatchGlobals *)arg0)->fallbackCamera;
    }
    return bestNode;
}
