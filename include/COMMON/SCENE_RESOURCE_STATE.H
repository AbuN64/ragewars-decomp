#ifndef COMMON_SCENE_RESOURCE_STATE_H
#define COMMON_SCENE_RESOURCE_STATE_H
#include "TYPES.H"

typedef struct SceneResourceStateView SceneResourceStateView;
struct SceneResourceStateView {
    s32 loadStage; /* +0x0: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad4[0x18];
    s32 levelDirectoryKey; /* +0x1C: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad20[0x10];
    s32 sceneDirectoryKey; /* +0x30: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad34[0x8];
    u8 selectionClearCursorAnchor; /* +0x3C: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad3D[0x3];
    s32 visibilityResourceKey; /* +0x40: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad44[0x8];
    s32 * levelDirectory; /* +0x4C: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad50[0x10];
    s32 * sceneResources; /* +0x60: src/Scene_LoadLevelResources_SceneResourceState.c */
    u8 sceneIndexDataSlot; /* +0x64: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad65[0x3];
    void * gridBoundsAndSections; /* +0x68: src/Scene_LoadLevelResources_SceneResourceState.c */
    void * collisionData; /* +0x6C: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad70[0x1C];
    s32 * visibilityTable; /* +0x8C: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad90[0x24];
    s32 * slotPoolDefinition; /* +0xB4: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 levelIndexResourceHandle; /* +0xB8: src/Scene_LoadLevelResources_SceneResourceState.c */
    void ** collisionResourceHandle; /* +0xBC: src/Scene_LoadLevelResources_SceneResourceState.c */
    void ** gridBoundsResourceHandle; /* +0xC0: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 sceneIndexResourceHandle; /* +0xC4: src/Scene_LoadLevelResources_SceneResourceState.c */
    void ** levelInfoResourceHandle; /* +0xC8: src/Scene_LoadLevelResources_SceneResourceState.c */
    void ** skyLayersResourceHandle; /* +0xCC: src/Scene_LoadLevelResources_SceneResourceState.c */
    void ** animatedInstancesResourceHandle; /* +0xD0: src/Scene_LoadLevelResources_SceneResourceState.c */
    void ** actorLinksResourceHandle; /* +0xD4: src/Scene_LoadLevelResources_SceneResourceState.c */
    char padD8[0x10];
    s32 * matrixPoolResourceHandle; /* +0xE8: src/Scene_LoadLevelResources_SceneResourceState.c */
    void ** levelPathsResourceHandle; /* +0xEC: src/Scene_LoadLevelResources_SceneResourceState.c */
    void ** navPointsResourceHandle; /* +0xF0: src/Scene_LoadLevelResources_SceneResourceState.c */
    void ** navLinksResourceHandle; /* +0xF4: src/Scene_LoadLevelResources_SceneResourceState.c */
    char padF8[0x4];
    void ** navVisionResourceHandle; /* +0xFC: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 visibilityResourceHandle; /* +0x100: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad104[0x24];
    u8 matrixPool; /* +0x128: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad129[0xF];
    void * levelActors; /* +0x138: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 levelActorCursor; /* +0x13C: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 levelActorCount; /* +0x140: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad144[0xF58 - 0x144];
    s32 kind1Cursor;
    char padF5C[0x1B08 - 0xF5C];
    u8 batchSlotPool; /* +0x1B08: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad1B09[0xFC6F];
    u8 effectPool; /* +0x11778: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad11779[0x3C0F];
    u8 sceneEffectPool; /* +0x15388: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad15389[0x5F27];
    void * sceneSettings; /* +0x1B2B0: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad1B2B4[0x8];
    u8 levelNameBuffer; /* +0x1B2BC: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad1B2BD[0x3F];
    f32 minimumCollisionY; /* +0x1B2FC: src/Scene_LoadLevelResources_SceneResourceState.c */
    void * skyLayerEntries; /* +0x1B300: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 skyLayerCount; /* +0x1B304: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad1B308[0x18];
    u8 dynamicLightPool; /* +0x1B320: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad1B321[0xE7];
    s32 specialSceneEnabled; /* +0x1B408: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 levelSelection; /* +0x1B40C: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad1B410[0xC];
    s32 gameplayStarted; /* +0x1B41C: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad1B420[0x14];
    s32 spawnPlacementKey; /* +0x1B434: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad1B438[0xA4];
    void * navPointSet; /* +0x1B4DC: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 navPointCount; /* +0x1B4E0: src/Scene_LoadLevelResources_SceneResourceState.c */
    void * navLinkSet; /* +0x1B4E4: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 navLinkCount; /* +0x1B4E8: src/Scene_LoadLevelResources_SceneResourceState.c */
    void * navVisionSet; /* +0x1B4EC: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 navVisionCount; /* +0x1B4F0: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad1B4F4[0xC];
    IntrusiveList navigationSearchNodes; /* +0x1B500: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad1B514[0x100];
    f32 spawnOffsetX;
    f32 spawnOffsetY;
    f32 spawnOffsetZ;
    char pad1B620[0x84];
    s32 selectedActorCount; /* +0x1B6A4: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad1B6A8[0x4];
    s32 sceneLoadResetState; /* +0x1B6AC: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad1B6B0[0x260];
    s32 visibilityHeaderWord0; /* +0x1B910: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 visibilityHeaderWord1; /* +0x1B914: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 visibilityHeaderWord2; /* +0x1B918: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 visibilityHeaderWord3; /* +0x1B91C: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 visibilityHeaderWord4; /* +0x1B920: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 visibilityHeaderWord5; /* +0x1B924: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad1B928[0x4];
    s32 hasVisibilityPayload; /* +0x1B92C: src/Scene_LoadLevelResources_SceneResourceState.c */
};
#endif
