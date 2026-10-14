#include "span_1000/code_8026AC38.h"
#include "span_1000/code_80286050.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"



/* Draws a scene through cached display lists: loads the scene if needed (returning if that fails), calls the model's base list, and on first use records two lists in the frame's command stream, one for objects without flag 4 and one for objects with it, each drawn through func_802504B0_de inside a func_8026D980_de pass and preceded by a branch past its end; finally calls the first cached list. */






extern Gfx *D_80110634;
extern void func_80253908_de(s32 heap);
extern void func_80288938_de(Scene_func_80288EA8_de *scene);
extern void *func_8028FDB4_de(void *table, s32 index);


extern void func_802504B0_de(Object_func_80288EA8_de *object, void *camera);

void func_80288EA8_de(Scene_func_80288EA8_de *scene, void *camera) {
    Object_func_80288EA8_de **objects;
    Object_func_80288EA8_de *object;
    Gfx *branch;
    s32 pass;

    if (scene->loaded == 0) {
        func_80253908_de(0);
        func_80288938_de(scene);
        if (scene->loaded == 0) {
            return;
        }
    }
    gSPDisplayList(D_80110634++, (unsigned int)func_8028FDB4_de(scene->model, 2));
    if (scene->lists[0] == 0) {
        for (pass = 0; pass < 2; pass++) {
            scene->lists[pass] = D_80110634;
            gSPBranchList(D_80110634++, 0);
            func_8026D980_de();
            objects = func_8028FDB4_de(scene->model, 1);
            while (*objects != 0) {
                object = *objects++;
                switch (pass) {
                case 0:
                    if (!(object->flags & 4)) {
                        func_802504B0_de(object, camera);
                    }
                    break;
                case 1:
                    if (object->flags & 4) {
                        func_802504B0_de(object, camera);
                    }
                    break;
                }
            }
            func_8026D9D0_de();
            gSPEndDisplayList(D_80110634++);
            gSPBranchList(scene->lists[pass]++, (unsigned int)D_80110634);
        }
    }
    gSPDisplayList(D_80110634++, (unsigned int)scene->lists[0]);
}
