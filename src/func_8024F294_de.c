#include "types.h"
#include "span_1000/code_802508E0.h"
#include "span_1000/code_802536F4.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_80245BC0_de_closed.h"
#include "span_1000/code_8024E914.h"
#include "span_16E000/code_8044ACCC.h"
struct ObjB;
extern void **func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern CachedResource *func_80251F6C_de(s32, s32, CachedResource *, CachedResource *, s32, void *, void *, void *, s32);
extern s32 func_8028FE28_de(s32 *, s32, s32);
extern s32 func_8028FE3C_de(void *, s32, s32, s32 *);
extern void func_80253754_de(void *, Node80253610 *);
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
        resource = func_8025193C_de(0, obj->model, obj->model, 0x18, 0, 0, 0, &D_800C3DAC_de, 1);
        if (resource != 0) {
            key = func_8028FE28_de(*resource, obj->model, 1);
            func_80253838_de(0, resource);
            found = func_802540F4_de(0, &header, key, &D_800C3DC0_de, 1);
            if (found != 0) {
                table = header;
                obj->resourceName = func_8028FE3C_de(table, key, index % table[0], &obj->resourceSize);
                obj->loadedType = index;
                func_80253838_de(0, found);
            }
        }
    }
    if (obj->resourceName != 0) {
        resource = func_8025193C_de(0, obj->resourceName, obj->resourceName, obj->resourceSize, 0, 0, &D_0026D7F4, &D_800C3DD4_de, 0);
    } else {
        resource = 0;
    }
    if (resource != 0) {
        func_8026E158_de(resource);
        block = func_80251F6C_de(0, D_800CD3F0, (void *)resource, obj->blockNode, 8, obj, &D_0024F8DC, &D_800C8ED0, 0);
        if (block != 0) {
            func_80253754_de(0, (void *)block);
        }
        func_80253754_de(0, (void *)resource);
    }
}
