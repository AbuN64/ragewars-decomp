#include "include_asm.h"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/LONE/D_800CD8D0.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LABEL.H"
#include "TYPES.H"
#include "FRONTEND/FRONTEND_DRAWMODELPREVIEW.H"

#include "COMMON/WORLD.H"
#include "COMMON/SCENERECAT10C0.H"
#include "COMMON/ACTOR_DEFINITION.H"
extern void *SetN64_GetDirectoryEntry(void *, void *, s32);
extern void *SetN64_LocatePackSection(void *, void *, s32, s32 *);
extern void *Scene_GetActorDefinition(void *, u16);
extern void Gobjinst_LoadModel(void *, void *, void *, s32);
typedef struct FrontendModelHeader {
    u8 prefix[0x1C];
    u16 definitionIndex;
} FrontendModelHeader;
/* Scans the world's preview model id table for entries equal to id. For each one it loads the model's index and info
 * resources; when the model's actor definition has the expected character and the preview's kind, it binds model i to
 * the preview (Gobjinst_LoadModel with extra) and stops. */
void Preview_SelectMatchingPreviewModel(Obj8041CAD8 *preview, s32 id, s32 extra, s32 expected) {
    Obj8041CAD8At190 *previewState = &preview->sub190;
    Shared_World *scene = &g_world;
    struct TableRecAt8 *list = scene->modelIds;
    s32 count = list->count;
    u16 *entries = list->entries;
    s32 i;
    s32 found = 0;
    void *modelName;
    void **indexResource;
    void **modelResource;
    void *modelData;
    ActorDefinitionHeader *definition;
    s32 modelSize;

    for (i = 0; i < count && !found; i++) {
        Shared_World *world = &g_world;

        if (entries[i] == id) {
            modelName = SetN64_GetDirectoryEntry(world->indexedDirectory, (void *)world->indexedBank, i);
            indexResource = Cache_RequestResource(0, (u32)modelName, (u32)modelName, 0x18, 0, 0, 0, "anim object index", 1);
            if (indexResource != 0) {
                modelData = SetN64_LocatePackSection(*indexResource, modelName, 0, &modelSize);
                modelResource = Cache_RequestResource(0, (u32)modelData, (u32)modelData, modelSize, 0, 0, 0, "anim object info", 1);
                if (modelResource != 0) {
                    definition = Scene_GetActorDefinition(world, ((FrontendModelHeader *)SetN64_GetPackSection(*modelResource, 0))->definitionIndex);
                    if (definition->character == expected && definition->kind == preview->unk0) {
                        previewState->modelIndex = i;
                        previewState->type = id;
                        Gobjinst_LoadModel(previewState, world->indexedDirectory, (void *)world->indexedBank, extra);
                        found = 1;
                    }
                    Cache_UnlockResource(0, (struct Node80253610 *)modelResource);
                }
                Cache_UnlockResource(0, (struct Node80253610 *)indexResource);
            }
        }
    }
}

