#include "SCENE/802508E0_9.H"
#include "include_asm.h"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/SCENERECAT10C0.H"
#include "SCENE/80286050.H"
#include "gbi.h"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

/* Draws a scene through cached display lists: loads the scene if needed (returning if that fails), calls the model's base list, and on first use records two lists in the frame's command stream, one for objects without flag 4 and one for objects with it, each drawn through StaticInstance_DrawModel inside a Geometry_BeginModelBatch pass and preceded by a branch past its end; finally calls the first cached list. */






extern Gfx *g_displayListCursor;
extern void func_80253908_de(s32 heap);
extern void Scene_BuildCachedGeometry(SceneSceneDrawCachedOpaqueGeometry *scene);


extern void StaticInstance_DrawModel(ObjectSceneDrawCachedOpaqueGeometry *object, void *camera);

void Scene_DrawCachedOpaqueGeometry(SceneSceneDrawCachedOpaqueGeometry *scene, void *camera) {
    ObjectSceneDrawCachedOpaqueGeometry **objects;
    ObjectSceneDrawCachedOpaqueGeometry *object;
    Gfx *branch;
    s32 pass;

    if (scene->loaded == 0) {
        func_80253908_de(0);
        Scene_BuildCachedGeometry(scene);
        if (scene->loaded == 0) {
            return;
        }
    }
    gSPDisplayList(g_displayListCursor++, (unsigned int)SetN64_GetPackSection(scene->model, 2));
    if (scene->lists[0] == 0) {
        for (pass = 0; pass < 2; pass++) {
            scene->lists[pass] = g_displayListCursor;
            gSPBranchList(g_displayListCursor++, 0);
            Geometry_BeginModelBatch();
            objects = SetN64_GetPackSection(scene->model, 1);
            while (*objects != 0) {
                object = *objects++;
                switch (pass) {
                case 0:
                    if (!(object->flags & 4)) {
                        StaticInstance_DrawModel(object, camera);
                    }
                    break;
                case 1:
                    if (object->flags & 4) {
                        StaticInstance_DrawModel(object, camera);
                    }
                    break;
                }
            }
            Geometry_FlushModelBatch();
            gSPEndDisplayList(g_displayListCursor++);
            gSPBranchList(scene->lists[pass]++, (unsigned int)g_displayListCursor);
        }
    }
    gSPDisplayList(g_displayListCursor++, (unsigned int)scene->lists[0]);
}

#include "stddef.h"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/SCENERECAT10C0.H"
#include "gbi.h"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ACTOR_DEFINITION.H"
extern void Cache_ReleaseResource(void *arg0, void *arg1);

/* One sector of the world: its model resource, its x/z extent and its cell in the streaming grid. */
/* Views of the SN debug records this pass reads, with their original member names: CScene_t (0x1B930 bytes),
 * CActiveGridSection_t (0xC), CBoundsRect_t (0x10), CGameStaticInstance_t (0xE8) and CGameSimpleInstance_t (0x1C8). */
typedef struct CBoundsRect_t {
    f32 m_MinX;
    f32 m_MinZ;
    f32 m_MaxX;
    f32 m_MaxZ;
} CBoundsRect_t;
typedef struct CActiveGridSection_t {
    struct Node80253610 *m_pmeGridSection;
    CBoundsRect_t *m_pBoundsRect;
    u16 gridSectionX;
    u16 gridSectionZ;
} CActiveGridSection_t;
typedef struct CGameStaticInstance_t {
    char pad0[0x4];
    u16 m_nObjType; /* ih.m_nObjType */
    char pad6[0x18 - 0x6];
    ActorDefinitionHeader *m_pI; /* ih.m_pI */
    char pad1C[0x4];
    struct Node80253610 *m_pmeGridSection;
    char pad24[0xB8 - 0x24];
    Box m_Bounds;
    char padD0[0xD8 - 0xD0];
    u16 m_wFlags; /* 4 drawn late, 8 static event, 0x200 culled */
    char padDA[0xE8 - 0xDA];
} CGameStaticInstance_t;
typedef struct CGameSimpleInstance_t {
    char pad0[0x18];
    ActorDefinitionHeader *m_pI; /* ah.ih.m_pI */
    char pad1C[0x60 - 0x1C];
    struct Node80253610 *m_pmeGridSection;
    char pad64[0x17C - 0x64];
    Box m_Bounds;
    char pad194[0x19C - 0x194];
    u16 m_wFlags; /* 1 hidden, 2 frustum tested, 0x20 drawn late */
    char pad19E[0x1C0 - 0x19E];
    s32 m_VisBits;
    char pad1C4[0x4];
} CGameSimpleInstance_t;
typedef struct ScenePropSection {
    s32 kind;
    s32 count;
    CGameStaticInstance_t props[1];
} ScenePropSection;
typedef struct SceneStaticSection {
    s32 kind;
    s32 count;
    CGameSimpleInstance_t statics[1];
} SceneStaticSection;
typedef struct CScene_t {
    char pad0[0x94];
    TableRecAt8 *m_pusObjectTypes;
    char pad98[0xB4C - 0x98];
    CGameStaticInstance_t *m_pStaticEventsInstances[64];
    s32 m_nStaticEventsInstances;
    char padC50[0x10BC - 0xC50];
    s32 m_nTransparentInstances;
    void *m_pTransparentInstances[64];
    char pad11C0[0x1504 - 0x11C0];
    s32 m_nActiveGridSections;
    CActiveGridSection_t m_ActiveGridSections[128];
    char pad1B08[0x1B6B0 - 0x1B08];
    struct Node80253610 *m_pmeVisibilityData;
    char m_VisData[0x25C]; /* CVisibilityData_t */
    char pad1B910[0x1B928 - 0x1B910];
    s32 m_bVisibilityValid;
    char pad1B92C[0x1B930 - 0x1B92C];
} CScene_t;

