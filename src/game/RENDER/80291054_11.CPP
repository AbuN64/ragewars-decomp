#include "COMMON/WORLD.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "RENDER/80291054.H"
#include "TYPES.H"

extern void Items_ResetActorPools(void *arg0, s32 arg1);
extern void Ovlgame_InitializePlayerPool(void *arg0, void *arg1, void *arg2);
extern s32 Menu_RequestTrackByKey(s32);
extern void OvlScene_SetSelection(void *arg0, s32 arg1, s32 arg2);
extern void Items_LoadPreviewBufferA(void *arg0);
extern void Items_LoadPreviewBufferB(void *arg0);





void SetN64_ResetPlayerItems(s32 sessionAddress, s32 selectionKey) {
    ObjRecAt255C8 *object = (void *)sessionAddress;
    Items_ResetActorPools(&object->unk255C8, 1);
    Ovlgame_InitializePlayerPool(&object->unk25580, (void *)1, 0);
    OvlScene_SetSelection(&g_world, ~Menu_RequestTrackByKey(selectionKey), 0);
    Items_LoadPreviewBufferA(&g_world);
    Items_LoadPreviewBufferB(&g_world);
}
