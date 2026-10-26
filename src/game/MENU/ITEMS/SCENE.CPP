#include "include_asm.h"
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"
#include "COMMON/OBJB.H"
#include "COMMON/EXTERNS_8.H"

extern s32 func_8028B21C_de(struct Shared_World *, s32);
extern s32 func_8028C198_de(void *, s32);
extern s32 SetN64_GetDirectoryEntry(s32 *, s32, s32);
extern s32 SetN64_LocatePackSection(void *, s32, s32, s32 *);
typedef struct { u32 w[7]; } Blk28;
void func_8044B600_de(void *level, void *buffer, s32 name) {
    void *table;
    s32 bytes;
    s32 key;
    s32 size;
    s32 shapeKey;
    s32 index;
    void **header;
    void **resource;
    void **shape;
    void *first;
    u32 *source;
    index = func_8028B21C_de(level, name);
    if (index == -1) {
        ((u32 *)buffer)[2] = 0;
    } else {
        size = func_8028C198_de(level, index);
        header = Cache_RequestResource(0, size, size, 0x18, 0, 0, 0, g_constructMapObjectIndex, 1);
        if (header != 0) {
            key = SetN64_GetDirectoryEntry(*header, size, 1);
            resource = func_802540F4_de(0, &table, key, g_constructMapSimpModelsIndex, 1);
            if (resource != 0) {
                shapeKey = SetN64_LocatePackSection(table, key, 0, &bytes);
                shape = Cache_RequestResource(0, shapeKey, shapeKey, bytes, 0, 0, &D_0026D7F4, g_constructMapSimpleModel, 1);
                if (shape != 0) {
                    first = SetN64_GetPackSection(*shape, 2);
                    first = SetN64_GetPackSection(first, 0);
                    source = SetN64_GetPackSection(first, 0);
                    *(Blk28 *)buffer = *(Blk28 *)source;
                    Cache_ReleaseResource(0, shape);
                }
                Cache_ReleaseResource(0, resource);
            }
            Cache_ReleaseResource(0, header);
        }
    }
}
