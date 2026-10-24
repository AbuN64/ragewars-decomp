#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LABEL.H"
#include "TYPES.H"
#include "FRONTEND/8041BEA8_6.H"

#if defined(VERSION_DE)
INCLUDE_ASM("ovl_80400000", func_8041C614);
#endif
#if !(defined(VERSION_DE))
#ifdef NON_MATCHING
#include "COMMON/WORLD.H"
extern u8 D_800DD460_de[], D_800DD474[];
extern void *func_8028FE28_de(void *, void *, s32);
extern void *func_8028FE3C_de(void *, void *, s32, s32 *);
extern void *func_8028CF6C_de(void *, u16);
extern void func_80246BE8_de(void *, void *, void *, s32);
#include "COMMON/SCENERECAT10C0.H"
#include "COMMON/ACTOR_DEFINITION.H"
typedef struct FrontendModelHeader {
    u8 prefix[0x1C];
    u16 definitionIndex;
} FrontendModelHeader;

static inline struct TableRecAt8 *Frontend_GetPreviewModelIds(Shared_World *world) {
    return world->modelIds;
}

/* 19/121 aligned edits; remaining: world-pointer setup and failed-index branch scheduling. */
void Frontend_SelectMatchingPreviewModel(struct Unk8041CE88 *preview, s32 id, s32 extra, s32 expected) {
    Shared_World *world;
    Obj8041CAD8At190 *previewState = &((Obj8041CAD8 *)preview)->sub190;
    struct TableRecAt8 *list = Frontend_GetPreviewModelIds(&D_8011FE88);
    s32 count = list->count;
    s32 i = 0;
    s32 found = 0;
    u16 *entry;
    void *modelName;
    void **indexResource;
    void **modelResource;
    void *modelData;
    ActorDefinitionHeader *definition;
    s32 modelSize;
    if (count <= 0) {
        return;
    }
    world = &D_8011FE88;
    entry = list->entries;
    do {
        if (*entry == id) {
            modelName = func_8028FE28_de(world->indexedDirectory, (void *)world->indexedBank, i);
            indexResource = func_8025193C_de(0, (u32)modelName, (u32)modelName, 0x18, 0, 0, 0, (const char *)D_800DD460_de, 1);
            if (indexResource != 0) {
                modelData = func_8028FE3C_de(*indexResource, modelName, 0, &modelSize);
                modelResource = func_8025193C_de(0, (u32)modelData, (u32)modelData, modelSize, 0, 0, 0, (const char *)D_800DD474, 1);
                if (modelResource != 0) {
                    definition = func_8028CF6C_de(world, ((FrontendModelHeader *)func_8028FDB4_de(*modelResource, 0))->definitionIndex);
                    if (definition->character == expected && definition->kind == ((Obj8041CAD8 *)preview)->unk0) {
                        previewState->unk4 = i;
                        previewState->unkE4 = id;
                        func_80246BE8_de(previewState, world->indexedDirectory, (void *)world->indexedBank, extra);
                        found = 1;
                    }
                    func_80253754_de(0, (struct Node80253610 *)modelResource);
                }
                func_80253754_de(0, (struct Node80253610 *)indexResource);
            }
        }
        i++;
        entry++;
    } while (i < count && !found);
}
#else
INCLUDE_ASM("ovl_80400000", Frontend_SelectMatchingPreviewModel);
#endif
#endif

#ifdef NON_MATCHING
/* The names m2c output assumes (its valid-syntax macros), so a draft compiles on its own. */
#ifndef NULL
#define NULL ((void *)0)
#endif
typedef int M2C_UNK;
typedef signed char M2C_UNK8;
typedef short M2C_UNK16;
typedef int M2C_UNK32;
typedef long long M2C_UNK64;
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
#include "MENU/GFX/80414430_19.H"
#include "TYPES.H"
#include "gbi.h"
#include "particle/80271B18_3.H"
s32 func_80246E44_de(void *);
s32 func_80249E28_de(void *, void *);
s32 func_8024B8C4_de(void *);
s32 func_802737F0_de(void *, f32);
extern MenuModelScreen D_80141008[];
void func_8041C7F4_de(Obj8041CAD8 *self) {
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
            Gfx *g = D_80110634++;
            char *address = (char *)(u32)(D_800D297C << 6);
            address += 0x380;
            address += (u32)view;
            gSPMatrix(g, (u32)address, G_MTX_LOAD | G_MTX_PROJECTION);
        }
        local10 = self->unk48C;
        func_80272898_de(&view->camera, &local10, &local20);
        if (func_8025477C_de() == 0) {
            func_8025476C_de(1);
        }
        func_80417138_de(0x33335);
        gDPPipeSync(D_80110634++);
        gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
        gDPSetTexturePersp(D_80110634++, G_TP_PERSP);
        gDPSetTextureFilter(D_80110634++, G_TF_BILERP);
        func_8026D844_de();
        draw->unk8 = local20;
        draw->unk1C4 = local20;
        func_8024B8C4_de(draw);
        draw->unk8 = local20;
        draw->unk1C4 = local20;
        if (self->unk49C != 0 || draw->unk10E == 0) {
            func_80246E44_de(draw);
            if (self->unk4A0 != 0) {
                func_802737F0_de(&draw->unk74, (f32)self->unk4A0 * D_800DD488);
            }
        }
        draw->unk6C = self->unk498 * *(&D_800DD488 + 1);
        draw->unk8 = local20;
        draw->unk1C4 = local20;
        func_8026D980_de();
        func_80249E28_de(draw, view);
        draw->unk140 = D_800DF520;
        draw->unk158 = D_800DF520;
        func_8026D9D0_de();
        D_800CC380 = saved;
    }
}