extern s32 D_800D2AE0;
extern s32 D_800CD730;
extern Shared_func_80234FDC_S1 *Sky_FindScreenMessage(GameplayCamera *camera);
extern s32 VisData_TestVisibilityGridBit(void *grid, s32 x, s32 z, s32 index);
extern s32 VisData_TestBoxAgainstFrustum(void *planes, void *bounds);
extern void StaticInstance_RegisterGeometryResources(CGameStaticInstance_t *prop, GameplayCamera *camera);
extern s32 StaticInstance_UpdateDistanceFade(CGameStaticInstance_t *prop, GameplayCamera *camera);
extern void StaticInstance_DrawDistanceFadedModel(CGameStaticInstance_t *prop, GameplayCamera *camera);
extern void SimpleInstance_RegisterModelVariantResources(CGameSimpleInstance_t *object, GameplayCamera *camera);
extern void func_8024EB90_de(CGameSimpleInstance_t *object);

static __inline__ s32 SceneFindShip(TableRecAt8 *table) {
    s32 i;
    s32 count = table->count;
    u16 *p = table->entries;
    for (i = 0; i < count; i++) {
        if (p[i] == 0x33) {
            return i;
        }
    }
    return -1;
}
void func_80289084_de(CScene_t *world, GameplayCamera *camera) {
    CScene_t *scene;
    CGameStaticInstance_t *props;
    CGameStaticInstance_t *prop;
    s32 model;
    s32 sectorIndex;
    s32 sectorCount;
    u32 mask;
    s32 viewMask;
    s32 shipModel;
    s32 showShip;
    Shared_func_80234FDC_S1 *player;
    CActiveGridSection_t *sector;
    CActiveGridSection_t *sectors;
    CGameSimpleInstance_t *statics;
    ScenePropSection *propSection;
    SceneStaticSection *staticSection;
    s32 propCount;
    s32 staticCount;
    s32 queued;
    s32 i;

    mask = D_801462C8.sceneMask;
    viewMask = camera->floorSurface;
    world->m_nTransparentInstances = 0;
#if defined(VERSION_US_REV1)
    if (D_800D2AE0 == 0 && D_801462C8.local != 0) {
#else
    if (D_801462C8.local != 0) {
#endif
        Scene_DrawCachedOpaqueGeometry(world, camera);
        return;
    }
    player = Sky_FindScreenMessage(camera);
    shipModel = SceneFindShip(world->m_pusObjectTypes);
    showShip = 0;
    if (player != NULL && shipModel != -1) {
        showShip = D_801462C8.local == 0;
    }
    gDPPipeSync(g_displayListCursor++);
    gDPSetCycleType(g_displayListCursor++, G_CYC_2CYCLE);
    scene = world;
    Geometry_BeginModelBatch();
    scene->m_nTransparentInstances = 0;
    if (player != NULL && (player->unk664 & 0x100)) {
        gSPMoveWord(g_displayListCursor++, G_MW_CLIP, G_MWO_CLIP_RNX, FRUSTRATIO_1);
        gSPMoveWord(g_displayListCursor++, G_MW_CLIP, G_MWO_CLIP_RNY, FRUSTRATIO_1);
        gSPMoveWord(g_displayListCursor++, G_MW_CLIP, G_MWO_CLIP_RPX, (u16)-FRUSTRATIO_1);
        gSPMoveWord(g_displayListCursor++, G_MW_CLIP, G_MWO_CLIP_RPY, (u16)-FRUSTRATIO_1);
    } else {
        gSPMoveWord(g_displayListCursor++, G_MW_CLIP, G_MWO_CLIP_RNX, FRUSTRATIO_2);
        gSPMoveWord(g_displayListCursor++, G_MW_CLIP, G_MWO_CLIP_RNY, FRUSTRATIO_2);
        gSPMoveWord(g_displayListCursor++, G_MW_CLIP, G_MWO_CLIP_RPX, (u16)-FRUSTRATIO_2);
        gSPMoveWord(g_displayListCursor++, G_MW_CLIP, G_MWO_CLIP_RPY, (u16)-FRUSTRATIO_2);
    }
    sectorCount = scene->m_nActiveGridSections;
    sectors = scene->m_ActiveGridSections;
    for (sectorIndex = 0; sectorIndex < sectorCount; sectorIndex++) {
        sector = &sectors[sectorIndex];
        if (!(sector->m_pBoundsRect->m_MaxX > camera->clipBounds[0].x && sector->m_pBoundsRect->m_MinX < camera->clipBounds[1].x &&
              sector->m_pBoundsRect->m_MaxZ > camera->clipBounds[0].z && sector->m_pBoundsRect->m_MinZ < camera->clipBounds[1].z)) {
            continue;
        }
        Cache_MarkResourceInUse(0, sector->m_pmeGridSection);
        model = sector->m_pmeGridSection->field0;
        propSection = SetN64_GetPackSection(model, 0);
        propCount = propSection->count;
        props = propSection->props;
        for (i = 0; i < propCount; i++) {
            prop = props;
            prop += i;
            queued = 0;
            if (!(prop->m_pI->gate & mask)) {
                continue;
            }
            prop->m_pmeGridSection = sector->m_pmeGridSection;
            if (D_800CD730 == 0) {
                StaticInstance_RegisterGeometryResources(prop, camera);
            }
            if ((prop->m_wFlags & 8) && (prop->m_pI->flags & 4)) {
                queued = 1;
                if (prop->m_nObjType == shipModel) {
                    if (showShip && scene->m_nStaticEventsInstances != 64) {
                        scene->m_pStaticEventsInstances[scene->m_nStaticEventsInstances++] = prop;
                    }
                } else if (scene->m_nStaticEventsInstances != 64) {
                    scene->m_pStaticEventsInstances[scene->m_nStaticEventsInstances++] = prop;
                }
            }
            if (scene->m_bVisibilityValid != 0 &&
                VisData_TestVisibilityGridBit(scene->m_VisData, sector->gridSectionX, sector->gridSectionZ, i) == 0) {
                continue;
            }
            if (camera->clipBounds[1].x > prop->m_Bounds.min.x && camera->clipBounds[0].x < prop->m_Bounds.max.x &&
                camera->clipBounds[1].z > prop->m_Bounds.min.z && camera->clipBounds[0].z < prop->m_Bounds.max.z &&
                camera->clipBounds[1].y > prop->m_Bounds.min.y && camera->clipBounds[0].y < prop->m_Bounds.max.y &&
                VisData_TestBoxAgainstFrustum(camera->clipPlanes, &prop->m_Bounds)) {
                if ((prop->m_wFlags & 8) && !queued && (prop->m_nObjType != shipModel || showShip)) {
                    if (scene->m_nStaticEventsInstances != 64) {
                        scene->m_pStaticEventsInstances[scene->m_nStaticEventsInstances++] = prop;
                    }
                }
                if (StaticInstance_UpdateDistanceFade(prop, camera)) {
                    if (prop->m_wFlags & 4) {
                        if (scene->m_nTransparentInstances != 64) {
                            scene->m_pTransparentInstances[scene->m_nTransparentInstances++] = prop;
                        }
                    } else {
                        StaticInstance_DrawDistanceFadedModel(prop, camera);
                    }
                }
                prop->m_wFlags &= ~0x200;
            } else {
                prop->m_wFlags |= 0x200;
            }
        }
        staticSection = SetN64_GetPackSection(model, 1);
        staticCount = staticSection->count;
        statics = staticSection->statics;
        for (i = 0; i < staticCount; i++) {
            statics[i].m_pmeGridSection = sector->m_pmeGridSection;
            if (D_800CD730 == 0) {
                SimpleInstance_RegisterModelVariantResources(&statics[i], camera);
            }
            if ((statics[i].m_pI->gate & mask) && !(statics[i].m_wFlags & 1) && (viewMask & statics[i].m_VisBits) &&
                camera->clipBounds[1].x > statics[i].m_Bounds.min.x && camera->clipBounds[0].x < statics[i].m_Bounds.max.x &&
                camera->clipBounds[1].z > statics[i].m_Bounds.min.z && camera->clipBounds[0].z < statics[i].m_Bounds.max.z &&
                camera->clipBounds[1].y > statics[i].m_Bounds.min.y && camera->clipBounds[0].y < statics[i].m_Bounds.max.y &&
                (statics[i].m_wFlags & 2) && VisData_TestBoxAgainstFrustum(camera->clipPlanes, &statics[i].m_Bounds)) {
                if (statics[i].m_wFlags & 0x20) {
                    if (scene->m_nTransparentInstances != 64) {
                        scene->m_pTransparentInstances[scene->m_nTransparentInstances++] = &statics[i];
                    }
                } else {
                    func_8024EB90_de(&statics[i]);
                }
            }
        }
    }
    Geometry_FlushModelBatch();
    if (scene->m_bVisibilityValid != 0) {
        Cache_UnlockResource(NULL, scene->m_pmeVisibilityData);
        Cache_ReleaseResource(NULL, scene->m_pmeVisibilityData);
    }
}
