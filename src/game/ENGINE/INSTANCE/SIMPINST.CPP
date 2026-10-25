#include "TYPES.H"
#include "COMMON/MANAGER.H"
#include "COMMON/RESOURCELOCKSTATE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/EXTERNS_8.H"
#include "COMMON/PROPGEOMETRY.H"
#include "WORLD_2/8024E914.H"
#include "COMMON/OBJB.H"
#include "SCENE/802508E0_4.H"

struct ObjB;
extern CachedResource *func_80251F6C_de(s32, s32, CachedResource *, CachedResource *, s32, void *, void *, void *, s32);
extern s32 Render_GetDirectoryEntry(s32 *, s32, s32);
extern s32 Render_LocatePackSection(void *, s32, s32, s32 *);
extern void Scene_UnlockResource(void *, Node80253610 *);
extern void func_8026E158_de(void **);
void func_8024F294_de(struct ObjB *object, s32 unused) {
    void *memory = object;
    ResourceObject23 *obj = memory;
    void *header;
    s32 *table;
    void **resource;
    void **found;
    CachedResource *block;
    s32 key;
    s32 index;
    index = obj->type;
    if (index != obj->loadedType) {
        resource = Scene_RequestResource(0, obj->model, obj->model, 0x18, 0, 0, 0, D_800C3DAC_de, 1);
        if (resource != 0) {
            key = Render_GetDirectoryEntry(*resource, obj->model, 1);
            Scene_ReleaseResource(0, resource);
            found = func_802540F4_de(0, &header, key, D_800C3DC0_de, 1);
            if (found != 0) {
                table = header;
                obj->resourceName = Render_LocatePackSection(table, key, index % table[0], &obj->resourceSize);
                obj->loadedType = index;
                Scene_ReleaseResource(0, found);
            }
        }
    }
    if (obj->resourceName != 0) {
        resource = Scene_RequestResource(0, obj->resourceName, obj->resourceName, obj->resourceSize, 0, 0, &D_0026D7F4, D_800C3DD4_de, 0);
    } else {
        resource = 0;
    }
    if (resource != 0) {
        func_8026E158_de(resource);
        block = func_80251F6C_de(0, D_800CD3F0, (void *)resource, obj->blockNode, 8, obj, &D_0024F8DC, &D_800C8ED0, 0);
        if (block != 0) {
            Scene_UnlockResource(0, (void *)block);
        }
        Scene_UnlockResource(0, (void *)resource);
    }
}
