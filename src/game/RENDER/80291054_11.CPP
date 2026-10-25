#include "COMMON/WORLD.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "RENDER/80291054.H"
#include "TYPES.H"

extern void Items_ResetActorPools(void *arg0, s32 arg1);
extern void func_804499B0_de(void *arg0, void *arg1, void *arg2);
extern s32 func_804030E0_de(s32);
extern void Items_SetSelection(void *arg0, s32 arg1, s32 arg2);
extern void Items_LoadPreviewBufferA(void *arg0);
extern void Items_LoadPreviewBufferB(void *arg0);





void Render_ResetPlayerItems(s32 arg0, s32 arg1) {
    ObjRecAt255C8 *object = (void *)arg0;
    Items_ResetActorPools(&object->unk255C8, 1);
    func_804499B0_de(&object->unk25580, (void *)1, 0);
    Items_SetSelection(&g_world, ~func_804030E0_de(arg1), 0);
    Items_LoadPreviewBufferA(&g_world);
    Items_LoadPreviewBufferB(&g_world);
}