#ifdef NON_MATCHING
/* The names m2c output assumes (its valid-syntax macros), so a draft compiles on its own. */
#ifndef NULL
#define NULL ((void *)0)
#endif
#define M2C_FIELD(base, type, offset) (*(type)((char *)(base) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_ERROR(desc) (0)
#define M2C_TRAP_IF(cond) (0)
#define M2C_BREAK(...) (0)
#define M2C_SYNC(...) (0)
#define M2C_DCACHE_CLEAN(addr) (0)
#define M2C_DCACHE_INVALIDATE(addr) (0)
#define M2C_DCACHE_CLEAN_INVALIDATE(addr) (0)
#define M2C_DCACHE_BLOCK_SETZERO(addr) (0)
#define M2C_DCACHE_BLOCK_SETZERO_LOCKED(addr) (0)
#define M2C_ICACHE_INVALIDATE(addr) (0)
#define M2C_PREFETCH(addr) (0)
#define M2C_PREFETCH_STORE(addr) (0)
#define GLUE_F64(a, b) (0.0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#undef F3DEX_GBI
#undef F3D_GBI
#define F3DEX_GBI_2
#endif
#include "COMMON/GFX.H"
#include "COMMON/GLOBALS.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/TRIPLE.H"
#include "MENU/GFX/COMBINE_CONFIGUREPRIMITIVERENDERFLAGS.H"
#include "TYPES.H"
#include "gbi.h"
#include "particle/80271B18_3.H"
s32 func_80246E44_de(void *);
s32 Gobjinst_DrawVisibleCachedActor(void *, void *);
s32 Gobjinst_RotatePoseMatrixBuffers(void *);
s32 PitchMatrixLocal(void *, f32);
extern MenuModelScreen D_80141008[];
void Preview_DrawModelPreview(Obj8041CAD8 *self) {
    CVector3 local10;
    CVector3 local20;
    MenuModelScreen *view;
    Obj8041CAD8At190 *draw;
    s32 saved;
    view = D_80141008;
    draw = &self->sub190;
    if (self->unk478 != 0) {
        saved = D_800CC380;
        D_800CC380 = 0;
        {
            Gfx *g = g_displayListCursor++;
            u32 address = (u32)(D_800D297C << 6);
            address += 0x380;
            address += (u32)view;
            gSPMatrix(g, (u32)address, G_MTX_LOAD | G_MTX_PROJECTION);
        }
        local10 = self->unk48C;
        Graphu64_TransformPoint(&view->camera, &local10, &local20);
        if (func_8025477C_de() == 0) {
            Cache_SetResourceActivityState(1);
        }
        Combine_ConfigurePrimitiveRenderFlags(0x33335);
        gDPPipeSync(g_displayListCursor++);
        gDPSetCycleType(g_displayListCursor++, G_CYC_2CYCLE);
        gDPSetTexturePersp(g_displayListCursor++, G_TP_PERSP);
        gDPSetTextureFilter(g_displayListCursor++, G_TF_BILERP);
        Geometry_InitializeModelRenderState();
        draw->unk8 = local20;
        draw->unk1C4 = local20;
        Gobjinst_RotatePoseMatrixBuffers(draw);
        draw->unk8 = local20;
        draw->unk1C4 = local20;
        if (self->unk49C != 0 || draw->unk10E == 0) {
            func_80246E44_de(draw);
            if (self->unk4A0 != 0) {
                PitchMatrixLocal(&draw->unk74, (f32)self->unk4A0 * 0.017453294f);
            }
        }
        draw->unk6C = self->unk498 * 0.017453294f;
        draw->unk8 = local20;
        draw->unk1C4 = local20;
        Geometry_BeginModelBatch();
        Gobjinst_DrawVisibleCachedActor(draw, view);
        draw->unk140 = D_800DF520;
        draw->unk158 = D_800DF520;
        Geometry_FlushModelBatch();
        D_800CC380 = saved;
    }
}

#include "COMMON/WORLD.H"
#include "RESMGR/802A0888.H"
extern void *Scene_FindActorDefinition(void *, s32, s32, void *);
extern void Gobjinst_InitializeActor(void *, s32, s32, s32, void *, s32, s32, f32, CVector3, s32, CVector3, CVector3, s32);
extern void Gobjinst_DispatchActorTypeUpdate();
/* Starts a menu model preview: loads the projection, spawns the model through Scene_FindActorDefinition, keeps a copy
 * of its record, places it scaled to the screen and runs its first update. Returns the copy, or 0 when no model. */
