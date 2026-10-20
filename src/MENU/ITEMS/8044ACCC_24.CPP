#include "include_asm.h"
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"
#include "COMMON/OBJB.H"
#include "COMMON/EXTERNS_8.H"

#ifdef NON_MATCHING
extern s32 func_8028B21C_de(struct Shared_World *, s32);
extern s32 func_8028C198_de(void *, s32);
extern s32 func_8028FE28_de(s32 *, s32, s32);
extern s32 func_8028FE3C_de(void *, s32, s32, s32 *);
void func_8044B600_de(void *level, void *buffer, s32 name) {
    u32 *output = buffer;
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
    u32 word0, word1, word2, word3;
    index = func_8028B21C_de(level, name);
    if (index == -1) {
        output[2] = 0;
    } else {
        size = func_8028C198_de(level, index);
        header = func_8025193C_de(0, size, size, 0x18, 0, 0, 0, D_800C4EE0_de, 1);
        if (header != 0) {
            key = func_8028FE28_de(*header, size, 1);
            resource = func_802540F4_de(0, &table, key, D_800C4F04_de, 1);
            if (resource != 0) {
                shapeKey = func_8028FE3C_de(table, key, 0, &bytes);
                shape = func_8025193C_de(0, shapeKey, shapeKey, bytes, 0, 0, func_8026D7F4_de, D_800C4F2C_de, 1);
                if (shape != 0) {
                    first = func_8028FDB4_de(*shape, 2);
                    first = func_8028FDB4_de(first, 0);
                    source = func_8028FDB4_de(first, 0);
                    word0 = source[0];
                    word1 = source[1];
                    word2 = source[2];
                    word3 = source[3];
                    output[0] = word0;
                    output[1] = word1;
                    output[2] = word2;
                    output[3] = word3;
                    word0 = source[4];
                    word1 = source[5];
                    word2 = source[6];
                    output[4] = word0;
                    output[5] = word1;
                    output[6] = word2;
                    func_80253838_de(0, shape);
                }
                func_80253838_de(0, resource);
            }
            func_80253838_de(0, header);
        }
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_8044B600_de);
#endif
