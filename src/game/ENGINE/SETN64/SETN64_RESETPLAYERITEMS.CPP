#include "COMMON/WORLD.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "RENDER/SESSION_HANDLER_AND_RENDER_STATE.H"
#include "TYPES.H"

extern void Pools_ResetActorPools(void *owner, s32 actorCount);
extern void Player_InitializePlayerPool(void *pool, void *count, void *force_active);
extern s32 Track_RequestTrackByKey(s32);
extern void Scene_SetSelection(void *state, s32 selection, s32 mode);
extern void Scene_LoadPreviewBufferA(void *previewToLoad);
extern void Scene_LoadPreviewBufferB(void *state);





void SetN64_ResetPlayerItems(s32 sessionAddress, s32 selectionKey) {
    ObjRecAt255C8 *object = (void *)sessionAddress;
    Pools_ResetActorPools(&object->unk255C8, 1);
    Player_InitializePlayerPool(&object->unk25580, (void *)1, 0);
    Scene_SetSelection(&g_world, ~Track_RequestTrackByKey(selectionKey), 0);
    Scene_LoadPreviewBufferA(&g_world);
    Scene_LoadPreviewBufferB(&g_world);
}
