#include "COMMON/ACTOR_DEFINITION.H"
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
void *Scene_GetActorDefinition(void *arg0, s32 arg1);
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
        inst->variation = &g_defaultEffectDefinition;
    } else {
        inst->variation = Scene_GetActorDefinition(&g_world, rec->variation);
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
    v.y = inst->position.y + GameObject_GetActorHeight(inst) * 0.5f;
    v.z = inst->position.z;
    inst->light = D_800CBC90[0];
    inst->f1C4 = 0;
}

/* Draws a static object through its cached display list, building the cache on first use: emits a branch placeholder, loads the object's model, builds its rotation (the shared D_8013B190 angle for type 8), scale and position raised by its height offset into the current matrix slot, draws the model with its material through Geometry_DrawModelResource and SimpleInstance_SpawnModelEffect unless the type is 12, ends the list, patches the placeholder to skip past it and calls the cached list. The display list writes match only as block-scoped initialisers taking D_80110634++. */












extern void **func_8024F6EC_de(StaticObject *, s32);
extern void ScaleMatrixLocal(MatrixF *, f32, f32, f32);
extern s32 GraphU64_LimitVectorLength(CVector3 *, f32);
extern void TranslateMatrix(MatrixF *, f32, f32, f32);
extern void SwapMatrixUpForward(MatrixF *);
extern void GraphU64_ConvertMatrixToFixed(MatrixF *, char *);

extern void SimpleInstance_SpawnModelEffect(StaticObject *, void **);

void func_8024EB90_de(StaticObject *obj) {
    MatrixF matrix;
    void **resource;
    Gfx *branch;

    Geometry_InvalidateMaterialKeys();
    TextLoad_ResetTextureCache();
    if (obj->cached != 0) {
        gSPDisplayList(g_displayListCursor++, (unsigned int)obj->cached);
        return;
    }
    resource = func_8024F6EC_de(obj, obj->model);
    if (resource == 0) {
        return;
    }
    obj->cached = g_displayListCursor;
    gSPBranchList(g_displayListCursor++, 0);
    if (*obj->type == 8) {
        BuildYawMatrix(&matrix, g_world.elapsed);
    } else {
        BuildYawMatrix(&matrix, obj->angle);
    }
    ScaleMatrixLocal(&matrix, obj->scale, obj->scale, obj->scale);
    GraphU64_LimitVectorLength(&obj->position, 20000.0f);
    TranslateMatrix(&matrix, obj->position.x, obj->position.y + obj->height, obj->position.z);
    SwapMatrixUpForward(&matrix);
    GraphU64_ConvertMatrixToFixed(&matrix, obj->matrices[D_800D297C]);
    if (*obj->type != 12) {
        Geometry_DrawModelResource(resource, obj->matrices[D_800D297C], 0, obj->lights, 0, obj->material);
        SimpleInstance_SpawnModelEffect(obj, resource);
    }
    gSPEndDisplayList(g_displayListCursor++);
    gSPBranchList(obj->cached++, (unsigned int)g_displayListCursor);
    gSPDisplayList(g_displayListCursor++, (unsigned int)obj->cached);
    Cache_UnlockResource(0, resource);
}
