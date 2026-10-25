#include "COMMON/MODEL_RENDER.H"
#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/PROPGEOMETRY.H"
#include "WORLD_2/8024E914.H"
#include "SCENE/802508E0_9.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/FRUSTUM.H"
#include "gbi.h"
#include "TYPES.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "GAME/CODE_8027302C.H"
#include "SYSTEM/80296FF8_6.H"

#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/WORLD.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
void *func_8028CF6C_de(void *arg0, s32 arg1);
typedef struct SimpleRecordIn {
    s32 visBits;
    CVector3 position;
    f32 maxRadius;
    u16 type;
    u16 region;
    u16 flags;
    u16 id;
    u16 variation;
    s8 rotY;
    u8 pad;
} SimpleRecordIn;
typedef struct SimpleInstanceOut {
    s8 kind;
    u8 pad1[3];
    u16 type;
    u8 pad6[2];
    CVector3 position;
    void *region;
    void *variation;
    u8 pad1C[0x50 - 0x1C];
    s32 owner;
    s32 f54;
    s32 f58;
    s32 f5C;
    u8 pad60[0x174 - 0x60];
    f32 rotY;
    u8 pad178[4];
    CVector3 boxMin;
    CVector3 boxMax;
    f32 f194;
    s32 f198;
    u16 flags;
    u16 id;
    s32 f1A0;
    s32 f1A4;
    Shared_ParticleLighting light;
    s32 visBits;
    s32 f1C4;
} SimpleInstanceOut;
void World_InitSimpleInstance(SimpleInstanceOut *inst, SimpleRecordIn *rec, s32 owner, char *segments) {
    CVector3 v;
    inst->kind = 3;
    inst->type = rec->type;
    inst->visBits = rec->visBits;
    inst->position = rec->position;
    inst->position.y = inst->position.y + 10.24f;
    inst->rotY = rec->rotY * (3.1415927f / 127.0f);
    inst->f194 = 0.35f;
    inst->f198 = 0;
    inst->boxMin.x = rec->position.x - rec->maxRadius;
    inst->boxMin.y = rec->position.y - rec->maxRadius;
    inst->boxMin.z = rec->position.z - rec->maxRadius;
    inst->boxMax.x = rec->position.x + rec->maxRadius;
    inst->boxMax.y = rec->position.y + rec->maxRadius;
    inst->boxMax.z = rec->position.z + rec->maxRadius;
    inst->owner = owner;
    inst->f54 = -1;
    inst->f58 = 0;
    inst->f5C = 0;
    if (rec->variation == 0xFFFF) {
        inst->variation = &D_8011B388;
    } else {
        inst->variation = func_8028CF6C_de(&D_8011FE88, rec->variation);
    }
    if (rec->region == 0xFFFF) {
        inst->region = 0;
    } else {
        inst->region = segments + (rec->region << 5);
    }
    inst->flags = rec->flags | 2;
    inst->f1A0 = 0;
    inst->f1A4 = 0;
    inst->id = rec->id;
    v.x = inst->position.x;
    v.y = inst->position.y + Particle_GetActorHeight(inst) * 0.5f;
    v.z = inst->position.z;
    inst->light = D_800CBC90[0];
    inst->f1C4 = 0;
}

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
    System_ResetTextureCache();
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
        func_802736D4_de(&matrix, D_8011FE88.elapsed);
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
