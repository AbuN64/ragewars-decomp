#include "COMMON/MODEL_RENDER.H"
#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/PROPGEOMETRY.H"
#include "SCENE/802508E0_9.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/FRUSTUM.H"
#include "gbi.h"
#include "TYPES.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "GAME/CODE_8027302C.H"
#include "SYSTEM/80296FF8_6.H"

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/WORLD.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
void *func_8028CF6C_de(void *arg0, s32 arg1);
void func_8024E990_de(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    ((s8 *) arg0)[0 / sizeof(s8)] = 3;
    ((u16 *) arg0)[4 / sizeof(u16)] = (u16) ((u16 *) arg1)[20 / sizeof(u16)];
    ((s32 *) arg0)[448 / sizeof(s32)] = (s32) ((s32 *) arg1)[0 / sizeof(s32)];
    ((f32 *) arg0)[8 / sizeof(f32)] = (f32) ((f32 *) arg1)[4 / sizeof(f32)];
    ((f32 *) arg0)[12 / sizeof(f32)] = (f32) ((f32 *) arg1)[8 / sizeof(f32)];
    ((f32 *) arg0)[16 / sizeof(f32)] = (f32) ((f32 *) arg1)[12 / sizeof(f32)];
    ((f32 *) arg0)[12 / sizeof(f32)] = (f32) (((f32 *) arg0)[12 / sizeof(f32)] + D_800C3D80_de);
    ((s32 *) arg0)[408 / sizeof(s32)] = 0;
    ((f32 *) arg0)[404 / sizeof(f32)] = (f32) D_800C3D88_de;
    ((f32 *) arg0)[372 / sizeof(f32)] = (f32) ((f32) ((s8 *) arg1)[30 / sizeof(s8)] * D_800C3D84_de);
    ((f32 *) arg0)[380 / sizeof(f32)] = (f32) (((f32 *) arg1)[4 / sizeof(f32)] - ((f32 *) arg1)[16 / sizeof(f32)]);
    ((f32 *) arg0)[384 / sizeof(f32)] = (f32) (((f32 *) arg1)[8 / sizeof(f32)] - ((f32 *) arg1)[16 / sizeof(f32)]);
    ((f32 *) arg0)[388 / sizeof(f32)] = (f32) (((f32 *) arg1)[12 / sizeof(f32)] - ((f32 *) arg1)[16 / sizeof(f32)]);
    ((f32 *) arg0)[392 / sizeof(f32)] = (f32) (((f32 *) arg1)[4 / sizeof(f32)] + ((f32 *) arg1)[16 / sizeof(f32)]);
    ((f32 *) arg0)[396 / sizeof(f32)] = (f32) (((f32 *) arg1)[8 / sizeof(f32)] + ((f32 *) arg1)[16 / sizeof(f32)]);
    ((s32 *) arg0)[80 / sizeof(s32)] = arg2;
    ((s32 *) arg0)[84 / sizeof(s32)] = -1;
    ((f32 *) arg0)[400 / sizeof(f32)] = (f32) (((f32 *) arg1)[12 / sizeof(f32)] + ((f32 *) arg1)[16 / sizeof(f32)]);
    ((s32 *) arg0)[88 / sizeof(s32)] = 0;
    ((s32 *) arg0)[92 / sizeof(s32)] = 0;
    if (((u16 *) arg1)[28 / sizeof(u16)] == 0xFFFF) {
        ((s8 **) arg0)[24 / sizeof(s8 *)] = &D_8011B388;
    } else {
        ((s8 **) arg0)[24 / sizeof(s8 *)] = func_8028CF6C_de(&D_8011FE88, (s32) ((u16 *) arg1)[28 / sizeof(u16)]);
    }
    if (((u16 *) arg1)[22 / sizeof(u16)] == 0xFFFF) {
        ((s32 *) arg0)[20 / sizeof(s32)] = 0;
    } else {
        ((s32 *) arg0)[20 / sizeof(s32)] = (s32) (arg3 + (((u16 *) arg1)[22 / sizeof(u16)] << 5));
    }
    ((s32 *) arg0)[416 / sizeof(s32)] = 0;
    ((s32 *) arg0)[420 / sizeof(s32)] = 0;
    ((s16 *) arg0)[412 / sizeof(s16)] = (s16) (((u16 *) arg1)[24 / sizeof(u16)] | 2);
    ((u16 *) arg0)[414 / sizeof(u16)] = (u16) ((u16 *) arg1)[26 / sizeof(u16)];
    Particle_GetActorHeight(arg0);
    ((s32 *) arg0)[424 / sizeof(s32)] = (s32) ((s32 *) D_800CBC90)[0 / sizeof(s32)];
    ((s32 *) arg0)[428 / sizeof(s32)] = (s32) ((s32 *) D_800CBC90)[4 / sizeof(s32)];
    ((s32 *) arg0)[432 / sizeof(s32)] = (s32) ((s32 *) D_800CBC90)[8 / sizeof(s32)];
    ((s32 *) arg0)[436 / sizeof(s32)] = (s32) ((s32 *) D_800CBC90)[12 / sizeof(s32)];
    ((s32 *) arg0)[440 / sizeof(s32)] = (s32) ((s32 *) D_800CBC90)[16 / sizeof(s32)];
    ((s32 *) arg0)[444 / sizeof(s32)] = (s32) ((s32 *) D_800CBC90)[20 / sizeof(s32)];
    ((s32 *) arg0)[452 / sizeof(s32)] = 0;
}
#else
INCLUDE_ASM("span_1000", func_8024E990_de);
#endif

/* Draws a static object through its cached display list, building the cache on first use: emits a branch placeholder, loads the object's model, builds its rotation (the shared D_8013B190 angle for type 8), scale and position raised by its height offset into the current matrix slot, draws the model with its material through func_8026DA4C_de and func_8024ED90_de unless the type is 12, ends the list, patches the placeholder to skip past it and calls the cached list. The display list writes match only as block-scoped initialisers taking D_80110634++. */












extern void **func_8024F6EC_de(StaticObject *, s32);
extern void func_8027347C_de(MatrixF *, f32, f32, f32);
extern s32 func_8027254C_de(CVector3 *, f32);
extern void func_80273448_de(MatrixF *, f32, f32, f32);
extern void func_80273D6C_de(MatrixF *);
extern void func_8027027C_de(MatrixF *, char *);

extern void func_8024ED90_de(StaticObject *, void **);

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
