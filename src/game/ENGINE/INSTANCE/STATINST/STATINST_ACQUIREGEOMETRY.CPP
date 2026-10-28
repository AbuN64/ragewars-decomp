#include "TYPES.H"
#include "COMMON/GFX.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/EXTERNS_8.H"
#include "COMMON/PROPGEOMETRY.H"
#include "COMMON/OBJB.H"
#include "SCENE/802508E0_4.H"

extern char g_statObjectIndexText[];
extern s32 SetN64_GetDirectoryEntry(s32 *,s32,s32);
extern s32 SetN64_LocatePackSection(void *,s32,s32,s32 *);
extern void Cache_LockResource(void *,Node80253610 *);
void *Statinst_AcquireGeometry(ResourceOwner *owner,s32 index) {
    void **block;
    void *allocation;
    s32 key;
    void *table;
    s32 *entries;
    if (owner->resource != 0) {
        Cache_LockResource(0,owner->resource);
        return owner->resource;
    }
    if (index != owner->index) {
        block = Cache_RequestResource(0,owner->key,owner->key,0x18,0,0,0,g_statObjectIndexText,1);
        if (block != 0) {
            key = SetN64_GetDirectoryEntry(*block,owner->key,1);
            Cache_ReleaseResource(0,block);
            allocation = Cache_RequestWordCountedResource(0,&table,key,s_statModelsIndexText,1);
            if (allocation != 0) {
                entries = table;
                owner->selected = SetN64_LocatePackSection(table,key,index % *entries,&owner->size);
                owner->index = index;
                Cache_ReleaseResource(0,allocation);
            }
        }
    }
    if (owner->selected != 0) {
        return Cache_RequestResource(0,owner->selected,owner->selected,owner->size,0,0,D_0026D7D4_de,s_statModelText,0);
    } else { return 0; }
}
