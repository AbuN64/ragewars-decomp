#include "TYPES.H"
#include "COMMON/GFX.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/EXTERNS_8.H"
#include "COMMON/PROPGEOMETRY.H"
#include "COMMON/OBJB.H"
#include "SCENE/802508E0_4.H"

extern char D_800C3E5C_de[];
extern s32 Render_GetDirectoryEntry(s32 *,s32,s32);
extern s32 Render_LocatePackSection(void *,s32,s32,s32 *);
extern void Scene_LockResource(void *,Node80253610 *);
void *Instance_AcquireGeometry(ResourceOwner *owner,s32 index) {
    void **block;
    void *allocation;
    s32 key;
    void *table;
    s32 *entries;
    if (owner->resource != 0) {
        Scene_LockResource(0,owner->resource);
        return owner->resource;
    }
    if (index != owner->index) {
        block = Scene_RequestResource(0,owner->key,owner->key,0x18,0,0,0,D_800C3E5C_de,1);
        if (block != 0) {
            key = Render_GetDirectoryEntry(*block,owner->key,1);
            Scene_ReleaseResource(0,block);
            allocation = func_802540F4_de(0,&table,key,D_800C8F70,1);
            if (allocation != 0) {
                entries = table;
                owner->selected = Render_LocatePackSection(table,key,index % *entries,&owner->size);
                owner->index = index;
                Scene_ReleaseResource(0,allocation);
            }
        }
    }
    if (owner->selected != 0) {
        return Scene_RequestResource(0,owner->selected,owner->selected,owner->size,0,0,D_0026D7D4_de,D_800C3E94_de,0);
    } else { return 0; }
}
