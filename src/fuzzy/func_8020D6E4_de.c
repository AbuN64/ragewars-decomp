#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "shared/func_8020EF80_eu_x_closed.h"
#include "span_1000/code_8020D370.h"
#include "span_C76B0/data.h"
#include "types.h"

extern s32 func_8020CC0C_de(PickupGoalNodeList *, s32, s32);
extern Vec3 *func_8020C994_de(PickupGoalNodeList *, s32);

s32 func_8020D6E4_de(Selection_func_8020D4AC_de *sel) {
    Vec3 avg;
    Shared_PickupGoalNode *info;
    Vec3 *node;
    s32 next;
    s32 best;
    s32 i;
    f32 inv;

    next = -1;
    i = 0;
    best = sel->objectCount;
    if (best > 0) {
        for (; i < sel->objectCount; i++) {
            if (0.0f < sel->stages[i].distance) {
                best = i;
            }
        }
    }
    if (best != sel->objectCount) {
        if (sel->stages[best].to >= 0) {
            for (i = 0; i < 3; i++) {
                if (sel->ids[i] == sel->id) {
                    next = sel->ids[i + 1];
                    break;
                }
            }
            if (next != -1 && func_8020CC0C_de(&D_8013B364, sel->id, sel->stages[best].to) != -1 &&
                func_8020CC0C_de(&D_8013B364, next, sel->stages[best].to) != -1) {
                i = 3;
                do {
                    if (sel->ids[i - 1] == sel->id) {
                        sel->ids[i] = sel->stages[best].to;
                        break;
                    }
                    sel->ids[i] = sel->ids[i - 1];
                    i--;
                } while (i > 0);
                avg.z = 0.0f;
                avg.y = 0.0f;
                avg.x = 0.0f;
                for (i = 0; i < sel->objectCount; i++) {
                    avg.x += sel->dirs[i].x;
                    avg.y += sel->dirs[i].y;
                    avg.z += sel->dirs[i].z;
                }
                inv = D_800C1DB4_de / (f32)sel->objectCount;
                avg.x = avg.x * inv;
                avg.y = avg.y * inv;
                avg.z = avg.z * inv;
                info = func_8020CFE0_de(&D_8013B364, sel->stages[best].to);
                avg.x = avg.x * (f32)info->unknown14[0];
                avg.y = avg.y * (f32)info->unknown14[0];
                avg.z = avg.z * (f32)info->unknown14[0];
                node = func_8020C994_de(&D_8013B364, sel->stages[best].to);
                sel->result.x = node->x + avg.x;
                sel->result.y = node->y + avg.y;
                sel->result.z = node->z + avg.z;
                sel->stageCount++;
                sel->lastNode = sel->stages[best].to;
                return 0;
            }
        }
    }
    sel->failed = 0;
    sel->stageCount += 0x14;
    return 1;
}
