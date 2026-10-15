#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024E914.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_80296014.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "span_1000/code_8022F3E8.h"
#include "span_1000/code_80291054.h"


/* Draws a static object through its cached display list, building the cache on first use: emits a branch placeholder, loads the object's model, builds its rotation (the shared D_8013B190 angle for type 8), scale and position raised by its height offset into the current matrix slot, draws the model with its material through func_8026DA4C_de and func_8024ED90_de unless the type is 12, ends the list, patches the placeholder to skip past it and calls the cached list. The display list writes match only as block-scoped initialisers taking D_80110634++. */












extern void **func_8024F6EC_de(StaticObject *, s32);
extern void func_8027347C_de(MatrixF *, f32, f32, f32);
extern s32 func_8027254C_de(Vec3 *, f32);
extern void func_80273448_de(MatrixF *, f32, f32, f32);
extern void func_80273D6C_de(MatrixF *);
extern void func_8027027C_de(MatrixF *, char *);
extern void func_8026DA4C_de(void **, char *, s32, char *, void *, s32);
extern void func_8024ED90_de(StaticObject *, void **);
extern void func_80253754_de(s32, void **);

void func_8024EB90_de(StaticObject *obj) {
    MatrixF matrix;
    void **resource;
    Gfx *branch;

    func_8026D8F8_de();
    func_80295FF4_de();
    if (obj->cached != 0) {
        gSPDisplayList(D_80110634++, (unsigned int)obj->cached);
        return;
    }
    resource = func_8024F6EC_de(obj, obj->model);
    if (resource == 0) {
        return;
    }
    obj->cached = D_80110634;
    gSPBranchList(D_80110634++, 0);
    if (*obj->type == 8) {
        func_802736D4_de(&matrix, D_8013B190);
    } else {
        func_802736D4_de(&matrix, obj->angle);
    }
    func_8027347C_de(&matrix, obj->scale, obj->scale, obj->scale);
    func_8027254C_de(&obj->position, 20000.0f);
    func_80273448_de(&matrix, obj->position.x, obj->position.y + obj->height, obj->position.z);
    func_80273D6C_de(&matrix);
    func_8027027C_de(&matrix, obj->matrices[D_800D297C]);
    if (*obj->type != 12) {
        func_8026DA4C_de(resource, obj->matrices[D_800D297C], 0, obj->lights, 0, obj->material);
        func_8024ED90_de(obj, resource);
    }
    gSPEndDisplayList(D_80110634++);
    gSPBranchList(obj->cached++, (unsigned int)D_80110634);
    gSPDisplayList(D_80110634++, (unsigned int)obj->cached);
    func_80253754_de(0, resource);
}