void *Preview_InitModelPreview(Obj8041CAD8 *self, s32 id, s32 modelKind, s32 previewModelId, s32 extra, CVector3 position, CVector3 facing,
                       f32 scale, s32 pitchDegrees) {
    CVector3 scales;
    CVector3 local60;
    CVector3 local70;
    CVector3 local80;
    MenuModelScreen *view;
    Obj8041CAD8At190 *draw;
    Gfx *g;
    f32 ratio;
    Ret8028CFA0 *source;
    XPlus_FillMemory(&local60, 0, sizeof(local60));
    g = g_displayListCursor++;
    view = D_80141008;
    gSPMatrix(g, &view->matrices[D_800D297C], G_MTX_LOAD | G_MTX_PROJECTION);
    self->unk49C = 1;
    self->unk4A0 = pitchDegrees;
    draw = &self->sub190;
    source = Scene_FindActorDefinition(&g_world, id, modelKind, g);
    if (source == 0) {
        self->unk478 = 0;
        return 0;
    }
    self->unk498 = scale;
    self->unk0 = id;
    self->unk478 = 1;
    self->copy4 = *source;
    self->unk480 = position;
    self->unk48C = facing;
    self->copy4.unk0 = 0;
    self->copy4.unk4 = 0;
    self->copy4.unk14 = 0;
    self->copy4.unk18 = 0;
    self->copy4.unk1C = 0;
    self->copy4.unk8 = 10240.0f;
    ratio = view->width / (f32)D_800E28D0;
    scales.x = self->unk480.x * ratio;
    scales.z = self->unk480.z * ratio;
    scales.y = self->unk480.y * (view->height / (f32)D_800E28D4);
    draw->unk50 = scales;
    local70 = self->unk48C;
    Graphu64_TransformPoint(&view->camera, &local70, &local80);
    Gobjinst_InitializeActor(draw, -1, previewModelId, D_800CD8D0, &self->copy4, -1, 0, self->unk498 * 0.017453294f, local80, 0,
                     self->unk480, local60, 0);
    Gobjinst_DispatchActorTypeUpdate(draw);
    if (self->unk0 == 9) {
        Preview_SelectPreviewModel(self, previewModelId, extra, modelKind);
    }
    return &self->copy4;
}

/* Copies the three-word vector passed by value into the object's vector at 0x480. */





void Preview_SetPreviewPosition(ObjRecAt480 *arg0, CVector3 v) {
    arg0->unk480 = v;
}

/* Copies the three-word vector passed by value into the object's vector at 0x48C. */





void Preview_SetPreviewFacing(ObjRecAt48C *arg0, CVector3 v) {
    arg0->unk48C = v;
}

/* Stores arg1 into the word at 0x498 of the object arg0. */



void Preview_SetPreviewAngle(ObjRecAt498 *arg0, s32 arg1) {
    arg0->unk498 = arg1;
}

/* Stores a value into the word at offset 0x49C of an object; func_80420618_de and Frontend_ConfirmEquipmentSelection call
   it with zero, Preview_InitModelPreview writes the same word directly and Preview_DrawModelPreview reads it. */


void Preview_SetPreviewTransformUpdate(struct Object49C *object, s32 value) {
    object->value = value;
}

/* Clears the preview model type (sub190.type = 0xFFFF), then selects the matching preview model. */
void Preview_SelectPreviewModel(Obj8041CAD8 *preview, s32 id, s32 extra, s32 expected) {
    preview->sub190.type = 0xFFFF;
    Preview_SelectMatchingPreviewModel(preview, id, extra, expected);
}

#if defined(VERSION_US)
unsigned int func_8041CEA8_us_padding_180EA8[2] = {
    0x35657175, 0xD60F0000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_8041D278_eu_x_padding_10D278[2] = {
    0x0C1077AB, 0x2404006E,
};
#endif

#if defined(VERSION_EU)
unsigned int func_8041D278_eu_padding_193278[2] = {
    0x00021200, 0x00621825,
};
#endif

#if defined(VERSION_DE)
unsigned int func_8041CE38_de_padding_182E38[2] = {
    0x24423834, 0x08102BBC,
};
#endif