#include "COMMON/WORLD.H"
#include "RESMGR/802A0888.H"
extern s32 D_800D297C, D_800E28D0, D_800E28D4;
extern s32 D_800CD8D0;
extern void *func_8028CFA0_de(void *, s32, s32, void *);
extern void func_802466A0_de(void *, s32, s32, s32, void *, s32, s32, f32, CVector3, s32, CVector3, CVector3, s32);
extern void func_8024B2D0_de();
/* Starts a menu model preview: loads the projection, spawns the model through func_8028CFA0_de, keeps a copy
 * of its record, places it scaled to the screen and runs its first update. Returns the copy, or 0 when no model. */
void *Frontend_InitModelPreview(Obj8041CAD8 *self, s32 id, s32 arg2, s32 arg3, s32 arg4, CVector3 position, CVector3 facing,
                       f32 scale, s32 arg8) {
    CVector3 scales;
    CVector3 local60;
    CVector3 local70;
    CVector3 local80;
    MenuModelScreen *view;
    Obj8041CAD8At190 *draw;
    Gfx *g;
    f32 ratio;
    Ret8028CFA0 *source;
    func_802A001C_de(&local60, 0, sizeof(local60));
    g = D_80110634++;
    view = D_80141008;
    gSPMatrix(g, &view->matrices[D_800D297C], G_MTX_LOAD | G_MTX_PROJECTION);
    self->unk49C = 1;
    self->unk4A0 = arg8;
    draw = &self->sub190;
    source = func_8028CFA0_de(&D_8011FE88, id, arg2, g);
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
    self->copy4.unk8 = D_800DD490_de;
    ratio = view->width / (f32)D_800E28D0;
    scales.x = self->unk480.x * ratio;
    scales.z = self->unk480.z * ratio;
    scales.y = self->unk480.y * (view->height / (f32)D_800E28D4);
    draw->unk50 = scales;
    local70 = self->unk48C;
    func_80272898_de(&view->camera, &local70, &local80);
    func_802466A0_de(draw, -1, arg3, D_800CD8D0, &self->copy4, -1, 0, self->unk498 * *(&D_800DD490_de + 1), local80, 0,
                     self->unk480, local60, 0);
    func_8024B2D0_de(draw);
    if (self->unk0 == 9) {
        func_8041CE18_de(self, arg3, arg4, arg2);
    }
    return &self->copy4;
}

/* Copies the three-word vector passed by value into the object's vector at 0x480. */





void func_8041CDB0_de(ObjRecAt480 *arg0, CVector3 v) {
    arg0->unk480 = v;
}

/* Copies the three-word vector passed by value into the object's vector at 0x48C. */





void func_8041CDDC_de(ObjRecAt48C *arg0, CVector3 v) {
    arg0->unk48C = v;
}

/* Stores arg1 into the word at 0x498 of the object arg0. */



void func_8041CE08_de(ObjRecAt498 *arg0, s32 arg1) {
    arg0->unk498 = arg1;
}

/* Stores a value into the word at offset 0x49C of an object; func_80420618_de and func_8043AB40_de call
   it with zero, Frontend_InitModelPreview writes the same word directly and func_8041C7F4_de reads it. */


void func_8041CE10_de(struct Object49C *object, s32 value) {
    object->value = value;
}

/* Sets field 0x274 of arg0 to 0xFFFF and then calls Frontend_SelectMatchingPreviewModel on it, passing its other three arguments through. */
void func_8041CE18_de(Unk8041CE88 *arg0, s32 id, s32 extra, s32 expected) {
    arg0->unk274 = 0xFFFF;
    Frontend_SelectMatchingPreviewModel(arg0, id, extra, expected);
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
