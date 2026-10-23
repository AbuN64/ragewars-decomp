#include "include_asm.h"
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"
#include "COMMON/OBJB.H"
#include "COMMON/EXTERNS_8.H"

extern s32 func_8028B21C_de(struct Shared_World *, s32);
extern s32 func_8028C198_de(void *, s32);
extern s32 func_8028FE28_de(s32 *, s32, s32);
extern s32 func_8028FE3C_de(void *, s32, s32, s32 *);
extern char D_0026D7F4;
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
        header = func_8025193C_de(0, size, size, 0x18, 0, 0, 0, D_800C4EE0_de, 1);
        if (header != 0) {
            key = func_8028FE28_de(*header, size, 1);
            resource = func_802540F4_de(0, &table, key, D_800C4F04_de, 1);
            if (resource != 0) {
                shapeKey = func_8028FE3C_de(table, key, 0, &bytes);
                shape = func_8025193C_de(0, shapeKey, shapeKey, bytes, 0, 0, &D_0026D7F4, D_800C4F2C_de, 1);
                if (shape != 0) {
                    first = func_8028FDB4_de(*shape, 2);
                    first = func_8028FDB4_de(first, 0);
                    source = func_8028FDB4_de(first, 0);
                    *(Blk28 *)buffer = *(Blk28 *)source;
                    func_80253838_de(0, shape);
                }
                func_80253838_de(0, resource);
            }
            func_80253838_de(0, header);
        }
    }
}
