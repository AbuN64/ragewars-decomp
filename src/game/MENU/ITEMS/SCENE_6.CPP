#include "COMMON/OBJB.H"
#include "COMMON/UNUSED.H"
#include "MENU/8044ACCC.H"
#include "TYPES.H"
#include "SCENE/802508E0_4.H"
extern void Scene_ReleaseResource(void *, void *); /* extern */

/* Loads a selected resource into the shared buffer and releases the temporary allocation. */

struct ItemsPreviewStateA;

/* extern */
extern s32 func_80264B6C_de(void); /* extern */
extern void *func_802BD3A0_de(void *, const void *, int); /* extern */
extern char D_00285160;
extern char g_loadSavePersistentData;

void Items_LoadPreviewBufferA(ItemsPreviewStateA *arg0) {
    s32 *temp_v0;
    s32 temp_a1;

    if (func_80264B6C_de() == 0) {
        temp_v0 = Scene_RequestResource(0, arg0->unk38, arg0->unk38, arg0->unk44, 0, 0, &D_00285160, &g_loadSavePersistentData, 1);
        func_802BD3A0_de(&D_800F91F0, (const void *)*temp_v0, 0x5800);
        Scene_ReleaseResource(0, temp_v0);
        arg0->unk4 = 1;
    }
}
