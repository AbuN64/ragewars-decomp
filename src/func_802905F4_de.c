#include "shared/gameplay_camera.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_8028FC98.h"
#include "types.h"




extern s32 D_800D15E0;

extern f32 D_800D15F0;
extern f32 D_800C53AC_de;



extern s32 func_80296B74_de(void *arg0, void *arg1);
extern void func_8024EB90_de(void *arg0);








void func_802905F4_de(char *arg0, char *arg1) {
    World_func_80290238_de *world = (void *)arg0;
    Shared_func_80234FDC_S2 *camera = (void *)arg1;
    Actor_func_80290238_de *entry;
    f32 value;
    f32 upper;
    f32 scale;
    f32 zero;

    func_8026D980_de();
    entry = world->head;
    if (entry != 0) {
        zero = 0.0f;
        upper = D_800C53A8_de;
        scale = D_800C53AC_de;
        do {
            if ((camera->clipBounds[1].x > entry->minX) &&
                (camera->clipBounds[0].x < entry->maxX) &&
                (camera->clipBounds[1].z > entry->minZ) &&
                (camera->clipBounds[0].z < entry->maxZ) &&
                (camera->clipBounds[1].y > entry->minY) &&
                (camera->clipBounds[0].y < entry->maxY) &&
                (func_80296B74_de(camera->clipPlanes, &entry->minX) != 0)) {
                value = entry->lifetime;
                D_800D15E0 = 0;
                if ((value > zero) && (value <= upper)) {
                    D_800D15E0 = 1;
                    D_800D15F0 = value * scale;
                }
                func_8024EB90_de(entry);
                D_800D15E0 = 0;
            }
            entry = entry->next;
        } while (entry != 0);
    }
    func_8026D9D0_de();
}
