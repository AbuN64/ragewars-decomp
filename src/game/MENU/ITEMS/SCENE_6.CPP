#include "COMMON/OBJB.H"
#include "COMMON/UNUSED.H"
#include "MENU/8044ACCC.H"
#include "TYPES.H"
#include "SCENE/802508E0_4.H"
extern void Cache_ReleaseResource(void *, void *); /* extern */

/* Loads a selected resource into the shared buffer and releases the temporary allocation. */

struct ItemsPreviewStateA;

/* extern */
extern s32 Control_IsSnapshotActive(void); /* extern */
extern void *func_802BD3A0_de(void *, const void *, int); /* extern */
extern char D_00285160;
extern char g_loadSavePersistentData;

void Items_LoadPreviewBufferA(ItemsPreviewStateA *previewToLoad) {
    s32 *persistentDataResource;
    s32 temp_a1;

    if (Control_IsSnapshotActive() == 0) {
        persistentDataResource = Cache_RequestResource(0, previewToLoad->unk38, previewToLoad->unk38, previewToLoad->unk44, 0, 0, &D_00285160, &g_loadSavePersistentData, 1);
        func_802BD3A0_de(&D_800F91F0, (const void *)*persistentDataResource, 0x5800);
        Cache_ReleaseResource(0, persistentDataResource);
        previewToLoad->unk4 = 1;
    }
}
